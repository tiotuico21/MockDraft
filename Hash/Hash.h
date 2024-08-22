#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Player.h"
using namespace std;
#ifndef HASH_H
#define HASH_H

class Hash {
	struct HashNode{
		Player* player;
		bool toRemove; 

		HashNode(Player* new_player, bool status) {
			player = new_player;
			toRemove = status;
		}
	};
	private:
		vector<HashNode*> playerDatabase;
		int size;
		int real_size;
		int prime;
		int doubleHash(int result, int place, int incrament, int hash_size);
		int totalCharValue(string name);
		HashNode* search(string name, int place, int temp, int incrament);
		int doubleFormula(int result, int incrament);
		int initialPlace(string name);
		void rehash();

	public:
		Hash();
		int hashName(vector<HashNode*> database, string name, int hash_size);
		void insert(Player* new_player);
		int findNextPrime(int size);
		void remove(string name);
		bool isPrime(int num);
		void display();
		Player* qbAssist(string first_name, string last_name, double ff_points);
		~Hash();

		void pubSearch(string name);
};

#endif 