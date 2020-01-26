#include <SFML/Graphics.hpp>
#include <array>
#include "Background.h"
#include "Bird.h"
#pragma once

class Game
{
public:
	Game();
	void DoGameLoop();

private:
	void Update(float dt);
	void Render();

	void CheckEvents();
	void CheckKeyboardEvents(const sf::Event & event);

	std::pair<sf::Sprite, sf::Sprite> GetTheFarestPipe() const;
	void GeneratePipePair(sf::Sprite & topPipe, sf::Sprite & bottomPipe);

	sf::RenderWindow m_window;
	sf::Clock m_clock;
	sf::View m_view;
	
	Background m_background;
	Bird m_bird;
	std::array<std::pair<sf::Sprite, sf::Sprite>, 5> m_pipes; // TODO: not a const value
};
