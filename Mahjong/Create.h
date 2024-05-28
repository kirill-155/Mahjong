#pragma once
#include "Header.h"
#include "Dice.h"

void Create(RenderWindow& window, int map = 1) {
	V_dice.clear();
	srand(time(0));
	ifstream in("Map/" + to_string(map) + ".txt");
	bool f = 0;
	if(in.is_open())
	while (!in.eof())
	{
		Vector2f pos;
		in >> pos.x >> pos.y;
		int level, cnt = 0;
		in >> level >> cnt;
		for (int i = 0; i < cnt; i++)
		{
			Dice dice;
			pos.x++;
			dice.level = level;
			dice.setPosition(pos.x * (WidthDice - ShiftLevel + 1) - level * ShiftLevel + ShiftWidth, pos.y * (HeightDice - ShiftLevel + 1) - level * ShiftLevel);
			if (f)
				dice.IdName = V_dice[V_dice.size() - 1].IdName;
			else
				dice.IdName = rand() % textures.size();
			f = !f;
			dice.setTexture(&textures[dice.IdName]);
			dice.setFillColor(Color(240, 240, 240));
			V_dice.push_back(dice);
		}
	}
	in.close();
	for (int i = 0; i < V_dice.size(); i++)
	{
		swap(V_dice[i], V_dice[rand() % V_dice.size()]);
	}
}