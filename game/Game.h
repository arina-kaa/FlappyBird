#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Bird.h"
#include "Pipes.h"
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

	sf::RenderWindow m_window;
	sf::Clock m_clock;
	sf::View m_view;
	
	Background m_background;
	Bird m_bird;
	Pipes m_pipes;

	bool isGameStarted = false;
};
