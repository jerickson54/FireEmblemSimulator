#pragma once#pragma once
/* HW11
* Author: Jake Erickson
* Section D
*
* Fire Emblem Class header file
*/

#include <string>
#include <cstring>
using namespace std;
class FireEmblem {

public:
	FireEmblem(); //default constructor

	FireEmblem(string n, int h, int a, int d, int sk, int m, int r, int s); //non-default constructor

	int getHealth() const; //accessors
	int getAttack() const;
	int getDefense() const;
	int getSkill() const;
	int getMagic() const;
	int getResistance() const;
	int getSpeed() const;
	string getName();

	void setAttack(int a); //mutator
	void setDefense(int d);
	void setHealth(int h);
	void setSkill(int sk);
	void setMagic(int m);
	void setResistance(int r);
	void setSpeed(int s);
	void setName(string n);

	void attackingPhysical(FireEmblem &defender);
	void attackingMagic(FireEmblem &defender);
	void defendingPhysical( FireEmblem &opponent);
	void defendingMagic(FireEmblem &opponent);

	void Introduction();





private:
	int health;
	int attack;
	int defense;
	int skill;
	int magic;
	int resistance;
	int speed;

	string name;
};