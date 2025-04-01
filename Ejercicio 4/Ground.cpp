#include "Ground.h"

const float SCALE = 30.f;
const float WALL_GROSOR = 1.9f;

Ground::Ground(b2World& world, float width, float height) {

    b2BodyDef limitBodyDef;
    limitBodyDef.position.Set(0.f, 0.f);
    b2Body* limitBody = world.CreateBody(&limitBodyDef);

    b2EdgeShape edge;
    b2PolygonShape wallShape;
    b2FixtureDef floorFixture, leftWallFixture, rightWallFixture;
    floorFixture.shape = &edge;
    floorFixture.restitution = 0.f;

    //Borde inferior
    edge.SetTwoSided(b2Vec2(0.f, height / SCALE), b2Vec2(width / SCALE, height / SCALE));
    floorFixture.friction = 0.6f; //Podemos probar los distintos coeficientes de rozamiento, aquí debajo dejo unos ejemplos
    /* hielo sobre hielo 0, 02
       cuero sobre madera 0, 3 - 0, 4
        cuero sobre metal 0, 6
        acero sobre acero 0, 6
        madera sobre madera 0, 25 - 0, 50
        latón sobre hielo 0, 02 */
        //Es importante definir estos valores tanto en el objeto como en la superficie
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

    //Borde derecho /!/Tengo un pequeño inconveniente con este borde, la colisión parece estar desplazada mas hacia afuera o hay un problema con la colision de la caja para este borde
    b2BodyDef rightWallBodyDef;
    rightWallBodyDef.position.Set(0.f, 0.f);
    b2Body* rightWallBody = world.CreateBody(&rightWallBodyDef);
    wallShape.SetAsBox(WALL_GROSOR / 2, height / (2 * SCALE), b2Vec2((width - WALL_GROSOR) / SCALE, height / (2 * SCALE)), 0);
    rightWallFixture.shape = &wallShape;
    rightWallBody->CreateFixture(&rightWallFixture);
    ground[2].setSize(sf::Vector2f(WALL_GROSOR * SCALE, height));
    ground[2].setPosition(width - (WALL_GROSOR * SCALE), 0.f);

    for (int i = 0; i < 3; i++) {
        ground[i].setFillColor(sf::Color::White);
    }
}

void Ground::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 3; i++) {
        window.draw(ground[i]);
    }
}