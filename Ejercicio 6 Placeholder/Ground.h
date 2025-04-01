#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class Ground {
public:
    Ground(b2World& world, float width, float height);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape ground[3];
};

#endif