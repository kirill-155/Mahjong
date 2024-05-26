#include "Header.h"
#include "Screensaver.h"

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

}

int main()
{
    //Screensaver();
    RenderWindow window(VideoMode(WidthWin, HeightWin), L"Mahjong", Style::Default);
    window.setPosition({ 200,100 });
    window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {
        // очищаем окно чёрным цветом
        window.clear(sf::Color::Black);

        Event_click(window);
        Drow(window);

        window.display();// конец текущего кадра
    }
    return 0;
}