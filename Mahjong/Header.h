#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <corecrt_math_defines.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#define _USE_MATH_DEFINES
#define SFML_STATIC

using namespace sf;
using std::string;
using std::vector;
using std::to_string;
using std::getline;
using std::cin;
using std::pair;
using std::ifstream;

string status = "screensaver";

const int WidthWin = 1600;
const int HeightWin = 800;

const int WidthDice = 64;
const int HeightDice = 84;
const double ShiftLevel = 4;
const double ShiftWidth = 300;

string FonWin = "Image/screensaver.jpg";
string FontText = "Font/NT Somic/NT Somic-VF.ttf";// шрифт
Font font;

class Dice;
vector<Texture> textures;// текстуры костей
vector<Dice> V_dice;// массив костей

// Иконки
const int radReStart = 30;
CircleShape ButReStart(radReStart);
const int MenuWiHe = radReStart * 2;
RectangleShape ButMenu(Vector2f(MenuWiHe, MenuWiHe));

// Кнопки меню
const int widthBtn = 200, heightBtn = 40;
RectangleShape BtnMenuPlay(Vector2f(widthBtn, heightBtn));
RectangleShape BtnMenuReStart(Vector2f(widthBtn, heightBtn));
RectangleShape BtnMenuMap(Vector2f(widthBtn, heightBtn));
RectangleShape BtnMenuFon(Vector2f(widthBtn, heightBtn));
RectangleShape BtnMenuDice(Vector2f(widthBtn, heightBtn));
RectangleShape BtnMenuExit(Vector2f(widthBtn, heightBtn));

void getTextureDice() {
	vector<string> Names;
	ifstream in("Image/Name.txt");
	if (in.is_open())
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

void preloading() {
	getTextureDice();

	font.loadFromFile(FontText);

	int interval = 50;
    BtnMenuPlay.setFillColor(Color(255, 184, 65));
    BtnMenuPlay.setOutlineThickness(-3);
    BtnMenuPlay.setOutlineColor(Color(0, 0, 0));
    BtnMenuPlay.setPosition(WidthWin / 2 - widthBtn / 2, HeightWin / 2 - heightBtn / 2 - interval / 2 * 5);

	BtnMenuReStart.setFillColor(Color(255, 184, 65));
	BtnMenuReStart.setOutlineThickness(-3);
	BtnMenuReStart.setOutlineColor(Color(0, 0, 0));
	BtnMenuReStart.setPosition(WidthWin / 2 - widthBtn / 2, HeightWin / 2 - heightBtn / 2 - interval / 2 * 3);

	BtnMenuMap.setFillColor(Color(255, 184, 65));
	BtnMenuMap.setOutlineThickness(-3);
	BtnMenuMap.setOutlineColor(Color(0, 0, 0));
	BtnMenuMap.setPosition(WidthWin / 2 - widthBtn / 2, HeightWin / 2 - heightBtn / 2 - interval / 2);

	BtnMenuFon.setFillColor(Color(255, 184, 65));
	BtnMenuFon.setOutlineThickness(-3);
	BtnMenuFon.setOutlineColor(Color(0, 0, 0));
	BtnMenuFon.setPosition(WidthWin / 2 - widthBtn / 2, HeightWin / 2 - heightBtn / 2 + interval / 2);

	BtnMenuDice.setFillColor(Color(255, 184, 65));
	BtnMenuDice.setOutlineThickness(-3);
	BtnMenuDice.setOutlineColor(Color(0, 0, 0));
	BtnMenuDice.setPosition(WidthWin / 2 - widthBtn / 2, HeightWin / 2 - heightBtn / 2 + interval / 2 * 3);

	BtnMenuExit.setFillColor(Color(255, 184, 65));
	BtnMenuExit.setOutlineThickness(-3);
	BtnMenuExit.setOutlineColor(Color(0, 0, 0));
	BtnMenuExit.setPosition(WidthWin / 2 - widthBtn / 2, HeightWin / 2 - heightBtn / 2 + interval / 2 * 5);

}