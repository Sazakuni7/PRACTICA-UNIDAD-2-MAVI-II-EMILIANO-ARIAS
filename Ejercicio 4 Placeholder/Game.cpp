#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Box2D Friction"),
world(b2Vec2(0.f, 9.8f)) {
    window.setFramerateLimit(60);
    ground = new Ground(world, 800, 600);
    box = new Box(world, 400.f, 555.f);
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        box->applyForce(-5.0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        box->applyForce(5.0f);
    }
}

void Game::update() {
    world.Step(1 / 60.0f, 10, 3);
    box->update();
}

void Game::render() {
    window.clear();
    box->draw(window);
    ground->draw(window);
    window.display();
}