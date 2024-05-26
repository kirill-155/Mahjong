#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <corecrt_math_defines.h>
#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#define SFML_STATIC

using namespace sf;
using std::string;
using std::vector;
using std::to_string;
using std::getline;
using std::cin;
using std::ifstream;

const int WidthWin = 1600;
const int HeightWin = 800;

const int WidthDice = 64;
const int HeightDice = 84;
const double ShiftLevel = 10;
const double ShiftWidth = 300;

class Dice;
vector<Texture> textures;
vector<Dice> V_dice;