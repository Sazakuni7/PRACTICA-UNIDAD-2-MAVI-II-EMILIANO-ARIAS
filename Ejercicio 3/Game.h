#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Ball.h"
#include "Wall.h"
#include "Obstaculo.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
    b2World world;
    Ball* ball;
    Wall* wall;
    std::vector<Obstaculo*> obstacles;
};