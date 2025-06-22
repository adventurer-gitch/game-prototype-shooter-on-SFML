#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"

namespace MyNamespace
{
	class Bullet
	{
	private:
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;

	public:
		sf::Image& getImage();
		sf::Texture& getTexture();
		sf::Sprite& getSprite();

	};
}