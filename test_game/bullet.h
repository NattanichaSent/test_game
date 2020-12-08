#pragma once
#include <SFML/Graphics.hpp>
#include "animation.h"
#include "Collider.h"

using namespace std;
class Bullet
{
public:
	Bullet(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speedx,sf::Vector2f position,sf::Vector2f size);
	~Bullet();
	
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
	void Oncollision(sf::Vector2f direction);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
	void SetPosition(sf::Vector2f(position)) { body.setPosition(position); }
private:
	float speedx;
	sf::RectangleShape body;
	sf::RectangleShape texture;
	Animation animation;
	unsigned int row;
	sf::Vector2f velocity;
};

