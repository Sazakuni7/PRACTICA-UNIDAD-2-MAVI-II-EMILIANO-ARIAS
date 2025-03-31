#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Ball {
public:
    Ball(b2World& world, float x, float y);
    void update();
    void render(sf::RenderWindow& window);

private:
    b2Body* body;
    sf::CircleShape shape;
};

#endif