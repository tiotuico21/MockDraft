//Ryan Tiotuico
//BST class to be used for general mock draft functions 
//allows you to store player data in a binary search tree structure and mock draft players

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Player.h"
using namespace std;
#ifndef BST_H
#define BST_H

const int LIMIT = 1000;
class BST {
private:
	/*
	* struct for binary search tree Nodes with a Player class object and pointers for the right and left leaf
	*/
	struct TreeNode {
		Player* player;
		TreeNode* right;
		TreeNode* left;
	};

	/*
	* member variable for BST that will make searching faster and store the data alphabetically by last name
	*/
	TreeNode* root;
	/*
	* member variable for 1D array to store all the players and allow them to be sorted by various member variables
	*/
	Player** ranking;
	/*
	* 2D array to be container to simulate a round mock draft of however many teams the user wants
	*/
	Player*** mock_draft;
	/*
	* tracks how many players added into data structure to make sorting possible
	*/
	int player_amount;

	/*
	* private functions for recursion and sorting
	*/
	TreeNode* insert(Player* new_player, TreeNode* root);
	TreeNode* search(string name, TreeNode* root);
	TreeNode* parent(string name, TreeNode* root);
	TreeNode* successor(string name, TreeNode* root);
	TreeNode* findMin(TreeNode* root);
	TreeNode* remove(string name, TreeNode* root);
	void exportTree(ofstream& out_file, TreeNode* root);
	void display(TreeNode* root);
	void destroy(TreeNode* root);
	int partition(string category, int beginning, int end);
	void sortByViabilityHelper(string category, int beg, int end);


public:
	/*
	* one constructor that will always create an empty tree first
	*/
	BST();

	/*
	* public functions to be called outside class including a destructor
	*/
	void removeInArray(string name);
	void pubInsert(Player* new_player);
	void pubDisplay();
	void rankingDisplay();
	void pubSearch(string name);
	void pubParent(string name);
	void pubSuccessor(string name);
	void pubRemove(string name);
	bool add(string line);
	void load(string name);
	void save(string name);
	void pubDestroy();
	int randomizedPartition(string category, int beg, int end);
	void sortByViability(string category);

	void takeMockDraft(int teams, int rounds);
	void displayDraft(int teams, int rounds);

	void displayDirections();

	~BST();




};

#endif 