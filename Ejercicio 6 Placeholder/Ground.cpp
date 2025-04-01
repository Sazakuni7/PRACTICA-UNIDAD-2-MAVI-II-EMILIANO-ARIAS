#include "Ground.h"

const float SCALE = 30.f;
const float WALL_GROSOR = 0.5f;

Ground::Ground(b2World& world, float width, float height) {

    b2BodyDef limitBodyDef;
    limitBodyDef.position.Set(0.f, 0.f);
    b2Body* limitBody = world.CreateBody(&limitBodyDef);

    b2EdgeShape edge;
    b2PolygonShape wallShape;
    b2FixtureDef floorFixture, leftWallFixture, topWallFixture;
    floorFixture.shape = &edge;
    floorFixture.restitution = 0.f;

    //Borde inferior
    edge.SetTwoSided(b2Vec2(0.f, height / SCALE), b2Vec2(width / SCALE, height / SCALE));
    floorFixture.friction = 0.6f;
    limitBody->CreateFixture(&floorFixture);
    ground[0].setSize(sf::Vector2f(width, 5.f));
    ground[0].setPosition(0.f, height - 5.f);

    //Borde izquierdo
    b2BodyDef leftWallBodyDef;
    leftWallBodyDef.position.Set(0.f, 0.f);
    b2Body* leftWallBody = world.CreateBody(&leftWallBodyDef);
    wallShape.SetAsBox(WALL_GROSOR / 2, height / (2 * SCALE), b2Vec2(WALL_GROSOR / 2, height / (2 * SCALE)), 0);
    leftWallFixture.shape = &wallShape;
    leftWallBody->CreateFixture(&leftWallFixture);
    ground[1].setSize(sf::Vector2f(WALL_GROSOR * SCALE, height));
    ground[1].setPosition(0.f, 0.f);

    //Borde superior
    b2BodyDef topWallBodyDef;
    topWallBodyDef.position.Set(0.f, 0.f);
    b2Body* topWallBody = world.CreateBody(&topWallBodyDef);
    edge.SetTwoSided(b2Vec2(0.f, 0.f), b2Vec2(width / SCALE, 0.f));
    topWallFixture.shape = &edge;
    topWallBody->CreateFixture(&topWallFixture);
    ground[2].setSize(sf::Vector2f(width, 5.f));
    ground[2].setPosition(0.f, 0.f);

    for (int i = 0; i < 3; i++) {
        ground[i].setFillColor(sf::Color::White);
    }
}

void Ground::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 3; i++) {
        window.draw(ground[i]);
    }
}
