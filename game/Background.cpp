#include "Background.h"
#include "Consts.h"

Background::Background()
{
	const auto backgroungPosition = getRandomBackground();
	backgroundTexture.loadFromFile(SPRITE_FILE, sf::IntRect(backgroungPosition.x, backgroungPosition.y, BACKGROUND_SIZE.x, BACKGROUND_SIZE.y));
	background.setTexture(backgroundTexture);
	background.setScale(4.2f, 2.8f);

	groundTexture.loadFromFile(SPRITE_FILE, sf::IntRect(GROUND_POSITION.x, GROUND_POSITION.y, GROUND_SIZE.x, GROUND_SIZE.y));
	ground.setTexture(groundTexture);
	ground.setPosition(0, 600);
	ground.setScale(4.2f, 2.f);
}

void Background::Update()
{
	//Move(GetOffset());
}

void Background::Draw(sf::RenderWindow & window)
{
	window.draw(background);
	window.draw(ground);
}

void Background::SetPosition(const sf::Vector2f & pos)
{
	const auto backgroundPosition = background.getPosition();
	const auto groundPosition = ground.getPosition();

	background.setPosition({ pos.x, backgroundPosition.y});
	ground.setPosition({ pos.x, groundPosition.y });
}

sf::Vector2u Background::getRandomBackground()
{	
	return (rand() % 2 == 1) ? BACKGROUND_POSITION_LIGHT : BACKGROUND_POSITION_DARK;
}