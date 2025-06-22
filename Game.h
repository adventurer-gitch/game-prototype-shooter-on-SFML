#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"

#include "Map.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

namespace MyNamespace
{
	struct EnemyBullet
	{
		Bullet bullet;
		sf::Vector2f direction;
		sf::Vector2f start_pos;

	};

	class Game
	{
	private:
		sf::RenderWindow* window;
		sf::Event event;
		std::string title;
		sf::VideoMode window_size;
		unsigned framerate_limit;
		bool vertical_sync_enabled;
		const float grand_window_size_width = 1920;
		const float grand_windwo_size_height = 1080;
		const float grand_player_size_x = 60;
		const float grand_player_size_y = 100;
		const float grand_enemy_size_x = 48;
		const float grand_enemy_size_y = 64;
		sf::Clock clock;
		float current_frame = 0;
		const float grand_speed = 1;
		boost::multiprecision::cpp_int kill_score = 0;
		boost::multiprecision::cpp_int damage_score = 0;

		Map map;

		Player player;

		sf::View* view;

		std::vector<Bullet> bullet;
		std::vector<sf::Vector2f> pos_bullet;

		Bullet bullets;
		sf::Vector2f pos_bullets;

		bool is_mouse_pressed = false;
		sf::Vector2f player_position;
		sf::Vector2f mouse_position;
		sf::Vector2f direction0;
		sf::Vector2f direction1;
		
		float length;
		float radius = 500;

		std::vector<Enemy> enemy;
		Enemy new_enemy;

		//Место для необходимых переменных
		sf::Vector2f enemy_start_position;

		
		std::vector<sf::Clock> enemy_fire_timer;
		std::vector<EnemyBullet> enemy_bullet;
		std::vector<sf::Vector2f> v_dir;
		Bullet new_enemy_bullet;
		float enemy_fire_rate = 2.f;
		float attack_range = 100;
		//sf::Vector2f dir;
		float dis;

		sf::Music music;
		sf::SoundBuffer buffer;
		sf::Sound sound;

		bool is_paused = false;

		sf::Font font;
		sf::Text text_kill_score;
		sf::Text text_damage_score;
		sf::Text text_health;

		sf::Clock game_clock;
		sf::Text time_text;
		sf::Text level_text;

		std::vector<sf::Vector2f> dir;

		void initWindow();
		void initView();
		void initMap();
		void initPlayer();
		void initBullet();
		void initEnemy();
		void initEnemyBullet();
		void initFont();
		void initTextKillScore();
		void initTextDamageScore();
		void initTextHealth();
		void initTimeText();
		void initLevel();

	public:
		Game();

		void updateEvent();

		void update();

		void render();

		void run();

		virtual ~Game();

	};
}