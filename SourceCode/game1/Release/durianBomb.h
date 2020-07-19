#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Player.h"
#include "globalboundcollision.h"
#include <time.h>
class durianBomb
{
public:durianBomb();
	   
	
	   sf::Vector2f durianBombPos[5];
	   void Update(float deltaTime, bool faceRight, sf::Sprite &playerSprite, sf::Sprite &newtonSprite, bool &newtondead ,short &state,int &score, bool& playerdead, float& healthbarlength, short& tempnewtonscore);
	   void draw(sf::RenderWindow& window);  

private:
	sf::Sprite appleTreeBody[4];

	sf::Texture durianTexture;
	sf::Sprite durainbombBody[5];
	bool durianbombstate[5] = { 0,0,0,0,0 };
	bool durianbombitem[5] = { 0,0,0,0,0 };
	globalboundcollision checkdurianhit;
	bool displayDurianbomb[5] = { 1,1,1,1,1 };
	bool durianBombgoright[5] = {  };
	float timeforshootdurianbomb = 0.0f;
	bool appletreedead[4] = {};
	sf::RectangleShape healthbar;
	float healthbarlength = 200.0f;
	sf::Font nameFont;
	sf::Text playerName;
	sf::Texture Background;
	sf::Sprite backgroundsprite;
	sf::SoundBuffer soundBuffer;
	sf::SoundBuffer throwdurian;
	sf::Sound throwthing;
	sf::Sound bombhit;
	short durianbulletcount;

	sf::Sprite durianicon;
	sf::Text durianremain;

	sf::SoundBuffer pickbuff;
	sf::Sound pickeffect;

};

