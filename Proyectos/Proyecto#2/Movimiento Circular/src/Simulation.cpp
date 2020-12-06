#include "Simulation.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* background;
GameObject* asteroid;
GameObject* asteroid2;
GameObject* asteroid3;
GameObject* asteroid4;

Simulation::Simulation()
{}

Simulation::~Simulation()
{}

void Simulation::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initialized!" << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}
	else {
		std::cout << "Couldn't initiate SDL..." << std::endl;
		isRunning = false;
	}

	background = new GameObject("assets/blue.png", renderer);
	asteroid = new GameObject("assets/asteroid.png", renderer);
	asteroid2 = new GameObject("assets/asteroid.png", renderer);
	asteroid3 = new GameObject("assets/asteroid.png", renderer);
	asteroid4 = new GameObject("assets/asteroid.png", renderer);

	asteroidBody.position = vec2D(640.0f, 360.0f);
	asteroid2Body.position = vec2D(640.0f, 360.0f);
	asteroid3Body.position = vec2D(640.0f, 360.0f);
	asteroid4Body.position = vec2D(640.0f, 360.0f);
}

void Simulation::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Simulation::update(float dt)
{
	timeCount += dt;
	/*Al cambiar los radios de los asteroides, se puede ver la distancia de separacion en el eje en que esta girando el asteroide. Entre mayor es el radio mas grande la distancia de separacion.*/
	/*Al cambiar ambas frecuencias angulares (X y Y), el objeto cambia su velocidad. Entre mayor es la frecuencia, mayor es la velocidad. Si cambias la frecuencia en un solo eje, el movimiento circular se pierde.*/

	asteroid->update(asteroidBody.position.x - 50, asteroidBody.position.y - 50, 100, 100);
	asteroid2->update(asteroid2Body.position.x + 100 * cos(0.7 * timeCount) - 10, asteroid2Body.position.y + 100 * sin(0.7 * timeCount) - 10, 20, 20);
	asteroid3->update(asteroid3Body.position.x + 200 * cos(0.6 * timeCount) - 20, asteroid3Body.position.y + 200 * sin(0.6 * timeCount) - 20, 40, 40);
	asteroid4->update(asteroid4Body.position.x + 300 * cos(1 * timeCount) - 20, asteroid4Body.position.y + 300 * sin(1 * timeCount) - 20, 40, 40);
}

void Simulation::render()
{
	SDL_RenderClear(renderer);

	background->render(true);
	asteroid->render();
	asteroid2->render();
	asteroid3->render();
	asteroid4->render();

	SDL_RenderPresent(renderer);
}

void Simulation::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Simulation cleaned..." << std::endl;
}