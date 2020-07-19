#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <Windows.h>

class entername
{
public:

	entername();
	void draw(sf::RenderWindow& window);
	void Update(short& state, float deltaTime, short& tempscorenewton, short& tempscorenikola);
	std::string inputname;
	short selectmenu = -1;
	sf::SoundBuffer choosemenu;
	sf::Sound chooseffect;

	sf::SoundBuffer entermenu;
	sf::Sound entereffect;

private:
	sf::Vector2f namePosition;
	char last_char;
	int movetext;
	sf::Font enterFont;
	sf::Text enterName;
	sf::Text choosename;
	sf::Text start;
	sf::Event textenter;
	sf::Text back;
	sf::Vector2i mouseposition;
	
	float delaytime = 0.0f;
	sf::RectangleShape enterbox;
	sf::Text cauntion;



};

