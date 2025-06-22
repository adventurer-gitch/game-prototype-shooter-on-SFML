#include "Game.h"

void MyNamespace::Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}