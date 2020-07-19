////sprites
//sf::Sprite backgroundsprite;
//backgroundsprite.setTexture(Background);
//sf::Sprite newtonsprite;
//sf::Sprite playersprite;
//sf::Sprite appletreesprite1;
//sf::Sprite appletreesprite2;
//sf::Sprite appletreesprite3;
//sf::Sprite appletreesprite4;
//sf::Sprite durianbomb[5];
//
//std::vector<sf::Sprite> durianbombvector(5);
//	int runstate = 0;
//for (int i = 0; i < 5; i++) {
//
//
//	durianbombvector.push_back(durianbomb[i]);
//
//}
//std::vector<sf::Sprite> newtonvector(1);
//newtonvector.push_back(newtonsprite);
//
//int durianbombcount[5] = {};
//int durianbombstate[5] = {};
//
////player
//playersprite.setTexture(newtonstateTexture);
//playersprite.setTextureRect(sf::IntRect(0, 0, 40, 75));
//playersprite.setPosition(sf::Vector2f(50, 350));
//
//
////appletree
//appletreesprite1.setTexture(newtonstateTexture);
//appletreesprite2.setTexture(newtonstateTexture);
//appletreesprite3.setTexture(newtonstateTexture);
//appletreesprite4.setTexture(newtonstateTexture);
//appletreesprite1.setTextureRect(sf::IntRect(680, 0, 170, 210));
//appletreesprite1.setPosition(sf::Vector2f(400, 200));
//
//appletreesprite2.setTextureRect(sf::IntRect(680, 0, 170, 210));
//appletreesprite2.setPosition(sf::Vector2f(1000, 300));
//
//appletreesprite3.setTextureRect(sf::IntRect(680, 0, 170, 210));
//appletreesprite3.setPosition(sf::Vector2f(300, 400));
//
//appletreesprite4.setTextureRect(sf::IntRect(680, 0, 170, 210));
//appletreesprite4.setPosition(sf::Vector2f(900, 500));
//
////newton
//newtonvector[0].setTexture(newtonstateTexture);
//newtonvector[0].setTextureRect(sf::IntRect(0, 80, 65, 105));
//newtonvector[0].setPosition(sf::Vector2f(1000, 200));
//
////durianbomb
//for (int i = 0; i <= 4; i++) {
//	durianbombvector[i].setTexture(newtonstateTexture);
//}
//
//durianbombvector[0].setTextureRect(sf::IntRect(600, 0, 60, 80));
//durianbombvector[0].setPosition(sf::Vector2f(700, 200));
//
//durianbombvector[1].setTextureRect(sf::IntRect(600, 0, 60, 80));
//durianbombvector[1].setPosition(sf::Vector2f(200, 300));
//
//durianbombvector[2].setTextureRect(sf::IntRect(600, 0, 60, 80));
//durianbombvector[2].setPosition(sf::Vector2f(800, 400));
//
//durianbombvector[3].setTextureRect(sf::IntRect(600, 0, 60, 80));
//durianbombvector[3].setPosition(sf::Vector2f(650, 600));
//
//durianbombvector[4].setTextureRect(sf::IntRect(600, 0, 60, 80));
//durianbombvector[4].setPosition(sf::Vector2f(100, 550));
//playermove
//
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && playersprite.getPosition().x <= 1330) {
//	playersprite.move(sf::Vector2f(5.0f, 0));
//	if (runeffect.getStatus() == sf::Sound::Status::Stopped) {
//		runeffect.play();
//	}
//	if (runstate == 300) {
//
//		playersprite.setTextureRect(sf::IntRect(runstate, 0, 40, 70));
//		runstate = 50;
//
//	}
//	else {
//		playersprite.setTextureRect(sf::IntRect(runstate, 0, 40, 70));
//
//		runstate = runstate + 50;
//	}
//
//}
//
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && playersprite.getPosition().x >= 0) {
//	if (runeffect.getStatus() == sf::Sound::Status::Stopped) {
//		runeffect.play();
//	}
//	playersprite.move(sf::Vector2f(-5.0f, 0));
//	if (runstate == 300) {
//
//		playersprite.setTextureRect(sf::IntRect(runstate, 0, -40, 70));
//		runstate = 50;
//
//	}
//	else {
//		playersprite.setTextureRect(sf::IntRect(runstate, 0, -40, 70));
//		runstate = runstate + 50;
//	}
//
//}
//
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && playersprite.getPosition().y <= 700) {
//	playersprite.move(sf::Vector2f(0, 5.0f));
//	if (runeffect.getStatus() == sf::Sound::Status::Stopped) {
//		runeffect.play();
//	}
//	if (runstate == 300) {
//
//		playersprite.setTextureRect(sf::IntRect(runstate, 0, 40, 70));
//		runstate = 50;
//
//	}
//	else {
//		playersprite.setTextureRect(sf::IntRect(runstate, 0, 40, 70));
//		runstate = runstate + 50;
//	}
//}
//
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && playersprite.getPosition().y >= 125) {
//	playersprite.move(sf::Vector2f(0, -5.0f));
//	if (runeffect.getStatus() == sf::Sound::Status::Stopped) {
//		runeffect.play();
//	}
//	if (runstate == 300) {
//
//		playersprite.setTextureRect(sf::IntRect(runstate, 0, 40, 70));
//		runstate = 50;
//
//	}
//	else {
//		playersprite.setTextureRect(sf::IntRect(runstate, 0, 40, 70));
//		runstate = runstate + 50;
//	}
//}
//
//
//if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
//
//	runstate = 0;
//
//	playersprite.setTextureRect(sf::IntRect(runstate, 0, 40, 70));
//}
//
////check hit newton
//
//if (playersprite.getGlobalBounds().intersects(newtonvector[0].getGlobalBounds())) {
//
//	newtonvector.erase(newtonvector.begin());
//
//}
//
//
////checkhitdurian
//
//
//for (int i = 0; i <= 4; i++) {
//	if (playersprite.getGlobalBounds().intersects(durianbombvector[i].getGlobalBounds())) {
//
//		durianbombvector.erase(durianbombvector.begin() + i);
//
//		durianbombcount[i] = 1;
//	}
//}
//
////playershootbomb
//for (int i = 0; i <= 4; i++) {
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace) && durianbombcount[i] == 1) {
//		durianbomb[i].setTextureRect(sf::IntRect(600, 0, 60, 80));
//
//		durianbomb[i].setPosition(sf::Vector2f(playersprite.getPosition().x, playersprite.getPosition().y));
//		durianbombstate[i] = 1;
//		durianbombcount[i] = 0;
//		break;
//	}
//
//}
//
//for (int i = 0; i <= 4; i++) {
//	if (durianbombstate[i] == 1) {
//
//		durianbomb[i].move(sf::Vector2f(5.0f, 0));
//	}
//
//}
//
//window.draw(appletreesprite1);
//window.draw(appletreesprite2);
//window.draw(appletreesprite3);
//window.draw(appletreesprite4);
//window.draw(newtonvector[0]);
//for (int i = 0; i <= 4; i++) {
//	window.draw(durianbombvector[i]);
//}