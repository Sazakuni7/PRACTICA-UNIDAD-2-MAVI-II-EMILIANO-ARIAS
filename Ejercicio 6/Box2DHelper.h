#include <Box2D/Box2D.h>
#pragma once

class Box2DHelper
{
public:


	//-------------------------------------------------------------
// Crea un body din�mico sin fixtures centrado en 0,0
//-------------------------------------------------------------

	static b2Body* CreateDynamicBody(b2World* phyWorld) {

		// Declaramos el body
		b2Body* body;

		// Llenamos la definici�n
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(0.0f, 0.0f);
		body = phyWorld->CreateBody(&bodyDef);

		return body;
	}

	//-------------------------------------------------------------
// Crea un body est�tico sin fixtures centrado en 0,0
//-------------------------------------------------------------
	static b2Body* CreateStaticBody(b2World* phyWorld)
	{
		// Declaramos el body
		b2Body* body;

		// Llenamos la definici�n
		b2BodyDef bodyDef;
		bodyDef.type = b2_staticBody;
		bodyDef.position.Set(0.0f, 0.0f);
		body = phyWorld->CreateBody(&bodyDef);

		return body;
	}


	//-------------------------------------------------------------
	// Crea un body cinem�tico sin fixtures centrado en 0,0
	//-------------------------------------------------------------
	static b2Body* CreateKinematicBody(b2World* phyWorld)
	{
		// Declaramos el body
		b2Body* body;

		// Llenamos la definici�n
		b2BodyDef bodyDef;
		bodyDef.type = b2_kinematicBody;
		bodyDef.position.Set(0.0f, 0.0f);
		body = phyWorld->CreateBody(&bodyDef);

		return body;
	}

	//-------------------------------------------------------------
// Crea un fixture rectangular con el 0,0 en el medio
//-------------------------------------------------------------
	static b2FixtureDef CreateRectangularFixtureDef(float sizeX, float sizeY, float density, float friction, float restitution)
	{

		b2PolygonShape* box = new b2PolygonShape();

		box->SetAsBox(sizeX / 2.0f, sizeY / 2.0f, b2Vec2(0.0f, 0.0f), 0.0f);

		b2FixtureDef fixtureDef;
		fixtureDef.shape = box;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		fixtureDef.restitution = restitution;

		return fixtureDef;
	}

	//-------------------------------------------------------------
// Crea un body din�mico con un fixture rectangular centrado en el origen
//-------------------------------------------------------------
	static b2Body* CreateRectangularDynamicBody(b2World* phyWorld, float sizeX, float sizeY, float density, float friction, float restitution)
	{
		b2Body* body = CreateDynamicBody(phyWorld);
		b2FixtureDef box = CreateRectangularFixtureDef(sizeX, sizeY, density, friction, restitution);
		body->CreateFixture(&box);

		return body;
	}


	//-------------------------------------------------------------
	// Crea un body cinem�tico con un fixture rectangular centrado en el origen
	//-------------------------------------------------------------
	static b2Body* CreateRectangularKinematicBody(b2World* phyWorld, float sizeX, float sizeY)
	{
		b2Body* body = CreateKinematicBody(phyWorld);
		b2FixtureDef box = CreateRectangularFixtureDef(sizeX, sizeY, 0.0f, 0.0f, 0.0f);
		body->CreateFixture(&box);

		return body;
	}

	//-------------------------------------------------------------
// Crea un fixture circular con el 0,0 en el medio
//-------------------------------------------------------------
	static b2FixtureDef CreateCircularFixtureDef(float radius, float density, float friction, float restitution)
	{
		b2CircleShape* circle = new b2CircleShape();
		circle->m_p = b2Vec2(0.0f, 0.0f);
		circle->m_radius = radius;

		b2FixtureDef fixtureDef;
		fixtureDef.shape = circle;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		fixtureDef.restitution = restitution;

		return fixtureDef;
	}

	//-------------------------------------------------------------
// Crea un body din�mico con un fixture circular centrado en el origen
//-------------------------------------------------------------
	static b2Body* CreateCircularDynamicBody(b2World* phyWorld, float radius, float density, float friction, float restitution)
	{
		b2Body* body = CreateDynamicBody(phyWorld);
		b2FixtureDef cir = CreateCircularFixtureDef(radius, density, friction, restitution);
		body->CreateFixture(&cir);

		return body;
	}

	//-------------------------------------------------------------
	// Crea un body est�tico con un fixture rectangular centrado en el origen
	//-------------------------------------------------------------
	static b2Body* CreateRectangularStaticBody(b2World* phyWorld, float sizeX, float sizeY)
	{
		b2Body* body = CreateStaticBody(phyWorld);
		b2FixtureDef box = CreateRectangularFixtureDef(sizeX, sizeY, 0.0f, 0.0f, 0.0f);
		body->CreateFixture(&box);

		return body;
	}

};