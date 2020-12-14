#ifndef SimPhy_H
#define SimPhy_H

#include "SimPhyBody.h"
#include <vector>

struct SimPhyWorld
{
	// Definimos el constructor de la clase. 
	SimPhyWorld() {}
	SimPhyWorld(vec2D gravity) : gravity(gravity) {}

	// Declaramos la variable gravedad del world. 
	vec2D gravity;

	// Declaramos un vector que contenga todos los cuerpos en este world. 
	std::vector<SimPhyBody*> bodies;

	// Creamos una funci�n para establecer la gravedad del world. 
	void setGravity(const vec2D& g);

	// Creamos una funci�n para agregar un cuerpo a este world. 
	void addBody(SimPhyBody* b);

	// Creamos la funci�n Step. Esta es la encargada de la simulaci�n.
	void Step(float dt); //El dt suele ser el tiempo que toma pasar de un frame al otro. 

};

#endif SimPhy_H 

