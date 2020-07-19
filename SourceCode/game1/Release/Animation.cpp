#include "Animation.h"
#include <iostream>



Animation::Animation(sf::Vector2u imageCount, float switchTime, int widthSize, int heightSize)
{
	beambuff.loadFromFile("beamsound.wav");
	beamshoot.setBuffer(beambuff);
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;
	
	uvsprites.width = widthSize;
	uvsprites.height = heightSize;

	nikolatimegunanimtion = 0.0f;

}

Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime, bool faceRight, bool idle, bool checknewton, bool checknikolabeam)
{
	//currentImage.x = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		if (checknikolabeam == 1) {
			
			if (currentImage.y >= imageCount.y) {
	
				currentImage.y = 0;


			}
			else if (idle == false) {
				currentImage.y++;
				
			}

			else if (idle == true) {

				currentImage.y = 0;

			}

		}
		



	
		//newton and player use this
		else {

			if (currentImage.x >= imageCount.x) {
				currentImage.x = 1;


			}
			else if (idle == false) {
				currentImage.x++;

			}

			else if (idle == true) {

				currentImage.x = 0;

			}

		}


	}


	if (checknikolabeam == 1) {
	
		if (faceRight) {

			if (currentImage.y == 0) {


				uvsprites.width = 0;
				uvsprites.left = 0;
				uvsprites.top = 0;
				uvsprites.height = 0;
			}


			else if (currentImage.y == 1) {

				uvsprites.width = 14;
				uvsprites.height = 69;
				uvsprites.left = 110;
				uvsprites.top = 178.5;

			}
			else if (currentImage.y == 2) {

				uvsprites.width = 1256;
				uvsprites.height = 69;
				uvsprites.left = 110;
				uvsprites.top = 280.5;
				if (beamshoot.getStatus() == sf::Sound::Status::Stopped) {
					beamshoot.play();
				}
			}
			else if (currentImage.y == 3) {

				uvsprites.width = 1256;
				uvsprites.height = 69;
				uvsprites.left = 110;
				uvsprites.top = 383;

			}
			else if (currentImage.y == 4) {

				uvsprites.width = 1256;
				uvsprites.height = 69;

				uvsprites.left = 110;
				uvsprites.top = 490;
				
			}
		}
	
	else {
		if (currentImage.y == 0) {
			uvsprites.width = 0;
			uvsprites.left = 0;
			uvsprites.top = 0;
			uvsprites.height = 0;

		}
		else if (currentImage.y == 1) {
			uvsprites.width = -14;
			uvsprites.height = 69;
			uvsprites.left = 124;
			uvsprites.top = 178.5;

		}
		else if (currentImage.y == 2) {

			if (beamshoot.getStatus() == sf::Sound::Status::Stopped) {
				beamshoot.play();
			}

			uvsprites.width = -1256;;
			uvsprites.height = 69;
			uvsprites.left =1366;
			uvsprites.top = 280.5;
		}
		else if (currentImage.x == 3) {

			uvsprites.width = -1256;
			uvsprites.height = 69;
			uvsprites.left = 1366;
			uvsprites.top = 383;

		
	

		}
		else if (currentImage.y == 4) {


			uvsprites.width = -1256;
			uvsprites.height = 69;
			uvsprites.left = 1366;
			uvsprites.top = 490;
			
		}

	}

}
		else if (checknewton == 1) {
			if (faceRight) {

				if (currentImage.x == 0) {
					uvsprites.width = 70;

					uvsprites.left = 0;
				}
				else if (currentImage.x == 1) {
					uvsprites.width = 80;

					uvsprites.left = 70;

				}
				else if (currentImage.x == 2) {
					uvsprites.width = 110;

					uvsprites.left = 150;
				}
				else if (currentImage.x == 3) {
					uvsprites.width = 120;

					uvsprites.left = 260;

				}
				else if (currentImage.x == 4) {
					uvsprites.width = 80;

					uvsprites.left = 380;
				}

			}
			else {
				if (currentImage.x == 0) {
					uvsprites.width = -70;

					uvsprites.left = 70;
				}
				else if (currentImage.x == 1) {
					uvsprites.width = -80;

					uvsprites.left = 150;

				}
				else if (currentImage.x == 2) {
					uvsprites.width = -110;

					uvsprites.left = 260;
				}
				else if (currentImage.x == 3) {
					uvsprites.width = -120;

					uvsprites.left = 380;

				}
				else if (currentImage.x == 4) {
					uvsprites.width = -80;

					uvsprites.left = 460;
				}

			}
		}
		else {
			if (faceRight) {

				uvsprites.width = abs(uvsprites.width);
				uvsprites.left = currentImage.x * uvsprites.width;

			}
			else {
				uvsprites.width = -abs(uvsprites.width);

				uvsprites.left = (currentImage.x + 1) * abs(uvsprites.width);

			}
		}

	

}




