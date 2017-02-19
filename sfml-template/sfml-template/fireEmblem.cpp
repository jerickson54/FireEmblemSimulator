/* HW 11 Class Fun
*
* Fire Emblem Class Functin Declarations
* Author:Jake Erickson
*
* Section D
*/

#include "FireEmblem.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

FireEmblem::FireEmblem() { //default constructor
	name = "Chrome";
	health = 15;
	attack = 8;
	defense = 5;
	skill = 10;
	magic = 3;
	resistance = 5;
	speed = 8;
}

FireEmblem::FireEmblem(string n, int h, int a, int d, int sk, int m, int r, int s) { //non-default constructor

	name = n;

	attack = a;

	health = h;

	defense = d;

	skill = sk;

	magic = m;

	resistance = r;
	
	speed = s;

}

string FireEmblem::getName() {
	return name;
}

int FireEmblem::getHealth() const { //accessor
	return health;
}

int FireEmblem::getAttack()const { //accessor

	return attack;
}

int FireEmblem::getDefense() const { //accessor
	return defense;
}

int FireEmblem::getSkill() const {
	return skill;
}

int FireEmblem::getMagic() const {
	return magic;
}

int FireEmblem::getResistance() const {
	return resistance;
}

int FireEmblem::getSpeed() const {
	return speed;
}



void FireEmblem::setName(string n) {
	name = n;
}

void FireEmblem::setAttack(int a) { //mutator

	attack = a;

}

void FireEmblem::setHealth(int h) { //mutator

	health = h;
}

void FireEmblem::setDefense(int d) { //mutator

	defense = d;
}

void FireEmblem::setSkill(int sk) {
	skill = sk;
}

void FireEmblem::setMagic(int m) {
	magic = m;
}

void FireEmblem::setResistance(int r) {
	resistance = r;
}

void FireEmblem::setSpeed(int s) {
	speed = s;
}




void FireEmblem::attackingPhysical(FireEmblem &defender) {

	//dont forget to add critical hit!!!

	int hit = ((rand() % 100) + 1); //hit rate


	int skillConvertor = (skill + 60);
	int criticalHit = (skill - 18);

	cout << "The battle commences!" << endl;


	if (hit <= skillConvertor) {
		if ((attack - defender.getDefense() > 0)) {
			cout << "The attack hit!" << endl;
			if (hit <= criticalHit) {
				cout << "Critical Hit!!" << endl;
				defender.health = defender.health - ((attack - defender.getDefense()) * 3);
			}
			else {
				defender.health = defender.health - (attack - defender.getDefense());
			}
		}

		
	}

	else {
		cout << "The opponent dodged your attack." << endl << endl;
	}

	if (defender.getHealth() <= 0) {
		cout << "Nice! Your " << name << " defeated the enemy " << defender.getName() <<" !" << endl;
	}

	




}

void FireEmblem::attackingMagic(FireEmblem &defender) {

	int hit = ((rand() % 100) + 1); //hit rate

	int skillConvertor = (skill + 60);
	int criticalHit = (skill - 18);

	cout << "The battle commences!" << endl;


	if (hit <= skillConvertor) {
		if ((magic - defender.getResistance() > 0)) {
			cout << "The attack hit!" << endl;
			if (hit <= criticalHit) {
				cout << "Critical Hit!!" << endl;
				defender.health = defender.health - ((magic  - defender.getDefense()) * 3);
			}
			else {
				defender.health = defender.health - (magic - defender.getDefense());
			}
		}

	
	}

	else {
		cout << "The opponent dodged your attack." << endl << endl;
	}
	

	if (defender.getHealth() <= 0) {
		cout << "Nice! Your " << name << " defeated the enemy " << defender.getName() << " !" << endl;
	}



}

void FireEmblem::defendingPhysical(FireEmblem &opponent) {

	//the paramters of a,d, and h, are the user's stats so use objectName.get() to get stats.
	//the other class parameter is the enenmy.

	int dodge = ((rand() % 100) + 1); //dodge rate
	
	int skillDodge = (5 + skill);

	cout << "Your opponent attacks!" << endl;

		if (dodge <= skillDodge) {
			
			cout<<"Your " << name <<" dodged!" << endl << endl;
			}

		else {
			if ((opponent.getAttack() - defense) > 0) {
				health = health - (opponent.getAttack() - defense);
				cout << "Ouch!" <<endl;
			}
		}

		if (health <= 0) {
			cout << "Oh no! Your " << name << " is out of health!" << endl;
		}

		
	


}

void FireEmblem::defendingMagic(FireEmblem &opponent) {


	int dodge = ((rand() % 100) + 1); //dodge rate

	int skillDodge = (5 + skill);

	cout << "Your opponent attacks!" << endl;

	if (dodge <= skillDodge) {

		cout << "Your " << name << " dodged!" << endl << endl;
	}

	else {
		if ((opponent.getMagic() - resistance) > 0) {
			health = health - (opponent.getMagic() - resistance);
			cout << "Ouch!" << endl;
		}
	}

	if (health <= 0) {
		cout << "Oh no! Your " << name << " is out of health!" << endl;
	}

}



void FireEmblem::Introduction() {

	cout << "Welcome to Fire Emblem. Two nations, Hoshido and Nohr, are at war. Your job is to defeat your enemy." << endl;
	cout << "Hoshido is a bountiful nation along the coast, while Nohr is a barren land." << endl;
	cout << "You shall choose a side. Hoshido or Nohr and fight." << endl;
	cout << "If you defeat your enemy you will have won the war and bring peace to the land." << endl << endl;

}




