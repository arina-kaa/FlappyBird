#include <SFML/Graphics.hpp>
#include <array>
#pragma once

class Pipes
{
public:
	Pipes();
	void Update(float birdPositionX);
	void Draw(sf::RenderWindow& window);

private:
	std::pair<float, float> GetVoidLimit();
	std::pair<sf::Sprite, sf::Sprite> GetTheFarestPipe() const;
	void GeneratePipePair(sf::Sprite& topPipe, sf::Sprite& bottomPipe);
	
	sf::Texture pipeTextureUp, pipeTextureDown;
	std::array<std::pair<sf::Sprite, sf::Sprite>, 5> m_pipes; // TODO: not a const value
};
