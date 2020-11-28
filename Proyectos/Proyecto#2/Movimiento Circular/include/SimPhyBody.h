#pragma once
#ifndef SimPhyBody_H
#define SimPhyBody_H

#include "SimPhyMath.h"

struct SimPhyBody
{

	// Declaramos el constructor de la clase.
	SimPhyBody();

	// Declaramos la masa del objeto y el rec�proco de la masa. 
	float mass;
	float invMass;

	// Declaramos la posici�n (lineal) del objeto. 
	vec2D position;

	// Declaramos la velocidad (lineal) del objeto. 
	vec2D velocity;

	// Declaramos la fuerza aplicada al objeto. 
	vec2D force;

	// Creamos una funci�n para agregar fuerzas al cuerpo. 
	void addForce(const vec2D& f);

	// Creamos una funci�n para establecer la masa del objeto. 
	void setMass(const float& m);

	// Creamos una funci�n que muestre las propiedades del objeto. 
	void displayBodyInfo();

};

#endif SimPhyBody_H

