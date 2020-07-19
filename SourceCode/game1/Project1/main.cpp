#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <Windows.h>
#include <fstream>
#include "Player.h"
#include "Newton.h"
#include "durianBomb.h"
#include "Menu.h"
#include "Selectstate.h"
#include "entername.h"
#include "playernikolastate.h"
#include "playerbullet.h"
#include "nikola.h"
#include "nikolabeam.h"

int main() 
{
	short state = 0;
	// Init window
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Let's kill the Scientists", sf::Style::Fullscreen);
	window.setFramerateLimit(30);
	// Init entity
	float delayTime = 0.0f;

	std::fstream playerNameandScoreWrite;

	// Init sound and music
	sf::Music musiconmenu;
	musiconmenu.openFromFile("wdan.wav");
	musiconmenu.setVolume(100.0f);
	musiconmenu.setLoop(true);

	sf::Music musiconnewton;
	musiconnewton.openFromFile("GetOnTheFloor.wav");
	musiconnewton.setVolume(50.0f);
	musiconnewton.setLoop(true);
	
	sf::Music musiconnikola;
	musiconnikola.openFromFile("pyt.wav");
	musiconnewton.setVolume(50.0f);
	musiconnewton.setLoop(true);

	
	Player playeranimation(sf::Vector2u(8, 0), 0.05f, 50, 75,200.0f);
	Newton newtonanimation(sf::Vector2u(5, 0), 0.2f, 70, 110, 100.0f);
	playernikolastate playeronnikola(sf::Vector2u(5, 0), 0.05f, 50, 70, 200.0f);
	nikola nikolaletgo(sf::Vector2u(0,1),0.05f, 115, 104, 50.0f);
	durianBomb durianfuckingbomb;
	playerbullet fuckingbullet;
	nikolabeam nikolalightbeam(sf::Vector2u(0, 4), 0.01f,0, 0, 50.0f);
	Menu mymenu;
	Selectstate choosestate;
	//highscore myscore;
	entername entername;
	sf::RectangleShape backgroundhowtoplay;
	backgroundhowtoplay.setFillColor(sf::Color::White);
	backgroundhowtoplay.setSize(sf::Vector2f(window.getSize().x,window.getSize().y));

	sf::Texture howtoplaybackgorund;
	sf::Sprite howtoplaysprite;
	howtoplaybackgorund.loadFromFile("howtoplay.png");
	howtoplaysprite.setTexture(howtoplaybackgorund);


	sf::Font font;
	if (!font.loadFromFile("THSarabunNew.ttf")) {
		std::cout << "Can\'t load font" << std::endl;
	}
	sf::Text myname;
	myname.setFont(font);
	myname.setCharacterSize(50);
	myname.setString(L"ชื่อ              คะแนน");
   sf::Text back(L"กลับสู่หน้าหลัก", font);
   back.setCharacterSize(40);
	std::ofstream fileWriter;
	sf::String playerInput;


	std::map<int, std::string> score;
	std::ifstream fileReader;

	std::string word;

	int starSpriteAnimation = 0;
	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();
		
		sf::Event myevent;
		while (window.pollEvent(myevent)) {
			if (myevent.type == sf::Event::KeyPressed && myevent.key.code==sf::Keyboard::Delete)
			{
				if (state == 3) {
					playeranimation.playerdead = 1;
					newtonanimation.newtondead = 1;
				
					state = 2;
					Sleep(300);
					
			
				}
				else if (state == 4) {
					playeronnikola.playerdead = 1;
					nikolaletgo.nikoladead = 1;
					state = 2;
					Sleep(300);
					
				}
			
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && state==5) {
				if (entername.entereffect.getStatus() == sf::Sound::Status::Stopped) {
					entername.entereffect.play();
				}
				
				state = 0;
				Sleep(300);
			
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && state == 6) {
				if (entername.entereffect.getStatus() == sf::Sound::Status::Stopped) {
					entername.entereffect.play();
				}

				state = 0;
				Sleep(300);

			}
			else if (state == 0) {
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && mymenu.selectmenu == 0)
				{
					if (entername.entereffect.getStatus() == sf::Sound::Status::Stopped) {
						entername.entereffect.play();
					}

					state = 1;
					Sleep(300);
					mymenu.selectmenu = 0;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && mymenu.selectmenu == 1) {
					if (entername.entereffect.getStatus() == sf::Sound::Status::Stopped) {
						entername.entereffect.play();
					}

					state = 5;
					Sleep(300);
					mymenu.selectmenu = 0;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && mymenu.selectmenu == 2) {
					if (entername.entereffect.getStatus() == sf::Sound::Status::Stopped) {
						entername.entereffect.play();
					}

					state = 6;
					Sleep(300);
					mymenu.selectmenu = 0;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && mymenu.selectmenu == 3) {
					if (entername.entereffect.getStatus() == sf::Sound::Status::Stopped) {
						entername.entereffect.play();
					}
					Sleep(300);
					window.close();
				}
			

				 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
					// if (entername.chooseffect.getStatus() == sf::Sound::Status::Stopped) {
						 entername.chooseffect.play();
					// }
				
					mymenu.selectmenu--;
					if (mymenu.selectmenu < 0) {
						mymenu.selectmenu = 0;
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
					// if (entername.chooseffect.getStatus() == sf::Sound::Status::Stopped) {
						 entername.chooseffect.play();
					// }
					mymenu.selectmenu++;
					if (mymenu.selectmenu > 3) {
						mymenu.selectmenu = 3;
					}
				}
			
			}

		
			else if (state == 2) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && choosestate.selectmenu == 0) {
					if (entername.entereffect.getStatus() == sf::Sound::Status::Stopped) {
						entername.entereffect.play();
					}
					state = 3;
					Sleep(300);
					choosestate.selectmenu = 0;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && choosestate.selectmenu == 1) {
					if (entername.entereffect.getStatus() == sf::Sound::Status::Stopped) {
						entername.entereffect.play();
					}
					state = 4;
					Sleep(300);
					choosestate.selectmenu = 1;
				}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && choosestate.selectmenu == 2) {
					if (entername.entereffect.getStatus() == sf::Sound::Status::Stopped) {
						entername.entereffect.play();
					}
					state = 0;
					Sleep(300);
					choosestate.selectmenu = 0;
					int playerScore = (playeranimation.tempscorenewton + playeronnikola.tempalternativeelectricsore) / 2;
					playerNameandScoreWrite.open("playerNameandScore.txt", std::ios::app);
					playerNameandScoreWrite << entername.inputname << ',' << playerScore << std::endl;
					playerNameandScoreWrite.close();
					entername.inputname.clear();
					playeranimation.tempscorenewton = 0;
					playeronnikola.tempalternativeelectricsore = 0;

				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
					//if (entername.chooseffect.getStatus() == sf::Sound::Status::Stopped) {
						entername.chooseffect.play();
					//}
					choosestate.selectmenu--;
					if (choosestate.selectmenu < 0) {
						choosestate.selectmenu = 0;
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
					//if (entername.chooseffect.getStatus() == sf::Sound::Status::Stopped) {
						entername.chooseffect.play();
					//}
					choosestate.selectmenu++;
					if (choosestate.selectmenu > 2) {
						choosestate.selectmenu = 2;
					}
				}

				

			}
			
		
			else {
				break;
			}
		}


		
		window.setMouseCursorVisible(false);
			

			window.clear();
			if (state == 0) {
				musiconnewton.stop();
				musiconnikola.stop();
				if ( musiconmenu.getStatus() == sf::Sound::Status::Stopped) {
					musiconmenu.play();
				}
	
				mymenu.Update(state,deltaTime);
				mymenu.draw(window);



			}
			

			else if (state == 1) {
				musiconnewton.stop();
				musiconnikola.stop();
				if (musiconmenu.getStatus() == sf::Sound::Status::Stopped) {
					musiconmenu.play();
				}


				entername.Update(state,deltaTime,playeranimation.tempscorenewton,playeronnikola.tempalternativeelectricsore);
				entername.draw(window);

			}
			else if (state == 2) {
				musiconnewton.stop();
				musiconnikola.stop();
				if (musiconmenu.getStatus() == sf::Sound::Status::Stopped) {
					musiconmenu.play();
				}


				choosestate.Update(state,deltaTime,entername.inputname,playeranimation.tempscorenewton, playeronnikola.tempalternativeelectricsore);
				choosestate.draw(window);

			}

			
			else if (state == 3) {
				musiconmenu.stop();
				musiconnikola.stop();
				if (musiconnewton.getStatus() == sf::Sound::Status::Stopped) {
					musiconnewton.play();
				}


			
				durianfuckingbomb.Update(deltaTime, playeranimation.faceRight, playeranimation.playerBody, newtonanimation.newtonBody, newtonanimation.newtondead,state,playeranimation.score,playeranimation.playerdead,playeranimation.healthbarlength,playeranimation.tempscorenewton);
				newtonanimation.Update(deltaTime, playeranimation.playerposition, playeranimation.playerBody, playeranimation.playerdead, playeranimation.score,playeranimation.tempscorenewton,state);
				playeranimation.Update(deltaTime, newtonanimation.applebullet, newtonanimation.bulletstate,state,entername.inputname, playeranimation.playerdead);
				
				durianfuckingbomb.draw(window);
				newtonanimation.draw(window);
				playeranimation.draw(window);
			}
			else if (state == 4) {

				

				musiconmenu.stop();
				musiconnewton.stop();
				if ( musiconnikola.getStatus() == sf::Sound::Status::Stopped) {
					musiconnikola.play();
				}
				
				playeronnikola.Update(deltaTime, state, nikolalightbeam.nikolabeamSprite,nikolaletgo.nikoladead,entername.inputname);
				
					
					
				fuckingbullet.Update(deltaTime, playeronnikola.playerBody, playeronnikola.faceRight, state,playeronnikola.playerdead,nikolaletgo.nikoladead);
				nikolaletgo.Update(deltaTime, playeronnikola.playerposition, fuckingbullet.bulletBody, state, playeronnikola.playerdead,playeronnikola.alternativeelectricsore,playeronnikola.tempalternativeelectricsore);
				
				nikolalightbeam.Update(deltaTime, nikolaletgo.nikolaBody, playeronnikola.playerBody, fuckingbullet.bulletBody, nikolaletgo.faceRight,nikolaletgo.nikoladead);

				
				playeronnikola.draw(window);
				nikolaletgo.draw(window);
				fuckingbullet.draw(window);
				nikolalightbeam.draw(window);

			}
			else if (state == 5) {
				
			
				sf::Text text;
				text.setFont(font);
				text.setCharacterSize(40);
				text.setFillColor(sf::Color::White);
				fileReader.open("playerNameandScore.txt");
			
				if(fileReader.peek() != std::ifstream::traits_type::eof() )
				{
					do {
						fileReader >> word;
						auto first_token = word.substr(0, word.find(','));
						auto second_token = std::stoi(word.substr(word.find(',') + 1, word.length()));
						score[second_token] = first_token;
					} while (fileReader.good());
					fileReader.close();

					std::map<int, std::string>::iterator end = score.end();
					std::map<int, std::string>::iterator beg = score.begin();
					end--;
					beg--;
					int currentDisplay = 0;
					for (std::map<int, std::string>::iterator it = end; it != beg; it--) {
						text.setString(it->second);
						text.setPosition(500, 250 + 40 * currentDisplay);
						window.draw(text);
						text.setString(std::to_string(it->first));
						text.setPosition(700, 250 + 40 * currentDisplay);
						window.draw(text);
						currentDisplay++;
						if (currentDisplay == 5) {
							break;
						}
					}
					currentDisplay = 0;
					myname.setPosition(500, 170);
					back.setPosition((window.getSize().x / 2) - 60, window.getSize().y / 2 + 150);
					
					
				
					
					
				}
				else {
					myname.setPosition(500, 170);
					back.setPosition((window.getSize().x / 2) - 60, window.getSize().y / 2 + 150);
				}
				back.setFillColor(sf::Color(255, 100, 100));
			
				
				
				

				window.draw(myname);
				window.draw(back);
			}
			else if (state == 6) {
			howtoplaysprite.setPosition(150, 0);
			window.draw(backgroundhowtoplay);
			window.draw(howtoplaysprite);
			back.setPosition((window.getSize().x / 2) - 100, 700);
			window.draw(back);
			back.setFillColor(sf::Color(255, 100, 100));
			
			}





		






		
			window.display();
				
	}
		return 0;
}
