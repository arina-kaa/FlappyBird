#include <SFML/Graphics.hpp>
#pragma once

class CBird
{
public:
	CBird();
	void Update();
	void Draw(sf::RenderWindow& window);
private:
	sf::Texture birdTexture;
	sf::Sprite bird;

	sf::Vector2f velocity;
};
