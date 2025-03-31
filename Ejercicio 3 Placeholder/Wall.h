#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Wall {
public:
    Wall(b2World& world, float width, float height);
    void render(sf::RenderWindow& window);

private:
    sf::RectangleShape walls[4];
};

#endif