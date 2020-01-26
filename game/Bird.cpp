#include "Bird.h"
#include "Consts.h"

Bird::Bird()
	:m_velocity(BIRD_INITIAL_VELOCITY)
{
	birdTexture.loadFromFile(SPRITE_FILE, sf::IntRect(BIRD_POSITION.x, BIRD_POSITION.y, BIRD_SIZE.x, BIRD_SIZE.y));
	m_bird.setTexture(birdTexture);
	m_bird.setPosition(BIRD_INITIAL_POSITION);
	m_bird.setScale(3, 3);
}

void Bird::Update(float dt)
{
	m_velocity.y += ACCELERATION * dt;

	Move(dt);
}

void Bird::Draw(sf::RenderWindow & window)
{
	window.draw(m_bird);
}

void Bird::SetVelocity(const sf::Vector2f & velocity)
{
	m_velocity = velocity;
}

void Bird::Move(float dt)
{
	auto pos = m_bird.getPosition();
	pos += m_velocity * dt;

	m_bird.setPosition(pos);
}

sf::Vector2f Bird::GetPosition() const
{
	return m_bird.getPosition();
}
