#pragma once
#include<SFML/Graphics.hpp>
#include"Collider.h"
class Platform
{
public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position );
	~Platform();
	
	void Texture(sf::Texture* texture);
	void Draw(sf::RenderWindow& window);
	Collider GetCollider(){ return Collider(body); }
	sf::RectangleShape body;

private:
	
	sf::Vector2f velocity;
};

