#include "Menu.h"
Menu::Menu()
{
	//cout << "Hello World";
	if (!this->bgTexture.loadFromFile("bg/bg_Menu2.png"))
	{
		cout << "ERROR, Can not load bg, In menu.cpp";
	}
	this->bgBody.setTexture(&this->bgTexture);
	this->bgBody.setPosition(sf::Vector2f(0,0));
	this->bgBody.setSize(sf::Vector2f(1080.0f, 720.0f));
	//this->titleTexture.loadFromFile("bg/bg_Title_game.jpg");
	this->playTexture.loadFromFile("bg/play.png");
	this->howtoTexture.loadFromFile("bg/howTo.png");
	this->scoreTexture.loadFromFile("bg/score.png");
	this->exitTexture.loadFromFile("bg/exit1.png");
	/*this->titleBody.setTexture(&this->titleTexture);
	this->titleBody.setPosition(sf::Vector2f(290, 60));
	this->titleBody.setSize(sf::Vector2f(500.0f, 100.0f));*/
	this->playBody.setTexture(&this->playTexture);
	this->playBody.setPosition(sf::Vector2f(540, 260));
	this->playBody.setSize(sf::Vector2f(300.0f, 80.0f));
	this->playBody.setOrigin(this->playBody.getSize()/2.0f);
	this->howtoBody.setTexture(&this->howtoTexture);
	this->howtoBody.setPosition(sf::Vector2f(540, 260+(110)));
	this->howtoBody.setSize(sf::Vector2f(300.0f, 80.0f));
	this->howtoBody.setOrigin(this->howtoBody.getSize() / 2.0f);
	this->scoreBody.setTexture(&this->scoreTexture);
	this->scoreBody.setPosition(sf::Vector2f(540, 260+(110*2)));
	this->scoreBody.setSize(sf::Vector2f(300.0f, 80.0f));
	this->scoreBody.setOrigin(this->scoreBody.getSize() / 2.0f);
	this->exitBody.setTexture(&this->exitTexture);
	this->exitBody.setPosition(sf::Vector2f(540, 260+(110*3)));
	this->exitBody.setSize(sf::Vector2f(300.0f, 80.0f));
	this->exitBody.setOrigin(this->exitBody.getSize() / 2.0f);

	/*
	* howtoplay
	*/
	this->bgHowtoTexture.loadFromFile("bg/howToBg.png");
	this->bgHowtoBody.setTexture(&this->bgHowtoTexture);
	this->bgHowtoBody.setPosition(sf::Vector2f(0, 0));
	this->bgHowtoBody.setSize(sf::Vector2f(1080.0f, 720.0f));

	this->backTexture.loadFromFile("bg/back.png");
	this->backHowToBody.setTexture(&this->backTexture);
	this->backHowToBody.setPosition(sf::Vector2f(540, 260 + (110 * 3)));
	this->backHowToBody.setSize(sf::Vector2f(300.0f, 80.0f));
	this->backHowToBody.setOrigin(this->backHowToBody.getSize() / 2.0f);

	/*
	* high score
	*/
	this->bgScoreTexture.loadFromFile("bg/score.png");
	this->bgScoreBody.setTexture(&this->bgScoreTexture);
	this->bgScoreBody.setPosition(sf::Vector2f(0, 0));
	this->bgScoreBody.setSize(sf::Vector2f(1080.0f, 720.0f));

	this->backScoreBody.setTexture(&this->backTexture);
	this->backScoreBody.setPosition(sf::Vector2f(540, 260 + (110 * 3)));
	this->backScoreBody.setSize(sf::Vector2f(300.0f, 80.0f));
	this->backScoreBody.setOrigin(this->backScoreBody.getSize() / 2.0f);

	this->font.loadFromFile("data/ff.ttf");
	this->Text_name.setFont(this->font);
	this->Text_name.setString("Name");
	this->Text_name.setCharacterSize(40);
	this->Text_name.setFillColor(sf::Color::Red);
	//this->Text_name.setStyle(sf::Text::Bold);
	this->Text_name.setPosition(370, 200);

	this->Text_score.setFont(this->font);
	this->Text_score.setString("Score");
	this->Text_score.setCharacterSize(40);
	this->Text_score.setFillColor(sf::Color::Blue);
	this->Text_score.setPosition(670, 200);


	/*
	* Input your name here settings
	*/
	this->objectInput.setSize(sf::Vector2f(300.0f, 70.0f));
	this->objectInput.setOrigin(sf::Vector2f(150.0f, 35.0f));
	this->objectInput.setPosition(sf::Vector2f(540, 360));
	this->cursorInput.setSize(sf::Vector2f(5.0f, 64.0f));
	this->cursorInput.setOrigin(sf::Vector2f(2.5f, 32.0f));
	this->cursorInput.setPosition(sf::Vector2f(395, 360));
	this->cursorInput.setFillColor(sf::Color::Black);
	this->textInput.setFont(this->font);
	this->textInput.setCharacterSize(40);
	this->textInput.setFillColor(sf::Color::Black);
	this->textInput.setPosition(390, 335);
}
Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window, sf::Event event)
{
	//cout << this->delTaTime << endl;
	clock.restart();
	if (this->delTaTime > 0.0003) {
		this->delTaTime = 0;
		//cout << "Clear" << endl;
	}
	else if (this->delTaTime != 0) {
		this->delTaTime += this->clock.restart().asSeconds();
	}
	switch (this->stateSub)
	{
	case 0:
		this->displayMenu(window);
		break;
	case 3:
		this->displayInputName(window, event);
		break;
	case 1:
		this->displayHowToPlay(window);
		break;
	case 2:
		this->displayHighScore(window);
		break;
	default:
		break;
	}
}

bool Menu::isGameStart()
{
	return this->isStart;
}

string Menu::getPlayerName()
{
	return this->inputName;
}

void Menu::checkMouse(sf::RenderWindow& window)
{
	//cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << " " <<  this->playBody.getPosition().x << " " << this->playBody.getPosition().y << endl;
	if (sf::Mouse::getPosition(window).x >= this->playBody.getPosition().x - this->playBody.getSize().x / 2  &&
		sf::Mouse::getPosition(window).x <= this->playBody.getPosition().x + this->playBody.getSize().x / 2 &&
		sf::Mouse::getPosition(window).y >= this->playBody.getPosition().y - this->playBody.getSize().y / 2 &&
		sf::Mouse::getPosition(window).y <= this->playBody.getPosition().y + this->playBody.getSize().y / 2)
	{
		//cout << "chon" << endl;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->delTaTime == 0) {
			//this->isStart = true;
			this->stateSub = 3;
			this->delTaTime = 0.001;
		}
		this->playBody.setScale(sf::Vector2f(1.2, 1.2));
	}
	else {
		this->playBody.setScale(sf::Vector2f(1, 1));
	}
	/*
	* howtoBody
	*/
	if (sf::Mouse::getPosition(window).x >= this->howtoBody.getPosition().x - this->howtoBody.getSize().x / 2 &&
		sf::Mouse::getPosition(window).x <= this->howtoBody.getPosition().x + this->howtoBody.getSize().x / 2 &&
		sf::Mouse::getPosition(window).y >= this->howtoBody.getPosition().y - this->howtoBody.getSize().y / 2 &&
		sf::Mouse::getPosition(window).y <= this->howtoBody.getPosition().y + this->howtoBody.getSize().y / 2)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->delTaTime == 0) {
			this->stateSub = 1;
			this->delTaTime = 0.001;
		}
		this->howtoBody.setScale(sf::Vector2f(1.2, 1.2));
	}
	else {
		this->howtoBody.setScale(sf::Vector2f(1, 1));
	}

	/*
	* high score
	*/
	if (sf::Mouse::getPosition(window).x >= this->scoreBody.getPosition().x - this->scoreBody.getSize().x / 2 &&
		sf::Mouse::getPosition(window).x <= this->scoreBody.getPosition().x + this->scoreBody.getSize().x / 2 &&
		sf::Mouse::getPosition(window).y >= this->scoreBody.getPosition().y - this->scoreBody.getSize().y / 2 &&
		sf::Mouse::getPosition(window).y <= this->scoreBody.getPosition().y + this->scoreBody.getSize().y / 2)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->delTaTime == 0) {
			this->stateSub = 2;
			this->delTaTime = 0.001;
		}
		this->scoreBody.setScale(sf::Vector2f(1.2, 1.2));
	}
	else {
		this->scoreBody.setScale(sf::Vector2f(1, 1));
	}


	/*
	* if click will close window
	*/
	if (sf::Mouse::getPosition(window).x >= this->exitBody.getPosition().x - this->exitBody.getSize().x / 2 &&
		sf::Mouse::getPosition(window).x <= this->exitBody.getPosition().x + this->exitBody.getSize().x / 2 &&
		sf::Mouse::getPosition(window).y >= this->exitBody.getPosition().y - this->exitBody.getSize().y / 2 &&
		sf::Mouse::getPosition(window).y <= this->exitBody.getPosition().y + this->exitBody.getSize().y / 2)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->delTaTime == 0) {
			window.close();
			this->delTaTime = 0.0001;
		}
		this->exitBody.setScale(sf::Vector2f(1.2, 1.2));
	}
	else {
		this->exitBody.setScale(sf::Vector2f(1, 1));
	}
}

void Menu::displayMenu(sf::RenderWindow& window)
{
	/*
	* Write about main here
	*/
	window.draw(this->bgBody);
	window.draw(this->titleBody);
	window.draw(this->playBody);
	window.draw(this->howtoBody);
	window.draw(this->scoreBody);
	window.draw(this->exitBody);
	checkMouse(window);
}

void Menu::displayHowToPlay(sf::RenderWindow& window)
{
	/*
	* Write about how to paly here
	*/

	/*
	* if click will back to main page
	*/
	if (sf::Mouse::getPosition(window).x >= this->backHowToBody.getPosition().x - this->backHowToBody.getSize().x / 2 &&
		sf::Mouse::getPosition(window).x <= this->backHowToBody.getPosition().x + this->backHowToBody.getSize().x / 2 &&
		sf::Mouse::getPosition(window).y >= this->backHowToBody.getPosition().y - this->backHowToBody.getSize().y / 2 &&
		sf::Mouse::getPosition(window).y <= this->backHowToBody.getPosition().y + this->backHowToBody.getSize().y / 2)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->delTaTime == 0) {
			this->stateSub = 0;
			this->delTaTime = 0.0001;
		}
		this->backHowToBody.setScale(sf::Vector2f(1.2, 1.2));
	}
	else {
		this->backHowToBody.setScale(sf::Vector2f(1, 1));
	}
	window.draw(this->bgHowtoBody);
	window.draw(this->backHowToBody);
}

void Menu::displayHighScore(sf::RenderWindow& window)
{
	/*
	* Write about hight score here
	*/
	if (this->isStartup == false) {
		cout << "Score is loaded" << endl;
		this->isStartup = true;
		ifstream myFile;
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
				this->scoreList.push_back(make_pair(tempInt, tempString));
				X = 1;
				tempInt = 0;
			}
			state = !state;
			//cout << Temp << endl;
		}
		myFile.close();
		string display_name = "Name\n";
		string display_score = "Score\n";
		for (int i = 0; i < this->scoreList.size(); i++) {
			//cout << scoreList[i].second << " " << this->scoreList[i].first << endl;
			display_name += scoreList[i].second + "\n";
			display_score += to_string(this->scoreList[i].first) + "\n";
		}
		this->Text_name.setString(display_name);
		this->Text_score.setString(display_score);
	}

	if (sf::Mouse::getPosition(window).x >= this->backScoreBody.getPosition().x - this->backScoreBody.getSize().x / 2 &&
		sf::Mouse::getPosition(window).x <= this->backScoreBody.getPosition().x + this->backScoreBody.getSize().x / 2 &&
		sf::Mouse::getPosition(window).y >= this->backScoreBody.getPosition().y - this->backScoreBody.getSize().y / 2 &&
		sf::Mouse::getPosition(window).y <= this->backScoreBody.getPosition().y + this->backScoreBody.getSize().y / 2)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->delTaTime == 0) {
			this->stateSub = 0;
			this->delTaTime = 0.0001;
		}
		this->backScoreBody.setScale(sf::Vector2f(1.2, 1.2));
	}
	else {
		this->backScoreBody.setScale(sf::Vector2f(1, 1));
	}

	window.draw(this->bgScoreBody);
	window.draw(this->Text_name);
	window.draw(this->Text_score);
	window.draw(this->backScoreBody);
}

void Menu::displayInputName(sf::RenderWindow& window, sf::Event event)
{
	if (event.type == sf::Event::EventType::TextEntered)
	{
		//cout << event.text.unicode << endl;
		if (this->lastCharInput != event.text.unicode && event.text.unicode == 8 &&
			this->inputName.length() > 0) // delete
		{

			this->lastCharInput = event.text.unicode;
			this->inputName.erase(this->inputName.length() - 1);
			this->textInput.setString(this->inputName);
			this->cursorInput.setPosition(395 + this->textInput.getGlobalBounds().width + 5, 360);
			std::cout << this->inputName << std::endl;

		}
		else if (this->lastCharInput != event.text.unicode &&
			(event.text.unicode >= 'a' && event.text.unicode <= 'z' ||
				event.text.unicode >= 'A' && event.text.unicode <= 'Z' ||
				event.text.unicode >= '0' && event.text.unicode <= '9')
			&& this->inputName.length() < 15)
		{
			//std::cout << event.text.unicode << std::endl;
			this->lastCharInput = event.text.unicode;

			this->inputName += event.text.unicode;

			this->textInput.setString(this->inputName);

			this->cursorInput.setPosition(395 + this->textInput.getGlobalBounds().width + 5, 360);

			std::cout << this->inputName << std::endl;
		}
		else if (this->lastCharInput != event.text.unicode && event.text.unicode == 13 && this->inputName.length() > 0) {
			//cout << "This key enter" << endl;
			this->isStart = true;
		}

	}

	if (event.type == sf::Event::EventType::KeyReleased && this->lastCharInput != ' ')
	{
		this->lastCharInput = ' ';
	}

	window.clear();
	window.draw(this->bgBody);
	window.draw(this->objectInput);

	this->totalTimeInput += clock.restart().asSeconds();
	if (this->totalTimeInput >= 0.05)
	{
		this->totalTimeInput = 0;
		this->stateInput = !this->stateInput;
	}
	if (this->stateInput == true)
	{
		window.draw(this->cursorInput);
	}

	window.draw(this->textInput);
}
