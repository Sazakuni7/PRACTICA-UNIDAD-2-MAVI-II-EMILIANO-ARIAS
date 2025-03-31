#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Ground.h"

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
    Block block;
    Ground ground;
};

#endif
