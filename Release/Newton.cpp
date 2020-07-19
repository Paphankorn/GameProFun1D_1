#include "Newton.h"


Newton::Newton(sf::Vector2u imageCount, float switchTime, int widthSize, int heightSize, float speed )
	:newtonrun(imageCount, switchTime, widthSize, heightSize)
{

	throwapple.loadFromFile("throwdurian.wav");
	throwthing.setBuffer(throwapple);
	this->speed = speed;
	row = 1;
	idle = true;
	faceRight = true;
	newtonTexture.loadFromFile("spriteforstate1.png");
	newtonBody.setTexture(newtonTexture);
	newtonBody.setTextureRect(sf::IntRect(0, 80, 70, 110));
	newtonrun.uvsprites.top = 80;
	newtonBody.setPosition(sf::Vector2f(1000, 350));
	

	newtonposition.x = newtonBody.getPosition().x + 40;
	newtonposition.y = newtonBody.getPosition().y + 50;
	for (auto i = 0; i < 3; i++) {
		
		applebullet[i].setTexture(newtonTexture);
		applebullet[i].setTextureRect(sf::IntRect(660, 0, 20, 20));
	
	}



}

void Newton::Update(float deltaTime, sf::Vector2f playerpositon, sf::Sprite &playerBody, bool &playerdead , int& score,short &tempscore,short &state)

{

	
	if (newtondead == 1|| playerdead==1) {

		for (auto i = 0; i < 3; i++) {
			applebullet[i].setPosition(-30, -30);
		}

		//score=0;
		newtonBody.setPosition(sf::Vector2f(1000, 350));
	}

	if (newtondead == 0) {
	

		sf::Vector2f newtonMovement(0.0f, 0.0f);


		if (newtonposition.x >= playerpositon.x + 500) {
			newtonMovement.x -= speed * deltaTime;



		}

		if (newtonposition.x + 500 <= playerpositon.x) {
			newtonMovement.x += speed * deltaTime;

		}

		if (newtonposition.y > playerpositon.y + 5) {
			newtonMovement.y -= speed * deltaTime;


		}
		if (newtonposition.y + 5 < playerpositon.y) {
			newtonMovement.y += speed * deltaTime;


		}

		if (playerdead == 1){
			idle = true;
		



		}
		else {
			idle = false;
			//bullet

			timeforshootbullet += deltaTime;
			//std::cout << timeforshootbullet << std::endl;
			if (timeforshootbullet > 0.8f) {
				timeforshootbullet = -0.2f;
				if (throwthing.getStatus() == sf::Sound::Status::Stopped) {
					throwthing.play();
				}
				for (auto i = 0; i < 3; i++) {

					if (bulletstate[i] == 0) {
						bulletstate[i] = 1;
						if (faceRight == true) {
							bulletdiractionright[i] = true;
							applebulletposition[i].x = newtonBody.getPosition().x + 70;
							applebulletposition[i].y = newtonBody.getPosition().y + 50;
						}
						else if (faceRight == false) {
							bulletdiractionright[i] = false;
							applebulletposition[i].x = newtonBody.getPosition().x;
							applebulletposition[i].y = newtonBody.getPosition().y + 50;
						}
						applebullet[i].setPosition(applebulletposition[i].x, applebulletposition[i].y);


						break;
					}
				}


			}
		
			for (auto i = 0; i < 3; i++) {


				if (bulletstate[i] == 1) {
					if (bulletdiractionright[i] == true) {
						applebullet[i].move(500 * deltaTime, 0);
					}
					if (bulletdiractionright[i] == false) {
						applebullet[i].move(-(500 * deltaTime), 0);

					}
				}
				if (applebullet[i].getPosition().x < -50) {

					bulletstate[i] = 0;
				}


			}
			newtonBody.move(newtonMovement);
			newtonposition.x = newtonBody.getPosition().x + 40;

			newtonposition.y = newtonBody.getPosition().y + 50;

		}

		if (newtonMovement.x > 0.0f || playerpositon.x > newtonposition.x) {
			faceRight = true;



		}
		else if (newtonMovement.x < 0.0f || playerpositon.x < newtonposition.x) {
			faceRight = false;

		}
		

		newtonrun.Update(row, deltaTime, faceRight, idle, 1,0);


		newtonBody.setTextureRect(newtonrun.uvsprites);



	




	}

	
	tempscore = score;
	
}

void Newton::draw(sf::RenderWindow& window)
{

	if (newtondead == 0) {
		window.draw(newtonBody);



		for (int i = 0; i < 3; i++) {
			if (applebulletposition[i].x > 0 && applebulletposition[i].y > 0) {
				window.draw(applebullet[i]);
			}
			if (applebullet[i].getPosition().x > window.getSize().x) {


				bulletstate[i] = 0;
			}

		}
	}



}


