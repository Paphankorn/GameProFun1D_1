#pragma once
#include "Animation.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
class nikolabeam
{
public:
	nikolabeam(sf::Vector2u imageCount, float switchTime, int widthSize, int heightSize, float speed);
	void Update(float deltaTime, sf::Sprite& nikolabody,sf::Sprite playerBody,sf::Sprite *playerbulletbody, bool faceRight,bool &nikoladead);
	void draw(sf::RenderWindow& window);
	bool idle;
	sf::Sprite nikolabeamSprite;
private:
	
	sf::Texture nikolabeamTexture;
	
	float timeforshootbeam = 0.00f;
	Animation nikolabeamanimation;
	unsigned int row;
};

