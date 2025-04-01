#include "Box.h"

const float SCALE = 30.f;

Box::Box(b2World& world, float x, float y) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x / SCALE, y / SCALE + 5);
    body = world.CreateBody(&bodyDef);

    float boxWidth = 1.5f;
    float boxHeight = 1.0f;

    b2PolygonShape boxShape;
    boxShape.SetAsBox(boxWidth / 2, boxHeight / 2);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;
    fixtureDef.density = 0.2f; //Cambiamos aquí el peso de la caja
    fixtureDef.friction = 0.6f;  //Podemos probar los distintos coeficientes de rozamiento, aquí debajo dejo unos ejemplos
    /* hielo sobre hielo 0, 02
       cuero sobre madera 0, 3 - 0, 4
        cuero sobre metal 0, 6
        acero sobre acero 0, 6
        madera sobre madera 0, 25 - 0, 50
        latón sobre hielo 0, 02 */
        //Es importante definir estos valores tanto en el objeto como en la superficie
    fixtureDef.restitution = 0.0f;
    body->CreateFixture(&fixtureDef);

    shape.setSize(sf::Vector2f(boxWidth * SCALE, boxHeight * SCALE));
    shape.setOrigin((boxWidth * SCALE) / 2, (boxHeight * SCALE) / 2);
    shape.setFillColor(sf::Color::Blue);
}

void Box::applyForce(float force) {
    body->ApplyForceToCenter(b2Vec2(force, 0), true);
}

void Box::update() {
    b2Vec2 pos = body->GetPosition(); 
    shape.setPosition(pos.x * SCALE, pos.y * SCALE);
    shape.setRotation(body->GetAngle() * 180 / b2_pi);
}

void Box::draw(sf::RenderWindow& window) {
    window.draw(shape);
}