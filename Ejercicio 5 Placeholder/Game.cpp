#include "Game.h"

Game::Game() : window(sf::VideoMode(1024, 768), "Emiliano Arias - Ejercicio 5 - Caja en pendiente"),
world(b2Vec2(0.f, 9.8f)) {
    window.setFramerateLimit(60);
    ground = new Ground(world, 1024,768);
    box = new Box(world, 100.f, 0.f);
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
}

void Game::update() {
    world.Step(1 / 60.0f, 10, 3);
    ground->update();
    box->update();

}

void Game::render() {
    window.clear();
    box->draw(window);
    ground->draw(window);
    window.display();
}