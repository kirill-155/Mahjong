#pragma once
#include <fstream>
#include "Header.h"
#include "Dice.h"

void getTextureDice() {
	vector<string> Names;
	ifstream in("Image/Name.txt");
	if(in.is_open())
		while (!in.eof())
		{
			string Name;
			in >> Name;
			Names.push_back(Name);
		}
	in.close();

	textures.resize(Names.size());
	for (int i = 0; i < Names.size(); i++)
	{
		textures[i].loadFromFile("Image/Кости_белые/" + Names[i] + ".png");
		textures[i].setSmooth(true);
	}
}

void Create(RenderWindow& window, int map = 1) {
	srand(time(0));
	getTextureDice();
	ifstream in("Map/" + to_string(map) + ".txt");
	bool f = 0;
	if(in.is_open())
	while (!in.eof())
	{
		Vector2f pos;
		in >> pos.x >> pos.y;
		int level, cnt;
		in >> level >> cnt;
		for (int i = 0; i < cnt; i++)
		{
			Dice dice;
			pos.x++;
			dice.setPosition(pos.x * WidthDice - level * ShiftLevel + ShiftWidth, pos.y * HeightDice - level * ShiftLevel);
			if (f)
				dice.IdName = V_dice[V_dice.size() - 1].IdName;
			else
				dice.IdName = rand() % textures.size();
			f = !f;
			dice.setTexture(&textures[dice.IdName]);
			V_dice.push_back(dice);
		}
	}
	in.close();
	for (int i = 0; i < V_dice.size(); i++)
	{
		swap(V_dice[i], V_dice[rand() % V_dice.size()]);
	}
}