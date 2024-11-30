#include <iostream>
#include <sstream>
#include <string>
#include "Hash.h"
#include "Player.h"
#include "BSTTemp.h"
using namespace std;

int main() {
	BST<Player, Player::LessThanFantasyPoints, Player::GreaterFantasyPoints, Player::EqualFantasyPoints> bstFF(Player::LessThanFantasyPoints(), Player::GreaterFantasyPoints(), Player::EqualFantasyPoints());

	//insatiate a player

	//insert into tree



}



