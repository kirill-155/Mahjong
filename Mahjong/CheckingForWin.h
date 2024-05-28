#pragma once
#include "Header.h"
#include "Dice.h"

bool is_block(int IdV_dice) { // проверка на блокирование кости
    Vector2f pos = V_dice[IdV_dice].getPosition();
    pos.x += WidthDice / 2.0;
    pos.y += HeightDice / 2.0;
    int cnt = 0;
    bool left = 1, rigt = 1;
    for (int i = 0; i < V_dice.size(); i++)
    {
        if (V_dice[i].level - 1 == V_dice[IdV_dice].level && V_dice[i].is_click(Vector2f(pos.x, pos.y), 15)) // если на данной кости лежит другая
            return true;
        if (left && V_dice[i].level == V_dice[IdV_dice].level && V_dice[i].is_click(Vector2f(pos.x + WidthDice, pos.y + ShiftLevel), 5))
            left = 0;
        if (rigt && V_dice[i].level == V_dice[IdV_dice].level && V_dice[i].is_click(Vector2f(pos.x - WidthDice, pos.y + ShiftLevel), 5))
            rigt = 0;
    }
    if (left || rigt)
        return false;
    return true;
}

bool CheckingForWin() { // проверка на возможность ходить
    for (int i = 0; i < V_dice.size(); i++)
    {
        if(!is_block(i))
            for (int j = 0; j < V_dice.size(); j++)
            {
                if (!is_block(j) && V_dice[i].level == V_dice[j].level && i != j && V_dice[i].IdName == V_dice[j].IdName)
                    return 1;
            }
    }
    return 0;
}