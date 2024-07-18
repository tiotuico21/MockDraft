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

		TreeNode* root;
		Player** ranking;
		int player_amount;

		/*
		* 
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
		BST() {
			root = nullptr;
			ranking = new Player * [100];
			for (int i = 0; i < 100; i++) {
				ranking[i] = nullptr;
			}
			player_amount = 0;
		}

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

		~BST();




};

#endif
