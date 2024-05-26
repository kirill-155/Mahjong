#include "Header.h"
#include "Screensaver.h"
#include "Create.h"
#include "Update.h"

void Event_click(RenderWindow& window) {
    Event event;
    while (window.pollEvent(event))// проверяем все события окна которые сработали с момента последней итерации цикла
    {
        if (event.type == Event::Closed)// событие "закрытия": мы закрываем окно
            window.close();
    }
}

void Drow(RenderWindow& window) {

    sf::Texture texture;
    if (!texture.loadFromFile("Image/фон_1.jpg"))
    {
        // ошибка...
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    window.draw(sprite);
    //Create(window);
    Update(window);
}

int main()
{
    system("chcp 1251 > nul");
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(WidthWin, HeightWin), L"Mahjong", Style::Default, settings);
    window.setPosition({ 200,100 });
    window.setVerticalSyncEnabled(true);

    Create(window);
    while (window.isOpen())
    {
        //system("pause");

        // очищаем окно чёрным цветом
        window.clear(sf::Color::Black);

        Event_click(window);
        Drow(window);

        window.display();// конец текущего кадра
    }
    return 0;
}