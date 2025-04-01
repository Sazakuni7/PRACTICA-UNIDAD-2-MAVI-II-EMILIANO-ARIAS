#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Emiliano Arias - Ejercicio 2 - Pelota rebotando"), world(b2Vec2(0.f, 0.f)) {
    window.setFramerateLimit(60);
    wall = new Wall(world, 800, 600);
    ball = new Ball(world, 400.f, 300.f);
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update() {
    world.Step(1.3f / 60.0f, 8, 3);
    ball->update();
}

void Game::render() {
    window.clear();
    ball->dibujar(window);
    wall->render(window);
    window.display();
}