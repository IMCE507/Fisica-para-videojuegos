#include "SimPhyWorld.h"

int main()
{
	SimPhyWorld firstSimulation(vec2D(0.0f, 9.81f)); //Declaracion del World "firstSimulation" con una fuerza de gravedad 9.81.
	SimPhyBody firstBody;//Declaracion del objetp "firstBody".
	SimPhyBody secondBody;//Declaracion del objeto "secondBody".

	/*Accediendo al campo "position" del objeto "secondBody", igualamos el valor de "position" a un vec2D(5.0f, 10.0f), asi cambiando la 
	posicion de "secondBody" a la coordenada (5, 10). */
	secondBody.position = vec2D(5.0f, 10.0f); 

	/*Accediendo al campo "velocity" del objeto "secondBody", igualamos el valor de "velocity" a un vec2D(7.5f, 3.8f), asi cambiando la
	velocidad inicial de "secondBody" a 7.5 en x y 3.8 en y. */
	secondBody.velocity = vec2D(7.5f, 3.8f);

	firstSimulation.addBody(&firstBody);//Utilizando el metodo "addBody" del world "firstSimulation", agregamos el Body "firstBody" a la lista de objetos que interactuan con este mundo.
	firstSimulation.addBody(&secondBody);//Utilizando el metodo "addBody" del world "firstSimulation", agregamos el Body "secondBody" a la lista de objetos que interactuan con este mundo.

	float frameTime = 0.5f; //Declaracion del frame time. Este es valor de ejemplo para indicar el tiempo que transcurre entre frames.
	int counter = 0;//Declaracion de la variable counter y la inicializamos a 0. Utilizamos esta variable para contar la cantidad de ciclos en el while de la proxima linea. 

	while (counter < 10) { //Usamos la estructura recursiva while para hacer bucles hasta que la variable counter sea mayor que 10.
		firstBody.displayBodyInfo();//Utilizando el metodo "displayBodyInfo" del Body "firstBody", desplegamos la informacion escencial del body (masa, velocidad y posicion).
		secondBody.displayBodyInfo(); //Utilizando el metodo "displayBodyInfo" del Body "secondBody", desplegamos la informacion escencial del body (masa, velocidad y posicion).
		firstSimulation.Step(frameTime);//Actualiza la posicion y velocidad de los bodies que estan en incluidos en el mundo "firstSimulation".
		counter++;//incrementamos el valor de counter a +1. Si esta variable no incrementa entonces el bucle sera infinito. 
	}

	return 0;//Finalizacion de la simulacion
}