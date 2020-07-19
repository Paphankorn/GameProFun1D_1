#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>

class Selectstate
{
public:
	Selectstate();
	void draw(sf::RenderWindow& window);
	void Update(short& state, float deltaTime,std::string &inputname, short& score, short& alternativeelectricsore);
	short selectmenu = 0;
	short playerScore = 0;
private:

	sf::Texture statetexture[2];
	sf::Sprite statepicture[2];
	sf::Font stateFont;

	sf::Text stateName[2];
	sf::Text select;
	sf::Text back;
	sf::Vector2i mouseposition;
	sf::Text nikolascore;
	sf::Text newtonscore;
	sf::Text totalscore;
	sf::Text scoretext;
	sf::Text resultscore;
	sf::Text playerName;
	float delaytime = 0.0f;

};

