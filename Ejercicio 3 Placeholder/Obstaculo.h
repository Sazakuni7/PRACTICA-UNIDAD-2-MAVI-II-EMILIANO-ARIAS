#pragma once
#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Obstaculo {
public:
    Obstaculo(b2World& world, float x, float y, float width, float height);
    void render(sf::RenderWindow& window);

private:
    sf::RectangleShape shape;
    b2Body* body;
};

#endif