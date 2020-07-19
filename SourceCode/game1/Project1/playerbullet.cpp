#include "playerbullet.h"

playerbullet::playerbullet()
{
	bulletTexture.loadFromFile("spritenikolaforstate2.png");

	myfont.loadFromFile("THSarabunNew Bold.ttf");
	for (auto i = 0; i < 10; i++) {

		bulletBody[i].setTexture(bulletTexture);
		bulletBody[i].setTextureRect(sf::IntRect(510, 0, 70, 33));
	}


	bulleticon.setTexture(bulletTexture);
	bulleticon.setTextureRect(sf::IntRect(510, 0, 70, 33));

	bulleticon.setPosition(sf::Vector2f(230, 10));

		showremainbullet.setFont(myfont);
	showremainbullet.setCharacterSize(30);
	soundgun.loadFromFile("lasergun.wav");
	gunshoot.setBuffer(soundgun);
	
}

void playerbullet::Update(float deltaTime, sf::Sprite playerSprite,bool faceRight, short& state, bool& playerdead, bool& nikoladead)
{
	timeforshootbullet += deltaTime;
	if (timeforshootbullet > 0.1f) {
		timeforshootbullet -= 0.1f;

		for (auto i = 0; i < 10; i++) {
			if (bulletstate[i]==0&&sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				if (gunshoot.getStatus() == sf::Sound::Status::Stopped) {
					gunshoot.play();
				}
			
				displaybullet[i] = 1;
				bulletstate[i] = 1;

				if (faceRight == true) {
					bulletgoright[i] = true;
					bulletPos[i].x = playerSprite.getPosition().x + 50;
					bulletPos[i].y = playerSprite.getPosition().y + 20;
				}
				else if (faceRight == false) {
					bulletgoright[i] = false;
					bulletPos[i].x = playerSprite.getPosition().x - 50;
					bulletPos[i].y = playerSprite.getPosition().y + 20;
				}
				bulletBody[i].setPosition(bulletPos[i].x, bulletPos[i].y);

				break;

			}
			//std::cout << "  " << bulletstate[i];
		}
		//std::cout << std::endl;

	}
	for (auto i = 0; i <10; i++) {


		if (bulletstate[i] == 1) {
			if (bulletgoright[i] == true) {
				bulletBody[i].setTextureRect(sf::IntRect(510, 0, 70, 33));
				bulletBody[i].move(400 * deltaTime, 0);
			}
			if (bulletgoright[i] == false) {
				bulletBody[i].setTextureRect(sf::IntRect(584, 0, -70, 33));
				bulletBody[i].move(-(400 * deltaTime), 0);

			}
		}
		if (bulletBody[i].getPosition().x < -200) {

			bulletstate[i] = 0;
		}
	if (playerdead == 1 || nikoladead == 1) {
			bulletBody[i].setPosition(-500, -500);

		}
	
}
	for (auto i = 0; i < 10; i++) {
		countbullet += bulletstate[i] ;
	}
	
	countbullet = 10 - countbullet;

	std::stringstream ss;
	ss << countbullet;
	showremainbullet.setString(ss.str());

	countbullet = 0;
}

void playerbullet::draw(sf::RenderWindow& window)
{
	showremainbullet.setPosition(sf::Vector2f(320,10));
	window.draw(bulleticon);
	window.draw(showremainbullet);
	for (int i = 0; i < 10; i++) {

		if (displaybullet[i] == 1&& bulletBody[i].getPosition().x>0&& bulletBody[i].getPosition().y>0) {
			window.draw(bulletBody[i]);
			if (bulletBody[i].getPosition().x > window.getSize().x) {

				displaybullet[i] = 0;
				bulletstate[i] = 0;

			}
		}

	}

}
