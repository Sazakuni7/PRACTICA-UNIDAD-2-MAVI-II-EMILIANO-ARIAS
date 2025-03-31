#include "Ground.h"

const float SCALE = 30.f;

Ground::Ground(b2World& world) {
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(400.0f / SCALE, 550.0f / SCALE);
    body = world.CreateBody(&groundBodyDef);

    b2PolygonShape piso;
    piso.SetAsBox(300.0f / SCALE, 10.0f / SCALE);
    body->CreateFixture(&piso, 0.0f);

    shape.setSize(sf::Vector2f(600, 20));
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(300, 10);
    shape.setPosition(body->GetPosition().x * SCALE, body->GetPosition().y * SCALE);
}

void Ground::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
}