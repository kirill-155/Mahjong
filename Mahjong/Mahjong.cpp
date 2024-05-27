#include "Header.h"
#include "Screensaver.h"
#include "Create.h"
#include "Update.h"

int idHig = -1;

void Win(RenderWindow& window) {
    const float width = 1000, height = 500;
    RectangleShape rectangle(sf::Vector2f(width, height));
    Texture texture;
    texture.loadFromFile("Image/меню.jpg");
    texture.setSmooth(true);
    rectangle.setTexture(&texture);
    rectangle.setPosition(WidthWin / 2 - width / 2, HeightWin / 2 - height / 2);
    window.draw(rectangle);

    Font font;
    font.loadFromFile("Font/NT Somic/NT Somic-VF.ttf");
    Text text;
    text.setFont(font);// выбираем шрифт
    text.setString(L"Победа!");
    text.setCharacterSize(80);// выбираем размер символов в пикселях
    text.setFillColor(Color(255, 0, 0));// выбираем цвет
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);// выбираем стиль текста
    text.setPosition(WidthWin / 2 - 150, HeightWin / 2 - 200);
    window.draw(text);
}

bool is_block(int IdV_dice) {
    Vector2f pos = V_dice[IdV_dice].getPosition();
    pos.x += WidthDice / 2.0;
    pos.y += HeightDice / 2.0;
    int cnt = 0;
    bool left = 1, rigt = 1;
    for (int i = 0; i < V_dice.size(); i++)
    {
        if(V_dice[i].level - 1 == V_dice[IdV_dice].level && V_dice[i].is_click(Vector2f(pos.x, pos.y), 15))
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

void Event_click(RenderWindow& window) {
    Event event;
    while (window.pollEvent(event))// проверяем все события окна которые сработали с момента последней итерации цикла
    {
        if (event.type == Event::Closed)// событие "закрытия": мы закрываем окно
            window.close();

        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)//нажатие мыши
        {
            for (int i = V_dice.size() - 1; i >= 0; i--)
            {
                if (V_dice[i].is_click(Vector2f(event.mouseButton.x, event.mouseButton.y)))//нажатие на кость
                {
                    if (idHig == i)
                    {
                        idHig = -1;
                        Vector2f pos = V_dice[i].getPosition();
                        V_dice[i].setPosition(pos.x, pos.y + 10);
                        V_dice[i].setFillColor(Color(240, 240, 240));
                    }
                    else if (!is_block(i)) if (idHig == -1)
                    {
                        idHig = i;
                        Vector2f pos = V_dice[i].getPosition();
                        V_dice[i].setPosition(pos.x, pos.y - 10);
                        V_dice[i].setFillColor(Color(255, 255, 255));
                    }
                    else
                    {
                        Vector2f pos = V_dice[idHig].getPosition();
                        V_dice[idHig].setPosition(pos.x, pos.y + 10);
                        V_dice[idHig].setFillColor(Color(240, 240, 240));
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
    if (V_dice.empty())
        Win(window);

}

int main()
{
    system("chcp 1251 > nul");
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(WidthWin, HeightWin), L"Mahjong", Style::Default, settings);
    window.setPosition({ 200,100 });
    window.setVerticalSyncEnabled(true);

    Create(window, 1);
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