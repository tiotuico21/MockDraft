//Ryan Tiotuico
//Interface for mock draft simulator
#include <iostream>
#include <sstream>
#include <string>
#include "BST.h"
#include "Player.h"
using namespace std;

int main() {

	string line;
	BST list;
	bool done = false;
	bool bad_input = false;
	string word;

	/*
	* uses string stream as essentially a command line that takes words and if they are valid does the appropriate
	* functions including adding new entries, removing entries, saving, loading, etc
	*
	* will notify if any of your inputs are invalid
	*/

	list.displayDirections();
	while (!done && std::getline(std::cin, line)) {
		//getline(cin, line);
		std::stringstream stream(line);
		string word;
		string name;
		string extra_input;
		string category;
		string string_teams;
		string string_rounds;
		string string_pick_number;
		int teams;
		int rounds;
		int pick_number;
		bool mock_draft = false;

		stream >> word;

		bad_input = false;

		if (word == "quit" && stream >> extra_input) {
			cout << "Error: Too many arguments" << endl;
			bad_input = true;
		}
		else if (word == "quit") {
			done = true;
		}
		else if (word == "add") {
			if (line.length() <= 4) {
				bad_input = true;
			}
			else if (list.add(line.substr(4))) {
				cout << "Player added" << endl;
			}
			else {
				bad_input = true;
			}
		}
		else if (word == "assist") {
			if (!(stream >> extra_input)) {
				list.assist();
			}
			else {
				bad_input = true;
			}
		}
		else if (word == "p&c" && stream >> name) {
			if (!(stream >> extra_input)) {
				list.displayPlayerProsAndCons(name);
			}
			else {
				bad_input = true;
			}
		}
		else if (word == "print") {
			if (!(stream >> extra_input)) {
				list.pubDisplay();
			}
			else {
				bad_input = true;
			}
		}
		else if (word == "ranking") {
			if (!(stream >> extra_input)) {
				list.rankingDisplay();
			}
			else {
				bad_input = true;
			}
		}
		else if (word == "sort" && stream >> category) {
			if (!(stream >> extra_input)) {
				list.sortByViability(category);
				list.rankingDisplay();
			}
			else {
				bad_input = true;
			}
		}
		else if (word == "search" && stream >> name) {
			if (stream >> extra_input) {
				bad_input = true;
			}
			else {
				list.pubSearch(name);
			}
		}
		else if (word == "remove" && stream >> name) {
			if (stream >> extra_input) {
				bad_input = true;
			}
			else {
				list.pubRemove(name);
			}
		}
		else if (word == "load" && stream >> name) {
			if (stream >> extra_input) {
				bad_input = true;
			}
			else {
				list.load(name);
			}
		}
		else if (word == "save" && stream >> name) {
			if (stream >> extra_input) {
				bad_input = true;
			}
			else {
				list.save(name);
			}
		}
		else if (word == "mock" && stream >> string_teams && stream >> string_rounds && stream >> string_pick_number) {
			if (stream >> extra_input) {
				bad_input = true;
			}
			else {
				teams = stoi(string_teams);
				rounds = stoi(string_rounds);
				pick_number = stoi(string_pick_number);
				list.takeMockDraft(teams, rounds, pick_number);
			}
		}
		else if (word == "directions") {
			if (stream >> extra_input) {
				bad_input = true;
			}
			else {
				list.displayDirections();
			}
		}
		else {
			bad_input = true;
		}
		if (!mock_draft && bad_input) {
			cout << "Please try again" << endl;
		}
		else {
			cout << "-------------------------------" << endl;
		}

	}
}