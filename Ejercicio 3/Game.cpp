#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Emiliano Arias - Ejercicio 3 - Pelota rebotando obstaculos"), world(b2Vec2(0.f, 0.f)) {
    window.setFramerateLimit(60);
    wall = new Wall(world, 800, 600);
    ball = new Ball(world, 400.f, 300.f);

    obstacles.push_back(new Obstaculo(world, 200.f, 200.f, 50.f, 50.f));
    obstacles.push_back(new Obstaculo(world, 600.f, 200.f, 70.f, 30.f));
    obstacles.push_back(new Obstaculo(world, 400.f, 400.f, 60.f, 40.f));
    obstacles.push_back(new Obstaculo(world, 150.f, 450.f, 50.f, 70.f));
    obstacles.push_back(new Obstaculo(world, 650.f, 500.f, 80.f, 40.f));
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
    world.Step(2.0f / 60.0f, 8, 3);
    ball->update();
}

void Game::render() {
    window.clear();
    ball->render(window);
    wall->render(window);
    for (Obstaculo* obs : obstacles) {
        obs->render(window);
    }
    window.display();
}