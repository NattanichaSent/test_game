#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
using namespace std;
class Menu
{
public:
	Menu();
	~Menu();
	void draw(sf::RenderWindow &window, sf::Event event);
	bool isGameStart();
	string getPlayerName();
private:
	sf::Clock clock;
	double delTaTime = 0;

	sf::Texture bgTexture;
	sf::RectangleShape bgBody;
	/*
	* main menu
	*/
	void displayMenu(sf::RenderWindow& window);
	sf::Texture titleTexture,playTexture,howtoTexture,scoreTexture,exitTexture;
	sf::RectangleShape titleBody,playBody,howtoBody,scoreBody,exitBody;
	void checkMouse(sf::RenderWindow& window);
	bool isStart = false;
	int stateSub = 0;
	/*
	* 0: normal
	* 3: input name
	* 1: howtoplay
	* 2: high score
	*/

	/*
	* how to play zone
	*/
	void displayHowToPlay(sf::RenderWindow& window);
	sf::Texture backTexture, bgHowtoTexture;
	sf::RectangleShape backHowToBody, bgHowtoBody;
	/*
	* high score zone
	*/
	void displayHighScore(sf::RenderWindow& window);
	sf::Texture bgScoreTexture;
	sf::RectangleShape backScoreBody, bgScoreBody;
	bool isStartup = false;
	vector<pair<int, string> > scoreList;
	sf::Font font;
	sf::Text Text_score, Text_name;


	/*
	* input your name
	*/
	void displayInputName(sf::RenderWindow& window, sf::Event event);
	sf::RectangleShape objectInput;
	sf::RectangleShape cursorInput;
	float totalTimeInput = 0;
	sf::Clock clockInput;
	bool stateInput = false;
	char lastCharInput = ' ';
	std::string inputName;
	sf::Text textInput;
};

