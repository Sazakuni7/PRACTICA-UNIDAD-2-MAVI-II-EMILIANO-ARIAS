#include "Wall.h"

const float SCALE = 30.f;

Wall::Wall(b2World& world, float width, float height) {

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.f, 0.f);
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    b2EdgeShape edge;
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &edge;
    fixtureDef.restitution = 1.f;

    //Borde inferior
    edge.SetTwoSided(b2Vec2(0.f, height / 30.f), b2Vec2(width / 30.f, height / 30.f));
    groundBody->CreateFixture(&fixtureDef);
    walls[0].setSize(sf::Vector2f(width, 5.f));
    walls[0].setPosition(0.f, height - 5.f);

    //Borde superior
    edge.SetTwoSided(b2Vec2(0.f, 0.f), b2Vec2(width / 30.f, 0.f));
    groundBody->CreateFixture(&fixtureDef);
    walls[1].setSize(sf::Vector2f(width, 5.f));
    walls[1].setPosition(0.f, 0.f);

    //Borde izquierdo
    edge.SetTwoSided(b2Vec2(0.f, 0.f), b2Vec2(0.f, height / 30.f));
    groundBody->CreateFixture(&fixtureDef);
    walls[2].setSize(sf::Vector2f(5.f, height));
    walls[2].setPosition(0.f, 0.f);

    //Borde derecho
    edge.SetTwoSided(b2Vec2(width / 30.f, 0.f), b2Vec2(width / 30.f, height / 30.f));
    groundBody->CreateFixture(&fixtureDef);
    walls[3].setSize(sf::Vector2f(5.f, height));
    walls[3].setPosition(width - 5.f, 0.f);

    for (int i = 0; i < 4; i++) {
        walls[i].setFillColor(sf::Color::White);
    }
}

void Wall::render(sf::RenderWindow& window) {
    for (int i = 0; i < 4; i++) {
        window.draw(walls[i]);
    }
}