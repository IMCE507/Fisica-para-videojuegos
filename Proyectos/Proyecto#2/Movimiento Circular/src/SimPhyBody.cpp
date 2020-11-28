#include "SimPhyBody.h"

SimPhyBody::SimPhyBody()
{
	position.setZero();

	velocity.setZero();

	force.setZero();

	mass = 1.0f;
	invMass = 1.0f; /* 1/mass */
}

void SimPhyBody::addForce(const vec2D& f)
{
	force += f;
}

void SimPhyBody::setMass(const float& m)
{
	mass = m;
	invMass = 1 / m;
}

void SimPhyBody::displayBodyInfo()
{
	std::cout << "m: " << mass << std::endl;
	std::cout << "Inv mass: " << invMass << std::endl;
	std::cout << "pos: ", position.displayVector();
	std::cout << "vel: ", velocity.displayVector();
	std::cout << "\n" << std::endl;
}