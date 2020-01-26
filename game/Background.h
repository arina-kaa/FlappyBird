#include <SFML/Graphics.hpp>
#pragma once

class Background
{
public:
	Background();
	void Update();
	void Draw(sf::RenderWindow & window);
	void SetPosition(const sf::Vector2f & pos);

private:
	sf::Vector2u getRandomBackground();

	sf::Texture backgroundTexture;
	sf::Sprite background;
	sf::Texture groundTexture;
	sf::Sprite ground;
};