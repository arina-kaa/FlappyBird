#include "Game.h"
#include "Consts.h"

CGame::CGame():window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), WINDOW_TITLE)
{
	window.setFramerateLimit(WINDOW_FRAME_LIMIT);
}

void CGame::DoGameLoop()
{
	while (window.isOpen())
	{
		CheckEvents();
		Update();
		Render();
		window.display();
	}
}

void CGame::CheckEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		CheckKeyboardEvents(event);

		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void CGame::CheckKeyboardEvents(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Space:
			if (!isGameStarted) isGameStarted = true;
			break;
		default:
			break;
		}
	}
}

void CGame::Update()
{
	//hero.Update();
}

void CGame::Render()
{
	background.Draw(window);
	bird.Draw(window);
}