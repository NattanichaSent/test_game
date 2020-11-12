#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include<iostream>
class Monster
{
public:
	Monster(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed,sf::Vector2f position);
	~Monster();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);
	void SetPosition(sf::Vector2f(position))
	{
		monster.setPosition(position);
	}
	sf::Vector2f GetPosition() { return	monster.getPosition(); }
	Collider GetCollider() { return Collider(monster); }
	float GetSpeed() { return speed; }

private:
	sf::RectangleShape monster;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;

	sf::Vector2f velocity;
	
};

