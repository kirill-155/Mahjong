#pragma once
#include "Header.h"
#include "Dice.h"

void Menu(RenderWindow& window) {
    const int widthVictoryWin = 300, heightVictoryWin = 380;
    RectangleShape victoryWin(Vector2f(widthVictoryWin, heightVictoryWin));
    victoryWin.setFillColor(Color(255, 184, 65));
    victoryWin.setPosition(WidthWin / 2 - widthVictoryWin / 2, HeightWin / 2 - heightVictoryWin / 2);
    window.draw(victoryWin);

    int k = 0;
    double interval = 50;
    Text text;
    text.setFont(font);// �������� �����
    text.setCharacterSize(28);// �������� ������ �������� � ��������
    text.setFillColor(Color(0, 0, 0));// �������� ����

    if (status != "pause")
    {
        interval = 62.5;
        BtnMenuReStart.setPosition(WidthWin / 2 - widthBtn / 2, HeightWin / 2 - heightBtn / 2 - 125 + k++ * interval);
        BtnMenuMap.setPosition(WidthWin / 2 - widthBtn / 2, HeightWin / 2 - heightBtn / 2 - 125 + k++ * interval);
        BtnMenuFon.setPosition(WidthWin / 2 - widthBtn / 2, HeightWin / 2 - heightBtn / 2 - 125 + k++ * interval);
        BtnMenuDice.setPosition(WidthWin / 2 - widthBtn / 2, HeightWin / 2 - heightBtn / 2 - 125 + k++ * interval);
        BtnMenuExit.setPosition(WidthWin / 2 - widthBtn / 2, HeightWin / 2 - heightBtn / 2 - 125 + k++ * interval);
        k = 0;
    }
    else
    {
        ++k;
        BtnMenuReStart.setPosition(WidthWin / 2 - widthBtn / 2, HeightWin / 2 - heightBtn / 2 - 125 + k++ * interval);
        BtnMenuMap.setPosition(WidthWin / 2 - widthBtn / 2, HeightWin / 2 - heightBtn / 2 - 125 + k++ * interval);
        BtnMenuFon.setPosition(WidthWin / 2 - widthBtn / 2, HeightWin / 2 - heightBtn / 2 - 125 + k++ * interval);
        BtnMenuDice.setPosition(WidthWin / 2 - widthBtn / 2, HeightWin / 2 - heightBtn / 2 - 125 + k++ * interval);
        BtnMenuExit.setPosition(WidthWin / 2 - widthBtn / 2, HeightWin / 2 - heightBtn / 2 - 125 + k++ * interval);
        k = 0;
        // ����������
        window.draw(BtnMenuPlay);
        text.setString(L"����������");
        text.setPosition(WidthWin / 2 - text.getGlobalBounds().width / 2 - 3, HeightWin / 2 - text.getGlobalBounds().height / 2 - 130 + k++ * interval);
        window.draw(text);
    }
    
    // ������
    window.draw(BtnMenuReStart);
    text.setString(L"������");
    text.setPosition(WidthWin / 2 - text.getGlobalBounds().width / 2 - 3, HeightWin / 2 - text.getGlobalBounds().height / 2 - 130 + k++ * interval);
    window.draw(text);

    // ����� �����
    window.draw(BtnMenuMap);
    text.setString(L"����� �����");
    text.setPosition(WidthWin / 2 - text.getGlobalBounds().width / 2 - 3, HeightWin / 2 - text.getGlobalBounds().height / 2 - 130 + k++ * interval);
    window.draw(text);

    // ����� ����
    window.draw(BtnMenuFon);
    text.setString(L"����� ����");
    text.setPosition(WidthWin / 2 - text.getGlobalBounds().width / 2 - 3, HeightWin / 2 - text.getGlobalBounds().height / 2 - 130 + k++ * interval);
    window.draw(text);

    // ����� ������
    window.draw(BtnMenuDice);
    text.setString(L"����� ������");
    text.setPosition(WidthWin / 2 - text.getGlobalBounds().width / 2 - 3, HeightWin / 2 - text.getGlobalBounds().height / 2 - 130 + k++ * interval);
    window.draw(text);

    // �����
    window.draw(BtnMenuExit);
    text.setString(L"�����");
    text.setPosition(WidthWin / 2 - text.getGlobalBounds().width / 2 - 3, HeightWin / 2 - text.getGlobalBounds().height / 2 - 130 + k++ * interval);
    window.draw(text);

}
