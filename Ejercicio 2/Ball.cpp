#include "Ball.h"

const float SCALE = 30.f;

Ball::Ball(b2World& world, float x, float y) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x / SCALE, y / SCALE);
    body = world.CreateBody(&bodyDef);

    b2CircleShape circle;
    circle.m_radius = 20.f / SCALE;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circle;
    fixtureDef.density = 1.f;
    fixtureDef.friction = 0.0f;
    fixtureDef.restitution = 1.0f; //Al incrementar los valores del coeficiente de restitución para el objeto, la pelota ganará fuerza de rebote en cada colisión (predeterminado es 1.0)

    body->CreateFixture(&fixtureDef);
    body->SetLinearVelocity(b2Vec2(5.f, 7.f));

    shape.setRadius(20.f);
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(20.f, 20.f);
}

void Ball::update() {
    b2Vec2 position = body->GetPosition();
    shape.setPosition(position.x * SCALE, position.y * SCALE);
}

void Ball::dibujar(sf::RenderWindow& window) {
    window.draw(shape);
}