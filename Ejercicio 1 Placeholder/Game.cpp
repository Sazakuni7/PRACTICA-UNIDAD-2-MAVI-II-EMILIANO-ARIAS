#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Emiliano Arias - Ejercicio 1 - Caída de bloque"), world(b2Vec2(0.0f, 9.8f)), block(world), ground(world) {
    window.setFramerateLimit(60);
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
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update() {
    world.Step(1.5f / 60.0f, 8, 3); //Avanzaremos a un paso de 1,5/60, ya que tendremos 60 frames/s en el juego
    block.update();
}

void Game::render() {
    window.clear();
    window.draw(ground);
    window.draw(block);
    window.display();
}