#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Bird.h"
#pragma once

class CGame
{
public:
	CGame();
	void DoGameLoop();
private:
	void Update();
	void Render();

	void CheckEvents();
	void CheckKeyboardEvents(const sf::Event& event);

	sf::RenderWindow window;
	
	CBackground background;
	CBird bird;

	bool isGameStarted;
};
