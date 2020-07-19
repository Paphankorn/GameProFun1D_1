#include "Player.h"

Player::Player(sf::Vector2u imageCount, float switchTime, int widthSize, int heightSize, float speed)
	:playerrun(imageCount, switchTime, widthSize, heightSize)
{
	soundBuffer.loadFromFile("runsound.wav");
	runeffect.setVolume(10.0f);
	runeffect.setBuffer(soundBuffer);


	soundBuffer2.loadFromFile("hurt.wav");
	
	hurteffect.setBuffer(soundBuffer2);
	this->speed = speed;
	row = 0;
	idle = true;
	faceRight = true;

	playerTexture.loadFromFile("spriteforstate1.png");
	playerBody.setTexture(playerTexture);


	
	playerBody.setTextureRect(sf::IntRect(0, 0, 50, 75));

	playerrun.uvsprites.top = 0;

	playerBody.setPosition(sf::Vector2f(50, 350));

	playerposition.x = playerBody.getPosition().x +30;

	playerposition.y = playerBody.getPosition().y+50 ;

	healthbar.setFillColor(sf::Color::Red);

	healthbar.setPosition(sf::Vector2f(10, 70));
	nameFont.loadFromFile("THSarabunNew Bold.ttf");
	playerName.setFont(nameFont);

	playerName.setStyle(sf::Text::Bold);
	playerName.setCharacterSize(50);
	playerName.setOutlineColor(sf::Color::Black);
	playerName.setOutlineThickness(2);
	playerName.setPosition(sf::Vector2f(10, 10));

	scoreDisplay.setFont(nameFont);


	scoreDisplay.setCharacterSize(40);
	//scoreDisplay.setOutlineColor(sf::Color::Black);
	//scoreDisplay.setOutlineThickness(2);

	scoretext.setFont(nameFont);


	scoretext.setCharacterSize(40);
	scoretext.setString(L"คะแนนวิชาแคลคูลัสของคุณคือ       คะแนน");
	//scoretext.setOutlineColor(sf::Color::Black);
	//scoretext.setOutlineThickness(2);

	guide.setFont(nameFont);
	guide.setCharacterSize(35);
	guide.setString(L"\"กดปุ่ม Delete เพื่อออก\"");

}

void Player::Update(float deltaTime, sf::Sprite* applebullet, bool *bulletstate,short &state , std::string& playerName,bool &newtondead)
{
	tempscorenewton = score;
	if (playerdead == 1 || newtondead == 1) {
		this->healthbarlength = 200.0f;
		playerBody.setPosition(sf::Vector2f(50, 350));
		
		//score = 0;
		playerdead = 0;
	}

	this->playerName.setString(playerName);
	this->healthbar.setSize(sf::Vector2f(healthbarlength,20 ));
	
	
	sf::Vector2f playerMovement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)&& playerBody.getPosition().x>0)
	{
		playerMovement.x -= speed * deltaTime;
		if (runeffect.getStatus() == sf::Sound::Status::Stopped) {
			runeffect.play();
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& playerBody.getPosition().x < 1320)
	{
		playerMovement.x += speed * deltaTime;
		if (runeffect.getStatus() == sf::Sound::Status::Stopped) {
			runeffect.play();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&playerBody.getPosition().y > 130)
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
	playerrun.Update(row, deltaTime, faceRight, idle, 0,0);

	playerBody.setTextureRect(playerrun.uvsprites);

	playerBody.move(playerMovement);

	playerposition.x = playerBody.getPosition().x + 30;

	playerposition.y = playerBody.getPosition().y + 40;
	

	for (int i = 0; i < 3; i++) {
	if (checkapplehitplayer.checkcollision(applebullet[i], playerBody)) {
		//std::cout << healthbarlength << std::endl;
	
	
		if (hurteffect.getStatus() == sf::Sound::Status::Stopped) {
			hurteffect.play();
		}

		applebullet[i].setPosition(sf::Vector2f(-20, -20));


		healthbarlength = healthbarlength -40;
		if (score > 0) {
			score = score - 18;
			if (score < 0) {
				score = 0;
			}
		}


	}


}
	

	std::stringstream ss;
	ss << score;
	scoreDisplay.setString(ss.str());

	if (healthbarlength == 0) {
		playerBody.setTextureRect(sf::IntRect(0, 0, 0, 0));
		playerBody.setPosition(sf::Vector2f(-100, 0));
		playerdead = 1;
		state = 2;
		if (score > 0) {
			score = score-60;
			if (score < 0) {
				score == 0;
			}
		}


	}

	

}

void Player::draw(sf::RenderWindow &window)
{



	if (playerdead == 0) {
		window.draw(playerBody);
	}
	scoreDisplay.setPosition(sf::Vector2f((window.getSize().x/2)+120, 70));
	scoretext.setPosition(sf::Vector2f((window.getSize().x / 2)-230, 70));
	guide.setPosition(sf::Vector2f((window.getSize().x / 2) - 150, 20));
	window.draw(healthbar);
	window.draw(playerName);
	window.draw(scoretext);
	window.draw(scoreDisplay);
	window.draw(guide);




}
