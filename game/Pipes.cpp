#include "Pipes.h"
#include "Consts.h"
#include <iostream>

Pipes::Pipes()
{
	pipeTextureUp.loadFromFile(SPRITE_FILE, sf::IntRect(PIPE_POSITION_UP.x, PIPE_POSITION_UP.y, PIPE_SIZE.x, PIPE_SIZE.y));
	pipeTextureDown.loadFromFile(SPRITE_FILE, sf::IntRect(PIPE_POSITION_DOWN.x, PIPE_POSITION_DOWN.y, PIPE_SIZE.x, PIPE_SIZE.y));

	for (auto& [topPipe, bottomPipe] : m_pipes)
	{
		topPipe.setTexture(pipeTextureUp);
		bottomPipe.setTexture(pipeTextureDown);

		topPipe.setScale({ 3.25f, 3.25f });
		bottomPipe.setScale({ 3.25f, 3.25f });

		GeneratePipePair(topPipe, bottomPipe);
	}
}

void Pipes::Update(float birdPositionX)
{
	for (auto& [topPipe, bottomPipe] : m_pipes)
	{
		if (topPipe.getPosition().x < birdPositionX - WINDOW_SIZE.x / 2 - topPipe.getScale().x * PIPE_SIZE.x)
		{
			GeneratePipePair(topPipe, bottomPipe);
		}
	}
}

void Pipes::Draw(sf::RenderWindow& window)
{
	for (auto& [topPipe, bottomPipe] : m_pipes)
	{
		window.draw(topPipe);
		window.draw(bottomPipe);
	}
}

std::pair<float, float> Pipes::GetVoidLimit()
{
	const unsigned eps = PIPE_SIZE.y / 10;
	const auto topLimit = eps + rand() % (int(WINDOW_SIZE.y - GROUND_SIZE.y) - 2 * eps - VOID_HEIGHT);
	return { float(topLimit), float(topLimit + VOID_HEIGHT) };
}

std::pair<sf::Sprite, sf::Sprite> Pipes::GetTheFarestPipe() const
{
	return *std::max_element(m_pipes.cbegin(), m_pipes.cend(), [](const auto& lhs, const auto& rhs) {
		return lhs.first.getPosition().x < rhs.first.getPosition().x;
	});
}

void Pipes::GeneratePipePair(sf::Sprite& topPipe, sf::Sprite& bottomPipe)
{
	auto theFarestPipePositionX = GetTheFarestPipe().first.getPosition().x;
	if (theFarestPipePositionX == 0) theFarestPipePositionX = 0.8f * (sf::Vector2f(WINDOW_SIZE).y - BIRD_SIZE.y);
	std::cout << theFarestPipePositionX << std::endl;

	const auto [topLimit, bottomLimit] = GetVoidLimit();
	topPipe.setPosition({ theFarestPipePositionX + PIPE_DISTANCE, topLimit - topPipe.getScale().y * PIPE_SIZE.y });
	bottomPipe.setPosition({ theFarestPipePositionX + PIPE_DISTANCE, bottomLimit });
}
