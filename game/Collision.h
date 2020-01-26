#pragma once

#include <SFML/Graphics.hpp>

namespace FlappyBird
{
	class Collision
	{
	public:
		Collision();

		bool ChechSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);
		bool ChechSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2);
	};
}
