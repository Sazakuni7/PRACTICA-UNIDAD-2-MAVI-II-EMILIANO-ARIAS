#include "Block.h"

const float SCALE = 30.f;

Block::Block(b2World& world) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(400.0f / SCALE, 100.0f / SCALE);
    body = world.CreateBody(&bodyDef);

    b2PolygonShape blockShape;
    blockShape.SetAsBox(25.0f / SCALE, 25.0f / SCALE);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &blockShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

    shape.setSize(sf::Vector2f(50, 50));
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin(25, 25);
}

void Block::update() {
    shape.setPosition(body->GetPosition().x * SCALE, body->GetPosition().y * SCALE);
    shape.setRotation(body->GetAngle() * 180 / b2_pi);
}

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
}