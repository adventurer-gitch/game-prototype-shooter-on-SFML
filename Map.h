#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"

namespace MyNamespace
{
	class Map
	{
	private:
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprire;

	public:
		sf::Image& getImage();
		sf::Texture& getTexture();
		sf::Sprite& getSprite();

	};
}