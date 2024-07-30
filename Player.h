//Ryan Tiotuico
//Player class for mock draft simulator
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
	/*
	* variables for all the info one player will have that must be stored
	*/
	string first_name;
	string last_name;
	string position;
	int depth;
	double ff_points;
	double passing_yards;
	double rushing_yards;
	double receiving_yards;
	int passing_td;
	int rushing_td;
	int receiving_td;
	int carries;
	int targets;
	int fumbles;
	int interceptions;
	double viability;
	bool taken;

	int ten;
	int twenty;
	int thirty;
	int forty;
	int fifty;
	int fiftyPlus;
	int miss; 

	
	int def_interceptions;
	int sacks;
	int def_fumbles;
	int points_allowed;


public:
	Player(string first_name, string last_name, string position, double ff_points,
		double passing_yards, double rushing_yards, int passing_td, int rushing_td, int fumbles, int interceptions) {
		this->first_name = first_name;
		this->last_name = last_name;
		this->position = position;
		this->depth = 100;
		this->ff_points = ff_points;
		this->passing_yards = passing_yards;
		this->rushing_yards = rushing_yards;
		this->receiving_yards = 0;
		this->passing_td = passing_td;
		this->rushing_td = rushing_td;
		this->receiving_td = 0;
		this->carries = 0;
		this->targets = 0;
		this->fumbles = fumbles;
		this->interceptions = interceptions;
		this->taken = false;
		this->interceptions = 0;

		this->ten = 0;
		this->twenty = 0;
		this->thirty = 0;
		this->forty = 0;
		this->fifty = 0;
		this->fiftyPlus = 0;
		this->miss = 0;

		this->sacks = 0;
		this->points_allowed = 0;

		/*
		* a weighted calculation to create a uniform way for users to decide what player they should draft at a specific pick
		*/
		this->viability = (ff_points)+(passing_yards * 0.10) + (rushing_yards * 1.01) + (passing_td * 4) + (rushing_td * 8)
			- fumbles - interceptions - this->depth * 4;
	}
	Player(string first_name, string last_name, string position, int depth, double ff_points, double receiving_yards,
		double rushing_yards, int receiving_td, int rushing_td, int carries, int targets, int fumbles) {
		this->first_name = first_name;
		this->last_name = last_name;
		this->position = position;
		this->depth = depth;
		this->ff_points = ff_points;
		this->passing_yards = 0;
		this->rushing_yards = rushing_yards;
		this->receiving_yards = receiving_yards;
		this->passing_td = 0;
		this->rushing_td = rushing_td;
		this->receiving_td = receiving_td;
		this->carries = carries;
		this->targets = targets;
		this->fumbles = fumbles;
		this->interceptions = 0;
		this->ten = 0;
		this->twenty = 0;
		this->thirty = 0;
		this->forty = 0;
		this->fifty = 0;
		this->fiftyPlus = 0;
		this->miss = 0;
		this->sacks = 0;
		this->points_allowed = 0;

		if (position == "WR" || position == "TE") {
			this->viability = ff_points + (receiving_yards)+(rushing_yards * 1.02) + (receiving_td * 6) +
				(rushing_td * 6.1) + (carries * 1.01) + (targets * 2) - fumbles - depth * 200;
		}
		else {
			this->viability = ff_points + (rushing_yards)+(receiving_yards * 1.05) + (rushing_td * 6) +
				(receiving_td * 6.25) + (carries)+(targets * 1.25) - fumbles - depth * 200;
		}
		this->taken = false;
	}

	Player(string first_name, string last_name, string position, double ff_points, int ten, int twenty, int thirty, int forty, int fifty, int fiftyPlus, int miss) {
		this->first_name = first_name;
		this->last_name = last_name;
		this->position = position;
		this->depth = 100;
		this->ff_points = ff_points;
		this->passing_yards = 0;
		this->rushing_yards = 0;
		this->receiving_yards = 0;
		this->passing_td = 0;
		this->rushing_td = 0;
		this->receiving_td = 0;
		this->carries = 0;
		this->targets = 0;
		this->fumbles = 0; 
		this->interceptions = 0;
		this->taken = false;
		this->ten = ten;
		this->twenty = twenty;
		this->thirty = thirty;
		this->forty = forty;
		this->fifty = fifty; 
		this->fiftyPlus = fiftyPlus;
		this->miss = miss;
		this->sacks = 0;
		this->points_allowed = 0;

		this->viability = (1 * ten) + (2 * twenty) + (3 * thirty) + (4 * forty) + (5 * fifty) + (7 * fiftyPlus) - (2 * miss);
		

	}

	Player(string city, string team, string position, double ff_points, int interceptions, int sacks, int fumbles, int points_allowed) {
		this->first_name = city;
		this->last_name = team;
		this->position = position;
		this->depth = 100;
		this->ff_points = ff_points;
		this->passing_yards = 0;
		this->rushing_yards = 0;
		this->receiving_yards = 0;
		this->passing_td = 0;
		this->rushing_td = 0;
		this->receiving_td = 0;
		this->carries = 0;
		this->targets = 0;
		this->taken = false;
		this->ten = 0;
		this->twenty = 0;
		this->thirty = 0;
		this->forty = 0;
		this->fifty = 0;
		this->fiftyPlus = 0;
		this->miss = 0;
		this->interceptions = interceptions;
		this->sacks = sacks;
		this->fumbles = fumbles;
		this->points_allowed = points_allowed;

		this->viability = (interceptions * 4) + (sacks * 2) + (fumbles * 4) - (points_allowed * 10);

	}

	double getViability() {
		return viability;
	}

	double getFFPoints() {
		return ff_points;
	}

	double getPassingYd() {
		return passing_yards;
	}

	bool getStatus() {
		return taken;
	}

	void setStatus() {
		taken = !(taken);
	}


	/*
	https://stackoverflow.com/questions/29200635/convert-float-to-string-with-precision-number-of-decimal-digits-specified
	description: prepares the data of a player into a string format to be exported into a txt file
	pre condition: must be a valid player object to apply this function on
	post condition: player data is returned as a string
	*/
	string to_export() {
		stringstream stream;
		/*
		* set all stats to two decimal places as a string
		*/
		stream << fixed << setprecision(2);
		/*
		* data to be exported dependent on the position
		*/
		if (position == "QB") {
			stream << first_name << " "
				<< last_name << " "
				<< position << " "
				<< ff_points << " "
				<< passing_yards << " "
				<< rushing_yards << " "
				<< passing_td << " "
				<< rushing_td << " "
				<< fumbles << " "
				<< interceptions;
		}
		else if (position == "TE" || position == "WR" || position == "RB"){
			stream << first_name << " "
				<< last_name << " "
				<< position << " "
				<< depth << " "
				<< ff_points << " "
				<< receiving_yards << " "
				<< rushing_yards << " "
				<< receiving_td << " "
				<< rushing_td << " "
				<< carries << " "
				<< targets << " "
				<< fumbles;
		}
		else if (position == "K") {
			stream << first_name << " "
				<< last_name << " "
				<< position << " "
				<< ff_points << " "
				<< ten << " "
				<< twenty << " "
				<< thirty << " "
				<< forty << " "
				<< fifty << " "
				<< fifty << " "
				<< fiftyPlus << " "
				<< miss << " ";
		}
		else {
			stream << first_name << " "
				<< last_name << " "
				<< position << " "
				<< ff_points << " "
				<< interceptions << " "
				<< sacks << " "
				<< fumbles << " "
				<< points_allowed; 
		}
		return stream.str();
	}

	/*
	* description: returns the name of a player
	* pre condition: none
	* post condition: returns the name of the player object
	*/
	string getName() {
		return last_name;
	}

	/*
	* description: displays info about a player
	* pre condition: none
	* post condition: displays the player
	*/
	void display() {
		if (position == "QB") {
			cout << position << " " << first_name << " " << last_name << " " << viability << " " << ff_points << " " << passing_yards << endl;
		}
		else {
			cout << position << " " << first_name << " " << last_name << " " << viability << " " << ff_points << " " << endl;
		}
	}


};

#endif 