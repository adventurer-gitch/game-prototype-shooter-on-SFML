#pragma once

#include <boost/multiprecision/cpp_int.hpp>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"

namespace MyNamespace
{
	class Player
	{
	private:
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;

		int health;
		float damage;
		float speed;
		boost::multiprecision::cpp_int level;

	public:
		sf::Image& getImage();
		sf::Texture& getTexture();
		sf::Sprite& getSprite();

		void setHealth(int health);
		void setDamage(float damage);
		void setSpeed(float speed);
		void setLevel(boost::multiprecision::cpp_int level);

		int getHealth() const;
		float getDamage() const;
		float getSpeed() const;
		boost::multiprecision::cpp_int getLevel() const;

	};
}