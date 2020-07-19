#pragma once
#include "Animation.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "globalboundcollision.h"
#include <sstream>
#include <fstream>

#include <SFML/Audio.hpp>
class Player
{
public:
	Player(sf::Vector2u imageCount, float switchTime, int widthSize, int heightSize, float speed);

	void Update(float deltaTime,sf::Sprite *applebullet, bool* bulletstate, short& state , std::string& playerName,bool& newtondead);
	void draw(sf::RenderWindow &window);
	sf::Vector2f playerposition;
	sf::Sprite playerBody;
	bool playerdead = 0;
	bool faceRight;
	int score = 0;
	short tempscorenewton = 0;;
	float healthbarlength = 200.0f;
private:

	globalboundcollision checkapplehitplayer;
	Animation playerrun;

	unsigned int row;
	float speed;

	bool idle;

	sf::Texture playerTexture;
	sf::RectangleShape healthbar;

	sf::Font nameFont;
	sf::Text playerName;
	sf::Text scoreDisplay;
	sf::Text scoretext;
	sf::Text guide;

	sf::SoundBuffer soundBuffer;
	
	sf::Sound runeffect;


	sf::SoundBuffer soundBuffer2;

	sf::Sound hurteffect;


};

