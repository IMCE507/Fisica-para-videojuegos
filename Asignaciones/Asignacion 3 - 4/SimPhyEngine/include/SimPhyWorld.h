#ifndef SimPhy_H//Header Guard para evitar doble inclusion
#define SimPhy_H

#include "SimPhyBody.h"//Incluimos el Header File "SimPhyBody.h". Usamos este Header para acceder a el struct SimPhyBody con sus campos y metodos.
#include <vector>//Inclusion de la libreria "vector". Usamos vector para acceder al tipo de dato "vector" y almacenar muchos datos del mismo tipo en una sola variable. 



/*Declaracion del struct SimPhyWorld. Este struct se encarga de aplicar calculos a los bodies creados o incluidos en el world. Si un objeto (Body) no se incluyen en el world, el objeto no se le aplicaran fisicas o calculos.*/
struct SimPhyWorld 
{
	
	SimPhyWorld() {} //Constructor del struct SimPhyWorld
	SimPhyWorld(vec2D gravedad) : gravity(gravedad) {} //Primera sobrecarga del constructor de SimPhyWorld. Tiene como parametro la gravedad como tipo vec2D y setea su valor con la variable local gravity. 


	vec2D gravity;//Declaracion de la variable local gravity. Esta variable se encarga de especificar la fuerza de gravedad del mundo instanciado. 

 
	std::vector<SimPhyBody*> bodies; //Vector que almacena todos los posibles "Bodies" que interactuan con este mundo (World).

 
	void setGravity(const vec2D& g);//Declaracion del metodo "setGravity". Se encarga de cambiar la gravedad del mundo instanciado. 


	void addBody(SimPhyBody* b);//Declaracion del metodo "addbody". Este metodo se encarga de añadir Bodies a la variable local bodies, asi los bodies instanciados puedan interactuar con el mundo. 


	/*Declaracion del metodo "Step". Este metodo se encarga de actualizar la velocidad y posicion de todos los bodies que estan incluidos en el World dependiendo de la gravedad.
	Recibe como parametro "dt" (delta time) de tipo float. "dt" seria el tiempo que transcurrio desde el ultimo frame actualizado. */
	void Step(float dt); 

};

#endif SimPhy_H 

