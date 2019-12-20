#include "Bird.h"
#include "Consts.h"

CBird::CBird()
{
	birdTexture.loadFromFile(SPRITE_FILE, sf::IntRect(0, 490, BIRD_SIZE.x, BIRD_SIZE.y));
	bird.setTexture(birdTexture);
	bird.setPosition(BIRD_INITIAL_POSITION);
	bird.setScale(3, 3);

	velocity = { 0, 0 };
}

void CBird::Update()
{
	//Move(GetOffset());
}

void CBird::Draw(sf::RenderWindow& window)
{
	window.draw(bird);
}