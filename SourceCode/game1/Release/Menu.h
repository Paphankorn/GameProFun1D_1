#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>



class Menu
{
public:
	Menu();
	void draw(sf::RenderWindow& window);
	void Update(short& state, float deltaTime);
	short selectmenu = 0;
private:
	sf::Texture Background;
	sf::Sprite backgroundsprite;
	sf::RectangleShape rectangle[4];
	sf::Font MenuFont;
	sf::Text Menuitem[4];
	sf::Text gameName;
	sf::Text myname;
	sf::Vector2i mouseposition;

	float delaytime=0.0f;

	sf::Text howtousemenu;
};

