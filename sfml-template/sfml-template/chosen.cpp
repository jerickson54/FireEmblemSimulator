#include "chosen.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include "fireEmblem.h"
#include <string>
#include <ctime>
#include <vector>
#include <sstream> //needed to convert from int to string


using namespace std;

chosen::chosen() {

	FireEmblem player("Archer", 28, 34, 18, 36, 7, 25, 30);
	sf::Sprite image;
	sf::Texture tex;

	

	if (!tex.loadFromFile("archer.png")) {
		cerr << "The file failed to open.";
	}

	image.setTexture(tex);


	fighter = player;
	user = image;
	
	

	




}

chosen::chosen(FireEmblem player, sf::Sprite image) {

	fighter = player;
	/*image.setTexture(tex);*/

	//the above doesnt work

	user = image;
	/*texture = tex;*/


}

void chosen::setPlayer(FireEmblem player) {

	fighter.setName(player.getName());
	fighter.setHealth(player.getHealth());
	fighter.setAttack(player.getAttack());
	fighter.setDefense(player.getDefense());
	fighter.setMagic(player.getMagic());
	fighter.setResistance(player.getResistance());
	fighter.setSkill(player.getSkill());
	fighter.setSpeed(player.getSpeed());


}

void chosen::setImage(sf::Sprite image) {

	/*image.setTexture(tex);*/
	user = image;

	//doesnt work. texture out of scope. learn better method better
}



FireEmblem chosen::getPlayer() {

	return fighter;
}



void chosen::returnPlayerOne(int selectionOne, chosen& playerOne) {

	


	

	if (selectionOne == 1) {
		FireEmblem archer("archer", 28, 34, 18, 36, 7, 25, 30);
		playerOne.setPlayer(archer);
		
		
		
		

	}

	if (selectionOne == 2) {
		FireEmblem mage("mage", 26, 10, 27, 20, 36, 33, 24);
		playerOne.setPlayer(mage);
	
		
		
		
	}
	if (selectionOne == 3) {

		FireEmblem hero("hero", 36, 36, 30, 35, 12, 18, 33);
		playerOne.setPlayer(hero);
	
		
		
	}
	if (selectionOne == 4) {

		FireEmblem goddess("goddess", 32, 12, 26, 35, 36, 30, 33);
		playerOne.setPlayer(goddess);
		
		
		
	}
	if (selectionOne == 5) {

		FireEmblem knight("knight", 40, 30, 34, 22, 0, 18, 18);
		playerOne.setPlayer(knight);
		
		
		
	}
	if (selectionOne == 6) {

		FireEmblem ninja("ninja", 30, 34, 20, 38, 0, 32, 38);
		playerOne.setPlayer(ninja);
		
		
		
	}
	if (selectionOne == 7) {

		FireEmblem berserker("berserker", 40, 36, 18, 35, 0, 15, 30);
		playerOne.setPlayer(berserker);
	
		
		

	}
	if (selectionOne == 8) {

		FireEmblem dragoon("dragoon", 40, 30, 30, 26, 30, 30, 22);
		playerOne.setPlayer(dragoon);
		
		
		
	}




}
