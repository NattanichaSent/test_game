#include "Monster.h"


Monster::Monster(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f size, sf::Vector2f position, int hp) :
	animation(texture, imageCount, switchTime)
{
	this->hp = hp;
	this->speed = speed;
	row = 0;
	faceRight = true;

	monster.setSize(size);
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
	velocity.y += 5.0f * deltaTime;
	if (velocity.x == 0)
	{
		row = 0;
	}
	else
	{
		row = 0;
		if (velocity.x > 0.0f)
			faceRight = false;
		else
			faceRight = true;
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
	
	
	if (direction.x < 0.0f)
	{
		//Collision on the left.
		speed = speed + 2.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right.
		speed = speed - 2.0f;
	}
	if (direction.y < 0.0f)
	{
		//printf("1234");
		//Collision on the bottom.
		velocity.y = 0.0f;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top.
		velocity.y = 0.0f;
		printf("1234");
	}
}

/*void Monster::OnCollisionX(sf::Vector2f direction)
{

	
	if (direction.x < 0.0f)
	{
		//Collision on the left.
		speed = speed + 50;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right.
		speed = speed + 50;
	}
	if (direction.y < 0.0f)
	{
		//Collision on the bottom.
		velocity.y = 0.0f;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top.
		velocity.y = 0.0f;
	}
}*/
