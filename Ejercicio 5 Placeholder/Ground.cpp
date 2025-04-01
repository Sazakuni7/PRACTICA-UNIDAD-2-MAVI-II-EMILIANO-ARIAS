#include "Ground.h"

const float SCALE = 30.f;

Ground::Ground(b2World& world, float width, float height) {
    //Definir el cuerpo de Box2D en el centro de la pantalla
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(width / (2 * SCALE) -8.0f, height / SCALE - 15.0f);
    groundBody = world.CreateBody(&groundBodyDef);

    //Crear el suelo inclinado
    b2PolygonShape groundShape;
    float groundWidth = width / SCALE;
    float groundHeight = 0.21f;
    groundShape.SetAsBox(groundWidth / 2, groundHeight, b2Vec2(0, 0), 0);
    b2FixtureDef groundFixture;
    groundFixture.shape = &groundShape;
    groundFixture.friction = 0.6f;
    groundBody->CreateFixture(&groundFixture);

    //Aplicar la rotación
    float angleRad = 25.f * b2_pi / 180.0f; //Aquí modificamos el primer valor para rotar la superficie cuanto querámos
    groundBody->SetTransform(groundBody->GetPosition(), angleRad);

    //Configurar el rectángulo de SFML
    ground.setSize(sf::Vector2f(width, 700.f));
    ground.setOrigin(width / 2.f, 5.5f);
    ground.setFillColor(sf::Color::White);
}

void Ground::update() {
    //Obtener la posición real del cuerpo en Box2D
    b2Vec2 pos = groundBody->GetPosition();
    float angle = groundBody->GetAngle() * 180.0f / b2_pi; // Convertir a grados

    //Ajustar la posición para que el dibujo coincida con el hitbox
    ground.setPosition(pos.x * SCALE, pos.y * SCALE);
    ground.setRotation(angle);
}

void Ground::draw(sf::RenderWindow& window) {
    window.draw(ground);
}