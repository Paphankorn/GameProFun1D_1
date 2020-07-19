#include "nikolabeam.h"

nikolabeam::nikolabeam(sf::Vector2u imageCount, float switchTime, int widthSize, int heightSize, float speed)
	:nikolabeamanimation(imageCount, switchTime, widthSize, heightSize)
{
	nikolabeamTexture.loadFromFile("spritenikolaforstate2.png");
	nikolabeamSprite.setTexture(nikolabeamTexture);
	row = 1;

		nikolabeamSprite.setTexture(nikolabeamTexture);
	nikolabeamSprite.setTextureRect(sf::IntRect(115, 70, 115, 104));
	nikolabeamanimation.uvsprites.left = 115;
	nikolabeamSprite.setPosition(sf::Vector2f(0, 2000));
	idle = false;

}

void nikolabeam::Update(float deltaTime, sf::Sprite& nikolabody, sf::Sprite playerBody, sf::Sprite* playerbulletbody, bool faceRight, bool& nikoladead)
{
	//std::cout << nikolabody.getPosition().x + 110 << std::endl;
	if (nikoladead == 0) {
		nikolabeamanimation.Update(row, deltaTime, faceRight, idle, 0, 1);

		nikolabeamSprite.setTextureRect(nikolabeamanimation.uvsprites);

		if (faceRight == 1) {
			nikolabeamSprite.setPosition(nikolabody.getPosition().x + 110, nikolabody.getPosition().y + 5);
		}
		else if (faceRight == 0) {
			if (nikolabeamanimation.currentImage.y == 1) {
				nikolabeamSprite.setPosition(nikolabody.getPosition().x - 14, nikolabody.getPosition().y + 5);
			}
			else {
				nikolabeamSprite.setPosition(nikolabody.getPosition().x - 1256, nikolabody.getPosition().y + 5);
			}
		}
		timeforshootbeam += deltaTime;
		if (nikolabeamanimation.currentImage.y == 0) {

			idle = true;

			if (timeforshootbeam >= 2.00f) {
				timeforshootbeam -= 2.00f;
				idle = false;
			}

		}


	}
	else {
		nikolabeamSprite.setPosition(sf::Vector2f(0, 2000));
	}


}

void nikolabeam::draw(sf::RenderWindow& window)
{

	window.draw(nikolabeamSprite);
}
