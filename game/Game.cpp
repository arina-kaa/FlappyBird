#include "Game.h"
#include "Consts.h"

Game::Game()
	:m_window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), WINDOW_TITLE)
{
	m_window.setFramerateLimit(WINDOW_FRAME_LIMIT);
	m_view.reset(sf::FloatRect(0, 0, float(WINDOW_SIZE.x), float(WINDOW_SIZE.y)));
	m_window.setView(m_view);
}

void Game::DoGameLoop()
{
	while (m_window.isOpen())
	{
		const auto dt = m_clock.restart().asSeconds();

		CheckEvents();
		Update(dt);
		m_window.setView(m_view);
		Render();
		m_window.display();
	}
}

void Game::CheckEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		CheckKeyboardEvents(event);

		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Game::CheckKeyboardEvents(const sf::Event & event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Space:
			if (!isGameStarted) isGameStarted = true;
			m_bird.SetVelocity({ BIRD_INITIAL_VELOCITY.x, JUMP_SPEED });
			break;
		default:
			break;
		}
	}
}

void Game::Update(float dt)
{
	m_pipes.Update(m_bird.GetPosition().x);
	m_bird.Update(dt);
	m_background.SetPosition({ m_bird.GetPosition().x - WINDOW_SIZE.x / 2.f , WINDOW_SIZE.y / 2.f });
	m_view.setCenter(m_bird.GetPosition().x, WINDOW_SIZE.y / 2.f);
}

void Game::Render()
{
	m_background.Draw(m_window);
	m_pipes.Draw(m_window);
	m_bird.Draw(m_window);
}
