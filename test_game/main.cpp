#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include<iostream>
#include<vector>
#include"Player.h"
#include "Platform.h"
#include "Monster.h"
#include "Menu.h"
#include "Bullet.h"

static const float View_HEIGHT = 720.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize((View_HEIGHT)*aspectRatio, View_HEIGHT);
}

void saveNewScore(string name, int score);

int main()
{
	float x = -150.0f;
	int state = 0;
	int gameState = 0;
	
	/*
	* 0 = Menu
	* 1 = in game
	* 2 = end game
	*/
	sf::Vector2f checkPoint;

	sf::RenderWindow window(sf::VideoMode(1080, 720), "Super AmongO",sf::Style::Resize);
	sf::RectangleShape frame(sf::Vector2f(1080.0f, 1000.0f));
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(View_HEIGHT, View_HEIGHT));

	sf::Texture bgpng;
	if (!bgpng.loadFromFile("bg/bgGame1.jpg")) //blackground in game
	{
		printf("load fail");
	}
	
	sf::RectangleShape bg(sf::Vector2f(10000, 620));
	bg.setPosition(sf::Vector2f(-500, -360));
	bg.setTexture(&bgpng);

	std::vector<Bullet>bullet;
	sf::Texture bulletTexture;
	bulletTexture.loadFromFile("bg/bullet.png");

	

	sf::Texture player_texture;
	player_texture.loadFromFile("bg/25.png"); //player
	Player player(&player_texture, sf::Vector2u(4, 2), 0.2f, 300.0f);

	

	sf::RectangleShape collision(sf::Vector2f(50, 50)); //monster
	collision.setPosition(100.f, 230.f);
	collision.setFillColor(sf::Color::Green);


	std::vector<Platform> platforms;
	std::vector<Platform> platformlonghon1;
	std::vector<Platform> blockMoney;
	std::vector<Platform> chonBlockMoney;
	std::vector<Platform> chonMonster;

	std::vector<Monster> monster;
	sf::Texture floor;
	floor.loadFromFile("bg/29.png"); //floor in game
	sf::Texture bg1;
	bg1.loadFromFile("bg/20.png"); //sao gun chark
	sf::Texture floor1;
	floor1.loadFromFile("bg/28.png"); //floor out game
	sf::Texture floor2;
	floor2.loadFromFile("bg/floor2.jpg");
	sf::Texture floor3;
	floor3.loadFromFile("bg/floor3.jpg");
	sf::Texture floor4;
	floor4.loadFromFile("bg/floor4.png");
	sf::Texture floorForDie1;
	floorForDie1.loadFromFile("bg/bfd3.jpg");
	sf::Texture sao;
	sao.loadFromFile("bg/sao.jpg");
	sf::Texture block1;
	block1.loadFromFile("bg/block.jpg");
	sf::Texture block2;
	block2.loadFromFile("bg/longBlock.jpg");
	sf::Texture blocklonghon;
	blocklonghon.loadFromFile("bg/block7.jpg");
	sf::Texture blockKung;
	blockKung.loadFromFile("bg/32.png");
	sf::Texture tor;
	tor.loadFromFile("bg/tor.png");
	sf::Texture bundai2;
	bundai2.loadFromFile("bg/bundai2.jpg");
	sf::Texture bundai3;
	bundai3.loadFromFile("bg/bundai3.jpg");
	sf::Texture bundai4;
	bundai4.loadFromFile("bg/bundai4.jpg");
	sf::Texture bundai5;
	bundai5.loadFromFile("bg/bundai5.jpg");
	sf::Texture bundai6;
	bundai6.loadFromFile("bg/bundai6.jpg");
	sf::Texture bundai7;
	bundai7.loadFromFile("bg/bundai7.jpg");
	sf::Texture bundai8;
	bundai8.loadFromFile("bg/bundai8.jpg");
	sf::Texture bundai9;
	bundai9.loadFromFile("bg/bundai9.jpg");
	sf::Texture bundai10;
	bundai10.loadFromFile("bg/bundai10.jpg");
	sf::Texture fallBlock;
	fallBlock.loadFromFile("bg/blk2.jpg");
	sf::Texture moneyBlock;
	moneyBlock.loadFromFile("bg/moneyBlock.jpg");
	sf::Texture monster1;
	monster1.loadFromFile("bg/monster1.png");
	sf::Texture meow;
	meow.loadFromFile("bg/meow.png");
	sf::Texture dragon;
	dragon.loadFromFile("bg/dragon.png");

	bool brokenblock[100];
	bool blocklonghonClock = true;
	bool blockfordie[100];
	bool blocklonghon1 = true;
	bool blocklonghon2 = true;
	bool itemblock[100];
	bool checkMon[100];
	bool checkState = false;

	/// ////////////////////////////////////////////// base 1 ////////////////////////////////////////////////////
	//platforms.push_back(Platform(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(420.0f, 110.0f))); 
	platforms.push_back(Platform(&block1, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(1070.0f, 110.0f)));
	platforms.push_back(Platform(&tor, sf::Vector2f(60.0f, 150.0f), sf::Vector2f(1500.0f, 200.0f))); 
	//platforms.push_back(Platform(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(1640.0f, 110.0f)));
	//platforms.push_back(Platform(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(1770.0f, 110.0f)));
	platforms.push_back(Platform(&tor, sf::Vector2f(60.0f, 150.0f), sf::Vector2f(1900.0f, 200.0f)));
	platforms.push_back(Platform(&tor, sf::Vector2f(60.0f, 150.0f), sf::Vector2f(2200.0f, 200.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 100.0f), sf::Vector2f(2250.0f, 250.0f))); 

	/// ////////////////////////////////////////////// base 2 ////////////////////////////////////////////////////
	platforms.push_back(Platform(&block1, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(2700.0f, 110.0f)));
	platforms.push_back(Platform(&block2, sf::Vector2f(400.0f, 60.0f), sf::Vector2f(3000.0f, 0.0f)));
	platforms.push_back(Platform(&block1, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(2900.0f, -200.0f)));
	platforms.push_back(Platform(&block1, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(3100.0f, -200.0f)));
	platforms.push_back(Platform(&block1, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(3700.0f, 110.0f)));
	//platforms.push_back(Platform(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(3800.0f, -50.0f)));
	platforms.push_back(Platform(&block1, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(3900.0f, 110.0f)));
	//platforms.push_back(Platform(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(4000.0f, -50.0f)));
	platforms.push_back(Platform(&block1, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(4100.0f, 110.0f)));
	platforms.push_back(Platform(&tor, sf::Vector2f(60.0f, 150.0f), sf::Vector2f(4300.0f, 200.0f)));
	 
	/// ////////////////////////////////////////////// base 3 ////////////////////////////////////////////////////
	platforms.push_back(Platform(&block1, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5850.0f, 233.5f))); //block7
	platforms.push_back(Platform(&bundai2, sf::Vector2f(50.0f, 100.0f), sf::Vector2f(5898.5f, 208.5f))); //block8
	platforms.push_back(Platform(&bundai3, sf::Vector2f(50.0f, 150.0f), sf::Vector2f(5947.0f, 183.0f))); //block9
	platforms.push_back(Platform(&bundai4, sf::Vector2f(50.0f, 200.0f), sf::Vector2f(5995.5f, 158.0f))); //block10
	platforms.push_back(Platform(&bundai5, sf::Vector2f(50.0f, 250.0f), sf::Vector2f(6044.0f, 133.0f))); //block11
	platforms.push_back(Platform(&bundai6, sf::Vector2f(50.0f, 300.0f), sf::Vector2f(6092.5f, 108.0f))); //block12
	platforms.push_back(Platform(&bundai7, sf::Vector2f(50.0f, 350.0f), sf::Vector2f(6141.0f, 83.0f))); //block13
	platforms.push_back(Platform(&bundai8, sf::Vector2f(50.0f, 400.0f), sf::Vector2f(6189.5f, 58.0f))); //block14
	platforms.push_back(Platform(&bundai9, sf::Vector2f(50.0f, 450.0f), sf::Vector2f(6238.0f, 33.0f))); //block15
	platforms.push_back(Platform(&bundai10, sf::Vector2f(50.0f, 500.0f), sf::Vector2f(6286.5f, 8.0f))); //block16

	/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(6670.0f, 235.0f))); //door to next map


	/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	platforms.push_back(Platform(&fallBlock, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(650.0f, -30.0f))); //block with fall block
	
	platforms.push_back(Platform(&floor1, sf::Vector2f(1200.0f, 100.0f), sf::Vector2f(120.0f, 310.0f))); //floor in game1
	platforms.push_back(Platform(&sao, sf::Vector2f(40.0f, 1000.0f), sf::Vector2f(-490.0f, 15.0f))); //sao gun chark
	platforms.push_back(Platform(&floor2, sf::Vector2f(1050.0f, 100.0f), sf::Vector2f(1525.0f, 310.0f))); //floor in game2
	platforms.push_back(Platform(&floor3, sf::Vector2f(1090.0f, 100.0f), sf::Vector2f(2720.0f, 310.0f))); //floor in game3
	platforms.push_back(Platform(&floor4, sf::Vector2f(950.0f, 100.0f), sf::Vector2f(3950.0f, 310.0f))); //floor in game4
	platforms.push_back(Platform(nullptr, sf::Vector2f(950.0f, 100.0f), sf::Vector2f(5000.0f, 310.0f))); //floor in game5
	platforms.push_back(Platform(nullptr, sf::Vector2f(1250.0f, 100.0f), sf::Vector2f(6200.0f, 310.0f))); //floor in game6
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	blockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(420.0f, 110.0f)));
	blockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(1640.0f, 110.0f)));
	blockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(1770.0f, 110.0f)));
	blockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(3800.0f, -50.0f)));
	blockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(4000.0f, -50.0f)));
	blockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(4800.0f, 110.0f)));
	blockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(4800.0f, -90.0f)));
	blockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5000.0f, -90.0f)));
	blockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5000.0f, 110.0f)));
	blockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5200.0f, 110.0f)));
	blockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5200.0f, -90.0f)));
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	chonBlockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(40.0f, 5.0f), sf::Vector2f(420.0f, 135.0f)));
	chonBlockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(40.0f, 5.0f), sf::Vector2f(1640.0f, 135.0f)));
	chonBlockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(40.0f, 5.0f), sf::Vector2f(1770.0f, 135.0f)));
	chonBlockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(40.0f, 5.0f), sf::Vector2f(3800.0f, -25.0f)));
	chonBlockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(4000.0f, -25.0f)));
	chonBlockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(40.0f, 5.0f), sf::Vector2f(4800.0f, 135.0f)));
	chonBlockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(40.0f, 5.0f), sf::Vector2f(4800.0f, -65.0f)));
	chonBlockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(40.0f, 5.0f), sf::Vector2f(5000.0f, -65.0f)));
	chonBlockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(40.0f, 5.0f), sf::Vector2f(5000.0f, 135.0f)));
	chonBlockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(40.0f, 5.0f), sf::Vector2f(5200.0f, 135.0f)));
	chonBlockMoney.push_back(Platform(&moneyBlock, sf::Vector2f(40.0f, 5.0f), sf::Vector2f(5200.0f, -65.0f)));

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	Platform blk1(&block1, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(350.0f, -40.0f));
	Platform blk2(&fallBlock, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(840.0f, -30.0f)); //fall block
	Platform blk3(&block1, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(500.0f, 0.0f));
	Platform blh1(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(1950.0f, -30.0f));
	Platform blh2(&blocklonghon, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(2000.0f, -170.0f));
	Platform itemblock1(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(3000.0f, -200.0f)); 
	Platform itemblock2(&moneyBlock , sf::Vector2f(50.0f, 50.0f), sf::Vector2f(4300.0f, -50.0f)); 
	Platform itemblock3(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(800.0f, -230.0f)); 
	Platform itemblock4(&moneyBlock, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(1070.0f, -90.0f));
	Platform itemblock5(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5000.0f, 110.0f)); //block1
	Platform itemblock6(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5000.0f, -90.0f)); //block2
	Platform itemblock7(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5200.0f, -90.0f)); //block3
	Platform itemblock8(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5200.0f, 110.0f)); //block4
	Platform itemblock9(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5400.0f, 110.0f))); //block5
	Platform itemblock10(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5400.0f, -90.0f))); //block6
	//Platform itemblock3(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(800.0f, -230.0f)); 
	Platform bfd1(nullptr, sf::Vector2f(250.0f, 50.0f), sf::Vector2f(2050.0f, 110.0f)); 
	Platform bfd2(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(3300.0f, 310.0f)); 
	Platform bfd3(&floorForDie1, sf::Vector2f(300.0f, 100.0f), sf::Vector2f(850.0f, 310.0f));
	Platform Ex1(nullptr, sf::Vector2f(10, 1000), sf::Vector2f(6830, 225)); //13 gun chark
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	int a = 0;
	float deltaTime = 0.0f;
	sf::Clock clock;

	float time = 0.0f;
	float bulletTime = 0.0f;
	sf::Clock bulletClock;
	sf::Clock clock1;

	std::memset(itemblock, true, sizeof itemblock);
	std::memset(brokenblock, true, sizeof brokenblock);
	std::memset(blockfordie, true, sizeof blockfordie);
	std::memset(checkMon, true, sizeof checkMon);

	/*
	* Menu
	*/
	Menu menu = Menu();
	/*------------------------------------------------------------------------------------------------------*/
	//saveNewScore("Eiei", 2000);
	while (window.isOpen())
	{
		
		while (gameState == 0)
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::Resized:
					ResizeView(window, view);
					break;
				}
			}
			//window.clear(sf::Color(67, 169, 238));
			menu.draw(window, event);
			if (menu.isGameStart() == true) {
				saveNewScore(menu.getPlayerName(), 20000);
				gameState = 1;
			}
			window.display();
		}
		while (gameState == 1)
		{
			window.clear(sf::Color(67, 169, 238));
			window.draw(bg);

			/*
			* Shoot Bullet
			*/
			bulletTime = bulletClock.getElapsedTime().asMilliseconds();
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				if (bulletTime > 500 && player.faceRight == true)
				{
					bullet.push_back(Bullet(&bulletTexture, sf::Vector2u(4, 2), 0.2f, 500.0f, player.GetPosition(), sf::Vector2f(10, 10)));
					
					bulletClock.restart();
				}
				else if(bulletTime > 500 && player.faceRight == false)
				{
					bullet.push_back(Bullet(&bulletTexture, sf::Vector2u(4, 2), 0.2f, -500.0f, player.GetPosition(), sf::Vector2f(10, 10)));

					bulletClock.restart();
				}
				
			}
			time = clock1.getElapsedTime().asMilliseconds();
			deltaTime = clock.restart().asSeconds();
			if (deltaTime > 1.0f / 20.0f)
			{
				deltaTime = 1.0f / 20.0f;
			}

			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::Resized:
					ResizeView(window, view);
					break;
				}
			}
			/*
			* check point
			*/
			if (state == 0 && checkState == true)
			{
				platformlonghon1.erase(platformlonghon1.begin(), platformlonghon1.end());
				monster.erase(monster.begin(), monster.end());
				blk1.body.setPosition(sf::Vector2f(350.0f, -40.0f));
				blk2.body.setPosition(sf::Vector2f(840.0f, -30.0f));
				blk3.body.setPosition(sf::Vector2f(500.0f, 0.0f));
				blh1.body.setPosition(sf::Vector2f(1950.0f, -30.0f));
				blh2.body.setPosition(sf::Vector2f(2000.0f, -170.0f));
				itemblock1.body.setPosition(sf::Vector2f(3000.0f, -200.0f));
				itemblock2.body.setPosition(sf::Vector2f(4300.0f, -50.0f));
				itemblock3.body.setPosition(sf::Vector2f(800.0f, -230.0f));
				itemblock4.body.setPosition(sf::Vector2f(1070.0f, -90.0f));
				itemblock5.body.setPosition(sf::Vector2f(5000.0f, 110.0f));
				itemblock6.body.setPosition(sf::Vector2f(5000.0f, -90.0f));
				itemblock7.body.setPosition(sf::Vector2f(5200.0f, 110.0f));
				itemblock8.body.setPosition(sf::Vector2f(5200.0f, -90.0f));
				itemblock9.body.setPosition(sf::Vector2f(5400.0f, 110.0f));
				itemblock10.body.setPosition(sf::Vector2f(5400.0f, -90.0f));
				//Platform itemblock3(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(800.0f, -230.0f)); 
				
				bfd1.body.setPosition(sf::Vector2f(2050.0f, 110.0f));
				bfd2.body.setPosition(sf::Vector2f(3300.0f, 310.0f));
				bfd3.body.setPosition(sf::Vector2f(850.0f, 310.0f));
				Ex1.body.setPosition(sf::Vector2f(6830, 225)); //13 gun chark
				std::memset(itemblock, true, sizeof itemblock);
				std::memset(checkMon, true, sizeof checkMon);
				std::memset(blockfordie, true, sizeof blockfordie);
				blocklonghon2 = true;
				blocklonghon1 = true;

				checkState = false;

			}

			/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////



			printf("x = %.f   y = %.f \n", player.GetPosition().x, player.GetPosition().y);
			//printf("time = %.f ", time);
			player.Update(deltaTime);
			/*for (Platform& Platforms : platforms) Platforms.Update(deltaTime);*/
			if (player.GetPosition().x <= 6450)
			{
				if (player.GetPosition().x >= x)
				{
					view.setCenter(sf::Vector2f(player.GetPosition().x, 0));
					x++;
				}

			}

			Collider playerCollision = player.GetCollider();

			sf::Vector2f direction;

			for (Platform& platform : platforms)
			{
				if (platform.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
				{
					player.OnCollision(direction);
				}
				for (Monster& monster : monster)
				{
					monster.Update(deltaTime);
					Collider monsterCollision = monster.GetCollider();
					if (platform.GetCollider().CheckCollision(monsterCollision, direction, 1.0f)) //mon walk on platform
					{
						monster.OnCollision(direction);
					}
					/*if (monster.GetCollider().CheckCollision(playerCollision, direction, 1.0f) && player.GetPosition().y >= monster.GetPosition().y ) {
						printf("666");
						//player.OnCollision(direction);
					}*/
					if (monster.GetCollider().CheckCollision(playerCollision, direction, 1.0f)) //mon chon with player
					{

						player.OnCollision(direction);
					}
					if (bfd3.GetCollider().CheckCollision(monsterCollision, direction, 1.0f))
					{
						monster.OnCollision(direction);
					}
				}
			}
			/*
			* bullet chon with mon
			*/
			for (int j = 0; j < monster.size(); j++)
			{
				Collider monsterCollision = monster[j].GetCollider();
				for (int i = 0; i < bullet.size(); i++)
				{
					if (bullet[i].GetCollider().CheckCollision(monsterCollision, direction, 1.0f))
					{
						monster[j].hp -= player.dmg;
						bullet.erase(bullet.begin() + i);
						if (monster[j].hp <= 0)
						{
							monster.erase(monster.begin() + j);
						}
					}
				}
			}
			/*
			* bullet chon with platform
			*/
			for (Platform& platform : platforms)
			{
				for (int i = 0; i < bullet.size(); i++)
				{
					Collider bulletColision = bullet[i].GetCollider();
					if (platform.GetCollider().CheckCollision(bulletColision, direction, 1.0f))
					{
						bullet.erase(bullet.begin() + i);
					}

				}

			}

			/*
			* chon money block
			*/
			for (int i = 0; i < blockMoney.size(); i++)
			{
				if (blockMoney[i].GetCollider().CheckCollision(playerCollision, direction, 1.0))
				{
					player.OnCollision(direction);
				}
				if (chonBlockMoney[i].GetCollider().CheckCollision(playerCollision, direction, 1.0))
				{
					blockMoney[i].Texture(nullptr);
					player.OnCollision(direction);
				}
			}

			/*for (int i = 0; i < monster.size(); i++) 
			{
				Collider monsterCollision = monster[i].GetCollider();
				Collider playerCollision = player.GetCollider();
				if (player.GetCollider().CheckCollision(monsterCollision, direction, 1.0f) && direction.y > 0.0f) //mon chon with player
				{

					monster[i].OnCollision(direction);
					monster.erase(monster.begin()+i);
					//player.OnCollision(direction);
				}*/
				/*if (monster[i].GetCollider().CheckCollision(playerCollision, direction, 1.0f)  direction.x> 0.0f || direction.x < 0.0f|| direction.y< 0.0f) //mon chon with player
				{

					//monster[i].OnCollision(direction);
					player.SetPosition(sf::Vector2f(0, 0));
					//monster.erase(monster.begin() + i);
					//player.OnCollision(direction);
				}
			}*/
			///////// checkpoint //////////
			if (collision.getGlobalBounds().intersects(player.player.getGlobalBounds()))
			{
				checkPoint.x = collision.getPosition().x;
				checkPoint.y = collision.getPosition().y - 50;
			}

			if (player.GetPosition().y > 2000)
			{
				checkState = true;
				player.SetPosition(checkPoint);
				view.setCenter(sf::Vector2f(player.GetPosition().x, 0));
				x = 0;

			}
			/// //////////////// monster ///////////////////////
			if (player.GetPosition().x > 0 && checkMon[0])
			{
				monster.push_back(Monster(&dragon, sf::Vector2u(4, 1), 6.0f, 1.0f,sf::Vector2f(60,60), sf::Vector2f(500.0f, 100.0f),200));
				monster.push_back(Monster(&monster1, sf::Vector2u(2, 1), 6.0f, 1.0f, sf::Vector2f(40, 40), sf::Vector2f(1450.0f, 100.0f),100));
				checkMon[0] = false;
			}
			if (player.GetPosition().x > 2100 && checkMon[1])
			{
				monster.push_back(Monster(&monster1, sf::Vector2u(2, 1), 6.0f, 1.0f, sf::Vector2f(40, 40), sf::Vector2f(2900, 100),100));
				monster.push_back(Monster(&monster1, sf::Vector2u(2, 1), 6.0f, 1.0f, sf::Vector2f(40, 40), sf::Vector2f(3150, -100),100));
				checkMon[1] = false;
			}
			if (player.GetPosition().x > 3300 && checkMon[2])
			{
				monster.push_back(Monster(&monster1, sf::Vector2u(2, 1), 6.0f, 1.0f, sf::Vector2f(40, 40), sf::Vector2f(3600, 100),100));
				monster.push_back(Monster(&monster1, sf::Vector2u(2, 1), 6.0f, 1.0f, sf::Vector2f(40, 40), sf::Vector2f(3700, 100),100));
				monster.push_back(Monster(&monster1, sf::Vector2u(2, 1), 6.0f, 1.0f, sf::Vector2f(40, 40), sf::Vector2f(3800, -100),100));
				monster.push_back(Monster(&monster1, sf::Vector2u(2, 1), 6.0f, 1.0f, sf::Vector2f(40, 40), sf::Vector2f(3900, 100),100));
				monster.push_back(Monster(&monster1, sf::Vector2u(2, 1), 6.0f, 1.0f, sf::Vector2f(40, 40), sf::Vector2f(4000, -100),100));
				checkMon[2] = false;
			}
			if (player.GetPosition().x > 2050 && player.GetPosition().y < -200 && checkMon[3]) //mon from sky
			{
				monster.push_back(Monster(&meow, sf::Vector2u(1, 5), 1.0f, 1.0f, sf::Vector2f(40, 100), sf::Vector2f(2120, -600),100));
				checkMon[3] = false;
			}
			if (player.GetPosition().x > 1100 && checkMon[4])
			{
				monster.push_back(Monster(&monster1, sf::Vector2u(2, 1), 6.0f, 1.0f, sf::Vector2f(40, 40), sf::Vector2f(1700, 100),100));
				checkMon[4] = false;
			}
			if (player.GetPosition().x > 5950 && checkMon[5])
			{
				monster.push_back(Monster(&monster1, sf::Vector2u(2, 1), 6.0f, 1.0f, sf::Vector2f(40, 40), sf::Vector2f(6015, -400),100));
				monster.push_back(Monster(&monster1, sf::Vector2u(2, 1), 6.0f, 1.0f, sf::Vector2f(40, 40), sf::Vector2f(6070, -400),100));
				monster.push_back(Monster(&monster1, sf::Vector2u(2, 1), 6.0f, 1.0f, sf::Vector2f(40, 40), sf::Vector2f(6125, -400),100));
				monster.push_back(Monster(&monster1, sf::Vector2u(2, 1), 6.0f, 1.0f, sf::Vector2f(40, 40), sf::Vector2f(6180, -400),100));
				monster.push_back(Monster(&monster1, sf::Vector2u(2, 1), 6.0f, 1.0f, sf::Vector2f(40, 40), sf::Vector2f(6235, -400),100));
				monster.push_back(Monster(&monster1, sf::Vector2u(2, 1), 6.0f, 1.0f, sf::Vector2f(40, 40), sf::Vector2f(6290, -400),100));
				checkMon[5] = false;
			}
			if (player.GetPosition().x > 6305 && player.GetPosition().x < 6310 && checkMon[6])
			{
				monster.push_back(Monster(&monster1, sf::Vector2u(2, 1), 6.0f, 1.0f, sf::Vector2f(40, 40), sf::Vector2f(6365, -360),100));
				checkMon[6] = false;
			}

			if (player.GetPosition().y >= 230 && player.GetPosition().x >= 1950 && player.GetPosition().x <= 2050 && blockfordie[0] == true)
			{
				platformlonghon1.push_back(Platform(&blockKung, sf::Vector2f(250.0f, 20.0f), sf::Vector2f(2050.0f, 136.5f)));
				blockfordie[0] = false;
			}

			else clock1.restart();
			for (Platform& p : platformlonghon1)
				if (p.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
					player.OnCollision(direction);
			for (Platform& p : platformlonghon1)
				p.Draw(window);


			/////////////// block for die /////////////////// 
			bfd2.GetCollider().CheckCollision(playerCollision, direction, 0.0f);
			bfd2.Draw(window);


			bfd3.GetCollider().CheckCollision(playerCollision, direction, 0.0f);
			bfd3.Draw(window);


			///////////////block long hon/////////////////// 

			if (Ex1.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
				player.OnCollision(direction); //block long hon

			if (blh1.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
			{
				blocklonghon1 = false;
				player.OnCollision(direction); //block long hon
			}
			if (blocklonghon1 == false) blh1.Draw(window);


			if (blh2.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
			{
				blocklonghon2 = false;
				player.OnCollision(direction); //block long hon
			}
			if (blocklonghon2 == false) blh2.Draw(window);


			/// /////////////////////item block///////////////////////////


			if (itemblock1.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
			{
				itemblock[0] = false;
				player.OnCollision(direction);
			}
			if (itemblock[0] == false) itemblock1.Draw(window);

			for (int i = 1; i < 6; i++) //block item gra deng 5 loop
			{
				if (itemblock2.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
				{
					itemblock[i] = false;
					player.OnCollision(direction);
				}
				if (itemblock[i] == false) itemblock2.Draw(window);
			}


			if (itemblock3.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
			{
				itemblock[6] = false;
				player.OnCollision(direction);
			}
			if (itemblock[6] == false)
				itemblock3.Draw(window);

			if (itemblock4.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
			{
				itemblock[7] = false;
				player.OnCollision(direction);
			}
			if (itemblock[7] == false)
				itemblock4.Draw(window);

			if (itemblock5.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
			{
				itemblock[8] = false;
				player.OnCollision(direction);
			}
			if (itemblock[8] == false)
				itemblock5.Draw(window);

			if (itemblock6.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
			{
				itemblock[9] = false;
				player.OnCollision(direction);
			}
			if (itemblock[9] == false)
				itemblock6.Draw(window);

			if (itemblock7.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
			{
				itemblock[10] = false;
				player.OnCollision(direction);
			}
			if (itemblock[10] == false)
				itemblock7.Draw(window);

			if (itemblock8.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
			{
				itemblock[11] = false;
				player.OnCollision(direction);
			}
			if (itemblock[11] == false)
				itemblock8.Draw(window);

			if (itemblock9.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
			{
				itemblock[12] = false;
				player.OnCollision(direction);
			}
			if (itemblock[12] == false)
				itemblock9.Draw(window);

			if (itemblock10.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
			{
				itemblock[13] = false;
				player.OnCollision(direction);
			}
			if (itemblock[13] == false)
				itemblock10.Draw(window);

			
			for (Platform& platform : platforms)
				platform.Draw(window);
			for (Platform& platform : blockMoney)
				platform.Draw(window);
			///////////////////////////////block loen dai///////////////////////////// 

			blk1.GetCollider().CheckCollisionY(playerCollision, direction, 0.0f);
			blk1.Draw(window);

			blk2.GetCollider().CheckCollision(playerCollision, direction, 0.0f);
			blk2.Draw(window);

			blk3.GetCollider().CheckCollisionY(playerCollision, direction, 0.0f);
			blk3.Draw(window);
			


			
			
			/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			window.setView(view);
			player.Draw(window);
			for (Bullet &bullet : bullet)
			{
				bullet.Update(deltaTime);
				bullet.Draw(window);
			}
			for (Monster& monster : monster)
			{
				monster.Draw(window);
			}
			window.display();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}
		
		while (gameState == 2)
		{

		}
		
	}
	return 0;
}

void saveNewScore(string name, int score) {
	ifstream myFile;
	vector<pair<int, string> > scoreList;
	myFile.open("data/score.txt");
	string temp, tempString;
	bool state = false;
	int X = 1, tempInt = 0;
	while (getline(myFile, temp))
	{
		if (state == false)
		{
			tempString = temp;
		}
		else
		{
			for (int i = temp.length() - 1; i >= 0; i--, X *= 10)
			{
				tempInt += (temp[i] - '0') * X;
			}
			scoreList.push_back(make_pair(tempInt, tempString));
			X = 1;
			tempInt = 0;
		}
		state = !state;
		//cout << Temp << endl;
	}
	myFile.close();
	scoreList.push_back(make_pair(score, name));
	sort(scoreList.begin(), scoreList.end());
	ofstream writeFile;
	writeFile.open("data/score.txt");
	for (int i = 5; i >= 1; i--)
	{
		writeFile << scoreList[i].second << "\n" << scoreList[i].first << endl;
		//	cout << score[i].first << " -- " << score[i].second << endl;
	}
	writeFile.close();
}