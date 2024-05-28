#include "Header.h"
#include "Create.h"
#include "Update.h"
#include "CheckingForWin.h"
#include "Menu.h"

bool Click_icon(CircleShape& shape, const Event::MouseButtonEvent& pos) {
    Vector2f pos2 = shape.getPosition();
    return pos.x >= pos2.x && pos.y >= pos2.y && pos.x < pos2.x + radReStart * 2 && pos.y < pos2.y + radReStart * 2;
}

bool Click_icon(RectangleShape& shape, const Event::MouseButtonEvent& pos) {
    Vector2f pos2 = shape.getPosition();
    return pos.x >= pos2.x && pos.y >= pos2.y && pos.x < pos2.x + radReStart * 2 && pos.y < pos2.y + radReStart * 2;
}

bool Click_button(RectangleShape& shape, const Event::MouseButtonEvent& pos) {
    Vector2f pos2 = shape.getPosition();
    return pos.x >= pos2.x && pos.y >= pos2.y && pos.x < pos2.x + widthBtn && pos.y < pos2.y + heightBtn;
}

void Win(RenderWindow& window) {
    const int widthVictoryWin = 500, heightVictoryWin = 300;
    RectangleShape victoryWin(Vector2f(widthVictoryWin, heightVictoryWin));
    Texture texture;
    texture.loadFromFile("Image/меню.jpg");
    texture.setSmooth(true);// сглаживание текстуры
    victoryWin.setTexture(&texture);
    victoryWin.setFillColor(Color(255, 184, 65));
    victoryWin.setPosition(WidthWin / 2 - widthVictoryWin / 2, HeightWin / 2 - heightVictoryWin / 2);
    window.draw(victoryWin);

    Text text;
    text.setFont(font);// выбираем шрифт
    text.setString(L"Победа!");
    text.setCharacterSize(80);// выбираем размер символов в пикселях
    text.setFillColor(Color(0, 255, 0));// выбираем цвет
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);// выбираем стиль текста
    text.setPosition(WidthWin / 2 - text.getGlobalBounds().width / 2 - 3, HeightWin / 2 - 150);
    window.draw(text);

    // создание кнопки рестарта
    texture.loadFromFile("Image/Icon/update.png");
    ButReStart.setTexture(&texture);
    ButReStart.setPosition(WidthWin / 2 - radReStart - 40, HeightWin / 2);
    window.draw(ButReStart);

    // создание кнопки меню
    texture.loadFromFile("Image/Icon/menu.png");
    ButMenu.setTexture(&texture);
    ButMenu.setPosition(WidthWin / 2 - MenuWiHe / 2 + 40, HeightWin / 2);
    window.draw(ButMenu);
}

void Loss(RenderWindow& window) {
    const int widthVictoryWin = 500, heightVictoryWin = 300;
    RectangleShape victoryWin(Vector2f(widthVictoryWin, heightVictoryWin));
    Texture texture;
    texture.loadFromFile("Image/меню.jpg");
    texture.setSmooth(true);// сглаживание текстуры
    victoryWin.setTexture(&texture);
    victoryWin.setFillColor(Color(255, 184, 65));
    victoryWin.setPosition(WidthWin / 2 - widthVictoryWin / 2, HeightWin / 2 - heightVictoryWin / 2);
    window.draw(victoryWin);

    Text text;
    text.setFont(font);// выбираем шрифт
    text.setString(L"Поражение!");
    text.setCharacterSize(80);// выбираем размер символов в пикселях
    text.setFillColor(Color(255, 0, 0));// выбираем цвет
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);// выбираем стиль текста
    text.setPosition(WidthWin / 2 - text.getGlobalBounds().width / 2 - 3, HeightWin / 2 - 150);
    window.draw(text);

    // создание кнопки рестарта
    texture.loadFromFile("Image/Icon/update.png");
    ButReStart.setTexture(&texture);
    ButReStart.setPosition(WidthWin / 2 - radReStart - 40, HeightWin / 2);

    window.draw(ButReStart);

    // создание кнопки меню
    texture.loadFromFile("Image/Icon/menu.png");
    ButMenu.setTexture(&texture);
    ButMenu.setPosition(WidthWin / 2 - MenuWiHe / 2 + 40, HeightWin / 2);
    window.draw(ButMenu);
}

int idHig = -1;

void Event_click(RenderWindow& window) {
    Event event; 
    while (window.pollEvent(event))// проверяем все события окна которые сработали с момента последней итерации цикла
    {
        if (event.type == Event::Closed)// событие "закрытия": мы закрываем окно
            window.close();

        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)// нажатие мыши
        {
            if (status == "menu" || status == "pause")
            {
                if (Click_button(BtnMenuPlay, event.mouseButton) && status == "pause")
                {
                    status = "game";
                }
                else if (Click_button(BtnMenuReStart, event.mouseButton))
                {
                    Create(window, 1);
                    status = "game";
                }
                else if (Click_button(BtnMenuMap, event.mouseButton))
                {

                }
                else if (Click_button(BtnMenuFon, event.mouseButton))
                {

                }
                else if (Click_button(BtnMenuDice, event.mouseButton))
                {

                }
                else if (Click_button(BtnMenuExit, event.mouseButton))// событие "закрытия": мы закрываем окно
                    window.close();
            }

            if (status == "win" || status == "loss" || status == "game")
            {
                if(Click_icon(ButReStart, event.mouseButton))
                {
                    Create(window, 1);
                    status = "game";
                }
                else if (Click_icon(ButMenu, event.mouseButton) && status == "game")
                {
                    status = "pause";
                }
                else if (Click_icon(ButMenu, event.mouseButton))
                {
                    status = "menu";
                }

            }
            
            if (status == "game" || status == "pause")
                for (int i = V_dice.size() - 1; i >= 0; i--)
                {
                    if (V_dice[i].is_click(Vector2f(event.mouseButton.x, event.mouseButton.y)))// нажатие на кость
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
                                if (V_dice.empty())
                                    status = "win";
                                else if (!CheckingForWin())
                                    status = "loss";
                            }
                            idHig = -1;
                        }
                        break;
                    }
                }

            if (status == "screensaver")
            {
                FonWin = "Image/фон_1.jpg";
                do Create(window, 2);
                while (!CheckingForWin());
                status = "game";
            }
        }
    }
}

void Drow(RenderWindow& window) {

    Texture texture;
    texture.loadFromFile(FonWin);
    Sprite sprite;
    sprite.setTexture(texture);
    window.draw(sprite);
    if (status == "game" || status == "pause")
        Update(window);
    if (status == "win")
        Win(window);
    if (status == "loss")
        Loss(window);
    if (status == "menu" || status == "pause")
        Menu(window);

}

int main()
{
    system("chcp 1251 > nul");// руссификация
    ContextSettings settings;
    settings.antialiasingLevel = 5;// уровень сглаживания
    RenderWindow window(VideoMode(WidthWin, HeightWin), L"Mahjong", Style::Default, settings);
    window.setPosition({ 200,100 });
    window.setVerticalSyncEnabled(true);

    Image icon;
    if (!icon.loadFromFile("Image/Icon.png"))
    {
        return 1;
    }
    window.setIcon(48, 48, icon.getPixelsPtr());

    Music music;   // Music
    if (!music.openFromFile("Music/Mao_Czje_Dun_-_Kitajjskijj_Kommunisticheskijj_Pesnya_10_social_credit_75521604.mp3")) { return -1; }
    music.setVolume(20.f);
    music.setLoop(true);
    music.play();

    preloading();
    while (window.isOpen())
    {
        //system("pause");

        window.clear(Color::Black);// очищаем окно чёрным цветом

        Event_click(window);// обработка событий
        Drow(window);// отрисовка

        window.display();// конец текущего кадра
    }
    return 0;
}