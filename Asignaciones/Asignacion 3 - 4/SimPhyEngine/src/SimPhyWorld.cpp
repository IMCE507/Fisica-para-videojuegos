#include "SimPhyWorld.h"


void SimPhyWorld::setGravity(const vec2D& g) //Definicion del metodo "setGravity".
{
	gravity = g; //Igualamos el valor del parametro g, a la variable local "gravity" del struct SimPhyWorld.
}

void SimPhyWorld::addBody(SimPhyBody* b)//Definicion del metodo "addBody".
{
	bodies.push_back(b);//Agregamos al vector local "Bodies" los punteros de tipo "SimPhyBody" que recibe como parametro este metodo. 
}

void SimPhyWorld::Step(float dt)//Definicion del metodo "Step".
{

	/*Usamos la estructura recursiva "For" para navegar a cada body que esta almacenado en el vector "Bodies". 
	Mejor explicado... Accedemos a cada body que esta incluido en el world*/
	for (int counter = 0; counter < bodies.size(); counter++) 
	{
	    /*Añadimos velocidad en los ejes x , y dependiendo de la masa inversa del body y la fuerza de gravedad del mundo*/
		bodies[counter]->velocity.x += (gravity.x + bodies[counter]->force.x * bodies[counter]->invMass) * dt;
		bodies[counter]->velocity.y += (gravity.y + bodies[counter]->force.y * bodies[counter]->invMass) * dt;
	}


	/*Nuevamente navegamos a cada objeto incluido del world, pero esta vez para cambiar la posicion de los objetos despues de haber calculado la velocidad del mismo.*/
	for (int counter = 0; counter < bodies.size(); counter++) {

		bodies[counter]->position.x += bodies[counter]->velocity.x * dt;
		bodies[counter]->position.y += bodies[counter]->velocity.y * dt;

		bodies[counter]->force.setZero(); //Aplicamos el metodo "setZero" para dejar la fuerza en 0 en ambos ejes. 
	}
}
