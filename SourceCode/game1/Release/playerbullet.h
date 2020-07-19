#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Player.h"
#include "globalboundcollision.h"
#include <sstream>

class playerbullet
{
	public:
		playerbullet();
	sf::Vector2f bulletPos[10];
	void Update(float deltaTime,  sf::Sprite playerSprite, bool faceRight, short& state,bool & playerdead,bool &nikoladead);
	
	void draw(sf::RenderWindow& window);
	sf::Sprite bulletBody[10];

private:

	sf::Texture bulletTexture;


	bool bulletstate[10] = {};

	globalboundcollision checkbullethit;
	bool displaybullet[10] = { 1,1,1,1,1,1,1,1,1,1 };
	bool bulletgoright[10] = {  };
	float timeforshootbullet = 0.0f;
	sf::Sprite bulleticon;
	sf::RectangleShape healthbar;
	float healthbarlength = 200.0f;
	sf::Font nameFont;
	sf::Text playerName;
	sf::Texture Background;
	sf::Sprite backgroundsprite;
	sf::SoundBuffer soundBuffer;
	sf::Sound bombhit;
	short countbullet = 0;
	sf::Font myfont;
	sf::Text showremainbullet;
	sf::SoundBuffer soundgun;
	sf::Sound gunshoot;

};

