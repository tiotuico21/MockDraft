//Ryan Tiotuico
//Player class for mock draft simulator
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;
#ifndef PLAYER_H
#define PLAYER_H

const double QB_FF_LOWERBOUND = 239;
const double QB_FF_UPPERBOUND = 259;
const double QB_PYD_LOWERBOUND = 3524;
const double QB_PYD_UPPERBOUND = 3724;
const double QB_RUSHYD_LOWERBOUND = 170;
const double QB_RUSHYD_UPPERBOUND = 300;
const int QB_PTD_LOWERBOUND = 17;
const int QB_PTD_UPPERBOUND = 24;
const int QB_RUSHTD_LOWERBOUND = 2;
const int QB_RUSHTD_UPPERBOUND = 5;
const int QB_FUMBLES_LOWERBOUND = 2;
const int QB_FUMBLES_UPPERBOUND = 6;
const int QB_INTERCEPTIONS_LOWERBOUND = 7;
const int QB_INTERCEPTIONS_UPPERBOUND = 11;

const double RB_FF_LOWERBOUND = 160;
const double RB_FF_UPPERBOUND = 180;
const double RB_RECYD_LOWERBOUND = 296;
const double RB_RECYD_UPPERBOUND = 346;
const double RB_RUSHYD_LOWERBOUND = 942;
const double RB_RUSHYD_UPPERBOUND = 962;
const int RB_RECTD_LOWERBOUND = 1;
const int RB_RECTD_UPPERBOUND = 5;
const int RB_RUSHTD_LOWERBOUND = 4;
const int RB_RUSHTD_UPPERBOUND = 8;
const int RB_CARRIES_LOWERBOUND = 209;
const int RB_CARRIES_UPPERBOUND = 239;
const int RB_REC_LOWERBOUND = 35;
const int RB_REC_UPPERBOUND = 45;
const int RB_TARGETS_LOWERBOUND = 49;
const int RB_TARGETS_UPPERBOUND = 69;
const int RB_FUMBLES_LOWERBOUND = 1;
const int RB_FUMBLES_UPPERBOUND = 3;

const double WR_FF_LOWERBOUND = 105;
const double WR_FF_UPPERBOUND = 125;
const double WR_RECYD_LOWERBOUND = 852;
const double WR_RECYD_UPPERBOUND = 942;
const double WR_RUSHYD_LOWERBOUND = 20;
const double WR_RUSHYD_UPPERBOUND = 40;
const int WR_RECTD_LOWERBOUND = 5;
const int WR_RECTD_UPPERBOUND = 9;
const int WR_RUSHTD_LOWERBOUND = 0;
const int WR_RUSHTD_UPPERBOUND = 1;
const int WR_CARRIES_LOWERBOUND = 3;
const int WR_CARRIES_UPPERBOUND = 7;
const int WR_REC_LOWERBOUND = 55;
const int WR_REC_UPPERBOUND = 75;
const int WR_TARGETS_LOWERBOUND = 87;
const int WR_TARGETS_UPPERBOUND = 117;
const int WR_FUMBLES_LOWERBOUND = 0;
const int WR_FUMBLES_UPPERBOUND = 1;

const double TE_FF_LOWERBOUND = 67;
const double TE_FF_UPPERBOUND = 87;
const double TE_RECYD_LOWERBOUND = 285;
const double TE_RECYD_UPPERBOUND = 325;
const double TE_RUSHYD_LOWERBOUND = 0;
const double TE_RUSHYD_UPPERBOUND = 5;
const int TE_RECTD_LOWERBOUND = 3;
const int TE_RECTD_UPPERBOUND = 5;
const int TE_RUSHTD_LOWERBOUND = 0;
const int TE_RUSHTD_UPPERBOUND = 1;
const int TE_CARRIES_LOWERBOUND = 0;
const int TE_CARRIES_UPPERBOUND = 1;
const int TE_REC_LOWERBOUND = 45;
const int TE_REC_UPPERBOUND = 55;
const int TE_TARGETS_LOWERBOUND = 64;
const int TE_TARGETS_UPPERBOUND = 84;
const int TE_FUMBLES_LOWERBOUND = 0;
const int TE_FUMBLES_UPPERBOUND = 1;

const double K_FF_LOWERBOUND = 126;
const double K_FF_UPPERBOUND = 136;
const int K_TWENTY_LOWERBOUND = 6;
const int K_TWENTY_UPPERBOUND = 8;
const int K_THIRTY_LOWERBOUND = 7;
const int K_THIRTY_UPPERBOUND = 9;
const int K_FORTY_LOWERBOUND = 5;
const int K_FORTY_UPPERBOUND = 7;
const int K_FIFTY_LOWERBOUND = 2;
const int K_FIFTY_UPPERBOUND = 4;

const double DEF_FF_LOWERBOUND = 114;
const double DEF_FF_UPPERBOUND = 134;
const int DEF_PA_LOWERBOUND = 14;
const int DEF_PA_UPPERBOUND = 21;
const int DEF_SACK_LOWERBOUND = 40;
const int DEF_SACK_UPPERBOUND = 50;
const int DEF_INT_LOWERBOUND = 11;
const int DEF_INT_UPPERBOUND = 17;
const int DEF_FUMBLES_LOWERBOUND = 11;
const int DEF_FUMBLES_UPPERBOUND = 13;

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
	int receptions; 
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

	int adp;

	vector<string> pros;
	vector<string> cons;
	vector<string> avg;

	double playerPerfScore = 0; 
	bool evalMade;



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
		this->ten = 0;
		this->twenty = 0;
		this->thirty = 0;
		this->forty = 0;
		this->fifty = 0;
		this->fiftyPlus = 0;
		this->miss = 0;

		this->sacks = 0;
		this->points_allowed = 0;

		adp = 0;

		/*
		* a weighted calculation to create a uniform way for users to decide what player they should draft at a specific pick
		*/
		this->viability = (ff_points * 0.2)+(passing_yards * 0.10) + (rushing_yards * 1.01) + (passing_td * 4) + (rushing_td * 8)
			- fumbles - interceptions - this->depth * 4;

		this->pros = vector<string>(0);
		this->cons= vector<string>(0);
		this->avg = vector<string>(0);

		playerPerfScore = 0;
		evalMade = false; 

	}
	Player(string first_name, string last_name, string position, int depth, double ff_points, double receiving_yards,
		double rushing_yards, int receiving_td, int rushing_td, int carries, int receptions, int targets, int fumbles) {
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
		this->receptions = receptions; 
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


		adp = 0;

		if (position == "WR" || position == "TE") {
			this->viability = (ff_points) + (receiving_yards)+(rushing_yards * 1.02) + (receiving_td * 6) +
				(rushing_td * 6.28) + (carries * 1.01) + (receptions * 1.50) + (targets * 1.25) - fumbles - depth * 200;
		}
		else {
			this->viability = ff_points + (rushing_yards)+(receiving_yards * 1.02) + (rushing_td * 6) +
				(receiving_td * 6.25) + (carries * 0.01) + (targets * 1.3) + (receptions * 1.6) - fumbles - depth * 200;
		}
		this->taken = false;


		this->pros = vector<string>(0);
		this->cons = vector<string>(0);
		this->avg = vector<string>(0);

		playerPerfScore = 0;
		evalMade = false;

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


		adp = 0;


		this->pros = vector<string>(0);
		this->cons = vector<string>(0);
		this->avg = vector<string>(0);

		playerPerfScore = 0;
		evalMade = false;

		

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


		adp = 0;


		this->pros = vector<string>(0);
		this->cons = vector<string>(0);
		this->avg = vector<string>(0);

		playerPerfScore = 0;
		evalMade = false;


	}


	void insertProsAndCons(double scores, string category) {
		if (scores > 1) {
			pros.push_back(category);
		}
		else if (scores < -1) {
			cons.push_back(category);
		}
		else {
			avg.push_back(category);
		}
	}

	void insertProsAndConsException(double score, string category) {
		if (score > 1) {
			cons.push_back(category);
		}
		else if (score < -1) {
			pros.push_back(category);
		}
		else {
			avg.push_back(category);
		}
	}

	double getEvalScore(int lower_bound, int upper_bound, int stat) {
		if (stat <= upper_bound && stat >= lower_bound) {
			return 0;
		}
		else if (stat > upper_bound) {
			return (stat - upper_bound);
		}
		else {
			return (stat - lower_bound);
		}
	}

	double getEvalScore(double lower_bound, double upper_bound, double stat) {
		if (stat <= upper_bound && stat >= lower_bound) {
			return 0;
		}
		else if (stat > upper_bound) {
			return (stat - upper_bound);
		}
		else {
			return (stat - lower_bound);
		}
	}

	void displayProsAndCons() {
		cout << "Pros" << endl;
		for (int i = 0; i < (int) pros.size(); i++) {
			cout << pros[i] << endl;
		}
		cout << endl;
		cout << "Cons" << endl;

		for (int i = 0; i < (int) cons.size(); i++) {
			cout << cons[i] << endl;
		}
		cout << endl;

		cout << endl;
		cout << "Avg" << endl;

		for (int i = 0; i < (int) avg.size(); i++) {
			cout << avg[i] << endl;
		}
		cout << endl;

	}


	void rbEval() {
		double ff_points_eval_score = getEvalScore(RB_FF_LOWERBOUND, RB_FF_UPPERBOUND, ff_points);
		double rushing_yards_eval_score = getEvalScore(RB_RUSHYD_LOWERBOUND, RB_RUSHYD_UPPERBOUND, rushing_yards);
		double receiving_yards_eval_score = getEvalScore(RB_RECYD_LOWERBOUND, RB_RECYD_UPPERBOUND, receiving_yards);
		double rushing_td_eval_score = getEvalScore(RB_RUSHTD_LOWERBOUND, RB_RUSHTD_UPPERBOUND, rushing_td);
		double rec_td_eval_score = getEvalScore(RB_RECTD_LOWERBOUND, RB_RECTD_UPPERBOUND, receiving_td);
		double carries_eval_score = getEvalScore(RB_CARRIES_LOWERBOUND, RB_CARRIES_UPPERBOUND, carries);
		double rec_eval_score = getEvalScore(RB_REC_LOWERBOUND, RB_REC_UPPERBOUND, receptions);
		double targets_eval_score = getEvalScore(RB_TARGETS_LOWERBOUND, RB_TARGETS_UPPERBOUND, targets);
		double fumbles_eval_score = getEvalScore(RB_FUMBLES_LOWERBOUND, RB_FUMBLES_UPPERBOUND, fumbles);

		insertProsAndCons(ff_points_eval_score, "Fantasy Football Points");
		insertProsAndCons(rushing_yards_eval_score, "Rushing Yards");
		insertProsAndCons(receiving_yards_eval_score, "Receiving Yards");
		insertProsAndCons(rushing_td_eval_score, "Rushing Touchdowns");
		insertProsAndCons(rec_td_eval_score, "Receiving Touchdowns");
		insertProsAndCons(carries_eval_score, "Carries");
		insertProsAndCons(rec_eval_score, "Receptions"); 
		insertProsAndCons(targets_eval_score, "Targets");
		insertProsAndConsException(fumbles_eval_score, "Fumbles");
	}

	void wrEval() {
		double ff_points_eval_score = getEvalScore(WR_FF_LOWERBOUND, WR_FF_UPPERBOUND, ff_points);
		double receiving_yards_eval_score = getEvalScore(WR_RECYD_LOWERBOUND, WR_RECYD_UPPERBOUND, receiving_yards);
		double rushing_yards_eval_score = getEvalScore(WR_RUSHYD_LOWERBOUND, WR_RUSHYD_UPPERBOUND, rushing_yards);
		double rec_td_eval_score = getEvalScore(WR_RECTD_LOWERBOUND, WR_RECTD_UPPERBOUND, receiving_td);
		double rushing_td_eval_score = getEvalScore(WR_RUSHTD_LOWERBOUND, WR_RUSHTD_UPPERBOUND, rushing_td);
		double rec_eval_score = getEvalScore(WR_REC_LOWERBOUND, WR_REC_UPPERBOUND, receptions);
		double targets_eval_score = getEvalScore(WR_TARGETS_LOWERBOUND, WR_TARGETS_UPPERBOUND, targets);
		double carries_eval_score = getEvalScore(WR_CARRIES_LOWERBOUND, WR_CARRIES_UPPERBOUND, carries);
		double fumbles_eval_score = getEvalScore(WR_FUMBLES_LOWERBOUND, WR_FUMBLES_UPPERBOUND, fumbles);

		insertProsAndCons(ff_points_eval_score, "Fantasy Football Points");
		insertProsAndCons(receiving_yards_eval_score, "Receiving Yards");
		insertProsAndCons(rushing_yards_eval_score, "Rushing Yards");
		insertProsAndCons(rec_td_eval_score, "Receiving Touchdowns");
		insertProsAndCons(rushing_td_eval_score, "Rushing Touchdowns");
		insertProsAndCons(rec_eval_score, "Receptions");
		insertProsAndCons(targets_eval_score, "Targets");
		insertProsAndCons(carries_eval_score, "Carries");
		insertProsAndConsException(fumbles_eval_score, "Fumbles");

	}

	void teEval() {
		double ff_points_eval_score = getEvalScore(TE_FF_LOWERBOUND, TE_FF_UPPERBOUND, ff_points);
		double receiving_yards_eval_score = getEvalScore(TE_RECYD_LOWERBOUND, TE_RECYD_UPPERBOUND, receiving_yards);
		double rushing_yards_eval_score = getEvalScore(TE_RUSHYD_LOWERBOUND, TE_RUSHYD_UPPERBOUND, rushing_yards);
		double rec_td_eval_score = getEvalScore(TE_RECTD_LOWERBOUND, TE_RECTD_UPPERBOUND, receiving_td);
		double rushing_td_eval_score = getEvalScore(TE_RUSHTD_LOWERBOUND, TE_RUSHTD_UPPERBOUND, rushing_td);
		double rec_eval_score = getEvalScore(TE_REC_LOWERBOUND, TE_REC_UPPERBOUND, receptions);
		double targets_eval_score = getEvalScore(TE_TARGETS_LOWERBOUND, TE_TARGETS_UPPERBOUND, targets);
		double carries_eval_score = getEvalScore(TE_CARRIES_LOWERBOUND, TE_CARRIES_UPPERBOUND, carries);
		double fumbles_eval_score = getEvalScore(TE_FUMBLES_LOWERBOUND, TE_FUMBLES_UPPERBOUND, fumbles);

		insertProsAndCons(ff_points_eval_score, "Fantasy Football Points");
		insertProsAndCons(receiving_yards_eval_score, "Receiving Yards");
		insertProsAndCons(rushing_yards_eval_score, "Rushing Yards");
		insertProsAndCons(rec_td_eval_score, "Receiving Touchdowns");
		insertProsAndCons(rushing_td_eval_score, "Rushing Touchdowns");
		insertProsAndCons(rec_eval_score, "Receptions");
		insertProsAndCons(targets_eval_score, "Targets");
		insertProsAndCons(carries_eval_score, "Carries");
		insertProsAndConsException(fumbles_eval_score, "Fumbles");
	}

	void qbEval(){
		double ff_points_eval_score = getEvalScore(QB_FF_LOWERBOUND, QB_FF_UPPERBOUND, ff_points);
		double passing_yards_eval_score = getEvalScore(QB_PYD_LOWERBOUND, QB_FF_UPPERBOUND, passing_yards);
		double rushing_yards_eval_score = getEvalScore(QB_RUSHYD_LOWERBOUND, QB_RUSHYD_UPPERBOUND, rushing_yards);
		double passing_td_eval_score = getEvalScore(QB_PTD_LOWERBOUND, QB_PTD_UPPERBOUND, passing_td);
		double rushing_td_eval_score = getEvalScore(QB_RUSHTD_LOWERBOUND, QB_RUSHTD_UPPERBOUND, rushing_td);
		double fumbles_eval_score = getEvalScore(QB_FUMBLES_LOWERBOUND, QB_FUMBLES_UPPERBOUND, fumbles);
		double interceptions_eval_score = getEvalScore(QB_INTERCEPTIONS_LOWERBOUND, QB_INTERCEPTIONS_UPPERBOUND, interceptions);

		playerPerfScore = passing_td_eval_score + rushing_yards_eval_score + passing_td_eval_score + rushing_td_eval_score - (fumbles_eval_score + interceptions_eval_score);

		insertProsAndCons(ff_points_eval_score, "Fantasy Football Points");
		insertProsAndCons(passing_yards_eval_score, "Passing Yards");
		insertProsAndCons(rushing_yards_eval_score, "Rushing Yards");
		insertProsAndCons(passing_td_eval_score, "Passing Touchdowns");
		insertProsAndCons(rushing_td_eval_score, "Rushing Touchdowns");
		insertProsAndConsException(fumbles_eval_score, "Fumbles");;
		insertProsAndConsException(interceptions_eval_score, "Interceptions");


	}

	void kickerEval() {
		double ff_eval_score = getEvalScore(K_FF_LOWERBOUND, K_FF_UPPERBOUND, ff_points);
		double twenty_eval_score = getEvalScore(K_TWENTY_LOWERBOUND, K_TWENTY_UPPERBOUND, twenty);
		double thirty_eval_score = getEvalScore(K_THIRTY_LOWERBOUND, K_THIRTY_UPPERBOUND, thirty);
		double forty_eval_score = getEvalScore(K_FORTY_LOWERBOUND, K_FORTY_UPPERBOUND, forty);
		double fifty_eval_score = getEvalScore(K_FIFTY_LOWERBOUND, K_FIFTY_UPPERBOUND, fifty);

		insertProsAndCons(ff_eval_score, "Fantasy Points");
		insertProsAndCons(twenty_eval_score, "Twenty");
		insertProsAndCons(thirty_eval_score, "Thirty");
		insertProsAndCons(forty_eval_score, "Forty");
		insertProsAndCons(fifty_eval_score, "Fifty");
	}

	void defenseEval() {
		double ff_eval_score = getEvalScore(DEF_FF_LOWERBOUND, DEF_FF_UPPERBOUND, ff_points);
		double points_allowed_eval_score = getEvalScore(DEF_PA_LOWERBOUND, DEF_PA_UPPERBOUND, points_allowed);
		double interceptions_eval_score = getEvalScore(DEF_INT_LOWERBOUND, DEF_INT_UPPERBOUND, interceptions);
		double fumble_eval_score = getEvalScore(DEF_FUMBLES_LOWERBOUND, DEF_FUMBLES_UPPERBOUND, fumbles);
		double sacks_eval_score = getEvalScore(DEF_SACK_LOWERBOUND, DEF_SACK_UPPERBOUND, sacks);

		insertProsAndCons(ff_eval_score, "Fantasy Points");
		insertProsAndConsException(points_allowed_eval_score, "Points Allowed");
		insertProsAndCons(interceptions_eval_score, "Interceptions");
		insertProsAndCons(fumble_eval_score, "Fumbles");
		insertProsAndCons(sacks_eval_score, "Sacks");
	}
	void playerEval() {
		if (evalMade) {
			displayProsAndCons();
			return;
		}
		if (position == "QB") {
			qbEval();
			evalMade = true;
			displayProsAndCons();
		}
		else if (position == "RB") {
			rbEval();
			evalMade = true;
			displayProsAndCons();
		}
		else if (position == "WR") {
			wrEval();
			evalMade = true;
			displayProsAndCons();
		}
		else if (position == "TE") {
			teEval();
			evalMade = true;
			displayProsAndCons();
		}
		else if (position == "K") {
			kickerEval();
			evalMade = true;
			displayProsAndCons();
		}
		else {
			cout << "Not available at this time" << endl;
		}
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

	void setADP(int num) {
		adp = num;
	}

	void decramentADP() {
		adp--;
	}

	int getADP() {
		return adp;
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
				<< receptions << " "
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
			cout << adp << " " << position << " " << first_name << " " << last_name << " " << viability << " " << ff_points << " " << passing_yards << endl;
		}
		else {
			cout << adp << " " << position << " " << first_name << " " << last_name << " " << viability << " " << ff_points << " " << endl;
		}
	}


};

#endif 