#include <SFML/Graphics.hpp>
#pragma once

class CBackground
{
public:
	CBackground();
	void Update();
	void Draw(sf::RenderWindow& window);
private:
	sf::Texture backgroundTexture;
	sf::Sprite background;
};