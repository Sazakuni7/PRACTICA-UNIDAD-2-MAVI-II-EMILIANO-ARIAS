#include "Box.h"

const float SCALE = 30.f;

Box::Box(b2World& world, float x, float y) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_kinematicBody; //Ahora es un cuerpo cinemático
    bodyDef.position.Set(x / SCALE, y / SCALE);
    body = world.CreateBody(&bodyDef);

    float boxWidth = 1.5f;
    float boxHeight = 1.0f;

    b2PolygonShape boxShape;
    boxShape.SetAsBox(boxWidth / 2, boxHeight / 2);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;
    fixtureDef.density = 0.0f;
    fixtureDef.friction = 0.0f;
    fixtureDef.restitution = 0.0f;
    body->CreateFixture(&fixtureDef);

    shape.setSize(sf::Vector2f(boxWidth * SCALE, boxHeight * SCALE));
    shape.setOrigin((boxWidth * SCALE) / 2, (boxHeight * SCALE) / 2);
    shape.setFillColor(sf::Color::Blue);
}

void Box::move(float velocityY) {
    body->SetLinearVelocity(b2Vec2(0, velocityY));
}

void Box::stop() {
    body->SetLinearVelocity(b2Vec2(0.f, 0.f));
}

void Box::rotateTurret(sf::Vector2f mousePosition) {
    sf::Vector2f boxPosition = shape.getPosition();
    float angle = atan2(mousePosition.y - boxPosition.y, mousePosition.x - boxPosition.x);
    shape.setRotation(angle * 180 / b2_pi);
}

/*void Box::setNewRotation(float angle) {
}*/

void Box::update() {
    b2Vec2 pos = body->GetPosition();
    shape.setPosition(pos.x * SCALE, pos.y * SCALE);
    shape.setRotation(body->GetAngle() * 180 / b2_pi);
}

void Box::draw(sf::RenderWindow& window) {
    window.draw(shape);
}