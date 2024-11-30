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
	this->remove_amount = 0;
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
		int value = (int)letter;
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
		remove_amount++;
	}
}

int Hash::doubleFormula(int result, int incrament) {
	return ((result % size) + ((incrament + 1) * (prime - (result % prime)))) % size;
}

int Hash::doubleHash(int result, int place, int incrament, int hash_size) {
	int temp = place;

	if (playerDatabase[place] == nullptr) {
		return place;
	}
	else {
		int temp = doubleFormula(result, incrament);
		if (playerDatabase[temp] == nullptr) {
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



void Hash::save(string name) {
	ofstream out_file(name);

	if (!out_file) {
		cout << "Can't open file" << endl;
		return;
	}

	int saved_size = real_size - remove_amount;
	out_file << saved_size << endl;
	for (int i = 0; i < size; i++) {
		if (playerDatabase[i] == nullptr) {
			continue;
		}
		else if (playerDatabase[i]->toRemove) {
			continue;
		}
		else {
			out_file << playerDatabase[i]->player->to_export() << endl;
		}
	}
	cout << "Save successful" << endl;
}


/*
* description: function to parse data from a txt file of a player name and stats and add it to the tree
* pre condition: must have a valid string line of stats to parse
* post condition: adds the data if it is formatted and has the needed info, then returns true, otherwise
* returns false
*/
bool Hash::add(string line) {

	/*
	* uses string stream to parse the data and a bool to flag if the input is bad
	*/
	stringstream stream(line);
	bool good_input = true;


	/*
	* variables to hold the string info of the stats
	*/
	string first_name;
	string last_name;
	string position;
	string string_depth;
	string string_ff;
	string string_passing_yards;
	string string_rushing_yards;
	string string_receiving_yards;
	string string_passing_td;
	string string_rushing_td;
	string string_receiving_td;
	string string_carries;
	string string_receptions;
	string string_targets;
	string string_fumbles;
	string string_interceptions;
	string extra_input;

	string string_ten;
	string string_twenty;
	string string_thirty;
	string string_forty;
	string string_fifty;
	string string_fiftyPlus;
	string string_miss;

	string string_sacks;
	string string_points_allowed;

	/*
	* non string variables to be filled and passed into the Player constructor to add them to the BST
	*/
	int depth;
	double ff_points;
	double passing_yards;
	double rushing_yards;
	double receiving_yards;
	int passing_td;
	int rushing_td;
	int receiving_td;
	int carries;
	int receptions;
	int targets;
	int fumbles;
	int interceptions;

	int ten;
	int twenty;
	int thirty;
	int forty;
	int fifty;
	int fiftyPlus;
	int miss;

	int sacks;
	int points_allowed;


	/*
	* if there a info for a name and position then proceed, if not flag as bad input
	*/
	if (stream >> first_name && stream >> last_name && stream >> position) {

		/*
		* depending on the position make sure you have all the info and if so insert it into the BST and if not
		* flag as bad input
		*/
		if (position == "QB") {

			if (stream >> string_ff &&
				stream >> string_passing_yards &&
				stream >> string_rushing_yards &&
				stream >> string_passing_td &&
				stream >> string_rushing_td &&
				stream >> string_fumbles &&
				stream >> string_interceptions) {

				if (stream >> extra_input) {
					good_input = false;
					return good_input;
				}

				/*
				* converts string data to the correct numerical data type
				*/
				ff_points = stod(string_ff);
				passing_yards = stod(string_passing_yards);
				rushing_yards = stod(string_rushing_yards);
				passing_td = stoi(string_passing_td);
				rushing_td = stoi(string_rushing_td);
				fumbles = stoi(string_fumbles);
				interceptions = stoi(string_interceptions);

				Player* new_player = new Player(first_name, last_name, position, ff_points, passing_yards, rushing_yards, passing_td, rushing_td, fumbles, interceptions);

				insert(new_player);

				new_player = nullptr;
			}
			else {
				good_input = false;
			}
		}
		else if (position == "RB" || position == "WR" || position == "TE") {
			if (stream >> string_depth &&
				stream >> string_ff &&
				stream >> string_receiving_yards &&
				stream >> string_rushing_yards &&
				stream >> string_receiving_td &&
				stream >> string_rushing_td &&
				stream >> string_carries &&
				stream >> string_receptions &&
				stream >> string_targets &&
				stream >> string_fumbles) {

				if (stream >> extra_input) {
					good_input = false;
					return good_input;
				}

				depth = stoi(string_depth);
				ff_points = stod(string_ff);
				receiving_yards = stod(string_receiving_yards);
				rushing_yards = stod(string_rushing_yards);
				receiving_td = stoi(string_receiving_td);
				rushing_td = stoi(string_rushing_td);
				carries = stoi(string_carries);
				receptions = stoi(string_receptions);
				targets = stoi(string_targets);
				fumbles = stoi(string_fumbles);

				Player* new_player = new Player(first_name, last_name, position, depth, ff_points, receiving_yards, rushing_yards, receiving_td, rushing_td, carries, receptions, targets, fumbles);

				insert(new_player);

				new_player = nullptr;
			}
			else {
				good_input = false;
			}

		}
		else if (position == "K") {
			if (stream >> string_ff &&
				stream >> string_ten &&
				stream >> string_twenty &&
				stream >> string_thirty &&
				stream >> string_forty &&
				stream >> string_fifty &&
				stream >> string_fiftyPlus &&
				stream >> string_miss) {

				if (stream >> extra_input) {
					good_input = false;
					return good_input;
				}

				ff_points = stod(string_ff);
				ten = stoi(string_ten);
				twenty = stoi(string_twenty);
				thirty = stoi(string_thirty);
				forty = stoi(string_forty);
				fifty = stoi(string_fifty);
				fiftyPlus = stoi(string_fiftyPlus);
				miss = stoi(string_miss);

				Player* new_player = new Player(first_name, last_name, position, ff_points, ten, twenty, thirty, forty, fifty, fiftyPlus, miss);
				insert(new_player);
				new_player = nullptr;
			}
			else {
				good_input = false;
			}
		}
		else if (position == "DEF") {
			if (stream >> string_ff &&
				stream >> string_interceptions &&
				stream >> string_sacks &&
				stream >> string_fumbles &&
				stream >> string_points_allowed) {

				if (stream >> extra_input) {
					good_input = false;
					return good_input;
				}

				ff_points = stod(string_ff);
				interceptions = stoi(string_interceptions);
				sacks = stoi(string_fumbles);
				fumbles = stoi(string_fumbles);
				points_allowed = stoi(string_points_allowed);


				Player* new_player = new Player(first_name, last_name, position, ff_points, interceptions, sacks, fumbles, points_allowed);
				insert(new_player);
				new_player = nullptr;
			}
			else {
				good_input = false;
			}
		}
		else {
			good_input = false;
		}


		return good_input;
	}
	return good_input;

}

void Hash::load(string name) {
	ifstream in_file;
	int new_size;
	in_file.open(name);

	if (!in_file) {
		cout << "File failed to open" << endl;
		return;
	}
	string line;

	if (getline(in_file, line)) {
		new_size = stoi(line);
	}
	else {
		cout << "cannot find size" << endl;
		return;
	}
	

	cout << "destroying" << endl;
	destroy();

	remove_amount = 0;

	if (new_size < 5) {
		size = new_size * 10;
	}
	else if (new_size < 10) {
		size = new_size * 5;
	}
	else {
		size = new_size * 3;
	}


	cout << size << endl;

	playerDatabase.resize(size, nullptr);

	prime = findNextPrime(size);

	while (getline(in_file, line)) {
		add(line);
	}

	
}

void Hash::destroy() {
	for (int i = 0; i < size; i++) {
		if (playerDatabase[i] == nullptr) {
			continue;
		}
		else {
			Player* remove = playerDatabase[i]->player;
			delete playerDatabase[i];
			delete remove;
			playerDatabase[i] = nullptr;
			remove = nullptr;
		}
	}
	playerDatabase.clear();
	real_size = 0;
}

Hash::~Hash() {
	destroy();
}