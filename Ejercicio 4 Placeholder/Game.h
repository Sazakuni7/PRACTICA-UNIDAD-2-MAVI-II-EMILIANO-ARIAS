#ifndef GAME_H
#define GAME_H

#include "Box.h"
#include "Ground.h"
#include <SFML/Graphics.hpp>

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
    Box* box;
    Ground* ground;
};

#endif