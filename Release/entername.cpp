#include "entername.h"

entername::entername()
{
	
	enterFont.loadFromFile("THSarabunNew.ttf");
	enterName.setFont(enterFont);
	enterName.setFillColor(sf::Color::Black);
	enterName.setCharacterSize(60);

	choosename.setFont(enterFont);
	choosename.setCharacterSize(60);
	choosename.setString(L"พิมพ์ชื่อ");
	cauntion.setFont(enterFont);
	cauntion.setCharacterSize(30);
	cauntion.setString(L"(ภาษาอังกฤษหรือตัวเลขเท่านั้นและพิมพ์ได้ไม่เกิน 20 ตัวอักษร พิมเว้นวรรคไม่ได้นะอิอิ)");
	cauntion.setFillColor(sf::Color::Red);

	start.setFont(enterFont);
	start.setCharacterSize(50);
	start.setString(L"เริ่มเกมส์");
	back.setFont(enterFont);
	back.setString(L"กลับสู่หน้าหลัก");
	back.setCharacterSize(40);
	enterbox.setFillColor(sf::Color::White);
	enterbox.setSize(sf::Vector2f(700, 50));
	movetext =0;

	choosemenu.loadFromFile("seletion.wav");
	chooseffect.setBuffer(choosemenu);

	entermenu.loadFromFile("selectmenu.wav");
	entereffect.setBuffer(entermenu);
}

void entername::draw(sf::RenderWindow& window)
{
	namePosition.x = ((window.getSize().x / 2) - 150) - movetext;
	namePosition.y = ((window.getSize().y / 2) - 40);
	back.setPosition((window.getSize().x / 2) - 60, window.getSize().y / 2 +150);
	enterName.setPosition(sf::Vector2f(window.getSize().x /2-200, window.getSize().y / 2 - 150));
	choosename.setPosition(sf::Vector2f((window.getSize().x / 2) - 350, window.getSize().y / 2 - 150));
	cauntion.setPosition(window.getSize().x / 2 - 200, window.getSize().y / 2 - 80);
	enterbox.setPosition(window.getSize().x / 2 -200, window.getSize().y / 2 - 130);


	start.setPosition(sf::Vector2f((window.getSize().x / 2) - 60, window.getSize().y / 2 + 50));
	enterName.setString(inputname);
	window.draw(enterbox);
	window.draw(enterName);
	window.draw(choosename);
	window.draw(cauntion);
	window.draw(start);

	while (window.pollEvent(textenter)) {
		if (textenter.type == sf::Event::EventType::TextEntered && inputname.length() < 20) {

			last_char = textenter.text.unicode;
			if (last_char >='0'&&last_char<='9'|| last_char >= 'A' && last_char <= 'Z'|| last_char >= 'a' && last_char <= 'z') {
				inputname += last_char;
		        selectmenu = 0;
				
				
			
			}
		
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && inputname.length() > 0) {
			inputname.erase(inputname.end() - 1);
			//movetext -= 4;
		}

		
mouseposition = sf::Mouse::getPosition(window);

		
	}
	window.draw(back);
}

void entername::Update(short& state,float deltaTime,short &tempscorenewton,short& tempscorenikola)
{

	start.setFillColor(sf::Color::White);
	back.setFillColor(sf::Color::White);
	//std::cout << mouseposition.x << "  " << mouseposition.y << std::endl;
	delaytime += deltaTime;
	if (delaytime >= 0.125f) {
		delaytime -= 0.125f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && selectmenu == 0)
		{
			if (entereffect.getStatus() == sf::Sound::Status::Stopped) {
				entereffect.play();
			}
			state = 2;
		
			Sleep(175);
			tempscorenewton = 0;
			tempscorenikola = 0;
			selectmenu = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && selectmenu == 1) {
			if (entereffect.getStatus() == sf::Sound::Status::Stopped) {
				entereffect.play();
			}
			state = 0;
			Sleep(175);
			selectmenu = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
			//if (chooseffect.getStatus() == sf::Sound::Status::Stopped) {
				chooseffect.play();
			//}

			selectmenu--;
			if (selectmenu < 0) {
				selectmenu = 0;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
			//if (chooseffect.getStatus() == sf::Sound::Status::Stopped) {
				chooseffect.play();
			//}
			selectmenu++;
			if (selectmenu > 1) {
				selectmenu = 1;
			}
		}


	}




	
	
	if (selectmenu == 0) {

		start.setFillColor(sf::Color(255, 100, 100));

	}
	else if (selectmenu == 1) {

		back.setFillColor(sf::Color(255, 100, 100));

	}

	
}
