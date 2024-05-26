#include "Header.h"
#include "Screensaver.h"
#include "Create.h"
#include "Update.h"

int idHig = -1;

void Event_click(RenderWindow& window) {
    Event event;
    while (window.pollEvent(event))// проверяем все события окна которые сработали с момента последней итерации цикла
    {
        if (event.type == Event::Closed)// событие "закрытия": мы закрываем окно
            window.close();

        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == Mouse::Left)
            {
                for (int i = V_dice.size() - 1; i >= 0; i--)
                {
                    if (V_dice[i].is_click(Vector2f(event.mouseButton.x ,event.mouseButton.y)))
                    {
                        if (idHig == i)
                        {
                            idHig = -1;
                            Vector2f pos = V_dice[i].getPosition();
                            V_dice[i].setPosition(pos.x, pos.y + 10);
                        }
                        else if (idHig == -1)
                        {
                            idHig = i;
                            Vector2f pos = V_dice[i].getPosition();
                            V_dice[i].setPosition(pos.x, pos.y - 10);
                        }
                        else
                        {
                            Vector2f pos = V_dice[idHig].getPosition();
                            V_dice[idHig].setPosition(pos.x, pos.y + 10);
                            if (V_dice[i].IdName == V_dice[idHig].IdName)
                            {
                                if (idHig > i)
                                {
                                    V_dice.erase(V_dice.begin() + idHig);
                                    V_dice.erase(V_dice.begin() + i);
                                }
                                else {
                                    V_dice.erase(V_dice.begin() + i);
                                    V_dice.erase(V_dice.begin() + idHig);
                                }
                            }
                            idHig = -1;
                        }
                        break;
                    }
                }
            }
        }
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