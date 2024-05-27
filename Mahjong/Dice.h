#pragma once
#include "Header.h"

class  Dice : public Shape {
private:
    FloatRect rect;
    float radius = 0;
    Vector2f position{ 0.f, 0.f };

    vector<Vector2f> m;
    unsigned PointCount;

    void init()
    {
        vector<Vector2f> sin_4;
        {
            const float PREC = M_PI_2 / 15;
            for (float f = 0.0; f < M_PI_2; f += PREC)
            {
                sin_4.push_back({ sinf(f) * radius, cosf(f) * radius });
            }
        }

        vector<Vector2f> sin_4_reverse(sin_4.rbegin(), sin_4.rend());

        const float WIDE2 = rect.width - radius;
        const float HEIGHT2 = rect.height - radius;

        for (const auto& e : sin_4_reverse)
        {
            m.push_back({ WIDE2 + e.x, HEIGHT2 + e.y });
        }

        for (const auto& e : sin_4)
        {
            m.push_back({ radius - e.x, HEIGHT2 + e.y });
        }

        for (const auto& e : sin_4_reverse)
        {
            m.push_back({ radius - e.x, radius - e.y });
        }

        for (const auto& e : sin_4)
        {
            m.push_back({ WIDE2 + e.x, radius - e.y });
        }
    }

public:
    int IdName;
    int level;

    Dice(const Rect<float> rt, const float rs) : rect(rt), radius(rs) {
        init();
        setPosition(rt.left, rt.top);
        sf::Shape::update();
    }
    Dice(const float width, const float height, const float rs) : rect(FloatRect(0, 0, width, height)), radius(rs) {
        init();
        setPosition(0, 0);
        sf::Shape::update();
    }
    Dice() {
        rect = FloatRect(0, 0, WidthDice, HeightDice);
        radius = 0;
        init();
        setPosition(0, 0);
        //setOutlineThickness(-1);//контур
        setOutlineColor(sf::Color::Black);
        sf::Shape::update();
    }

    void setScrool(const Vector2f pos, const float width, const float height, const float rs) {
        rect = FloatRect(pos.x, pos.y, pos.x + width, pos.y + height);
        radius = rs;
    }

    bool is_click(Vector2f pos, double inaccuracy = 0) {
        Vector2f pos2 = getPosition();
        return pos.x >= pos2.x - inaccuracy && pos.y >= pos2.y - inaccuracy && pos.x < pos2.x + WidthDice + inaccuracy && pos.y < pos2.y + HeightDice + inaccuracy;
    }

    virtual size_t getPointCount() const { return m.size(); }
    virtual Vector2f getPoint(size_t i) const { return m[i]; }
};

void swap(Dice& a, Dice& b) {
    int IdName = a.IdName;
    a.setTexture(&textures[b.IdName]);
    a.IdName = b.IdName;
    b.setTexture(&textures[IdName]);
    b.IdName = IdName;
}