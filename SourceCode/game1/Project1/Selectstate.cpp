#include "Selectstate.h"

Selectstate::Selectstate()
{

	stateFont.loadFromFile("THSarabunNew.ttf");
	for (int i = 0; i < 2; i++) {
		stateName[i].setFont(stateFont);
		stateName[i].setCharacterSize(50);
	}
	stateName[0].setString(L"วิชาแคลคูลัส");
	stateName[1].setString(L"วิชาไฟฟ้ากระแสสลับ");

	select.setFont(stateFont);
	select.setString(L"เลือกด่าน");
	select.setStyle(sf::Text::Bold);
	select.setCharacterSize(50);

	back.setFont(stateFont);
	back.setString(L"กลับสู่หน้าหลัก");
	back.setCharacterSize(40);

	totalscore.setFont(stateFont);

	totalscore.setCharacterSize(40);

resultscore.setFont(stateFont);
resultscore.setCharacterSize(40);

resultscore.setString(L"คะแนนผลการเรียน        คะแนน");

	nikolascore.setFont(stateFont);
	
	nikolascore.setCharacterSize(40);
	scoretext.setFont(stateFont);

	scoretext.setCharacterSize(40);
	scoretext.setString(L"ได้       คะแนน");

	
	playerName.setFont(stateFont);

	playerName.setCharacterSize(40);
	

	newtonscore.setFont(stateFont);

	newtonscore.setCharacterSize(40);
	
	statetexture[0].loadFromFile("newtonstate.png");
	statepicture[0].setTexture(statetexture[0]);

	statetexture[1].loadFromFile("nikolastate.png");
	statepicture[1].setTexture(statetexture[1]);


	statepicture[0].setPosition(sf::Vector2f(100,200));
	statepicture[1].setPosition(sf::Vector2f(100, 200));
}

void Selectstate::draw(sf::RenderWindow& window)
{
	stateName[0].setPosition((window.getSize().x / 2), (window.getSize().y / 2)-150);
	stateName[1].setPosition((window.getSize().x / 2), (window.getSize().y / 2) - 50);
	select.setPosition((window.getSize().x/2) - 100, 100);
	
	
	
	playerName.setPosition(100, window.getSize().y / 2 + 140);
	
	totalscore.setPosition(330, window.getSize().y / 2 + 180 );
	resultscore.setPosition(100, window.getSize().y / 2 + 180);
	window.draw(playerName);
	window.draw(totalscore);
	window.draw(resultscore);
	if(selectmenu==0){
		newtonscore.setPosition((window.getSize().x / 2) + 345, (window.getSize().y / 2) - 140);
		scoretext.setPosition((window.getSize().x / 2) + 300, (window.getSize().y / 2) - 140);
		window.draw(statepicture[0]);
		window.draw(newtonscore);
		window.draw(scoretext);
	}
	else if (selectmenu == 1) {
		nikolascore.setPosition((window.getSize().x / 2) + 345, (window.getSize().y / 2) - 40);
		scoretext.setPosition((window.getSize().x / 2) + 300, (window.getSize().y / 2) - 40);
		window.draw(statepicture[1]);
		window.draw(nikolascore);
		window.draw(scoretext);
	}
	window.draw(stateName[0]);
	window.draw(stateName[1]);
	
	
	window.draw(select);
	window.draw(back);
	mouseposition = sf::Mouse::getPosition(window);
	back.setPosition((window.getSize().x / 2)-100, (window.getSize().y / 2)+250);
}

void Selectstate::Update(short& state,float deltaTime, std::string& inputname,short &score,short & alternativeelectricsore)
{
	playerName.setString(inputname);
	//std::cout << score << "    " << alternativeelectricsore << std::endl;
	playerScore = (score + alternativeelectricsore) / 2;
	//std::cout << mouseposition.x << "   " << mouseposition.y << "    " << state << std::endl;
	stateName[0].setFillColor(sf::Color::White);
	stateName[1].setFillColor(sf::Color::White);
	back.setFillColor(sf::Color::White);

	if (selectmenu == 0) {

		stateName[0].setFillColor(sf::Color(255, 100, 100));


	}
	else if (selectmenu == 1) {

		stateName[1].setFillColor(sf::Color(255, 100, 100));

	}
	else if (selectmenu == 2) {

		back.setFillColor(sf::Color(255, 100, 100));

	}
	std::stringstream ss1;
	std::stringstream ss2;
	ss1 << alternativeelectricsore;
	nikolascore.setString(ss1.str());
	ss2 << score;
	newtonscore.setString(ss2.str());
	std::stringstream ss3;
	ss3 << playerScore;
	totalscore.setString(ss3.str());
		
}
