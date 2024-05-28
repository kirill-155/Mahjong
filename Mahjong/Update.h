#pragma once
#include "Header.h"
#include "Dice.h"

void Update(RenderWindow& window) {
	for (int i = 0; i < V_dice.size(); i++) // ���������� ����
		window.draw(V_dice[i]);

    // �������� ������ ��������
    Texture texture;
    texture.loadFromFile("Image/Icon/update.png");
    texture.setSmooth(true);
    ButReStart.setPosition(WidthWin - radReStart * 2 - 80, 5);
    ButReStart.setTexture(&texture);
    window.draw(ButReStart);

    // �������� ������ ����
    texture.loadFromFile("Image/Icon/menu.png");
    ButMenu.setPosition(WidthWin - MenuWiHe - 10, 5);
    ButMenu.setTexture(&texture);
    window.draw(ButMenu);
}