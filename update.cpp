#include "Game.h"

void MyNamespace::Game::update()
{
	this->updateEvent();

	if (this->is_paused)
	{
		this->clock.restart();
		return;
	}

	float time0 = (float)this->clock.getElapsedTime().asMicroseconds();
	this->clock.restart();
	time0 /= 800;

	if (!this->music.getStatus())
	{
		this->music.play();
	}

	//////////////////////////////////////////PLAYER LOGICS////////////////////////////////////////////////////////BEGIN
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->current_frame += (float)0.005 * time0;

		if (this->current_frame > 4)
		{
			this->current_frame -= 4;
		}

		this->player.getSprite().setTextureRect(sf::IntRect(int(this->current_frame) * this->grand_player_size_x, this->grand_player_size_y, this->grand_player_size_x, this->grand_player_size_y));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			this->player.getSprite().move(-this->player.getSpeed() * time0 / 10 * 0.7071067811865475244008443621048, -this->player.getSpeed() * time0 / 10 * 0.7071067811865475244008443621048);
			this->view->move(sf::Vector2f(-this->grand_speed * time0 / 10 * 0.7071067811865475244008443621048, -this->grand_speed * time0 / 10 * 0.7071067811865475244008443621048));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			this->player.getSprite().move(-this->player.getSpeed() * time0 / 10 * 0.7071067811865475244008443621048, this->player.getSpeed() *time0 / 10 * 0.7071067811865475244008443621048);
			this->view->move(sf::Vector2f(-this->grand_speed * time0 / 10 * 0.7071067811865475244008443621048, this->grand_speed * time0 / 10 * 0.7071067811865475244008443621048));
		}
		else
		{
			this->player.getSprite().move(-this->player.getSpeed() * time0 / 10, 0);
			this->view->move(sf::Vector2f(-this->player.getSpeed() * time0 / 10, 0));
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->current_frame += 0.005 * time0;

		if (this->current_frame > 4)
		{
			this->current_frame -= 4;
		}

		this->player.getSprite().setTextureRect(sf::IntRect(int(this->current_frame) * this->grand_player_size_x, 2 * this->grand_player_size_y, this->grand_player_size_x, this->grand_player_size_y));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			this->player.getSprite().move(this->grand_speed * time0 / 10 * 0.7071067811865475244008443621048, -this->grand_speed * time0 / 10 * 0.7071067811865475244008443621048);
			this->view->move(sf::Vector2f(this->grand_speed * time0 / 10 * 0.7071067811865475244008443621048, -this->grand_speed * time0 / 10 * 0.7071067811865475244008443621048));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			this->player.getSprite().move(this->grand_speed * time0 / 10 * 0.7071067811865475244008443621048, this->grand_speed * time0 / 10 * 0.7071067811865475244008443621048);
			this->view->move(sf::Vector2f(this->grand_speed * time0 / 10 * 0.7071067811865475244008443621048, this->grand_speed * time0 / 10 * 0.7071067811865475244008443621048));
		}
		else
		{
			this->player.getSprite().move(this->grand_speed * time0 / 10, 0);
			this->view->move(sf::Vector2f(this->grand_speed * time0 / 10, 0));
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->current_frame += 0.005 * time0;

		if (this->current_frame > 4)
		{
			this->current_frame -= 4;
		}

		this->player.getSprite().setTextureRect(sf::IntRect(int(this->current_frame) * this->grand_player_size_x, 3 * this->grand_player_size_y, this->grand_player_size_x, this->grand_player_size_y));
		this->player.getSprite().move(0, -this->grand_speed * time0 / 10);
		this->view->move(sf::Vector2f(0, -this->grand_speed * time0 / 10));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->current_frame += 0.005 * time0;

		if (this->current_frame > 4)
		{
			this->current_frame -= 4;
		}

		this->player.getSprite().setTextureRect(sf::IntRect(int(this->current_frame) * this->grand_player_size_x, 0 * this->grand_player_size_y, this->grand_player_size_x, this->grand_player_size_y));
		this->player.getSprite().move(0, this->grand_speed * time0 / 10);
		this->view->move(sf::Vector2f(0, this->grand_speed * time0 / 10));
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!this->is_mouse_pressed)
		{
			this->bullet.push_back(this->bullets);
			this->player_position = this->player.getSprite().getPosition();
			this->mouse_position = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
			this->direction0 = sf::Vector2f(this->mouse_position.x - this->player_position.x, this->mouse_position.y - this->player_position.y);
			this->bullet.back().getSprite().setPosition(this->player_position);
			this->length = std::sqrt(std::pow(this->direction0.x, 2) + std::pow(this->direction0.y, 2));

			if (this->length != 0)
			{
				this->direction1 = sf::Vector2f(this->direction0.x / this->length, this->direction0.y / this->length);
			}
			else
			{
				this->direction1 = this->direction0;
			}

			this->pos_bullets = sf::Vector2f(this->direction1.x / this->grand_speed, this->direction1.y * this->grand_speed);
			this->pos_bullet.push_back(this->pos_bullets);

			this->is_mouse_pressed = true;
		}

		this->sound.play();
	}
	else
	{
		this->is_mouse_pressed = false;
	}

	for (int i = 0; i < this->bullet.size(); ++i)
	{
		this->bullet[i].getSprite().move(this->pos_bullet[i] * time0);

		for (int j = 0; j < this->enemy.size(); ++j) 
		{
			bool hitX = this->bullet[i].getSprite().getPosition().x > this->enemy[j].getSprite().getPosition().x - this->enemy[j].getSprite().getGlobalBounds().width / 2 && this->bullet[i].getSprite().getPosition().x < this->enemy[j].getSprite().getPosition().x + this->enemy[j].getSprite().getGlobalBounds().width / 2;
			bool hitY = this->bullet[i].getSprite().getPosition().y > this->enemy[j].getSprite().getPosition().y - this->enemy[j].getSprite().getGlobalBounds().height / 2 && this->bullet[i].getSprite().getPosition().y < this->enemy[j].getSprite().getPosition().y + this->enemy[j].getSprite().getGlobalBounds().height / 2;
			
			if (hitX && hitY) 
			{
				// Удаление врага и пули игрока 
				 this->bullet.erase(this->bullet.begin() + i); 
				 this->pos_bullet.erase(this->pos_bullet.begin() + i);
				 --i;
				 this->enemy[j].setHealth(this->enemy[j].getHealth() - this->player.getDamage() - (float)this->player.getLevel());
				 this->damage_score = this->damage_score + static_cast<boost::multiprecision::cpp_int>(this->player.getDamage()) + this->player.getLevel() - 1;
				 // Уменьшаем индекс, чтобы не пропустить следующий элемент 
				 break; 
			} 
		}
	}
	
	for (int i = 0; i < this->bullet.size(); ++i)
	{
		//bool a = this->radius <= std::sqrt(std::pow(this->bullet[i].getSprite().getPosition().x - this->player.getSprite().getPosition().x, 2) + std::pow(this->bullet[i].getSprite().getPosition().y - this->player.getSprite().getPosition().y, 2));

		if (this->radius <= std::sqrt(std::pow(this->bullet[i].getSprite().getPosition().x - this->player.getSprite().getPosition().x, 2) + std::pow(this->bullet[i].getSprite().getPosition().y - this->player.getSprite().getPosition().y, 2)))
		{
			this->bullet.erase(this->bullet.begin());
			this->pos_bullet.erase(this->pos_bullet.begin());
		}
	}
	/////////////////////////////////////////////PLAYER LOGICS/////////////////////////////////////////END

	/////////////////////////////////////////////ENEMIES LOGICS//////////////////////////////////////BEGIN

	if (this->enemy.size() < 100) {
		sf::FloatRect viewRect = this->view->getViewport();
		bool a = true, b = true, c = true, d = true, e = true, f = true, g = true, h = true;

		do { 
			this->enemy_start_position.x = static_cast<float>(std::rand() % static_cast<int>(this->map.getSprite().getGlobalBounds().width)) - this->map.getSprite().getGlobalBounds().width / 2;
			this->enemy_start_position.y = static_cast<float>(std::rand() % static_cast<int>(this->map.getSprite().getGlobalBounds().height)) - this->map.getSprite().getGlobalBounds().height / 2;

			a = this->enemy_start_position.x > this->view->getCenter().x - this->view->getSize().x / 2;
			b = this->enemy_start_position.x < this->view->getCenter().x + this->view->getSize().x / 2;
			c = this->enemy_start_position.y > this->view->getCenter().y - this->view->getSize().y / 2;
			d = this->enemy_start_position.y < this->view->getCenter().y + this->view->getSize().y / 2;
			e = this->enemy_start_position.x > this->map.getSprite().getPosition().x - this->map.getSprite().getGlobalBounds().width / 2;
			f = this->enemy_start_position.x < this->map.getSprite().getPosition().x + this->map.getSprite().getGlobalBounds().width / 2;
			g = this->enemy_start_position.y > this->map.getSprite().getPosition().y - this->map.getSprite().getGlobalBounds().height / 2;
			h = this->enemy_start_position.y < this->map.getSprite().getPosition().y + this->map.getSprite().getGlobalBounds().height / 2;
			
		} while (a and b and c and d and e and f and g and h);
		


		this->new_enemy.getSprite().setPosition(this->enemy_start_position);
		this->enemy.push_back(this->new_enemy);
	}
	
	



	//for (int i = 0; i < this->enemy_bullet.size(); ++i)
	//{
	//	bool a = this->enemy_bullet[i].getSprite().getPosition().x > this->player.getSprite().getPosition().x - this->player.getSprite().getGlobalBounds().width / 2;
	//	bool b = this->enemy_bullet[i].getSprite().getPosition().x < this->player.getSprite().getPosition().x + this->player.getSprite().getGlobalBounds().width / 2;
	//	bool c = this->enemy_bullet[i].getSprite().getPosition().y > this->player.getSprite().getPosition().y - this->player.getSprite().getGlobalBounds().height / 2;
	//	bool d = this->enemy_bullet[i].getSprite().getPosition().y < this->player.getSprite().getPosition().y + this->player.getSprite().getGlobalBounds().height / 2;

	//	if (a and b and c and d)
	//	{
	//		this->enemy_bullet.erase(this->enemy_bullet.begin() + i);
	//	}
	//}


	/*for (size_t i = 0; i < this->enemy.size(); i++)
	{
		auto& enemy = this->enemy[i];
		auto& fire_timer = this->enemy_fire_timer[i];

		sf::Vector2f direction = this->player.getSprite().getPosition() - enemy.getSprite().getPosition();
		float distance = std::sqrt(std::pow(direction.x, 2) + std::pow(direction.y, 2));

		if (distance != 0)
		{
			direction /= distance;
		}

		if (distance < this->attack_range)
		{
			if (fire_timer.getElapsedTime().asSeconds() >= this->enemy_fire_rate)
			{
				Bullet enemyBullet;
				enemyBullet.getImage().loadFromFile("Images/fake_bullet_0.png");
				enemyBullet.getImage().createMaskFromColor(sf::Color(255, 255, 255));
				enemyBullet.getTexture().loadFromImage(enemyBullet.getImage());
				enemyBullet.getSprite().setTexture(enemyBullet.getTexture());
				enemyBullet.getSprite().setPosition(enemy.getSprite().getPosition());

				EnemyBullet newEnemyBullet = { enemyBullet, direction };
				this->enemy_bullet.push_back(newEnemyBullet);
				fire_timer.restart();
			}
		}
		else
		{
			enemy.getSprite().move(direction.x* this->grand_speed* time0 / 20, direction.y* this->grand_speed* time0 / 20);
		}
	}

	for (auto& enemyBullet : this->enemy_bullet)
	{
		Bullet& bullet = enemyBullet.bullet;
		sf::Vector2f& bulletDirection = enemyBullet.direction;
		bullet.getSprite().move(bulletDirection.x * this->grand_speed * time0 / 20, bulletDirection.y * this->grand_speed * time0 / 20);
	}*/
	
	for (int i = 0; i < this->enemy.size(); ++i)
	{
		sf::Vector2f new_dir;
		new_dir = this->player.getSprite().getPosition() - this->enemy[i].getSprite().getPosition();
		this->dis = std::sqrt(std::pow(new_dir.x, 2) + std::pow(new_dir.y, 2));

		if (this->dis != 0)
		{
			new_dir /= this->dis;
		}

		if (this->dis < this->attack_range)
		{
			if (this->enemy_fire_timer[i].getElapsedTime().asSeconds() >= this->enemy_fire_rate)
			{
				this->new_enemy_bullet.getSprite().setPosition(this->enemy[i].getSprite().getPosition());

				EnemyBullet newEnemyBullet = { this->new_enemy_bullet, new_dir };
				this->enemy_bullet.push_back(newEnemyBullet);
				this->enemy_bullet.back().start_pos = this->enemy_bullet.back().bullet.getSprite().getPosition();
				this->enemy_fire_timer[i].restart();
			}
		}
		else
		{
			this->enemy[i].getSprite().move(new_dir.x* this->grand_speed* time0 / 20, new_dir.y* this->grand_speed* time0 / 20);
		}

		this->dir.push_back(new_dir);
	}

	for (int i = 0; i < this->enemy_bullet.size(); ++i)
	{
		this->enemy_bullet[i].bullet.getSprite().move(this->enemy_bullet[i].direction.x* this->grand_speed* time0 / 20, this->enemy_bullet[i].direction.y* this->grand_speed* time0 / 20);
	}

	for (int i = 0; i < this->enemy_bullet.size(); ++i)
	{
		bool a = this->enemy_bullet[i].bullet.getSprite().getPosition().x > this->player.getSprite().getPosition().x - this->player.getSprite().getGlobalBounds().width / 2;
		bool b = this->enemy_bullet[i].bullet.getSprite().getPosition().x < this->player.getSprite().getPosition().x + this->player.getSprite().getGlobalBounds().width / 2;
		bool c = this->enemy_bullet[i].bullet.getSprite().getPosition().y > this->player.getSprite().getPosition().y - this->player.getSprite().getGlobalBounds().height / 2;
		bool d = this->enemy_bullet[i].bullet.getSprite().getPosition().y < this->player.getSprite().getPosition().y + this->player.getSprite().getGlobalBounds().height / 2;

		if (a and b and c and d)
		{
			this->enemy_bullet.erase(this->enemy_bullet.begin() + i);

			this->player.setHealth(this->player.getHealth() - this->enemy[i].getDamage());
		}
		else
		{
			float distance = std::sqrt(std::pow(this->enemy_bullet[i].bullet.getSprite().getPosition().x - this->enemy_bullet[i].start_pos.x, 2) + std::pow(this->enemy_bullet[i].bullet.getSprite().getPosition().y - this->enemy_bullet[i].start_pos.y, 2));

			if (distance > this->radius)
			{
				this->enemy_bullet.erase(this->enemy_bullet.begin() + i);
			}
		}
	}

	/////////////////////////////////////////////ENEMIES LOGICS////////////////////////////////////////END

	if (this->player.getHealth() <= 0)
	{
		this->window->close();
		std::cout << "Game over!" << std::endl;
		system("PAUSE");
	}

	for (int i = 0; i < this->enemy.size(); ++i)
	{
		if (this->enemy[i].getHealth() <= 0)
		{
			this->enemy.erase(this->enemy.begin() + i);
			this->kill_score++;
		}
	}
	
	{
		this->current_frame += 0.005 * time0;

		if (this->current_frame > 3)
		{
			this->current_frame -= 3;
		}

		for (int i = 0; i < this->enemy.size(); ++i)
		{
			float dx = this->player.getSprite().getPosition().x - this->enemy[i].getSprite().getPosition().x;
			float dy = this->player.getSprite().getPosition().y - this->enemy[i].getSprite().getPosition().y;

			if (abs(dx) > abs(dy))
			{
				if (dx > 0)
				{
					this->enemy[i].getSprite().setTextureRect(sf::IntRect(int(this->current_frame) * this->grand_enemy_size_x, 1 * this->grand_enemy_size_y, this->grand_enemy_size_x, this->grand_enemy_size_y));
				}
				else
				{
					this->enemy[i].getSprite().setTextureRect(sf::IntRect(int(this->current_frame) * this->grand_enemy_size_x, 3 * this->grand_enemy_size_y, this->grand_enemy_size_x, this->grand_enemy_size_y));
				}
			}
			else
			{
				if (dy > 0)
				{
					this->enemy[i].getSprite().setTextureRect(sf::IntRect(int(this->current_frame)* this->grand_enemy_size_x, 2 * this->grand_enemy_size_y, this->grand_enemy_size_x, this->grand_enemy_size_y));
				}
				else
				{
					this->enemy[i].getSprite().setTextureRect(sf::IntRect(int(this->current_frame)* this->grand_enemy_size_x, 0 * this->grand_enemy_size_y, this->grand_enemy_size_x, this->grand_enemy_size_y));
				}
			}
		}
	}

	std::ostringstream kill_score_string;
	kill_score_string << this->kill_score;
	std::string text_string_kill_score = "Убито врагов: " + kill_score_string.str();
	this->text_kill_score.setString(sf::String::fromUtf8(text_string_kill_score.begin(), text_string_kill_score.end()));
	this->text_kill_score.setPosition(this->view->getCenter().x - this->view->getSize().x / 2, this->view->getCenter().y - this->view->getSize().y / 2);

	std::ostringstream damage_score_string;
	damage_score_string << this->damage_score;
	std::string text_string_damage_score = "Нанесено урона: " + damage_score_string.str();
	this->text_damage_score.setString(sf::String::fromUtf8(text_string_damage_score.begin(), text_string_damage_score.end()));
	this->text_damage_score.setPosition(this->view->getCenter().x - this->view->getSize().x / 2, this->view->getCenter().y - this->view->getSize().y / 2 + 20);

	std::ostringstream health_string;
	health_string << this->player.getHealth();
	std::string text_string_health = "Здоровье: " + health_string.str();
	this->text_health.setString(sf::String::fromUtf8(text_string_health.begin(), text_string_health.end()));
	this->text_health.setPosition(this->view->getCenter().x - this->view->getSize().x / 2, this->view->getCenter().y + this->view->getSize().y / 2 - 20);

	sf::Time elapsed = game_clock.getElapsedTime();

	int hour = static_cast<int>(elapsed.asSeconds()) / 3600;
	int minute = (static_cast<int>(elapsed.asSeconds()) % 3600) / 60;
	int second = static_cast<int>(elapsed.asSeconds()) % 60;

	std::ostringstream time_stream;
	time_stream << hour << ':' << minute / 10 << minute % 10 << ':' << second / 10 << second % 10;
	this->time_text.setString(time_stream.str());
	this->time_text.setPosition(this->view->getCenter().x, this->view->getCenter().y - this->view->getSize().y / 2 + 20);

	std::ostringstream level_string;
	level_string << this->player.getLevel();
	std::string text_level = "Уровень: " + level_string.str();
	this->level_text.setString(sf::String::fromUtf8(text_level.begin(), text_level.end()));
	this->level_text.setPosition(this->view->getCenter().x, this->view->getCenter().y - this->view->getSize().y / 2 + 40);

	this->player.setLevel(this->kill_score / 10);
}