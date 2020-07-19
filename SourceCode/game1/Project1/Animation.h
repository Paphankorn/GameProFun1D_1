#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>

class Animation
{
public:

	Animation(sf::Vector2u imageCount,float switchTime,int widthSize, int heightSize);
	~Animation();
	  
	void Update(int row, float deltaTime,bool faceRight,bool idle,bool checknewton, bool checknikolabeam);



public:
	sf::IntRect uvsprites;
	sf::Vector2u currentImage;
	sf::Vector2u imageCount;
	float nikolatimegunanimtion;
	float totalTime;
	float switchTime;


private:
	sf::SoundBuffer beambuff;
	sf::Sound beamshoot;




};

