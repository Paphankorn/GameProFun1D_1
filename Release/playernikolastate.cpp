#include "playernikolastate.h"

playernikolastate::playernikolastate(sf::Vector2u imageCount, float switchTime, int widthSize, int heightSize, float speed)
	:playergunandrun(imageCount, switchTime, widthSize, heightSize)
{
	soundBuffer.loadFromFile("runsound.wav");
	runeffect.setVolume(5.0f);
	runeffect.setBuffer(soundBuffer);
	this->speed = speed;
	row = 0;
	pickbuff.loadFromFile("pickitem.wav");
	pickeffect.setBuffer(pickbuff);
	idle = true;
	faceRight = true;
	lightningbuff.loadFromFile("Lightning.wav");
	lightningeffect.setBuffer(lightningbuff);
	hurtbuff.loadFromFile("hurt.wav");
	hurteffect.setBuffer(hurtbuff);
	healthbar.setFillColor(sf::Color::Red);
	healthbar.setPosition(sf::Vector2f(10, 70));
	playerTexture.loadFromFile("spritenikolaforstate2.png");
	playerBody.setTexture(playerTexture);
	playergunandrun.uvsprites.top = 0;
	playerBody.setPosition(sf::Vector2f(50, 350));
	BackgroundTexture.loadFromFile("backgroundnikola.png");
	nikolaBackground.setTexture(BackgroundTexture);
	for (auto i = 0; i < 2; i++) {
		lightning[i].setTexture(playerTexture);
		lightning[i].setTextureRect(sf::IntRect(300, 0, 120, 273));

		lightning[i].setPosition(-1000, -1000);
	
			lightningPos[i].x = rand() % 1200;
			lightningPos[i].y = (rand() % 300) + 140;
		
	}
	armor.setTexture(playerTexture);
	armor.setTextureRect(sf::IntRect(420,0,90,140));
	armor.setPosition(sf::Vector2f(1000,200));
	
	armoricon.setTexture(playerTexture);
	armoricon.setTextureRect(sf::IntRect(420, 0, 90, 140));
	armoricon.setPosition(sf::Vector2f(230, 50));
	armoricon.setScale(sf::Vector2f(0.5f, 0.5f));

	nameFont.loadFromFile("THSarabunNew Bold.ttf");

	scoretext.setFont(nameFont);
	scoreDisplay.setFont(nameFont);
	guide.setFont(nameFont);
	guide.setCharacterSize(35);
	guide.setString(L"\"กดปุ่ม Delete เพื่อออก\"");

	scoreDisplay.setCharacterSize(40);

	showremainarmor.setFont(nameFont);
	showremainarmor.setCharacterSize(30);


	tellplayer.setFont(nameFont);
	tellplayer.setCharacterSize(30);
	tellplayer.setOutlineColor(sf::Color::Black);
	tellplayer.setString(L"+เกราะเพิ่ม 50 %");
	scoretext.setCharacterSize(40);
	scoretext.setString(L"คะแนนวิชาไฟฟ้ากระแสสลับของคุณคือ        คะแนน");
	playerName.setFont(nameFont);
	playerName.setStyle(sf::Text::Bold);
	playerName.setCharacterSize(50);
	playerName.setOutlineColor(sf::Color::Black);
	playerName.setOutlineThickness(2);
	playerName.setPosition(sf::Vector2f(10, 10));
	
}

void playernikolastate::Update(float deltaTime, short& state, sf::Sprite& nikolabeam,bool &nikoladead, std::string& inputname)
{

	playerName.setString(inputname);
	if (playerdead == 1|| nikoladead==1) {
		playerdead = 0;
		armorcount = 0;
		//nikoladead = 0;
		std::cout << alternativeelectricsore << std::endl;
		this->healthbarlength = 200.0f;
		alternativeelectricsore = 0;
		armor.setPosition(sf::Vector2f(rand() % 1000, (rand() % 500) + 140));
		playerBody.setPosition(sf::Vector2f(50, 350));

		for (auto i = 0; i < 2; i++) {
			lightning[i].setPosition(-1000, -1000);
		}
	}

	healthbar.setSize(sf::Vector2f(healthbarlength, 20));
	sf::Vector2f playerMovement(0.0f, 0.0f);
	if (playerdead == 0) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && playerBody.getPosition().x > 0)
		{
			playerMovement.x -= speed * deltaTime;
			if (runeffect.getStatus() == sf::Sound::Status::Stopped) {
				runeffect.play();
			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && playerBody.getPosition().x < 1320)
		{
			playerMovement.x += speed * deltaTime;
			if (runeffect.getStatus() == sf::Sound::Status::Stopped) {
				runeffect.play();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && playerBody.getPosition().y > 130)
		{
			if (runeffect.getStatus() == sf::Sound::Status::Stopped) {
				runeffect.play();
			}
			playerMovement.y -= speed * deltaTime;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && playerBody.getPosition().y < 690)
		{
			playerMovement.y += speed * deltaTime;
			if (runeffect.getStatus() == sf::Sound::Status::Stopped) {
				runeffect.play();
			}
		}

		if (playerMovement.x == 0.0f && playerMovement.y == 0)
		{
			idle = true;
		}
		else {

			idle = false;
			if (playerMovement.x > 0.0f) {
				faceRight = true;
			}
			else if (playerMovement.x < 0.0f) {
				faceRight = false;
			}

		}


		playergunandrun.Update(row, deltaTime, faceRight, idle, 0, 0);

		playerBody.setTextureRect(playergunandrun.uvsprites);

		playerBody.move(playerMovement);

		playerposition.x = playerBody.getPosition().x;

		playerposition.y = playerBody.getPosition().y;
		//lightning
		srand(time(NULL));

		timeforlightningDisplay += deltaTime;
		if (timeforlightningDisplay >= 3.00f) {

			if (timeforlightningDisplay > 3.250f) {
				timeforlightningDisplay -= timeforlightningDisplay;
				//if (lightningeffect.getStatus() == sf::Sound::Status::Stopped) {
					lightningeffect.play();
			//	}
				for (auto i = 0; i < 2; i++) {
					lightningPos[i].x = rand() % 1200;
					lightningPos[i].y = (rand() % 300) + 140;
				}
			}
			else {

				for (auto i = 0; i < 2; i++) {

					lightning[i].setPosition(lightningPos[i].x, lightningPos[i].y);
				}
			}

		}
		else {
			for (auto i = 0; i < 2; i++) {
				lightning[i].setPosition(-1000, -1000);
			}
		}
		if (checkbeamhitplayer.checkcollision(playerBody, nikolabeam)) {
			if (hurteffect.getStatus() == sf::Sound::Status::Stopped) {
				hurteffect.play();
			}

			alternativeelectricsore -= 15;
			if (alternativeelectricsore < 0) {
				alternativeelectricsore = 0;
			}
			healthbarlength = (healthbarlength + playerArmor[0]) - 30;
			if (healthbarlength <= 0) {
				healthbarlength = 0;

			}
		}
		for (auto i = 0; i < 2; i++) {
			if (checkbeamhitplayer.checkcollision(playerBody, lightning[i])) {
				if (hurteffect.getStatus() == sf::Sound::Status::Stopped) {
					hurteffect.play();
				}
			
				alternativeelectricsore -= 7;
				if (alternativeelectricsore < 0) {
					alternativeelectricsore = 0;
				}
				healthbarlength = (healthbarlength + playerArmor[1]) - 10;
				if (healthbarlength <= 0) {
					healthbarlength = 0;

				}
			}
		}
		if (checkbeamhitplayer.checkcollision(playerBody, armor)) {
			if (pickeffect.getStatus() == sf::Sound::Status::Stopped) {
				pickeffect.play();
			}
			armorcount = 1;
			armor.setPosition(sf::Vector2f(-200, -200));
			playerArmor[0] = 15;
			playerArmor[1] = 5;
		}
		if (healthbarlength == 0) {
			playerdead = 1;
			state = 2;
			alternativeelectricsore -= 60;
			if (alternativeelectricsore < 0) {
				alternativeelectricsore = 0;
			}
		}
	}
	std::stringstream ss;
	ss << alternativeelectricsore;
	scoreDisplay.setString(ss.str());
	tempalternativeelectricsore = alternativeelectricsore;


	std::stringstream ss1;
	ss1 << armorcount;
	showremainarmor.setString(ss1.str());
}

void playernikolastate::draw(sf::RenderWindow& window)
{
	scoreDisplay.setPosition(sf::Vector2f((window.getSize().x / 2) + 170, 70));
	scoretext.setPosition(sf::Vector2f((window.getSize().x / 2) - 280, 70));
	guide.setPosition(sf::Vector2f((window.getSize().x / 2) - 150, 20));
	tellplayer.setPosition(10, 90);
	showremainarmor.setPosition(sf::Vector2f(320, 70));
	window.draw(nikolaBackground);
	window.draw(armor);
	if (playerdead == 0) {
		window.draw(playerBody);
	}
	
	for (auto i = 0; i < 2; i++) {
		window.draw(lightning[i]);
	}
	if (armorcount == 1) {
		window.draw(tellplayer);
	}
	window.draw(showremainarmor);
	window.draw(guide);
	window.draw(armoricon);
	window.draw(healthbar);
	window.draw(scoretext);
	window.draw(scoreDisplay);
	window.draw(playerName);

}
