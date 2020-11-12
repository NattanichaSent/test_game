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
	float GetSpeed() { return speed; }

private:
	sf::RectangleShape player;
	Animation animation;
	unsigned int row;
	float speed = 20;
	float maxSpeed = 400;
	float drag = 0.995;
	bool faceRight;

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};
