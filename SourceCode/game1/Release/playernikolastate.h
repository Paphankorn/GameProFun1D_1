#pragma once
#include "Animation.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "globalboundcollision.h"
#include <sstream>
#include <fstream>
#include <SFML/Audio.hpp>
#include <time.h>
class playernikolastate
{
public:
	playernikolastate(sf::Vector2u imageCount, float switchTime, int widthSize, int heightSize, float speed);

	void Update(float deltaTime, short& state, sf::Sprite& nikolabeam, bool& nikoladead,std::string &inputname);
	void draw(sf::RenderWindow& window);
	sf::Vector2f playerposition;
	sf::Sprite playerBody;
	bool playerdead = 0;
	bool faceRight;

	short alternativeelectricsore = 0;
	short tempalternativeelectricsore = 0;
	
	bool idle;
private:
	sf::Sprite lightning[2];
	sf::Vector2f lightningPos[2];

	globalboundcollision checkbeamhitplayer;
	Animation playergunandrun;

	unsigned int row;
	float speed;
	sf::Sprite armor;
	int playerArmor[2] = { 0 };
	float healthbarlength = 200.0f;
	sf::Sprite nikolaBackground;
	sf::Texture playerTexture,BackgroundTexture;
	sf::RectangleShape healthbar;
	sf::Font nameFont;
	sf::Text playerName;
	sf::Text scoreDisplay;
	sf::Text scoretext;
	sf::SoundBuffer soundBuffer;
	float timeforlightningDisplay = 0.0f;
	sf::Sound runeffect;
	sf::SoundBuffer lightningbuff;
	sf::Sound lightningeffect;
	sf::SoundBuffer hurtbuff;
	sf::Sound hurteffect;
	sf::Text guide;
	sf::Sprite armoricon;
	sf::Text showremainarmor;
	sf::Text tellplayer;
	short armorcount = 0;

	sf::SoundBuffer pickbuff;
	sf::Sound pickeffect;
};

