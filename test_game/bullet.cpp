#include "bullet.h"
Bullet::Bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speedx, sf::Vector2f position, sf::Vector2f size):
animation(texture, imageCount, switchTime)
{
	this->speedx = speedx;
	body.setSize(size);
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);

}

Bullet::~Bullet()
{
}

void Bullet::Update(float deltatime)
{
	velocity.x = speedx;
	body.setTextureRect(animation.uvRect);
	body.move(velocity*deltatime);
}
void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
