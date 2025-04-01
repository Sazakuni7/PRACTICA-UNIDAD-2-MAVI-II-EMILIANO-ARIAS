#include "Ball.h"

const float SCALE = 30.f;

Ball::Ball(b2World& world, sf::Vector2f position, sf::Vector2f direction) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x / SCALE, position.y / SCALE);
    body = world.CreateBody(&bodyDef);

    b2CircleShape circleShape;
    circleShape.m_radius = 0.3f; //Radio en metros

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.2f;
    fixtureDef.restitution = 0.5f;
    body->CreateFixture(&fixtureDef);

    shape.setRadius(circleShape.m_radius * SCALE);
    shape.setOrigin(circleShape.m_radius * SCALE, circleShape.m_radius * SCALE);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position);

    //Aplicar impulso en la dirección del disparo
    float speed = 10.f;
    body->ApplyLinearImpulseToCenter(b2Vec2(direction.x * speed, direction.y * speed), true);
}

void Ball::update() {
    b2Vec2 pos = body->GetPosition();
    shape.setPosition(pos.x * SCALE, pos.y * SCALE);
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(shape);
}