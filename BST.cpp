//Ryan Tiotuico
//cpp file for BST class
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip> 
#include <string>
#include "BST.h"
#include "Player.h"
using namespace std;

/*
* description: allocates memory for a new Node and correctly adds it to the right position of
* the binary search tree of Player objects
* pre condition: must have an already dynamically allocated player pointer and an instantiated root object
* post condition: Tree Node correctly added to the correct place of the binary search tree and returns this 
* modified tree
*/
BST::TreeNode* BST::insert(Player* new_player, TreeNode* root) {
	/*
	* if the tree is enmpty allocate memory for a new TreeNode object with the inputed player pointer
	* and set its leafs to nullptr
	*/
	if (root == nullptr) {
		root = new TreeNode();
		root->player = new_player;
		root->left = nullptr;
		root->right = nullptr;
		ranking[player_amount] = new_player;
		player_amount++;
		cout << "------------------" << endl;
		cout << player_amount << endl;
		cout << "------------------" << endl;
		
	}
	/*
	* else if the Node you are at has a name that is earlier in the alphabet than the 
	* player pointer name you want to add, then move to the right of the BST
	*/
	else if (new_player->getName() > root->player->getName()) {
		root->right = insert(new_player, root->right);
	}
	/*
	* else if the Node you are at has a name that is later in the alphabet than the
	* player pointer name you want to add, then move to the left of the BST
	*/
	else {
		root->left = insert(new_player, root->left);
	}

	/*
	* return the modified tree 
	*/
	return root;
}

/*
* description: public function to test the accuracy of our insert function 
* pre condition: takes a already allocated player pointer 
* post condition: Node with the inputted player pointer correctly added into the tree and returns nothing 
*/
void BST::pubInsert(Player* new_player) {
	root = insert(new_player, root);
}

/*
* description: uses inorder traveral to display all the Nodes presently in the tree
* pre condition: must have an already instantiated root object and it must not be emoty if you want it to display something
* post condition: uses the display method in the Player class to display each node's name and stats in the BST
*/
void BST::display(TreeNode* root) {
	if (root != nullptr) {
		display(root->left);
		root->player->display();
		display(root->right);
	}
}

/*
* description: public function to imprement recursive function of display
* pre condtion: must have an already constructed BST object and a non emoty tree to display something
* or else it'll say the tree is empty
* post condtion: displays the contents of the BST
*/
void BST::pubDisplay() {
	if (root == nullptr) {
		cout << "Tree empty" << endl;
	}
	display(root);
}

void BST::rankingDisplay() {
	int i = 0;
	cout << "Player ranking" << endl;
	while (ranking[i] != nullptr) {
		ranking[i]->display();
		i++;
	}
}

/*
* description: recursively searches thru the binary tree for a specific player name
* pre condition: must have a valid string name and alreayd instatiated root
* post condition: returns nullptr or the Node with the player pointer with the matching name depending
* if it is found or not 
* 
*/
BST::TreeNode* BST::search(string name, TreeNode* root) {
	/*
	* if the tree is empty or beyond the BST then return nullptr
	*/
	if (root == nullptr) {
		return nullptr;
	}
	/*
	* return the Node if it has the matching name
	*/
	else if (root->player->getName() == name) {
		return root;
	}
	/*
	* if the Node we are on does not have the matching name and the Node has a name later in the alphabet then what we want to fund
	* go left of the BST
	*/
	else if (root->player->getName() > name) {
		return search(name, root->left);
	}
	/*
	* if the Node we are on does not have the matching name and the Node has a name earlier in the alphabet
	* go right of the BST
	*/
	else {
		return search(name, root->right);
	}
}

/*
* description: public function to implement recursive search function
* pre condition: give valid string
* post condtion: returns nothing and either displays the player or says player was not found 
*/
void BST::pubSearch(string name) {
	TreeNode* printPlayer = search(name, root);
	if (printPlayer != nullptr) {
		printPlayer->player->display();
	}
	else {
		cout << "Player not found" << endl;
	}
}

/*
* description: finds the parent of a Node with a specific name 
* pre condtion: must give valid string name and the root must have already been instantiated
* post condition: returns the TreeNode of the parent of the Node with the name we inputted 
*/
BST::TreeNode* BST::parent(string name, TreeNode* root) {
	/*
	* if the tree is empty or gone beyond the BST return nullptr 
	*/
	if (root == nullptr) {
		return nullptr;
	}
	/*
	* else if root has the desired name then also return nullptr cuz root does not have a parent 
	*/
	else if (root->player->getName() == name) {
		return nullptr;
	}
	/*
	* if the root or Node we are on does not have a matching name and has no children also return nullptr 
	*/
	else if (root->right == nullptr && root->left == nullptr) {
		return nullptr;
	}
	/*
	* if the Node we are on only has a right child do this set of conditions 
	*/
	else if (root->right != nullptr && root->left == nullptr) {
		/*
		* if the right child has the matching name to the inputted one then return the Node we are on
		*/
		if (root->right->player->getName() == name) {
			return root;
		}
		/*
		* else try to keep finding the parent as you recursively go to the right child 
		*/
		else {
			return parent(name, root->right);
		}
	}
	/*
	* if the Node we are on only has a left child do this set of conditions 
	*/
	else if (root->left != nullptr && root->right == nullptr) {
		/*
		* if the left child has the matching name to the inputted one then return the Node we are on
		*/
		if (root->left->player->getName() == name) {
			return root;
		}
		/*
		* else try to keep finding the parent as you recursively go to the left child
		*/
		else {
			return parent(name, root->left);
		}
	}
	/*
	* if the Node you are on has two children and either of the children has the matching player name
	* then return this Node 
	*/
	else if (root->left->player->getName() == name || root->right->player->getName() == name) {
		return root;
	}
	/*
	* if the Node you are on has two children and has a name later than what you are trying to find then go to the left
	*/
	else if (root->player->getName() > name) {
		return parent(name, root->left);
	}
	/*
	* if the Node you are on has two children and has a name earlier than what you are trying to find then go to the right 
	*/

	else {
		return parent(name, root->right);
	}
}

/*
* description: public gunction to implement recursive parent function
* pre condition: must input a valid string 
* post condition: display the name of the pointer that is the parent to the pointer with the inputted name
*/
void BST::pubParent(string name) {
	TreeNode* displayParent = parent(name, root);
	if (displayParent != nullptr) {
		cout << "The parent of " << name << " is "
			<< displayParent->player->getName() << endl;
	}
	else {
		cout << "No parent" << endl;
	}
}

/*
* description: gives the TreeNode pointer that is the successor to the pointer with the inputted name
* pre condition: must input a valid string and have an instatiated TreeNode object for root
* post condition: returns the pointer of the successor to Node with the inputted name and returns nullptr
* if it does not have one 
*/
BST::TreeNode* BST::successor(string name, TreeNode* root) {
	/*
	* first create a pointer to move to the Node we want to find a successor for 
	*/
	TreeNode* selectNode = search(name, root);

	/*
	* if  dthe node we want oes not exist return nullptr 
	*/
	if (selectNode == nullptr) {
		return nullptr;
	}
	/*
	* else check if there is a right child and if there is go to it and if not return nullptr because
	* a successor indeed does not exist 
	*/
	else {
		if (selectNode->right == nullptr) {
			return nullptr;
		}
		/*
		* use findMin to then go all the way left if possible from the right child to find 
		*/
		else {
			return findMin(selectNode->right);
		}
	}
}

/*
* description: find the left most Node relative to the Node you input in parameters
* pre condition: must be a valid node already allocated
* post condition: returns the Node left most of the one you passed in
*/
BST::TreeNode* BST::findMin(TreeNode* root) {
	/*
	* if what you passed in is nullptr then do not move left further
	*/
	if (root == nullptr) {
		return nullptr;
	}
	/*
	* return the passed in Node if nothing else to the left
	*/
	else if (root->left == nullptr) {
		return root;
	}
	/*
	* recursively call on the left child if stil more nodes to the left 
	*/
	else {
		return findMin(root->left);
	}
}

/*
* description: public function to implement and test recursive successor function
* pre condtion: must have a valid string passed in]
* post condition: returns the successor if any of the Node with the player name you passed in
*/
void BST::pubSuccessor(string name) {
	TreeNode* displaySuccessor = successor(name, root);
	if (displaySuccessor != nullptr) {
		cout << "Successor of " << name << " is " <<
			displaySuccessor->player->getName() << endl;
	}
	else {
		cout << "No successor" << endl;
	}
}

//at first didnt cover uniinitalized values and assigned misaligned 
void BST::removeInArray(string name) {
	Player** temp = new Player*[100];
	int temp_index = 0;
	for (int i = 0; i < 100; i++) {
		if (ranking[i] != nullptr && ranking[i]->getName() != name) {
			temp[temp_index] = ranking[i];
			temp_index++;
		}
	}
	while (temp_index < 100) {
		temp[temp_index] = nullptr;
		temp_index++;
	}
	delete[] ranking;
	ranking = temp;
	player_amount--;
}
/*
* description: removes a specific Node with the string name
* pre condition: must provide a valid string name and a root already instatiated
* post condition: returns the modified tree with the deleted Node gone
*/
BST::TreeNode* BST::remove(string name, TreeNode* root) {
	/*
	* set TreeNode pointers to the Node you want to remove and the potential parent to the Node we will be removing
	* 
	* set this pointer for the parent to nullptr as it may not necessarily be on the parent of the Node we want to remove
	* depending if it is a successor or not 
	*/
	TreeNode* remove = search(name, root);
	TreeNode* remove_parent = nullptr; 

	/*
	* set a player pointer as well for nullptr, will need when having to deallocate both the Node and the player pointer it holds 
	*/
	Player* take_out = nullptr;

	/*
	* if we cannot find the Node we need to remove notify the user and return the same tree 
	*/
	if (remove == nullptr) {
		cout << "Player not found" << endl;
		return root;
	}
	/*
	* if we want to remove a root with no children, deallocate the root accordiingly
	*/
	else if (name == root->player->getName() &&
		root->right == nullptr &&
		root->left == nullptr) {
		take_out = remove->player;
		delete root;
		delete take_out;
		root = nullptr;
		take_out = nullptr;
		return root;
	}
	/*
	* if we want to remove the root and it only has a right child then move the root to this right child
	* and delete the orginal root properly 
	*/
	else if (name == root->player->getName() &&
		root->right != nullptr &&
		root->left == nullptr) {
		take_out = remove->player;
		root = root->right;
		delete remove;
		delete take_out;
		remove = nullptr;
		take_out = nullptr;
		return root; 
	}
	/*
	* if we want to remove the root and it only has a left child then move the root to this left child
	* and delete the orginal root properly
	*/
	else if (name == root->player->getName() &&
		root->right == nullptr &&
		root->left != nullptr) {
		take_out = remove->player;
		root = root->left;
		delete remove;
		delete take_out;
		remove = nullptr;
		take_out = nullptr;
		return root;
	}
	/*
	* if it is a non root node we are trying to remve and it has no children do the following
	*/
	else if (remove->right == nullptr && remove->left == nullptr) {
		/*
		* set the TreeNode pointer we previously declared for the parent to the parent of what we want to remove
		* and depending on if its a right or left child, set that child to nullptr now and delete to node properly
		*/
		remove_parent = parent(remove->player->getName(), root);
		if (name > remove_parent->player->getName()) {
			take_out = remove->player;
			delete remove;
			delete take_out;
			remove = nullptr;
			take_out = nullptr;
			remove_parent->right = nullptr;
			return root;
		}
		else {
			take_out = remove->player;
			delete remove;
			delete take_out;
			remove = nullptr;
			take_out = nullptr;
			remove_parent->left = nullptr;
			return root;

		}
	}
	/*
	* if we are trying to delete a non root node and it only has a right child do following 
	*/
	else if (remove->right != nullptr && remove->left == nullptr) {
		/*
		* set the TreeNode pointer we declared to the parent of what we want to remove
		*/
		remove_parent = parent(remove->player->getName(), root);
		/*
		* depending on if the node we want to remove was a right or left child set the parent's link to it
		* to what we want to remove's right child 
		*/
		if (name > remove_parent->player->getName()) {
			remove_parent->right = remove->right;
		}
		else {
			remove_parent->left = remove->right;
		}

		/*
		* now delete the node accordingly
		*/
		take_out = remove->player;
		delete remove;
		delete take_out;
		remove = nullptr;
		take_out = nullptr;
		return root;
	}
	/*
	* this condition follows the same process as the one above just with a non root node for a left child 
	*/
	else if (remove->right == nullptr && remove->left != nullptr) {
		remove_parent = parent(remove->player->getName(), root);
		if (name > remove_parent->player->getName()) {
			remove_parent->right = remove->left;
		}
		else {
			remove_parent->left = remove->left;
		}

		take_out = remove->player;
		delete remove;
		delete take_out;
		remove = nullptr;
		take_out = nullptr;
		return root;
	}
	
	/*
	* if what we want to remove has two children do the following 
	*/
	else {
		/*
		* set new TreeNode pointers for the successor of what we wanna remove and the parent of this successor
		* 
		* we will be deleting the successor really as it is easier to manage memory this way 
		*/
		TreeNode* remove_successor = successor(name, root);
		TreeNode* successor_parent = parent(remove_successor->player->getName(), root);

		/*
		* swap the player pointers of what we want to remove and the successor
		*/
		Player* temp = remove->player;
		remove->player = remove_successor->player;
		remove_successor->player = temp; 


		/*
		* if the successor is directly to the right of what we want to remove as in the successor had no left child 
		* then set the parent of the successor's (which is essentially are original removed node) right child
		* to the successor's right child
		* 
		* delete the successor accordingly after
		*/
		if (remove->player->getName() == successor_parent->player->getName()) {
			remove->right = remove->right->right;
			take_out = remove_successor->player;
			delete remove_successor;
			delete take_out;
			remove_successor = nullptr;
			take_out = nullptr;
			return root;
		}
		/*
		* else check to make sure there is no right child of the successor you have to link to the parent
		* and then the delete the successor accordingly
		*/
		else {
			if (remove_successor->right != nullptr) {
				successor_parent->left = remove_successor->right;
			}
			else {
				successor_parent->left = nullptr;
			}
			take_out = remove_successor->player;
			delete remove_successor;
			delete take_out;
			remove_successor = nullptr;
			take_out = nullptr;
			return root;
		}
	}
}

/*
* description: public function to implement recursive remove function
* pre condition: must have valid string name
* post condition: removes the node with the specified name if it is there 
*/
void BST::pubRemove(string name) {
	cout << "Removing " << name << endl;
	removeInArray(name);
	root = remove(name, root);
}

/*
* description: function to parse data from a txt file of a player name and stats and add it to the tree
* pre condition: must have a valid string line of stats to parse 
* post condition: adds the data if it is formatted and has the needed info, then returns true, otherwise
* returns false 
*/
bool BST::add(string line) {

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
	string string_targets;
	string string_fumbles;
	string string_interceptions;
	string extra_input;

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
	int targets;
	int fumbles;
	int interceptions;

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

				root = insert(new_player, root);

				new_player = nullptr;
			}
			else {
				good_input = false; 
			}
		}
		else if (position == "RB" || position == "WR") {
			if (stream >> string_depth &&
				stream >> string_ff &&
				stream >> string_receiving_yards &&
				stream >> string_rushing_yards &&
				stream >> string_receiving_td &&
				stream >> string_rushing_td &&
				stream >> string_carries &&
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
				targets = stoi(string_targets);
				fumbles = stoi(string_fumbles);

				Player* new_player = new Player(first_name, last_name, position, depth, ff_points, receiving_yards, rushing_yards, receiving_td, rushing_td, carries, targets, fumbles); 

				root = insert(new_player, root);

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

/*
* description: public function to load the a txt file of data into a new BST
* pre condition: must be a valid string name of a file in your system already
* post condition: a BST is created of the players in the chosen txt file 
*/
void BST::load(string name) {
	/*
	* create a new tree
	*/
	destroy(root);
	root = nullptr;
	delete[] ranking;
	ranking = nullptr;
	player_amount = 0;
	ranking = new Player * [100];
	for (int i = 0; i < 100; i++) {
		ranking[i] = nullptr;
	}
	ifstream in_file;

	in_file.open(name);

	/*
	* notify user if cannot open file
	*/
	if (!in_file) {
		cout << "File failed to open" << endl;
		return;
	}

	string line;
	
	/*
	* each player should occupy one line of the txt so parse the file line by line
	*/
	while (getline(in_file, line)) {
		add(line);
	}
}

/*
* description: recursive function using pre order traversal to convert your BST data to strings and 
* export them to a specified outfile so you can save your work 
* pre condition: must have a valid file and string name to export to and an already instantiated tree
* post condition: adds all the data of the BST in a string format that will be able to parse into a new tree when needed
*/
void BST::exportTree(ofstream& out_file, TreeNode* root) {
	if (root != nullptr) {
		out_file << root->player->to_export() << endl;
		exportTree(out_file, root->left);
		exportTree(out_file, root->right);
	}
}

/*
* description: function to save your BST using the exportTree function above
* pre condition: must have a valid string name to make a new txt file to store the data
* post condition: saves the data into a new txt file and states the save was successful if so 
*/
void BST::save(string name) {
	ofstream out_file(name);

	if (!out_file) {
		cout << "Can't open file" << endl;
		return;
	}

	exportTree(out_file, root);

	cout << "Save successful" << endl;

}

int BST::partition(string category, int beg, int end) {
	Player* p = ranking[beg];
	int m = beg;

	for (int k = beg + 1; k <= end; k++) {
		if (category == "v") {
			if (ranking[k]->getViability() >= p->getViability()) {
				m++;
				Player* temp = ranking[m];
				ranking[m] = ranking[k];
				ranking[k] = temp;
			}
		}
		else if (category == "ff") {
			if (ranking[k]->getFFPoints() >= p->getFFPoints()) {
				m++;
				Player* temp = ranking[m];
				ranking[m] = ranking[k];
				ranking[k] = temp;
			}
		}
		else if (category == "pyd") {
			if (ranking[k]->getPassingYd() >= p->getPassingYd()) {
				m++;
				Player* temp = ranking[m];
				ranking[m] = ranking[k];
				ranking[k] = temp;
			}
		}
		else {
			return -1;
		}
	}

	ranking[beg] = ranking[m];
	ranking[m] = p;

	return m;
}

int BST::randomizedPartition(string category, int beg, int end) {
	int pos = beg + rand() % (end - beg + 1);
	Player* temp = ranking[beg];
	ranking[beg] = ranking[pos];
	ranking[pos] = temp;
	return partition(category, beg, end);

}

void BST::sortByViability(string category) {
	sortByViabilityHelper(category, 0, player_amount - 1);
}

void BST::sortByViabilityHelper(string category, int beg, int end) {
	if (beg < end) {
		int pivotIndex = randomizedPartition(category, beg, end);
		if (pivotIndex == -1) {
			cout << "Invalid Category" << endl;
			return;
		}
		sortByViabilityHelper(category, beg, pivotIndex - 1);
		sortByViabilityHelper(category, pivotIndex + 1, end);
	}
}

/*
* description: deallocates the data in the BST using post order traversal 
* pre condition: must have an already instatiated root
* post condition: BST fully deallocated
*/
void BST::destroy(TreeNode* root) {
	if (root != nullptr) {
		destroy(root->left);
		destroy(root->right);
		cout << "deleting " << root->player->getName() << endl;
		Player* take_out = root->player;
		delete root;
		delete take_out;
		take_out = nullptr;
		root = nullptr;
	}
}

/*
* description: both pubDestroy and destructor works the same way
* pre condition: have a declared BST object
* post condition: deallocates the BST tree
*/
void BST::pubDestroy() {
	delete[] ranking;
	player_amount = 0;
	destroy(root);
}

BST::~BST() {
	pubDestroy();
}