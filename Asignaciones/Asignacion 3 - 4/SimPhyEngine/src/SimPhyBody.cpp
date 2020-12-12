#include "SimPhyBody.h"



SimPhyBody::SimPhyBody()//Definicion del constructor de la struct SimPhyBody. La explicación del uso de este constructor esta en SimPhyBody.h.
{

	/*Inicializamos la posicion del body instanciado a (0,0) (x,y). Usamos el metodo "setZero()" de la struct vec2D para hacer que el vector position del Body sea (0,0)*/
	position.setZero();

	/*Inicializamos la velocidad del body instanciado a (0,0) (x,y). Usamos el metodo "setZero()" de la struct vec2D para hacer que el vector velocidad del Body sea (0,0)*/
	velocity.setZero();

	/*Inicializamos la fuerza del body instanciado a (0,0) (x,y). Usamos el metodo "setZero()" de la struct vec2D para hacer que el vector force del Body sea (0,0)*/
	force.setZero();

	/*Inicializamos la masa del Body como 1.0f.*/
	mass = 1.0f;

	/*Inicializamos la masa inversa del Body a 1.0f*/
	invMass = 1.0f;


	/*Inicializamos los valores de nuestro Body para que no tengan valores nulos o "NULL" y asi evitamos errores a la hora de aplicar formulas y calculos en casos de que estos campos no se hallan "settiado".*/
}

void SimPhyBody::addForce(const vec2D& f)//Definicion del metodo "addForce" del struct SimPhyBody. La explicación del uso de este metodo esta en SimPhyBody.h.
{
	force += f;//Añade la cantidad de fuerza recibida del parametro "f" y la suma en la variable "force" de la struct SimPhyBody 
}

void SimPhyBody::setMass(const float& m)//Definicion del metodo "SetMass" del struct SimPhyBody. La explicación del uso de este metodo esta en SimPhyBody.h.
{
	mass = m;//Se iguala el valor "m" que se paso por parametro a la variable "mass" del Body.
	invMass = 1 / m;//Utilizando la formula de la masa inversa, dividimos 1 entre el valor pasado por parametro (m) y obtenemos la masa inversa del body.
}

void SimPhyBody::displayBodyInfo()//Definicion del metodo "displayBodyInfo" del struct SimPhyBody. La explicación del uso de este metodo esta en SimPhyBody.h.
{
	std::cout << "m: " << mass << std::endl;//Imprime el valor de la masa del body.
	std::cout << "Inv mass: " << invMass << std::endl;//Imprime el valor de la masa inversa del body.
	std::cout << "pos: ", position.displayVector();//Imprime la posicion del body.
	std::cout << "vel: ", velocity.displayVector();//Imprime la velocidad del body.
	std::cout << "\n" << std::endl;//Salto de linea 
}