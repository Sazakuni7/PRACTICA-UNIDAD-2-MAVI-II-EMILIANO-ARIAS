#ifndef GAME_H
#define GAME_H

#include "Box.h"
#include "Ground.h"
#include "Ball.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Game {
public:
    Game();
    void run();

private:
    std::vector<Ball*> balls;
    void processEvents();
    void update();
    void render();
    sf::RenderWindow window;
    b2World world;
    Box* box;
    Ground* ground;
};

#endif