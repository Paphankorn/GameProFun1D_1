#pragma once
#include "Animation.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include <vector>

class Newton
{
	public: 
		Newton(sf::Vector2u imageCount, float switchTime, int widthSize, int heightSize, float speed );

		void Update(float deltaTime, sf::Vector2f playerpositon, sf::Sprite &playerBody, bool &playerdead, int& score, short& tempscore, short& state);
		void draw(sf::RenderWindow& window);

		sf::Vector2f newtonposition;
		sf::Sprite newtonBody;
		
		sf::Vector2f applebulletposition[3];

		sf::Sprite applebullet[3];
	
		bool newtondead = 0;
		bool bulletstate[3] = { 0,0,0 };
		
private:
	sf::SoundBuffer throwapple;
	sf::Sound throwthing;
	
	bool bulletdiractionright[3];
	sf::Texture newtonTexture;
	Animation newtonrun;

	unsigned int row;
	float speed;
	bool faceRight;
	bool idle;



	float timeforshootbullet=0.00f;
};

