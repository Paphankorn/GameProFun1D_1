#include "nikola.h"

nikola::nikola(sf::Vector2u imageCount, float switchTime, int widthSize, int heightSize, float speed)

{
	this->speed = speed;
	row = 1;
	idle = false;
	faceRight = true;
	nikolaTexture.loadFromFile("spritenikolaforstate2.png");
	nikolaBody.setTexture(nikolaTexture);
	nikolaBody.setTextureRect(sf::IntRect(0, 70, 115, 104));
	healthbar.setFillColor(sf::Color::Red);
	nikolaBody.setPosition(sf::Vector2f(1000, 600));
	nameFont.loadFromFile("THSarabunNew Bold.ttf");
	nikolaname.setFont(nameFont);
	nikolaname.setString("Nikola Tesla");
	nikolaname.setStyle(sf::Text::Bold);
	nikolaname.setCharacterSize(50);
	nikolaname.setOutlineColor(sf::Color::Black);
	nikolaname.setOutlineThickness(2);

	
}

void nikola::Update(float deltaTime, sf::Vector2f playerpositon , sf::Sprite* playerbullet, short& state, bool& playerdead, short& alternativeelectricsore,short& tempalternativeelectricsore)

{


	if (playerdead == 1 || nikoladead == 1) {
		std::cout << alternativeelectricsore << std::endl;
		//playerdead = 0;
		nikoladead = 0;
		
		
		alternativeelectricsore = 0;
		this->healthbarlength = 200.00f;
		nikolaBody.setPosition(sf::Vector2f(1000, 600));
	
	
	}
	healthbar.setSize(sf::Vector2f(healthbarlength, 20));
	
	if (nikoladead == 0) {
		idle = false;
		sf::Vector2f nikolaMovement(0.0f, 0.0f);
		//std::cout << idle << std::endl;
		nikolaposition.x = nikolaBody.getPosition().x;
		nikolaposition.y = nikolaBody.getPosition().y+20;


		if (nikolaposition.x >= playerpositon.x + 1000) {
			nikolaMovement.x -= speed * deltaTime;



		}

		if (nikolaposition.x + 1000 <= playerpositon.x) {
			nikolaMovement.x += speed * deltaTime;

		}

		if (nikolaposition.y > playerpositon.y + 5) {
			nikolaMovement.y -= speed * deltaTime;


		}
		if (nikolaposition.y + 5 < playerpositon.y) {
			nikolaMovement.y += speed * deltaTime;


		}
		if (nikolaMovement.x > 0.0f || playerpositon.x > nikolaposition.x) {
			faceRight = true;

			nikolaBody.setTextureRect(sf::IntRect(0, 70, 115, 104));

		}
		else if (nikolaMovement.x < 0.0f || playerpositon.x < nikolaposition.x) {
			faceRight = false;
		
			nikolaBody.setTextureRect(sf::IntRect(115, 70, -115, 104));
		}
		nikolaBody.move(nikolaMovement);
		for (auto i = 0; i < 10; i++) {

			if(checknikolahit.checkcollision(playerbullet[i], nikolaBody)) {
				playerbullet[i].setPosition(15000, -300);
				alternativeelectricsore += 10;
			
				healthbarlength = healthbarlength - 20;
				
					if (this->healthbarlength <= 0) {
						this->healthbarlength=0;
					}
					if (this->healthbarlength == 0) {
						nikoladead = 1;
						
						state = 2;
					}
				
					
					
					
					
						
					
				
			}

		}
		
		if (alternativeelectricsore > 100) {
			alternativeelectricsore = 100;
		}


	}
	tempalternativeelectricsore = alternativeelectricsore;

}

void nikola::draw(sf::RenderWindow& window)
{
	if (nikoladead == 0) {
		window.draw(nikolaBody);

	}
	nikolaname.setPosition(sf::Vector2f(window.getSize().x - 220, 10));
	healthbar.setPosition(sf::Vector2f(window.getSize().x - 210, 70));
	window.draw(healthbar);
	window.draw(nikolaname);

}
