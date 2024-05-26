#pragma once
#include "Header.h"
#include "Dice.h"

void Update(RenderWindow& window) {
	for (int i = 0; i < V_dice.size(); i++)
		window.draw(V_dice[i]);
}