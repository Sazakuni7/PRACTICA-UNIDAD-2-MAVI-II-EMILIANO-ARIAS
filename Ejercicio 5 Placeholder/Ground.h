#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class Ground {
public:
    Ground(b2World& world, float width, float height);
    void draw(sf::RenderWindow& window);
    void update();

private:
    sf::RectangleShape ground;
    b2Body* groundBody;
};

#endif