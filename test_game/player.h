#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float jumpHeight);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);
	sf::Vector2f GetPosition() { return	player.getPosition(); }
	Collider GetCollider() { return Collider(player); }
	void SetPosition(sf::Vector2f(position)) { player.setPosition(position); }
	float GetSpeed() { return speed; }
	sf::RectangleShape player;
	bool faceRight;
	int dmg;

private:
	
	Animation animation;
	unsigned int row;
	float speed = 6;
	float maxSpeed = 200;
	float drag = 0.993;
	

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};
