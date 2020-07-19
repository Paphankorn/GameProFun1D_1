#include "Menu.h"

Menu::Menu()
{
	Background.loadFromFile("menubackground.png");
	backgroundsprite.setTexture(Background);
	
	MenuFont.loadFromFile("THSarabunNew Bold.ttf");
	for (auto i = 0; i < 4; i++) {
		Menuitem[i].setFont(MenuFont);
		Menuitem[i].setCharacterSize(50);
		
	}
	
	Menuitem[0].setString(L"เริ่มเกมใหม่");
	Menuitem[1].setString(L"คะแนนผลการเรียนสูงสุด 5 อันดับ");
	Menuitem[2].setString(L"วิธีเล่น");
	Menuitem[3].setString(L"ปิดเกม");

	gameName.setFont(MenuFont);
	gameName.setStyle(sf::Text::Bold);
	gameName.setString("Let's kill the Scientists!");
	gameName.setCharacterSize(80);

	myname.setFont(MenuFont);
	myname.setStyle(sf::Text::Bold);
	myname.setString(L"ปภังกร ธนโรจน์ 62010525");
	myname.setCharacterSize(30);


		howtousemenu.setFont(MenuFont);
	howtousemenu.setStyle(sf::Text::Bold);
	howtousemenu.setString(L"\"กดลูกศรขึ้นหรือลงเพื่อเลื่อนเมนูและกด Enter เพื่อเลือก\"");
	howtousemenu.setCharacterSize(30);
	
}

void Menu::draw(sf::RenderWindow& window)
{

	window.draw(backgroundsprite);
	howtousemenu.setPosition((window.getSize().x / 2), 600);
	Menuitem[0].setPosition(sf::Vector2f(window.getSize().x/2, 200));
	Menuitem[1].setPosition(sf::Vector2f(window.getSize().x / 2, 250));
	Menuitem[2].setPosition(sf::Vector2f(window.getSize().x / 2, 300));
	Menuitem[3].setPosition(sf::Vector2f(window.getSize().x / 2, 350));
	gameName.setPosition(sf::Vector2f((window.getSize().x/ 2),100));
	myname.setPosition(sf::Vector2f((window.getSize().x / 2), 650));
	window.draw(howtousemenu);
	
	for (auto i = 0; i < 4; i++) {
		window.draw(Menuitem[i]);
	}
	window.draw(gameName);
	window.draw(myname);

//	mouseposition = sf::Mouse::getPosition(window);
}

void Menu::Update(short& state,float deltaTime)
{
//	std::cout << mouseposition.x << "   " << mouseposition.y << "    "<< state <<std::endl;

	Menuitem[0].setFillColor(sf::Color::White);
	Menuitem[1].setFillColor(sf::Color::White);
	Menuitem[2].setFillColor(sf::Color::White);
	Menuitem[3].setFillColor(sf::Color::White);


	


	if (selectmenu == 0) {

		Menuitem[0].setFillColor(sf::Color(255, 100, 100));

	}
	else if (selectmenu == 1) {

		Menuitem[1].setFillColor(sf::Color(255, 100, 100));

	}
	else if (selectmenu == 2) {

		Menuitem[2].setFillColor(sf::Color(255, 100, 100));

	}
	else if (selectmenu == 3) {

		Menuitem[3].setFillColor(sf::Color(255, 100, 100));

	}


}
