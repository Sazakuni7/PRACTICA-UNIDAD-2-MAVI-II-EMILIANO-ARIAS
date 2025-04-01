#include "Game.h"

Game::Game() : window(sf::VideoMode(1024, 768), "Emiliano Arias - Ejercicio 6 - Torreta"),
world(b2Vec2(0.f, 9.8f)) {
    window.setFramerateLimit(60);
    ground = new Ground(world, 1024, 768);
    box = new Box(world, 25.f, 555.f);
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
    bool moving = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        box->move(-8.0);
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        box->move(8.0f);
        moving = true;
    }
    if (!moving) {
        box->stop();
    }
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    box->rotateTurret(window.mapPixelToCoords(mousePosition));
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
 
        sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        sf::Vector2f boxPosition = box->getPosition();

        sf::Vector2f direction = mousePosition - boxPosition;
        float length = sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length != 0) {
            direction /= length; //Normalizamos el vector
            balls.push_back(new Ball(world, boxPosition, direction));
        }
    }
}

void Game::update() { //El segmento comentado es un intento de solucionar que no se pueda disparar hacia abajo, es decir eje Y negativo (o incremento de Y en SFML)
    /*Calculamos el ángulo de rotación de la caja hacia el mouse
    sf::Vector2f boxPosition = box->getPosition();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    sf::Vector2f worldMousePos = window.mapPixelToCoords(mousePosition);

    float dx = worldMousePos.x - boxPosition.x;
    float dy = worldMousePos.y - boxPosition.y;

    //Corregimos la inversión del eje Y
    float angle = atan2(-dy, dx) * 180 / b2_pi; //calcula el ángulo entre el eje X y un segmento de línea que va desde el origen (0,0) hasta un punto específico (x,y)

    box->setNewRotation(angle); // Ajustar la rotación de la caja*/
    float timeStep = 1.0f / 60.0f;
    int velocityIterations = 8;
    int positionIterations = 3;
    world.Step(timeStep, velocityIterations, positionIterations);
    box->update();
    for (auto ball : balls)
        ball->update();
}

void Game::render() {
    window.clear();
    box->draw(window);
    ground->draw(window);
    for (auto ball : balls)
        ball->draw(window);
    window.display();
}