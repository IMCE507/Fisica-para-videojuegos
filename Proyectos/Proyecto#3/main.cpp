#include <Box2D/include/box2d.h>
#include "Simulation.h"

int main(int argc, char* args[])
{
	const float FPS = 60;
	const float frameDelay = 1000 / FPS;

	Uint32 frameStart;
	Uint32 frameEnd;
	float frameTime = 0.0f;

	Simulation* simulation = nullptr;
	simulation = new Simulation();
	simulation->init("Proyecto Final - Phys3300", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360, false);

	/*
		PIXEL PER METER VALUE
	*/

	float ppm = 70.0f;

	
	/* CREACION DEL MUNDO  */

	b2World GameWorld(b2Vec2(0.0f, 10.0f));


	/*CREACION CONTACT LISTENER*/

	MyContactListener Listener;
	GameWorld.SetContactListener(&Listener);


	/*CREACION PERSONAJE*/

	b2BodyDef PersonajeBodyDef;
	PersonajeBodyDef.position.Set(550.0f / ppm, 50.0f / ppm);
	PersonajeBodyDef.type = b2_dynamicBody;

	b2Body* PersonajeBody = GameWorld.CreateBody(&PersonajeBodyDef);

	b2PolygonShape PerosonajeBox;
	PerosonajeBox.SetAsBox(32.0f * 0.5 / ppm, 32.0f * 0.5 / ppm);
	
	b2FixtureDef PersonajeBodyFixture;
	PersonajeBodyFixture.shape = &PerosonajeBox;
	PersonajeBodyFixture.density = 1.0f;
	PersonajeBodyFixture.friction = 0.0f;

	PersonajeBody->CreateFixture(&PersonajeBodyFixture);
	PersonajeBody->SetFixedRotation(true);

	//Sensor del personaje
	PersonajeBodyFixture.isSensor = true;
	b2Fixture* SensorFixture = PersonajeBody->CreateFixture(&PersonajeBodyFixture);
	b2FixtureUserData* SensorData = &SensorFixture->GetUserData();
	SensorData->pointer = 69;




	/*CREACION DEL SUELO*/


	b2BodyDef SueloDef;
	SueloDef.position.Set(340.0f / ppm, 373.0f / ppm);
	
	b2Body* SueloBody = GameWorld.CreateBody(&SueloDef);

	b2PolygonShape SueloBox;
	SueloBox.SetAsBox(640.0f * 0.5 / ppm, 49.0f * 0.5 / ppm);

	b2FixtureDef SueloFixtures;
	SueloFixtures.shape = &SueloBox;
	SueloFixtures.density = 0.0f;

	SueloBody->CreateFixture(&SueloFixtures);

	//SENSOR DEL SUELO

	SueloFixtures.isSensor = true;
	b2Fixture* SueloSensorFixture = SueloBody->CreateFixture(&SueloFixtures);
	b2FixtureUserData* SueloSensorData = &SueloSensorFixture->GetUserData();
	SueloSensorData->pointer = 7;



	/*CREACION DE LA PRIMERA PLATAFORMA (PRIMERA MANO IZQUIERDA)*/

	b2BodyDef Plataforma1Def;
	Plataforma1Def.position.Set(100.0f / ppm, 280.0f / ppm);

	b2Body* Plataforma1Body;
	Plataforma1Body = GameWorld.CreateBody(&Plataforma1Def);


	b2PolygonShape Plataforma1Box;
	Plataforma1Box.SetAsBox(55.0f * 0.5 / ppm, 12.0f * 0.5 / ppm);

	b2FixtureDef Plataforma1Fixture;
	Plataforma1Fixture.shape = &Plataforma1Box;
	Plataforma1Fixture.density = 0.0f;

	Plataforma1Body->CreateFixture(&Plataforma1Fixture);


	//SENSOR DE LA PLATAFORMA 1 

	Plataforma1Fixture.isSensor = true;
	b2Fixture* Plat1SensorFixture = Plataforma1Body->CreateFixture(&Plataforma1Fixture);
	b2FixtureUserData* Plat1SensorData = &Plat1SensorFixture->GetUserData();
	Plat1SensorData->pointer = 99;



	/*CREACION DE LA SEGUNDA PLATAFORMA*/

	b2BodyDef Plataforma2Def;
	Plataforma2Def.position.Set(280.0f / ppm, 210.0f / ppm);

	b2Body* Plataforma2Body;
	Plataforma2Body = GameWorld.CreateBody(&Plataforma2Def);


	b2PolygonShape Plataforma2Box;
	Plataforma2Box.SetAsBox(55.0f * 0.5 / ppm, 12.0f * 0.5 / ppm);

	b2FixtureDef Plataforma2Fixture;
	Plataforma2Fixture.shape = &Plataforma2Box;
	Plataforma2Fixture.density = 0.0f;

	Plataforma2Body->CreateFixture(&Plataforma2Fixture);


	//SENSOR DE LA PLATAFORMA 2

	Plataforma2Fixture.isSensor = true;
	b2Fixture* Plat2SensorFixture = Plataforma2Body->CreateFixture(&Plataforma2Fixture);
	b2FixtureUserData* Plat2SensorData = &Plat2SensorFixture->GetUserData();
	Plat2SensorData->pointer = 420;



	/*CREACION DE LA TERCERA PLATAFORMA*/

	b2BodyDef Plataforma3Def;
	Plataforma3Def.position.Set(540.0f / ppm, 160.0f / ppm);

	b2Body* Plataforma3Body;
	Plataforma3Body = GameWorld.CreateBody(&Plataforma3Def);


	b2PolygonShape Plataforma3Box;
	Plataforma3Box.SetAsBox(250.0f * 0.5 / ppm, 15.0f * 0.5 / ppm);

	b2FixtureDef Plataforma3Fixture;
	Plataforma3Fixture.shape = &Plataforma3Box;
	Plataforma3Fixture.density = 0.0f;

	Plataforma3Body->CreateFixture(&Plataforma3Fixture);


	//SENSOR DE LA PLATAFORMA 3

	Plataforma3Fixture.isSensor = true;
	b2Fixture* Plat3SensorFixture = Plataforma3Body->CreateFixture(&Plataforma3Fixture);
	b2FixtureUserData* Plat3SensorData = &Plat3SensorFixture->GetUserData();
	Plat3SensorData->pointer = 1;



	/*CREACION DE PIEDRA*/

	b2BodyDef PiedraDef;
	PiedraDef.position.Set(610.0f / ppm, 320.0f / ppm);

	b2Body* PiedraBody;
	PiedraBody = GameWorld.CreateBody(&PiedraDef);


	b2PolygonShape PiedraBox;
	PiedraBox.SetAsBox(50.0f * 0.5 / ppm, 40.0f * 0.5 / ppm);

	b2FixtureDef PiedraFixture;
	PiedraFixture.shape = &PiedraBox;
	PiedraFixture.density = 0.0f;

	PiedraBody->CreateFixture(&PiedraFixture);


	//SENSOR DE LA PIEDRA

	PiedraFixture.isSensor = true;
	b2Fixture* PiedraSensorFixture = PiedraBody->CreateFixture(&PiedraFixture);
	b2FixtureUserData* PiedraSensorData = &PiedraSensorFixture->GetUserData();
	PiedraSensorData->pointer = 20;



	/*CREACION DE ARBOL*/

	b2BodyDef ARBOLDef;
	ARBOLDef.position.Set(640.0f / ppm, 70.0f / ppm);

	b2Body* ARBOLBody;
	ARBOLBody = GameWorld.CreateBody(&ARBOLDef);


	b2PolygonShape ARBOLBox;
	ARBOLBox.SetAsBox(39.0f * 0.5 / ppm, 104.0f * 0.5 / ppm);

	b2FixtureDef ARBOLFixture;
	ARBOLFixture.shape = &ARBOLBox;
	ARBOLFixture.density = 0.0f;

	ARBOLBody->CreateFixture(&ARBOLFixture);


	//SENSOR DEL ARBOL

	ARBOLFixture.isSensor = true;
	b2Fixture* ARBOLSensorFixture = ARBOLBody->CreateFixture(&ARBOLFixture);
	b2FixtureUserData* ARBOLSensorData = &ARBOLSensorFixture->GetUserData();
	ARBOLSensorData->pointer = 16;


	/*
		INICIA LA SIMULACIÓN.
	*/

	while (simulation->running()) {
		frameStart = SDL_GetTicks();

		simulation->handleEvents(PersonajeBody,Listener.onAir);
		simulation->update(PersonajeBody->GetPosition().x * ppm - 32, PersonajeBody->GetPosition().y * ppm - 32);
		simulation->render();

		/*
			AQUÍ VA EL STEP() DEL WORLD.
		*/

		GameWorld.Step(frameTime / 1000.0f, 6, 2);

		/*
			SE CALCULA EL FRAMETIME Y SE CORRIGE EL FRAMERATE SI ES NECESARIO.
		*/

		frameEnd = SDL_GetTicks();
		frameTime = frameEnd - frameStart;

		if (frameTime < frameDelay)
		{
			SDL_Delay(frameDelay - frameTime);
		}

		frameTime = SDL_GetTicks() - frameStart;
	}

	simulation->clean();

	return 0;
}