#pragma once
#include "Header.h"

void Screensaver() {
    RenderWindow window(VideoMode(WidthWin, HeightWin), L"Mahjong", Style::Default);
    window.setPosition({ 200,100 });
    window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        sf::Texture texture;
        if (!texture.loadFromFile("Image/заставка.jpg"))
        {
            // ошибка...
        }
        sf::Sprite sprite;
        sprite.setTexture(texture);
        window.draw(sprite);

        window.display();
    }
}