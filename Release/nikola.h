#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "globalboundcollision.h"

class nikola
{
public:
	nikola(sf::Vector2u imageCount, float switchTime, int widthSize, int heightSize, float speed);
	void Update(float deltaTime, sf::Vector2f playerpositon , sf::Sprite* playerbullet, short& state, bool& playerdead,short & alternativeelectricsore, short& tempalternativeelectricsore);
	void draw(sf::RenderWindow& window);

	sf::Sprite nikolaBody;
	bool nikoladead = 0;
	
	bool faceRight;

private:
	

	sf::Texture nikolaTexture;

	sf::Vector2f nikolaposition;
	unsigned int row;
	float speed;
	
	bool idle=true;
	globalboundcollision checknikolahit;

	sf::RectangleShape healthbar;
	float healthbarlength = 200.0f;
	sf::Font nameFont;
	sf::Text nikolaname;

	
};

