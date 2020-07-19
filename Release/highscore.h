#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>

class highscore
{
public:
	highscore();
	void Update();
	void draw(sf::RenderWindow& window);

private:
	std::ifstream highscoreReader;
	std::map<int, std::string> score;
	std::string word;
	sf::Text text;
	sf::Font font;
	float myscore;
	std::string playername;


};

