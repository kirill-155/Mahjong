#pragma once
#include <fstream>
#include "Header.h"
#include "Dice.h"

using std::ifstream;

void Create(int map = 1) {
	ifstream in("Map/" + to_string(map));
	vector<Dice> V_dice;

}