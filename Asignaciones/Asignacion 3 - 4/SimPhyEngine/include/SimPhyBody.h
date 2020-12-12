#pragma once//Usamos pragma once para no tener problemas de inclusiones repetidas y solo se incluyan las librerias una sola vez. 
#ifndef SimPhyBody_H//Header Guard para evitar doble inclusion, casi similar al pragma once de la linea anterior. 
#define SimPhyBody_H

#include "SimPhyMath.h"//Inclusion del header file "SimPhyMath.h". Usamos este Header para acceder al struct como vec2D con sus metodos. 

struct SimPhyBody //Declaracion del struct SimPhyBody. Este struct se utiliza para crear objetos (bodies) y "settiar" sus caracteristicas basicas. 
{

	//Declaracion del constructor de la struct SimPhyBody. Este Constructor se encarga  inicializar los valores del Body (mass, invMass, position, velocity, force).
	SimPhyBody();

	float mass;//Declaracion de la variable mass. La variable se encarga de almacenar el valor de la "masa" del body que estamos instanciando. 
	float invMass; //Declaracion de la variable invMass. Esta es la masa inversa del body. Se utiliza esta variable para hacer ciertos calculos de manera mas rapida y eficiente. 

	vec2D position;//Declaracion de la variable position. Esta variable es de tipo vec2D, un vector de dos dimensiones. position se encarga de almacenar un vector con la coordenadas exactas (x,y) del body.

	vec2D velocity;//Declaracion de la variable velocity. Se declara como tipo vec2D para saber la direccion de la velocidad del body.

	vec2D force;//Declaracion de la variable force. Almacena la cantidad de fuerza que se aplica en el body en las coordenadas X,Y.


	/*Declaracion del metodo "addForce". Este metodo se encarga de agregar la fuerza aplicada al body, y la guarda en la variable force. 
	Recibe como parametro una constante f (que indica la fuerza) de tipo vec2D para saber la direccion donde se aplica la fuerza*/
	void addForce(const vec2D& f);

	/*Declaracion del metodo "setMass". Este metodo se encarga de cambiar la masa del body instanciado. Usualmente al instanciar el body el constructor se encarga de "settiar" la masa
	en 1.0f, pero este metodo cambia el valor de la masa si el programador desea. El metodo recibe como parametro una constante "m" de tipo float que indica la masa del Body a "settiar". */
	void setMass(const float& m);

	/*Declaracion del metodo "DisplayBodyInfo". Este metodo se encarga de desplegar la informacion basica del Body como el valor de las variables mass, invmass, position y velocity.*/
	void displayBodyInfo();

};

#endif SimPhyBody_H

