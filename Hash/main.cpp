#include <iostream>
#include <sstream>
#include <string>
#include "Hash.h"
#include "Player.h"
using namespace std;

int main(){
	Hash database;
	Player* alyssa = database.qbAssist("Tre", "brown", 345);

	database.insert(alyssa);

	Player* tang = database.qbAssist("Tre", "bown", 345);

	database.insert(tang);

	Player* rudra = database.qbAssist("Tre", "brn", 345);

	database.insert(rudra);

	Player* new_player = database.qbAssist("Tre", "bown", 345);

	database.insert(new_player);

	new_player = database.qbAssist("Tre", "brokn", 345);

	database.insert(new_player);

	new_player = database.qbAssist("Tre", "brozn", 345);

	database.insert(new_player);

	new_player = database.qbAssist("Tre", "Orown", 345);

	database.insert(new_player);

	new_player = database.qbAssist("Tre", "brPwn", 345);

	database.insert(new_player);

	new_player = database.qbAssist("Tre", "Krown", 345);

	database.insert(new_player);


	database.display();
	database.pubSearch("brown");
	database.pubSearch("n");

	database.remove("brown");

	new_player = database.qbAssist("Tre", "OPPown", 345);

	database.insert(new_player);

	new_player = database.qbAssist("Tre", "bLKKKPwn", 345);

	database.insert(new_player);

	new_player = database.qbAssist("Tre", "KrkkKPwn", 345);

	database.insert(new_player);

	new_player = database.qbAssist("Tre", "OPlllown", 345);

	database.insert(new_player);

	new_player = database.qbAssist("Tre", "bPPPLPwn", 345);

}








