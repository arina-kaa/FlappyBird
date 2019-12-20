#include "Background.h"
#include "Consts.h"

CBackground::CBackground()
{
	backgroundTexture.loadFromFile(SPRITE_FILE, sf::IntRect(146, 0, BACKGROUND_SIZE.x, BACKGROUND_SIZE.y));
	background.setTexture(backgroundTexture);
	background.setScale(5.6, 3);
}

void CBackground::Update()
{
	//Move(GetOffset());
}

void CBackground::Draw(sf::RenderWindow& window)
{
	window.draw(background);
}