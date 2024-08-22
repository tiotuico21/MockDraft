#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip> 
#include <string>
#include "Hash.h"
#include "Player.h"
using namespace std;

Hash::Hash() {
	this->size = 33;
	this->real_size = 0;
	this->prime = findNextPrime(size);
	this->playerDatabase = vector<HashNode*>(size);
}

bool Hash::isPrime(int num) {
	for (int i = 2; i < 10; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int Hash::findNextPrime(int size) {
	int prime = size - 1;
	while (!isPrime(prime)) {
		prime--;
	}
	return prime;
}

int Hash::totalCharValue(string name) {
	int name_size = name.length();


	int result = 0;

	for (int i = 0; i < name_size; i++) {
		char letter = name[i];
		cout << letter << endl;
		int value = (int)letter;
		cout << "value " << value << endl;
		cout << result << endl;
		result = result + ((i + 1) * value);
	}

	return result;
}

int Hash::initialPlace(string name) {
	int place = totalCharValue(name) % size;
	return place;
}
int Hash::hashName(vector<HashNode*> database, string name, int hash_size) {
	int total = totalCharValue(name);
	int result = initialPlace(name); 

	if (database[result] != nullptr) {
		result = doubleHash(total, result, 0, hash_size);
	}

	return result;
}

void Hash::insert(Player* new_player) {
	real_size++;

	double real_size_decimal = (double) real_size;
	double size_decimal = (double) size;
	cout << endl;
	cout << "****************" << endl;
	cout << real_size_decimal / size_decimal << endl;
	cout << endl;
	cout << "****************" << endl;
	if (real_size_decimal/size_decimal >= 0.68) {
		cout << "yes rehashing is happening" << " size: " << size << endl;
		rehash();
		display();
		cout << "yes rehashing is happening" << " size: " << size << endl;
	}
	int place = hashName(playerDatabase, new_player->getName(), size);
	HashNode* new_node = new HashNode(new_player, false);
	playerDatabase[place] = new_node;

	cout << new_player->getName() << " " << "real size: " << real_size << " index: " << place << endl;

}

Hash::HashNode* Hash::search(string name, int place, int temp, int incrament) {
	cout << "Searching for at index " << temp << endl;
	if (playerDatabase[temp] == nullptr) {
		return nullptr;
	}
	else if (playerDatabase[temp]->player->getName() == name) {
		return playerDatabase[temp];

	}
	else{
		return search(name, place, doubleFormula(totalCharValue(name), incrament), incrament + 1);
	}

}

void Hash::pubSearch(string name) {
	int place = initialPlace(name);
	HashNode* find_player = search(name, place, place, 0);

	if (find_player == nullptr) {
		cout << "Player not found" << endl;
	}
	else {
		cout << "Player found" << endl;
		find_player->player->display();
	}
}

void Hash::remove(string name) {
	HashNode* remove_node = search(name, initialPlace(name), initialPlace(name), 0);

	if (remove_node == nullptr) {
		cout << "Player not found" << endl;
	}
	else {
		remove_node->toRemove = true; 
	}
}

int Hash::doubleFormula(int result, int incrament) {
	return ((result % size) + ((incrament + 1) * (prime - (result % prime)))) % size;
}

int Hash::doubleHash(int result, int place, int incrament, int hash_size) {
	int temp = place;

	if (playerDatabase[place] == nullptr) {
		cout << "place: " << place << endl;
		return place;
	}
	else {
		int temp = doubleFormula(result, incrament);
		cout << "double hash index: " << temp << endl;
		if (playerDatabase[temp] == nullptr) {
			cout << "^^^^^^^^^^^^" << endl;
			cout << "place: " << place << endl;
			return temp;
		}
		else {
			place = temp;
			return doubleHash(result, place, incrament + 1, hash_size);
		}
	}
}

void Hash::rehash() {
	int new_size = size * 2;

	vector<HashNode*> temp = vector<HashNode*>(size);

	for (int i = 0; i < size; i++) {
		temp[i] = playerDatabase[i];
	}

	playerDatabase.erase(playerDatabase.begin(), playerDatabase.end());
	
	playerDatabase.resize(new_size, nullptr);

	prime = findNextPrime(new_size);



	cout << "yes" << endl;

	display();

	for (int i = 0; i < size; i++) {
		if (temp[i] == nullptr) {
			continue;
		}
		else if (temp[i]->toRemove) {
			Player* remove_player = temp[i]->player;
			delete temp[i];
			delete remove_player;
			temp[i] = nullptr;
			remove_player = nullptr;
			continue;
		}
		int place = hashName(playerDatabase, temp[i]->player->getName(), new_size);
		playerDatabase[place] = temp[i];
	}

	
	size = new_size;

	display();
}

Player* Hash::qbAssist(string first_name, string last_name, double ff_points) {

	double passing_yards;
	double rushing_yards;
	int passing_td;
	int rushing_td;
	int fumbles;
	int interceptions;

	do {
		cout << "Passing Yards: ";
		cin >> passing_yards;
	} while (passing_yards < 0);


	do {
		cout << "Rushing Yards: ";
		cin >> rushing_yards;
	} while (rushing_yards < 0);

	do {
		cout << "Passing Touchdowns: ";
		cin >> passing_td;
	} while (rushing_yards < 0);

	do {
		cout << "Rushing Touchdowns: ";
		cin >> rushing_td;
	} while (rushing_td < 0);

	do {
		cout << "Fumbles: ";
		cin >> fumbles;
	} while (fumbles < 0);

	do {
		cout << "Interceptions: ";
		cin >> interceptions;
	} while (interceptions < 0);

	Player* new_player = new Player(first_name, last_name, "QB", ff_points, passing_yards, rushing_yards, passing_td, rushing_td, fumbles, interceptions);

	return new_player;
}

void Hash::display() {
	for (int i = 0; i < size; i++) {
		if (playerDatabase[i] == nullptr) {
			cout << "Index " << i << ": null" << endl;
		}
		else {
			cout << "Index " << i << ": ";
			playerDatabase[i]->player->display();
		}
	}
}



Hash::~Hash() {
	for (int i = 0; i < size; i++) {
		if (playerDatabase[i] == nullptr) {
			continue;
		}
		else {
			Player* remove = playerDatabase[i]->player;
			delete playerDatabase[i];
			delete remove;
			remove = nullptr;
		}
	}
}