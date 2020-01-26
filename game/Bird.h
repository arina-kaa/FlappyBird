#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#pragma once

class Bird
{
public:
	Bird();
	void Update(float dt);
	void Draw(sf::RenderWindow & window);

	void SetVelocity(const sf::Vector2f & velocity);
	sf::Vector2f GetPosition() const;

private:
	void Move(float dt);

	sf::Texture birdTexture;
	sf::Sprite m_bird;

	sf::SoundBuffer FlappyJump, FlappyPoint, FlappyCollision;
	sf::Sound FlappyJumpSound, FlappyPointSound, FlappyCollisionSound;

	sf::Vector2f m_velocity;
};
