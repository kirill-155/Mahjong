#pragma once
#include "Header.h"

class  Dice : public Shape {
private:
    FloatRect rect;
    double radius = 0;
    Vector2f position{ 0.f, 0.f };

    vector<Vector2f> m;
    unsigned PointCount;

    void init()
    {
        vector<Vector2f> sin_4;
        {
            const double PREC = M_PI_2 / 15;
            for (double f = 0.0; f < M_PI_2; f += PREC)
            {
                sin_4.push_back({ sinf(f) * radius, cosf(f) * radius });
            }
        }

        vector<Vector2f> sin_4_reverse(sin_4.rbegin(), sin_4.rend());

        const double WIDE2 = rect.width - radius;
        const double HEIGHT2 = rect.height - radius;

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
    Dice(const Rect<double> rt, const double rs) : rect(rt), radius(rs) {
        init();
        setPosition(rt.left, rt.top);
        sf::Shape::update();
    }
    Dice(const double width, const double height, const double rs) : rect(FloatRect(0, 0, width, height)), radius(rs) {
        init();
        setPosition(0, 0);
        sf::Shape::update();
    }
    Dice() {
        setPosition(0, 0);
        sf::Shape::update();
    }

    virtual size_t getPointCount() const { return m.size(); }
    virtual Vector2f getPoint(size_t i) const { return m[i]; }
};