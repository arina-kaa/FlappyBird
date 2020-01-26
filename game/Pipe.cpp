#include "Pipe.h"

namespace FlappyBird 
{
	Pipe::Pipe(GameDataRef data) : _data(data)
	{
		_landHeight = _data->assets.GetTexture("Land Background").getSize().y;
		_pipeSpawnOffsetY = 0;
	}

	void Pipe::SpawnBottomPipe()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up Background"));

		sprite.setPosition(
			_data->window.getSize().x, 
			_data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnOffsetY
		);

		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnTopPipe()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Down Background"));

		sprite.setPosition(_data->window.getSize().x, -_pipeSpawnOffsetY);

		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnInvisiblePipe()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up Background"));

		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnScoringPipe()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Scoring Pipe Background"));

		sprite.setPosition(_data->window.getSize().x, 0);

		scoringPipes.push_back(sprite);
	}

	void Pipe::MovePipes(float dt)
	{
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{
			if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width)
			{
				pipeSprites.erase(pipeSprites.begin() + i);
			}
			else
			{
				float movement = PIPE_MOVEMENT_SPEED * dt;
				pipeSprites.at(i).move(-movement, 0);
			}
		}

		for (unsigned short int i = 0; i < scoringPipes.size(); i++)
		{
			if (scoringPipes.at(i).getPosition().x < 0 - scoringPipes.at(i).getGlobalBounds().width)
			{
				scoringPipes.erase(scoringPipes.begin() + i);
			}
			else
			{
				float movement = PIPE_MOVEMENT_SPEED * dt;
				scoringPipes.at(i).move(-movement, 0);
			}
		}
	}

	void Pipe::DrawPipes()
	{
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{
			_data->window.draw(pipeSprites.at(i));
		}
	}

	void Pipe::RandomisePipeOffset()
	{
		_pipeSpawnOffsetY = rand() % (_landHeight + 1);
	}

	const std::vector<sf::Sprite>& Pipe::GetSprites() const
	{
		return pipeSprites;
	}

	std::vector<sf::Sprite>& Pipe::GetScoringSprites()
	{
		return scoringPipes;
	}
}