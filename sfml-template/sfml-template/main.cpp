
/* Fire Emblem Time!!
*
* For reference stats using non-default constructor are
*	HP	Attack	Defense		 Skill		Magic	Resistance	Speed
*	Scale between 0 - 40 for all stats
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include "fireEmblem.h"
#include "chosen.h"
#include <string>
#include <ctime>
#include <vector>
#include <sstream> //needed to convert from int to string


using namespace std;


void displayStats(); //displays stats for all the fighters


//Attacking Functions
//The first word in the function name is the attacker attack type
//after the VS the next word is defending type
//ex AttackVSAttack means attacking with physical Attack and defending against an opponent using the attack stat
void AttackVSAttack(FireEmblem& you, FireEmblem& opponent);
void AttackVSMagic(FireEmblem& you, FireEmblem& opponent);
void MagicVSAttack(FireEmblem& you, FireEmblem& opponent);
void MagicVSMagic(FireEmblem& you, FireEmblem& opponent);

//these variables carry your selected units
int selectionOne = 1;
int selectionTwo = 1 ;
int selectionThree = 1;

//classes
FireEmblem archer("Archer", 28, 34, 18, 36, 7, 25, 30);

FireEmblem mage("Mage", 26, 10, 27, 20, 36, 33, 24);

FireEmblem hero("Hero", 36, 36, 30, 35, 12, 18, 33);

FireEmblem goddess("Goddess", 32, 12, 26, 35, 36, 30, 33);

FireEmblem knight("Knight", 40, 30, 34, 22, 0, 18, 18);

FireEmblem ninja("Ninja", 30, 34, 20, 38, 0, 32, 38);

FireEmblem berserker("Viking", 40, 36, 18, 35, 0, 15, 30);

FireEmblem dragoon("Dragoon", 40, 30, 30, 26, 30, 30, 22);


//the sfml window functions
void MainMenu();
void selectionMenu(int& selectionOne, int& selectionTwo, int& selectionThree);
void battleTime();


int main() {

	srand(time(0));

	
	/*gettingStarted(allClasses);
	AttackVSMagic(dragoon,mage);
	AttackVSMagic(dragoon, mage);
	AttackVSMagic(dragoon, mage);*/


	//
	MainMenu();

	return 0;
}


void displayStats() {

	sf::RenderWindow stats(sf::VideoMode(640, 640), "Stats");
	sf::Font font;
	sf::Event event;
	sf::Text greeting("Welcome to the Battle Arena of Regna Ferox!", font);
	greeting.setCharacterSize(24);
	greeting.setPosition(sf::Vector2f(22, 0));
	int columns = 75;

	sf::Text backToMenu("Main Menu", font);
	backToMenu.setPosition(sf::Vector2f(255, 600));
	backToMenu.setCharacterSize(25);
	

	sf::Text heading;
	heading.setPosition(sf::Vector2f(5, 50));
	heading.setCharacterSize(18);



	if (!font.loadFromFile("data/capture.ttf")) {
		cerr << "The font could not be found.";

	}

	while (stats.isOpen()) {

		stringstream header; //string buffer to convert number to a string
		header << "Name" << "\t"  <<"   " << "HP" << "\t" << "Attack" << "\t" << "Defense" << "\t" << "Skill" << "\t" << "Magic" << "\t" << "Resistance" << "\t" << "Speed";

		

		stringstream battleStats[8];
		vector <FireEmblem> allClasses;
		allClasses.push_back(archer);
		allClasses.push_back(mage);
		allClasses.push_back(hero);
		allClasses.push_back(goddess);
		allClasses.push_back(knight);
		allClasses.push_back(ninja);
		allClasses.push_back(berserker);
		allClasses.push_back(dragoon);

		



		for (int i = 0; i < allClasses.size(); ++i) {

	
			
			
			battleStats[i] << allClasses.at(i).getName() << "\t" << allClasses.at(i).getHealth() << "\t" << "\t" << allClasses.at(i).getAttack() << "\t" << "\t" << "\t" << allClasses.at(i).getDefense() << "\t" << "\t" << "\t" << "\t" << allClasses.at(i).getSkill() << "\t" << "\t" << "\t" << allClasses.at(i).getMagic() << "\t" << "\t" << "\t" << "\t" << allClasses.at(i).getResistance() << "\t" << "\t" << "\t" << "\t" << allClasses.at(i).getSpeed();
			

		}


		
		sf::Text stat1;
		sf::Text stat2;
		sf::Text stat3;
		sf::Text stat4;
		sf::Text stat5;
		sf::Text stat6;
		sf::Text stat7;
		sf::Text stat8;

		stat1.setFont(font);
		stat1.setCharacterSize(18);
		stat1.setString(battleStats[0].str());
		stat1.setPosition(sf::Vector2f(5, 100));

		stat2.setFont(font);
		stat2.setCharacterSize(18);
		stat2.setString(battleStats[1].str());
		stat2.setPosition(sf::Vector2f(5, 150));

		stat3.setFont(font);
		stat3.setCharacterSize(18);
		stat3.setString(battleStats[2].str());
		stat3.setPosition(sf::Vector2f(5, 200));

		stat4.setFont(font);
		stat4.setCharacterSize(18);
		stat4.setString(battleStats[3].str());
		stat4.setPosition(sf::Vector2f(5, 250));

		stat5.setFont(font);
		stat5.setCharacterSize(18);
		stat5.setString(battleStats[4].str());
		stat5.setPosition(sf::Vector2f(5, 300));

		stat6.setFont(font);
		stat6.setCharacterSize(18);
		stat6.setString(battleStats[5].str());
		stat6.setPosition(sf::Vector2f(5, 350));

		stat7.setFont(font);
		stat7.setCharacterSize(18);
		stat7.setString(battleStats[6].str());
		stat7.setPosition(sf::Vector2f(5, 400));

		stat8.setFont(font);
		stat8.setCharacterSize(18);
		stat8.setString(battleStats[7].str());
		stat8.setPosition(sf::Vector2f(5, 450));



		heading.setFont(font);
		heading.setString(header.str());

		
		

		while (stats.pollEvent(event)) {

			backToMenu.setColor(sf::Color(0, 0, 128));

			sf::Vector2i localPosition = sf::Mouse::getPosition(stats);

			if (event.type == sf::Event::MouseButtonPressed) {

				//put if statements below regarding main menu button

	

					if (event.mouseButton.x > 255 && event.mouseButton.x < 345 && event.mouseButton.y >600 && event.mouseButton.y < 630)
					{
					
						stats.close();

					}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				stats.close(); //closes the window if escaped is pressed
			}

			if ((localPosition.x >= 255) && (localPosition.x <= 345) && (localPosition.y >= 600) && (localPosition.y <= 630)) {
				backToMenu.setColor(sf::Color(0, 255, 128));

			}





		}
		
		stats.draw(stat1);
		stats.draw(stat2);
		stats.draw(stat3);
		stats.draw(stat4);
		stats.draw(stat5);
		stats.draw(stat6);
		stats.draw(stat7);
		stats.draw(stat8);

		stats.draw(greeting);
		stats.draw(backToMenu);
		stats.draw(heading);
		stats.display();
		stats.clear();





	}


	

}

void AttackVSAttack(FireEmblem& you, FireEmblem& opponent) {


	cout << "Here are your starting stats: " << endl;
	cout << you.getName() <<" health: " << you.getHealth() << endl;
	cout << opponent.getName() << " health: " << opponent.getHealth() << endl << endl;

	you.attackingPhysical(opponent);
	cout << you.getName() << " health: " << you.getHealth() << endl;
	cout << opponent.getName() << " health: " << opponent.getHealth() << endl << endl;
	cout << endl;


	if (opponent.getHealth() >= 0) {
		you.defendingPhysical(opponent);
		cout << you.getName() << " health: " << you.getHealth() << endl;
		cout << opponent.getName() << " health: " << opponent.getHealth() << endl << endl;
	}



}

void AttackVSMagic(FireEmblem& you, FireEmblem& opponent) {


	cout << "Here are your starting stats: " << endl;
	cout << you.getName() << " health: " << you.getHealth() << endl;
	cout << opponent.getName() << " health: " << opponent.getHealth() << endl << endl;

	you.attackingPhysical(opponent);
	cout << you.getName() << " health: " << you.getHealth() << endl;
	cout << opponent.getName() << " health: " << opponent.getHealth() << endl << endl;
	cout << endl;

	if (opponent.getHealth() >= 0) {
		you.defendingMagic(opponent);
		cout << you.getName() << " health: " << you.getHealth() << endl;
		cout << opponent.getName() << " health: " << opponent.getHealth() << endl << endl;
	}



}

void MagicVSAttack(FireEmblem& you, FireEmblem& opponent) {


	cout << "Here are your starting stats: " << endl;
	cout << you.getName() << " health: " << you.getHealth() << endl;
	cout << opponent.getName() << " health: " << opponent.getHealth() << endl << endl;

	you.attackingMagic(opponent);
	cout << you.getName() << " health: " << you.getHealth() << endl;
	cout << opponent.getName() << " health: " << opponent.getHealth() << endl << endl;
	cout << endl;


	if (opponent.getHealth() >= 0) {
		you.defendingPhysical(opponent);
		cout << you.getName() << " health: " << you.getHealth() << endl;
		cout << opponent.getName() << " health: " << opponent.getHealth() << endl << endl;
	}



}

void MagicVSMagic(FireEmblem& you, FireEmblem& opponent) {


	cout << "Here are your starting stats: " << endl;
	cout << you.getName() << " health: " << you.getHealth() << endl;
	cout << opponent.getName() << " health: " << opponent.getHealth() << endl << endl;

	you.attackingMagic(opponent);
	cout << you.getName() << " health: " << you.getHealth() << endl;
	cout << opponent.getName() << " health: " << opponent.getHealth() << endl << endl;
	cout << endl;

	if (opponent.getHealth() >= 0) {
		you.defendingMagic(opponent);
		cout << you.getName() << " health: " << you.getHealth() << endl;
		cout << opponent.getName() << " health: " << opponent.getHealth() << endl << endl;
	}



}

void MainMenu() {

	


	sf::RenderWindow window(sf::VideoMode(640, 640), "Main Menu");
	sf::Font font;
	sf::Text FireEmblem("Fire Emblem", font);
	sf::Text Start("Start", font);
	sf::Text Exit("Exit", font);
	

	sf::Music ThemeSong;
	sf::Event event;

	sf::Sprite logo;
	sf::Texture logoTex;

	if (!ThemeSong.openFromFile("AMALEEthemesong.wav")) {
		cerr << "The file could not be found.";

	}

	if (!font.loadFromFile("data/capture.ttf")) {
		cerr << "The font could not be found.";

	}

	if (!logoTex.loadFromFile("fireEmblem.png")) {
		cerr << "The file failed to open.";
	}
	logo.setTexture(logoTex);


	

	
	Start.setPosition(sf::Vector2f(120, 600));
	Exit.setPosition(sf::Vector2f(450, 600));
	

	


	ThemeSong.play();
	ThemeSong.setLoop(true);

	while (window.isOpen())
	{
		

		while (window.pollEvent(event)) {

			sf::Vector2i localPosition = sf::Mouse::getPosition(window);
			//creates a variable localPosition of type vector2i and sets to mouse location

			Start.setColor((sf::Color(0, 0, 128)));
			Exit.setColor(sf::Color(0, 0, 128));
			

			if (event.type == sf::Event::MouseButtonPressed) {

				if (event.mouseButton.x > 120 && event.mouseButton.x < 180 && event.mouseButton.y >600 && event.mouseButton.y < 630)
				{
					window.close();
					    selectionMenu(selectionOne, selectionTwo, selectionThree);
						

				}
				if (event.mouseButton.x > 450 && event.mouseButton.x < 500 && event.mouseButton.y >600 && event.mouseButton.y < 630)
				{
					window.close();
				}
				

			}

			if ((localPosition.x >= 120) && (localPosition.x <= 180) && (localPosition.y >= 600) && (localPosition.y <= 630)) {
				Start.setColor(sf::Color(0, 255, 128));

			}
			else if ((localPosition.x >= 450) && (localPosition.x <= 500) && (localPosition.y >= 600) && (localPosition.y <= 630))
			{
				Exit.setColor(sf::Color(0, 255, 128));
			}
			
			

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close(); //closes the windowif escaped is pressed
			}
		}

		
		window.draw(logo);
		
		window.draw(Start);
		window.draw(Exit);
		
		window.display();

	}

}

void selectionMenu(int& selectionOne, int& selectionTwo, int& selectionThree) {


	sf::RenderWindow selection(sf::VideoMode(640, 640), "Team Selection");
	sf::Font font;

	bool readyToStart = false;
	int confirmCounter = 0;

	sf::Text archer("Archer", font);
	sf::Text mage("Mage", font);
	sf::Text hero("Hero",font);
	sf::Text goddess("Goddess", font);
	sf::Text knight("Knight", font);
	sf::Text ninja("Ninja", font);
	sf::Text berserker("Viking", font);
	sf::Text dragoon("Dragoon", font);
	sf::Text detail("Select three units!", font);
	sf::Text ok("Confirm", font);
	sf::Text remove("Delete", font);
	sf::Text toBattle("Start", font);

	sf::Text Stats("Class Stats", font);
	Stats.setPosition(sf::Vector2f(227, 565));

	sf::Text ready("Ready to Fight!", font);

	detail.setPosition(sf::Vector2f(200, 0));
	

	ok.setPosition(sf::Vector2f(120, 600));
	remove.setPosition(sf::Vector2f(440, 600));

	//used for flame animation

	enum flame{standard};
	sf::Vector2i source(1, standard);

	sf::Sprite flames;
	sf::Sprite flames2;
	sf::Sprite flames3;
	sf::Texture flamesTex;

	if (!flamesTex.loadFromFile("flames.png")) {
		cerr << "The file failed to open.";
	}
	sf::Texture flamesInvert;
	if (!flamesInvert.loadFromFile("flamesInvert.png")) {
		cerr << "The file failed to open.";
	}

	flames.setTexture(flamesTex);
	flames2.setTexture(flamesTex);
	flames3.setTexture(flamesTex);
	


	

	//first column
	archer.setPosition(sf::Vector2f(50, 225));
	mage.setPosition(sf::Vector2f(180, 225));
	hero.setPosition(sf::Vector2f(333, 225));
	goddess.setPosition(sf::Vector2f(450, 225));

	//second column
	knight.setPosition(sf::Vector2f(50, 400));
	ninja.setPosition(sf::Vector2f(180, 400));
	berserker.setPosition(sf::Vector2f(333, 400));
	dragoon.setPosition(sf::Vector2f(450, 400));

	toBattle.setPosition(sf::Vector2f(280, 500));
	toBattle.setColor(sf::Color(0, 0, 128));


	sf::Music start;
	sf::Event event;
	



	sf::Sprite classes;
	sf::Texture classestex;

	if (!font.loadFromFile("data/capture.ttf")) {
		cerr << "The font could not be found.";

	}

	if (!start.openFromFile("start.wav")) {
		cerr << "The file could not be found.";

	}

	if (!classestex.loadFromFile("classes.png")) {
		cerr << "The file failed to open.";
	}

	classes.setTexture(classestex);
	classes.setPosition(sf::Vector2f(0, 100));

	//needed for frame counter
	sf::Clock clock;
	float frameSpeed = 1000, frameCounter = 0, frameSwitch = 75;

	flames.setPosition(sf::Vector2f(80, 180));
	flames2.setPosition(sf::Vector2f(55, 180));
	flames3.setPosition(sf::Vector2f(105, 180));

	while (selection.isOpen()) {

		
		frameCounter += frameSpeed * clock.restart().asSeconds();
		//frame counter
		if (frameCounter >= frameSwitch)
		{

			frameCounter = 0;

			//cycles the images for the flame
			source.x++; //sets source.x = 2
			if (source.x * 28 >= flamesTex.getSize().x)
				source.x = 0; //cycling images


		}


		while (selection.pollEvent(event)) {
			sf::Vector2i localPosition = sf::Mouse::getPosition(selection);
			//creates a variable localPosition of type vector2i and sets to mouse location

			
		

			archer.setColor((sf::Color(0, 0, 128)));
			mage.setColor(sf::Color(0, 0, 128));
			hero.setColor(sf::Color(0, 0, 128));
			goddess.setColor(sf::Color(0, 0, 128));
			knight.setColor(sf::Color(0, 0, 128));
			ninja.setColor(sf::Color(0, 0, 128));
			berserker.setColor(sf::Color(0, 0, 128));
			dragoon.setColor(sf::Color(0, 0, 128));
			toBattle.setColor(sf::Color(255, 0, 255));

			ok.setColor(sf::Color(0, 255, 0));
			remove.setColor(sf::Color(0, 255, 0));

			Stats.setColor(sf::Color(0, 0, 128));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				selection.close(); //closes the windowif escaped is pressed
			}


			if (event.type == sf::Event::MouseButtonPressed) {

				if (event.mouseButton.x > 50 && event.mouseButton.x < 140 && event.mouseButton.y >100 && event.mouseButton.y < 260)
				{
					//cout << "archer" << endl;

					if (confirmCounter == 0) {
						flames.setPosition(sf::Vector2f(80, 180));
						selectionOne = 1;
					}
					if (confirmCounter == 1) {
						flames2.setPosition(sf::Vector2f(55, 180));
						selectionTwo = 1;
					}
					if (confirmCounter == 2) {
						flames3.setPosition(sf::Vector2f(105, 180));
						selectionThree = 1;
					}
					

				}

				if (event.mouseButton.x > 180 && event.mouseButton.x < 260 && event.mouseButton.y >100 && event.mouseButton.y < 260)
				{
					//cout << "mage" << endl;

					if (confirmCounter == 0) {
						flames.setPosition(sf::Vector2f(220, 180));
						selectionOne = 2;
					}
					if (confirmCounter == 1) {
						flames2.setPosition(sf::Vector2f(195, 180));
						selectionTwo = 2;
					}
					if (confirmCounter == 2) {
						flames3.setPosition(sf::Vector2f(245, 180));
						selectionThree = 2;
					}

				}

				if (event.mouseButton.x > 227 && event.mouseButton.x < 425 && event.mouseButton.y >565 && event.mouseButton.y < 595)
				{
					displayStats();
				}

				if (event.mouseButton.x > 333 && event.mouseButton.x < 400 && event.mouseButton.y >100 && event.mouseButton.y < 260)
				{
					//cout << "hero" << endl;

					if (confirmCounter == 0) {
						flames.setPosition(sf::Vector2f(372, 180));
						selectionOne = 3;
					}
					if (confirmCounter == 1) {
						flames2.setPosition(sf::Vector2f(347, 180));
						selectionTwo = 3;
					}
					if (confirmCounter == 2) {
						flames3.setPosition(sf::Vector2f(397, 180));
						selectionThree = 3;
					}
					

				}

				if (event.mouseButton.x > 450 && event.mouseButton.x < 570 && event.mouseButton.y >100 && event.mouseButton.y < 260)
				{
					//cout << "goddess" << endl;

					if (confirmCounter == 0) {
						flames.setPosition(sf::Vector2f(510, 180));
						selectionOne = 4;
					}
					if (confirmCounter == 1) {
						flames2.setPosition(sf::Vector2f(485, 180));
						selectionTwo = 4;
					}
					if (confirmCounter == 2) {
						flames3.setPosition(sf::Vector2f(535, 180));
						selectionThree = 4;
					}

				}

				if (event.mouseButton.x > 50 && event.mouseButton.x < 140 && event.mouseButton.y > 270  && event.mouseButton.y < 435 )
				{
					//cout << "Knight" << endl;

					if (confirmCounter == 0) {
						flames.setPosition(sf::Vector2f(95, 353));
						selectionOne = 5;
					}
					if (confirmCounter == 1) {
						flames2.setPosition(sf::Vector2f(70, 353));
						selectionTwo = 5;
					}
					if (confirmCounter == 2) {
						flames3.setPosition(sf::Vector2f(120, 353));
						selectionThree = 5;
					}
				}

				if (event.mouseButton.x > 180 && event.mouseButton.x < 250 && event.mouseButton.y > 270 && event.mouseButton.y < 435)
				{
					//cout << "ninja" << endl;

					if (confirmCounter == 0) {
						flames.setPosition(sf::Vector2f(215, 353));
						selectionOne = 6;
					}
					if (confirmCounter == 1) {
						flames2.setPosition(sf::Vector2f(190, 353));
						selectionTwo = 6;
					}
					if (confirmCounter == 2) {
						flames3.setPosition(sf::Vector2f(240, 353));
						selectionThree = 6;
					}
				}

				if (event.mouseButton.x > 333 && event.mouseButton.x < 420 && event.mouseButton.y > 270 && event.mouseButton.y < 435)
				{
					//cout << "berserker" << endl;

					if (confirmCounter == 0) {
						flames.setPosition(sf::Vector2f(377, 353));
						selectionOne = 7;
					}
					if (confirmCounter == 1) {
						flames2.setPosition(sf::Vector2f(352, 353));
						selectionTwo = 7;
					}
					if (confirmCounter == 2) {
						flames3.setPosition(sf::Vector2f(402, 353));
						selectionThree = 7;
					}
				}

				if (event.mouseButton.x > 450 && event.mouseButton.x < 570 && event.mouseButton.y > 270 && event.mouseButton.y < 435)
				{
					//cout << "dragoon" << endl;

					if (confirmCounter == 0) {
						flames.setPosition(sf::Vector2f(510, 353));
						selectionOne = 8;
					}
					if (confirmCounter == 1) {
						flames2.setPosition(sf::Vector2f(485, 353));
						selectionTwo = 8;
					}
					if (confirmCounter == 2) {
						flames3.setPosition(sf::Vector2f(535, 353));
						selectionThree = 8;
					}
				}

				if (event.mouseButton.x > 120 && event.mouseButton.x < 230 && event.mouseButton.y > 600 && event.mouseButton.y < 650)
				{
					cout << "confirm" << endl;
					if (confirmCounter < 4){
						confirmCounter++;
				}
					if (confirmCounter == 1) {
						flames.setTexture(flamesInvert);
						
					}
					if (confirmCounter == 2) {
						flames2.setTexture(flamesInvert);
						
					}
					if (confirmCounter == 3) {
						flames3.setTexture(flamesInvert);
						readyToStart = true;
					}
							
				}

				if (event.mouseButton.x > 440 && event.mouseButton.x < 550 && event.mouseButton.y > 600 && event.mouseButton.y < 650)
				{
					cout << "delete" << endl;
					if (confirmCounter > 0) {
						confirmCounter--;
					}
					readyToStart = false;
					if (confirmCounter == 2) {
						flames3.setTexture(flamesTex);
					}
					if (confirmCounter == 1) {
						flames2.setTexture(flamesTex);
					}
					if (confirmCounter == 0) {
						flames.setTexture(flamesTex);
					}
				}

				if (event.mouseButton.x > 280 && event.mouseButton.x < 365 && event.mouseButton.y > 500 && event.mouseButton.y < 550)
				{
					if (readyToStart) {
						/*cout << "Start!" << endl;
						cout << selectionOne <<"\t" << selectionTwo  <<"\t" << selectionThree << endl;*/
						selection.close();
						battleTime();
						
					}
				}

				
			}

			if ((localPosition.x >= 50) && (localPosition.x <= 140) && (localPosition.y >= 100) && (localPosition.y <= 260)) {
				archer.setColor(sf::Color(0, 255, 128));

			}
			else if ((localPosition.x >= 180) && (localPosition.x <= 260) && (localPosition.y >= 100) && (localPosition.y <= 260))
			{
				mage.setColor(sf::Color(0, 255, 128));
			}
			else if ((localPosition.x >= 333) && (localPosition.x <= 400) && (localPosition.y >= 100) && (localPosition.y <= 260))
			{
				hero.setColor(sf::Color(0, 255, 128));
			}
			else if ((localPosition.x >= 450) && (localPosition.x <= 570) && (localPosition.y >= 100) && (localPosition.y <= 260))
			{
				goddess.setColor(sf::Color(0, 255, 128));
			}

			//second column

			else if ((localPosition.x >= 50) && (localPosition.x <= 140) && (localPosition.y >= 270) && (localPosition.y <= 435))
			{
				knight.setColor(sf::Color(0, 255, 128));
			}
			else if ((localPosition.x >= 180) && (localPosition.x <= 250) && (localPosition.y >= 270) && (localPosition.y <= 435))
			{
				ninja.setColor(sf::Color(0, 255, 128));
			}
			else if ((localPosition.x >= 333) && (localPosition.x <= 420) && (localPosition.y >= 270) && (localPosition.y <= 435))
			{
				berserker.setColor(sf::Color(0, 255, 128));
			}
			else if ((localPosition.x >= 450) && (localPosition.x <= 570) && (localPosition.y >= 270) && (localPosition.y <= 435))
			{
				dragoon.setColor(sf::Color(0, 255, 128));
			}

			//last four buttons

			else if ((localPosition.x >= 120) && (localPosition.x <= 230) && (localPosition.y >= 600) && (localPosition.y <= 650))
			{
				ok.setColor(sf::Color(192, 192, 192));
			
			}

			else if ((localPosition.x >= 440) && (localPosition.x <= 550) && (localPosition.y >= 600) && (localPosition.y <= 650))
			{
				remove.setColor(sf::Color(192, 192, 192));
			}

			else if ((localPosition.x >= 227) && (localPosition.x <= 425) && (localPosition.y >= 565) && (localPosition.y <= 595))
			{
				Stats.setColor(sf::Color(0, 255, 128));
			}

			else if ((localPosition.x >= 280) && (localPosition.x <= 365) && (localPosition.y >= 500) && (localPosition.y <= 550))
			{
				toBattle.setColor(sf::Color(192, 192, 192));
			}
		}

		


		selection.draw(detail);
		selection.draw(ok);
		selection.draw(remove);
		if (readyToStart) {
			selection.draw(toBattle);
		}

		//cuts the image for the flame animation
		flames.setTextureRect(sf::IntRect(source.x * 28, source.y * 51, 28, 51));
		flames2.setTextureRect(sf::IntRect(source.x * 28, source.y * 51, 28, 51));
		flames3.setTextureRect(sf::IntRect(source.x * 28, source.y * 51, 28, 51));
		
		selection.draw(flames);
		if (confirmCounter >= 1) {
			selection.draw(flames2);
		}
		if (confirmCounter >= 2) {
			selection.draw(flames3);
		}

		selection.draw(archer);
		selection.draw(mage);
		selection.draw(hero);
		selection.draw(goddess);
		selection.draw(knight);
		selection.draw(ninja);
		selection.draw(berserker);
		selection.draw(dragoon);
		selection.draw(Stats);
		selection.draw(classes);
		selection.display();
		selection.clear();

	}







}

void battleTime() {

	vector<int> random;
	for (int i = 0; i < 3; ++i) {
		int randNum = (rand() % 8 + 1);
		random.push_back(randNum);
	}

	vector<double>fullhealth(6);
	//first three in this vector represent heroes
	//last three in this vector reresent enemies

	vector<double>currentHealth(6);
	//same applies to this vector, but current health as battle goes on
	
	//i need to do it this way so the vector index corresponds with health bats index
	

	int healthWidth = 10;
	int heroY = 200;
	int current = 0;
	int j = 0;
	int enemyNum = 0;

	sf::RenderWindow battle(sf::VideoMode(640,640), "Battle");
	sf::Font;
	sf::Event event;

	vector<sf::RectangleShape> healthBars (6);
	vector <sf::RectangleShape> remainingBars(6);


	


	//left column health bars

	for (int i = 0; i < 3; i++) {
		healthBars.at(i).setPosition(sf::Vector2f(0, healthWidth));
		remainingBars.at(i).setPosition(sf::Vector2f(0, healthWidth));
		healthWidth += 20;

		healthBars.at(i).setFillColor(sf::Color(0, 255, 0));
		healthBars.at(i).setSize(sf::Vector2f(200, 10));
		

		
		
		remainingBars.at(i).setFillColor(sf::Color(255, 0, 0));
		remainingBars.at(i).setSize(sf::Vector2f(200, 10));
	}

	healthWidth = 10;

	for (int i = 3; i < 6; i++) {
		healthBars.at(i).setPosition(sf::Vector2f(400, healthWidth));
		remainingBars.at(i).setPosition(sf::Vector2f(400, healthWidth));
		healthWidth += 20;

		healthBars.at(i).setFillColor(sf::Color(0, 255, 0));
		healthBars.at(i).setSize(sf::Vector2f(200, 10));


		remainingBars.at(i).setFillColor(sf::Color(255, 0, 0));
		remainingBars.at(i).setSize(sf::Vector2f(200, 10));
	}
	



	chosen standIn;

	vector<chosen>heroes(3);
	//doing enemies and heroes seperate for different textures and different stances
	vector<chosen>enemies(3);
	vector<sf::Texture>tex(3);
	vector<sf::Texture> eTex(3);

		for (int i = 0; i < 3; ++i) {

		if (i == 0) 
			standIn.returnPlayerOne(selectionOne, heroes.at(i));
		if (i == 1)
			standIn.returnPlayerOne(selectionTwo, heroes.at(i));
		if (i == 2)
			standIn.returnPlayerOne(selectionThree, heroes.at(i));
		if (!tex.at(i).loadFromFile(heroes.at(i).fighter.getName() + ".png")) {
			cerr << "The file failed to open.";
		}
		heroes.at(i).user.setTexture(tex.at(i));
		heroes.at(i).user.setPosition(sf::Vector2f(100, heroY));
		heroY += 100;

	}
		heroY = 200;

	for (int i = 0; i < 3; ++i) {
		standIn.returnPlayerOne(random.at(i), enemies.at(i));
		if (!eTex.at(i).loadFromFile(enemies.at(i).fighter.getName() + ".png")) {
			cerr << "The file failed to open.";
		}
		enemies.at(i).user.setTexture(eTex.at(i));
		enemies.at(i).user.setPosition(sf::Vector2f(500, heroY));
		heroY += 100;


	}

	for (int i = 0; i < 3; ++i) {

		fullhealth.at(i) = heroes.at(i).fighter.getHealth();
		

	}

	for (int i = 3; i < 6; ++i) {
		
		fullhealth.at(i) = enemies.at(j).fighter.getHealth();
		j++;

	}
	
	j = 0;
	

	

	

	//used for player's animation
	enum playerMov{Down,Left,Right,Up};
	sf::Vector2i source(1, Right); //heroes facing right
	sf::Vector2i sourceEnemy(1,Left); //enemies facing left

	//used for frame rate
	sf::Clock clock;
	float frameSpeed = 200, frameCounter = 0, frameSwitch = 75;



	sf::Font font;
	if (!font.loadFromFile("data/capture.ttf")) {
		cerr << "The font could not be found.";

	}
	sf::Text attack("Attack", font);
	attack.setPosition(sf::Vector2f(50, 600));

	sf::Text turn;

	vector <sf::Text> whoAttack(3);
	int xLoc = 30;
	bool whoToAttack = false;
	for (int i = 0; i < 3; ++i) {
		whoAttack.at(i).setPosition(sf::Vector2f(xLoc, 560));
		whoAttack.at(i).setFont(font);
		whoAttack.at(i).setCharacterSize(18);
		xLoc += 100;
		whoAttack.at(i).setString(enemies.at(i).fighter.getName());

	}
	
	sf::Text physical("Physical", font);
	sf::Text magic("Magical", font);
	physical.setCharacterSize(18);
	magic.setCharacterSize(18);
	physical.setPosition(sf::Vector2f(50, 520));
	magic.setPosition(sf::Vector2f(150, 520));


	bool PhysicalOrMagic = false;

	
	
	turn.setPosition(sf::Vector2f(40, 575));
	turn.setCharacterSize(20);
	
	turn.setFont(font);

	turn.setPosition(sf::Vector2f(40, 575));
	turn.setCharacterSize(20);

	turn.setFont(font);

	vector<double> battleHealth(6);


	while (battle.isOpen()) {

		for (int i = 0; i < 3; ++i) {

			currentHealth.at(i) = heroes.at(i).fighter.getHealth();
			
			
			if (currentHealth.at(i) > 0) {
				battleHealth.at(i) = (200 * (currentHealth.at(i) / fullhealth.at(i)));

				healthBars.at(i).setSize(sf::Vector2f(battleHealth.at(i), 10));
			}
			else {
				healthBars.at(i).setSize(sf::Vector2f(0, 10));
			}
			

		}

		for (int i = 3; i < 6; ++i) {

			currentHealth.at(i) = enemies.at(j).fighter.getHealth();
			if (currentHealth.at(i) > 0) {
				battleHealth.at(i) = (200 * (currentHealth.at(i) / fullhealth.at(i)));
				healthBars.at(i).setSize(sf::Vector2f(battleHealth.at(i), 10));
			}
			
			else {
				healthBars.at(i).setSize(sf::Vector2f(0, 10));
			}
			j++;

			
		}
		j = 0;

		

		turn.setString(heroes.at(current).fighter.getName() + "'s turn!");

		frameCounter += frameSpeed * clock.restart().asSeconds();
		if (frameCounter >= frameSwitch) {
			frameCounter = 0;
			source.x++;
			sourceEnemy.x++;

			if (source.x * 32 >= tex.at(1).getSize().x)
				source.x = 0; //cycles images

			if (sourceEnemy.x * 32 >= tex.at(1).getSize().x)
				sourceEnemy.x = 0; //cycles images
		}


		while (battle.pollEvent(event)) {

			for (int i = 0; i < 3; ++i) {
				whoAttack.at(i).setColor(sf::Color(255, 255, 255));
			}
			physical.setColor(sf::Color(255, 255, 255));
			magic.setColor(sf::Color(255, 255, 255));

			sf::Vector2i localPosition = sf::Mouse::getPosition(battle);
			attack.setColor(sf::Color(0, 0, 128));


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			battle.close(); //closes the windowif escaped is pressed
		}

		

		if (event.type == sf::Event::MouseButtonPressed) {

			if (event.mouseButton.x > 50 && event.mouseButton.x < 175 && event.mouseButton.y >600 && event.mouseButton.y < 650)
			{
				/*cout << "To fight!!!" << endl;*/		
				whoToAttack = true;

			}

			if (event.mouseButton.x > 30 && event.mouseButton.x < 90 && event.mouseButton.y >560 && event.mouseButton.y < 585 && whoToAttack)
			{
				/*cout << "One" << endl;*/
				/*AttackVSAttack(heroes.at(current).fighter, enemies.at(0).fighter);*/
				enemyNum = 0;
				whoToAttack = false;
				PhysicalOrMagic = true;

			}

			if (event.mouseButton.x > 130 && event.mouseButton.x < 220 && event.mouseButton.y >560 && event.mouseButton.y < 585 && whoToAttack)
			{
				/*cout << "TWo" << endl;*/
				enemyNum = 1;
				whoToAttack = false;
				PhysicalOrMagic = true;

			}

			if (event.mouseButton.x > 230 && event.mouseButton.x < 340 && event.mouseButton.y >560 && event.mouseButton.y < 585 && whoToAttack)
			{
			/*	cout << "Three" << endl;*/
				enemyNum = 2;
				whoToAttack = false;
				PhysicalOrMagic = true;

			}

			if (event.mouseButton.x > 50 && event.mouseButton.x < 140 && event.mouseButton.y >520 && event.mouseButton.y < 545 && PhysicalOrMagic)
			{
			/*	cout << "Physical!" << endl;*/
				PhysicalOrMagic = false;

				heroes.at(current).user.move(50, 0);


				if((random.at(enemyNum) == 2) || (random.at(enemyNum) == 4))
				AttackVSMagic(heroes.at(current).fighter, enemies.at(enemyNum).fighter);
				else {
				AttackVSAttack(heroes.at(current).fighter, enemies.at(enemyNum).fighter);
					
				}
				if (current <= 2)
					current++;
				if (current > 2)
					current = 0;

			}

			if (event.mouseButton.x > 150 && event.mouseButton.x < 240 && event.mouseButton.y >520 && event.mouseButton.y < 545 && PhysicalOrMagic)
			{
				/*cout << "Magical!!" << endl;*/
				PhysicalOrMagic = false;

				heroes.at(current).user.move(50, 0);

				if ((random.at(enemyNum) == 2) || (random.at(enemyNum) == 4))
					MagicVSMagic(heroes.at(current).fighter, enemies.at(enemyNum).fighter);
				else {
					MagicVSAttack(heroes.at(current).fighter, enemies.at(enemyNum).fighter);

				}

				
				if (current <= 2)
					current++;
				if (current > 2)
					current = 0;

			}
		}

			if ((localPosition.x >= 50) && (localPosition.x <= 175) && (localPosition.y >= 600) && (localPosition.y <= 650)) {
				
				attack.setColor(sf::Color(0, 255, 128));
			}

			else if ((localPosition.x >= 30) && (localPosition.x <= 120) && (localPosition.y >= 560) && localPosition.y <= 585 && whoToAttack) {
				whoAttack.at(0).setColor(sf::Color(0, 255, 128));
			}

			else if ((localPosition.x >= 130) && (localPosition.x <= 220) && (localPosition.y >= 560) && localPosition.y <= 585 && whoToAttack) {
				whoAttack.at(1).setColor(sf::Color(0, 255, 128));
			}

			else if ((localPosition.x >= 230) && (localPosition.x <= 320) && (localPosition.y >= 560) && localPosition.y <= 585 && whoToAttack) {
				whoAttack.at(2).setColor(sf::Color(0, 255, 128));
			}

			else if ((localPosition.x >= 50) && (localPosition.x <= 150) && (localPosition.y >= 520) && localPosition.y <= 545 && PhysicalOrMagic) {
				physical.setColor(sf::Color(0, 255, 128));
			}

			else if ((localPosition.x >= 150) && (localPosition.x <= 240) && (localPosition.y >= 520) && localPosition.y <= 545 && PhysicalOrMagic) {
				magic.setColor(sf::Color(0, 255, 128));
			}

			

			
			
		}

		

		for (int i = 0; i < 6; ++i) {
			battle.draw(remainingBars.at(i));
			battle.draw(healthBars.at(i));
			
		}

		for (int i = 0; i < 3; ++i) {
			heroes.at(i).user.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
			//cuts the image for use
			battle.draw(heroes.at(i).user);

		}

		for (int i = 0; i < 3; ++i) {
			enemies.at(i).user.setTextureRect(sf::IntRect(sourceEnemy.x * 32, sourceEnemy.y * 32, 32, 32));
			//cuts the image for use
			battle.draw(enemies.at(i).user);

		}

		if (whoToAttack) {
			for (int i = 0; i < 3; ++i) {
				battle.draw(whoAttack.at(i));

			}
		}

		if (PhysicalOrMagic) {
			battle.draw(physical);
			battle.draw(magic);
		}


		battle.draw(attack);
		battle.draw(turn);

		battle.display();
		battle.clear();
	}

}


