#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include "fireEmblem.h"
#include <string>
#include <ctime>
#include <vector>
#include <sstream> //needed to convert from int to string


using namespace std;


class chosen {

public:
	chosen(); //default constructor
	chosen(FireEmblem player, sf::Sprite image); //non-default constructor

	void setPlayer(FireEmblem player);
	void setImage(sf::Sprite image);
	

	FireEmblem getPlayer();

	void returnPlayerOne(int selectionOne,chosen& playerOne);
	

	sf::Sprite user; //needed to be public for access to draw
	FireEmblem fighter;



};