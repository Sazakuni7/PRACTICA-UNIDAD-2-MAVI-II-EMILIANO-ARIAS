#include "Obstaculo.h"

const float SCALE = 30.f;

Obstaculo::Obstaculo(b2World& world, float x, float y, float width, float height) {
    // Crear cuerpo en Box2D
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody; // No se mueve
    bodyDef.position.Set(x / SCALE, y / SCALE);
    body = world.CreateBody(&bodyDef);

    // Definir la forma de colisión
    b2PolygonShape box;
    box.SetAsBox((width / 2) / SCALE, (height / 2) / SCALE);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &box;
    fixtureDef.restitution = 0.8f; // Rebote moderado
    fixtureDef.friction = 0.5f;
    body->CreateFixture(&fixtureDef);

    // Crear la representación visual en SFML
    shape.setSize(sf::Vector2f(width, height));
    shape.setOrigin(width / 2, height / 2);
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Blue); // Color azul para distinguirlo
}

void Obstaculo::render(sf::RenderWindow& window) {
    window.draw(shape);
}