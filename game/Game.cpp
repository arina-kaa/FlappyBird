#include "Game.h"
#include "Consts.h"
#include <iostream>

namespace
{

std::pair<float, float> GetVoidLimit()
{
	const unsigned eps = PIPE_SIZE.y / 10;
	const auto topLimit = eps + rand() % (int(WINDOW_SIZE.y) - 2 * eps - VOID_HEIGHT);
	return {float(topLimit), float(topLimit + VOID_HEIGHT)};
}

}

Game::Game()
	:m_window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), WINDOW_TITLE)
{
	m_window.setFramerateLimit(WINDOW_FRAME_LIMIT);
	m_view.reset(sf::FloatRect(0, 0, float(WINDOW_SIZE.x), float(WINDOW_SIZE.y)));
	m_window.setView(m_view);

	sf::Texture pipeTexture;
	pipeTexture.loadFromFile(SPRITE_FILE, sf::IntRect(PIPE_POSITION.x, PIPE_POSITION.y, PIPE_SIZE.x, PIPE_SIZE.y));

	for (auto & [topPipe, bottomPipe] : m_pipes)
	{
		topPipe.setTexture(pipeTexture);
		bottomPipe.setTexture(pipeTexture);
		
		topPipe.setScale({ 3.25f, 3.25f });
		bottomPipe.setScale({ 3.25f, 3.25f });

		GeneratePipePair(topPipe, bottomPipe);
	}
}

void Game::DoGameLoop()
{
	while (m_window.isOpen())
	{
		const auto dt = m_clock.restart().asSeconds();

		CheckEvents();
		Update(dt);
		m_window.setView(m_view);
		Render();
		m_window.display();
	}
}

void Game::CheckEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		CheckKeyboardEvents(event);

		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Game::CheckKeyboardEvents(const sf::Event & event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Space:
			/*if (!isGameStarted) isGameStarted = true;*/
			m_bird.SetVelocity({ BIRD_INITIAL_VELOCITY.x, JUMP_SPEED });
			break;
		default:
			break;
		}
	}
}

void Game::Update(float dt)
{
	for (auto & [topPipe, bottomPipe] : m_pipes)
	{
		if (topPipe.getPosition().x < m_bird.GetPosition().x - WINDOW_SIZE.x / 2 - topPipe.getScale().x * PIPE_SIZE.x)
		{
			GeneratePipePair(topPipe, bottomPipe);
		}
	}

	m_bird.Update(dt);
	m_background.SetPosition({ m_bird.GetPosition().x - WINDOW_SIZE.x / 2.f , WINDOW_SIZE.y / 2.f });
	m_view.setCenter(m_bird.GetPosition().x, WINDOW_SIZE.y / 2.f);
}

void Game::Render()
{
	m_background.Draw(m_window);

	for (auto & [topPipe, bottomPipe] : m_pipes)
	{
		m_window.draw(topPipe);
		m_window.draw(bottomPipe);
	}

	m_bird.Draw(m_window);
}

std::pair<sf::Sprite, sf::Sprite> Game::GetTheFarestPipe() const
{
	return *std::max_element(m_pipes.cbegin(), m_pipes.cend(), [](const auto & lhs, const auto & rhs) {
		return lhs.first.getPosition().x < rhs.first.getPosition().x;
	});
}

void Game::GeneratePipePair(sf::Sprite & topPipe, sf::Sprite & bottomPipe)
{
	const auto theFarestPipePositionX = GetTheFarestPipe().first.getPosition().x;

	const auto [topLimit, bottomLimit] = GetVoidLimit();
	topPipe.setPosition({ theFarestPipePositionX + PIPE_DISTANCE, topLimit - topPipe.getScale().y * PIPE_SIZE.y });
	bottomPipe.setPosition({ theFarestPipePositionX + PIPE_DISTANCE, bottomLimit });
}
