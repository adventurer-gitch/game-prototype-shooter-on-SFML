#include "Game.h"

void MyNamespace::Game::updateEvent()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
		{
			this->window->close();
		}
		else if (this->event.type == sf::Event::KeyPressed)
		{
			if (this->event.key.code == sf::Keyboard::P)
			{
				this->is_paused = !this->is_paused;
			}
		}
	}
}