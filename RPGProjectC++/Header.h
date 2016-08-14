#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

/*
Author: Chad Ostler - D'Arcey Taylor - Patrick Ross - Ryan Jameson
Date: August 9, 2016.
Project 2
Professor: Matt Wilson
*/

using namespace std;

//Declare prototypes
string SelectClass();
string SelectRace();
void PrintActionMenu();
int MoveEvent(struct EventMaps inputMaps);
//Declare Classes
class Class {
private:
	string ClassName;

public:
	string getClass() {
		return ClassName;
	}
	void setClass(string input) {
		ClassName = input;
	}
};

class Race {
private:
	string RaceName;

public:
	string getRace() {
		return RaceName;
	}
	void setRace(string input) {
		RaceName = input;
	}
};

//Character class
class Character {

private:
	string Name;
	int MaxHealth;
	int CurrHealth;
	int Humanity;

public:
	vector<int> CurrLocation;
	Class CharClass;
	Race CharRace;

	Character(string Name) {
		setName(Name);
		setCurrHealth(200);
		setMaxHealth();
		setHumanity(5);
	};
	void attack() {

	}//end of attack

	 //random chance to critically strike with an attack; true = crit, false = not crit
#pragma warning(disable:4244)
	bool crit() {
		srand(time(NULL));
		int randNum = rand() % 100 + 1;
		if (randNum > 85) {
			return true;
		}
		else {
			return false;
		}
	}//end of crit
#pragma warning(default:4244)
	void health() {
	}//end of health

	 //Getters and setters
	string getName() {
		return Name;
	}//end of getName
	void setName(string Name) {
		this->Name = Name;
	}//end of SetName

	void setHumanity(int input) {
		this->Humanity = input;
	}
	int getHumanity() {
		return Humanity;
	}

	int getHealth() {
		return CurrHealth;
	}//end of getHealth

	void setCurrHealth(int Health) {
		CurrHealth = Health;
	}
	int getMaxHealth() {
		return MaxHealth;
	}
	void setMaxHealth() {
		MaxHealth = CurrHealth;
	}

	//this is hard to make sense of, moves the player basically
	void setLocation(vector<int> currentMap) {
		//if the currentLocation vector hasn't been initialized yet, create it
		if (CurrLocation.size() == 0) {
			for (int count = 0; count < 5; count++) {
				CurrLocation.push_back(0);
			}
			for (int count = 0; count < 5; count++) {
				//cout << "Element: " << count << ".		Location: " << CurrLocation.at(count) << "\n";
			}
		}
		//else everytime a move command is issued, "moves" the player through the map.
		else {
			//tracks current element index
			int element = 0;
			//catches CurrLocation element index up to the GameMap element index
			for (element = 0; CurrLocation.at(element) == currentMap.at(element); element++) {
			}
			//if the current location == the last spot on the GameMap, than it's the boss
			if(CurrLocation.at(4) + 1 == currentMap.at(4)) {
				
			}
			//if the value at the CurrLocation element index != the value of the gameMaps value at the current element index, increases CurrLocation's value
			else if (CurrLocation.at(element) != currentMap.at(element)) {
					CurrLocation.at(element)++;
				}
			
			cout << "Element: " << element << ".		Location: " << CurrLocation.at(element) << "\n";
		}
	}

};//end of Character class

  //declare structures

  //Enemy structure
struct Enemy {

private:
	string Name;
	int Health;
	int Damage;

public:
	void health() {

	}//end of health
	void attack() {

	}//end of attack
#pragma warning(disable:4244)
	bool crit() {
		srand(time(NULL));
		int randNum = rand() % 100 + 1;
		if (randNum > 75) {
			return true;
		}
		else {
			return false;
		}
	}//end of crit
	#pragma warning(default:4244)
	void encounter() {

	}//end of encounter
	void boss() {

	}//end of boss
};//end of Enemy Struct

//map structure
#pragma warning(disable:4244)
struct Map {
public:
	vector<int> map1;

	void createMap() {
		srand(time(NULL));
		for (int count = 0; count < 5; count++) {
			int randNum = rand() % 6 + 2;
			map1.push_back(randNum);
		}
		for (int count = 0; count < 5; count++) {
			cout << count << ". " << map1.at(count) << "\n";
		}
	}
};
#pragma warning(default:4244)
struct EventMaps {
public:
	vector<int> LocationMap;
	vector<int> GameMap;

	void setCurrentLocationMap(vector<int> locationMap) {
		LocationMap = locationMap;
	}
	void setGameMap(vector<int> gameMap) {
		GameMap = gameMap;
	}
};