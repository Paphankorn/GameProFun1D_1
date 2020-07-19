#include "durianBomb.h"

durianBomb::durianBomb()
{
	Background.loadFromFile("newtonstatebackground.png");
	throwdurian.loadFromFile("throw.wav");
	throwthing.setBuffer(throwdurian);


	pickbuff.loadFromFile("pickitem.wav");
	pickeffect.setBuffer(pickbuff);
	
	backgroundsprite.setTexture(Background);
	soundBuffer.loadFromFile("bombsound.wav");
	bombhit.setVolume(100.0f);
	bombhit.setBuffer(soundBuffer);

	durianTexture.loadFromFile("spriteforstate1.png");

	for (auto i = 0; i < 5; i++) {

		durainbombBody[i].setTexture(durianTexture);
		durainbombBody[i].setTextureRect(sf::IntRect(600, 0, 60, 80));

	}
	durainbombBody[0].setPosition(sf::Vector2f(300, 200));
	durainbombBody[1].setPosition(sf::Vector2f(1200, 300));
	durainbombBody[2].setPosition(sf::Vector2f(500, 400));
	durainbombBody[3].setPosition(sf::Vector2f(900, 600));
	durainbombBody[4].setPosition(sf::Vector2f(1000, 250));
	durianicon.setTexture(durianTexture);
	durianicon.setTextureRect(sf::IntRect(600, 0, 60, 80));
	
	for (auto i = 0; i < 4; i++) {
		
		appleTreeBody[i].setTexture(durianTexture);
		appleTreeBody[i].setTextureRect(sf::IntRect(680, 0, 170, 210));
		

	}

	
	
	appleTreeBody[0].setPosition(sf::Vector2f(400, 200));
	appleTreeBody[1].setPosition(sf::Vector2f(1100, 400));
	appleTreeBody[2].setPosition(sf::Vector2f(600, 500));
	appleTreeBody[3].setPosition(sf::Vector2f(800, 150));




	healthbar.setFillColor(sf::Color::Red);
	nameFont.loadFromFile("THSarabunNew Bold.ttf");
	playerName.setFont(nameFont);
	playerName.setString("Isaac Newton");
	playerName.setStyle(sf::Text::Bold);
	playerName.setCharacterSize(50);
	playerName.setOutlineColor(sf::Color::Black);
	

	
	durianremain.setFont(nameFont);
	
	durianremain.setCharacterSize(30);
	playerName.setOutlineColor(sf::Color::Black);
	playerName.setOutlineThickness(2);



}

void durianBomb::Update(float deltaTime, bool faceRight, sf::Sprite &playerSprite, sf::Sprite &newtonSprite,bool &newtondead,short &state, int &score,bool &playerdead,float &playerhealthbarlength,short &tempnewtonscore)
{



	if (playerdead == 1 || newtondead == 1) {
		newtondead = 0;
		playerSprite.setPosition(sf::Vector2f(50, 350));
		score = 0;
		this->healthbarlength = 200.0f;
		playerhealthbarlength = 200.0f;
	//	std::cout << healthbarlength << std::endl;
		for (auto i = 0; i < 5; i++) {
			durainbombBody[i].setPosition(sf::Vector2f(rand() % 1000, (rand() % 400) + 200));
			displayDurianbomb[i] = 1;
			durianbombstate[i] = 0;
			durianbombitem[i] = 0;
		}
		for (auto i = 0; i < 4; i++) {
		appletreedead[i] = 0;
	}
		
	appleTreeBody[0].setPosition(sf::Vector2f(400, 200));
	appleTreeBody[1].setPosition(sf::Vector2f(1100, 400));
	appleTreeBody[2].setPosition(sf::Vector2f(600, 500));
	appleTreeBody[3].setPosition(sf::Vector2f(800, 150));
	}
	srand(time(NULL));

	this->healthbar.setSize(sf::Vector2f(healthbarlength, 20));
	//std::cout << appleTreeBodyVector.size() << std::endl;
	for (auto i = 0; i < 5; i++) {
		//std::cout << checkdurianhit.checkcollision(playerSprite, durainbombBody[i])<<"  " ;
		if (checkdurianhit.checkcollision(playerSprite, durainbombBody[i]) && durianbombstate[i] == 0) {
			//if (pickeffect.getStatus() == sf::Sound::Status::Stopped) {
				pickeffect.play();
			//}
			displayDurianbomb[i] = 0;

			durianbombitem[i] = 1;
			durainbombBody[i].setPosition(sf::Vector2f(0, 0));
		}
		//std::cout << durianbombitem[i] << "  ";
	}

	
	
		
		for (int i = 0; i < 5; i++) {
			if (durianbombitem[i] == 0 && displayDurianbomb[i] == 0) {
			durianbombstate[i] = 0;
			displayDurianbomb[i] = 1;
		

			durainbombBody[i].setPosition(sf::Vector2f(rand() % 1000, (rand() % 400) + 200));


		}

		}

	


	timeforshootdurianbomb += deltaTime;
	if (timeforshootdurianbomb > 0.1f) {
		timeforshootdurianbomb -= 0.1f;

		for (auto i = 0; i < 5; i++) {
			if (durianbombitem[i] == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				if (throwthing.getStatus() == sf::Sound::Status::Stopped) {
					throwthing.play();
		}
				durianbombitem[i] = 0;
				displayDurianbomb[i] = 1;
				durianbombstate[i] = 1;



				if (faceRight == true) {
					durianBombgoright[i] = true;
					durianBombPos[i].x = playerSprite.getPosition().x + 50;
					durianBombPos[i].y = playerSprite.getPosition().y + 10;
				}
				else if (faceRight == false) {
					durianBombgoright[i] = false;
					durianBombPos[i].x = playerSprite.getPosition().x - 50;
					durianBombPos[i].y = playerSprite.getPosition().y + 10;
				}
				durainbombBody[i].setPosition(durianBombPos[i].x, durianBombPos[i].y);

				break;

			}
			//std::cout << "  " << durianbombstate[i];
		}
		//std::cout << std::endl;

	}
	for (auto i = 0; i < 5; i++) {


		if (durianbombstate[i] == 1) {
			if (durianBombgoright[i] == true) {
				durainbombBody[i].move(400 * deltaTime, 0);
			}
			if (durianBombgoright[i] == false) {
				durainbombBody[i].move(-(400 * deltaTime), 0);

			}
		}
		if (durainbombBody[i].getPosition().x < -200) {

			durianbombstate[i] = 0;
		}


	}


	for (auto i = 0; i < 5; i++) {

		if (checkdurianhit.checkcollision(appleTreeBody[0], durainbombBody[i]) && durianbombstate[i] == 1) {
			displayDurianbomb[i] = 0;
			durianbombstate[i] = 0;
			durainbombBody[i].setPosition(sf::Vector2f(-20, -20));
	
			appleTreeBody[0].setPosition(sf::Vector2f(-1000, 0));
			appletreedead[0] = 1;
			if (score < 100) {
				score = score + 15;
			}
			//if (bombhit.getStatus() == sf::Sound::Status::Stopped) {
				bombhit.play();
			//}

		}

		if (checkdurianhit.checkcollision(appleTreeBody[1], durainbombBody[i]) && durianbombstate[i] == 1) {
			displayDurianbomb[i] = 0;
			durianbombstate[i] = 0;
			durainbombBody[i].setPosition(sf::Vector2f(-100, -100));
	
			appleTreeBody[1].setPosition(sf::Vector2f(-1000, 0));
			appletreedead[1] = 1;
			if (score < 100) {
				score = score + 15;
			}
			//if (bombhit.getStatus() == sf::Sound::Status::Stopped) {
				bombhit.play();
			//}

		}
		if (checkdurianhit.checkcollision(appleTreeBody[2], durainbombBody[i]) && durianbombstate[i] == 1) {
			displayDurianbomb[i] = 0;
			durianbombstate[i] = 0;
			durainbombBody[i].setPosition(sf::Vector2f(-1000, -1000));
			appleTreeBody[2].setPosition(sf::Vector2f(-1000, 0));
			appletreedead[2] = 1;
			if (score < 100) {
				score = score + 15;
			}
			//if (bombhit.getStatus() == sf::Sound::Status::Stopped) {
				bombhit.play();
			//}

		}
		if (checkdurianhit.checkcollision(appleTreeBody[3], durainbombBody[i]) && durianbombstate[i] == 1) {
			displayDurianbomb[i] = 0;
			durianbombstate[i] = 0;
			durainbombBody[i].setPosition(sf::Vector2f(-1000, -1000));
	
			appleTreeBody[3].setPosition(sf::Vector2f(-1000, 0));
			appletreedead[3] = 1;
			if (score < 100) {
				score = score + 15;
			}
			//if (bombhit.getStatus() == sf::Sound::Status::Stopped) {
				bombhit.play();
			//}
		}

	}
	for (int i = 0; i < 5; i++) {
	if (checkdurianhit.checkcollision(durainbombBody[i], newtonSprite) && durianbombstate[i] == 1 ) {
		displayDurianbomb[i] = 0;
		durianbombstate[i] = 0;
		durainbombBody[i].setPosition(sf::Vector2f(-1000, -1000));
		
		
			if (appletreedead[0] == 1&& appletreedead[1] == 1&& appletreedead[2] == 1&& appletreedead[3] == 1) {
				newtondead = 1;
				healthbarlength = 0;
				state = 2;
				if (score < 100) {
					score = score + 40;
					if (score > 100) {
						score = 100;
					}
				}
			

			}

			//if (bombhit.getStatus() == sf::Sound::Status::Stopped) {
				bombhit.play();
			//}
		
	}
}
	for (auto i = 0; i < 5; i++) {
		durianbulletcount += durianbombitem[i];
	}



	std::stringstream ss;
	ss << durianbulletcount;
	durianremain.setString(ss.str());

	durianbulletcount = 0;
	tempnewtonscore = score;

}

void durianBomb::draw(sf::RenderWindow& window)
{
	durianicon.setPosition(sf::Vector2f(220, 30));
	durianremain.setPosition(sf::Vector2f(300, 50));
	window.draw(backgroundsprite);
	window.draw(durianremain);
	window.draw(durianicon);
	
	
	playerName.setPosition(sf::Vector2f(window.getSize().x - 220, 10));
	healthbar.setPosition(sf::Vector2f(window.getSize().x-210, 70));
	window.draw(playerName);
	for (int i = 0; i < 4; i++) {
		if (appletreedead[i] == 0) {
			window.draw(appleTreeBody[i]);
		}
	}
	for (int i = 0; i < 5; i++) {
	
		if (displayDurianbomb[i] == 1) {
			window.draw(durainbombBody[i]);
			if (durainbombBody[i].getPosition().x > window.getSize().x|| durainbombBody[i].getPosition().x <0|| durainbombBody[i].getPosition().y < 0|| durainbombBody[i].getPosition().y >window.getSize().y){

				displayDurianbomb[i] = 0;
				durianbombstate[i] = 0;

			}
		}
		
	}
	window.draw(healthbar);
}
