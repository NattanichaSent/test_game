#include "Monster.h"


Monster::Monster(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	monster.setSize(sf::Vector2f(50.0f, 55.0f));
	monster.setOrigin(monster.getSize() / 2.0f);
	monster.setPosition(position);
	monster.setTexture(texture);

}
Monster::~Monster()
{
}



void Monster::Update(float deltaTime)
{
	velocity.x *= 0.0f;
	velocity.x -= speed;
	velocity.y += 10.0f * deltaTime;
	if (velocity.x == 0)
	{
		row = 0;
	}
	else
	{
		row = 0;
		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	animation.Update(row, deltaTime, faceRight);
	monster.setTextureRect(animation.uvRect);
	monster.move(velocity * deltaTime);
}
void Monster::Draw(sf::RenderWindow& window)
{
	window.draw(monster);
}

void Monster::OnCollision(sf::Vector2f direction)
{
	
	
	if (direction.x <= 0.0f)
	{
		//Collision on the left.
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right.
		velocity.x = 0.0f;
	}
	if (direction.y <= 0.0f)
	{
		//Collision on the bottom.
		velocity.y = 0.0f;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top.
		velocity.y = 0.0f;
	}
}