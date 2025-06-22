#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"

namespace MyNamespace
{
	class Enemy
	{
	private:
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;

		int health;
		float damage;
		float speed;

	public:
		sf::Image& getImage();
		sf::Texture& getTexture();
		sf::Sprite& getSprite();

		void setHealth(int health);
		void setDamage(float damage);
		void setSpeed(float speed);

		int getHealth() const;
		float getDamage() const;
		float getSpeed() const;
	};
}