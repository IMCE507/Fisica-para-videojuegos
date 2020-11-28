#include "Simulation.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* background;
GameObject* asteroid;
GameObject* asteroid2;

const float ANGULO = 20.0f;
const float PI = 3.141592653589793f;
const float LONGITUD_CUERDA = 100.0f;

float theta;



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

	asteroidBody.position = vec2D(640.0f, 200.0f);
	asteroid2Body.position = vec2D(640.0f, 200.0f);


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

	theta = ANGULO / 180.0f * PI * cos(sqrtf(150 / LONGITUD_CUERDA) * timeCount);





	asteroid->update(asteroidBody.position.x - 10, asteroidBody.position.y - 10, 20, 20);
	asteroid2->update(asteroid2Body.position.x + LONGITUD_CUERDA * sin(theta) - 16, asteroid2Body.position.y + LONGITUD_CUERDA * cos(theta) - 16, 32, 32);

}

void Simulation::render()
{
	SDL_RenderClear(renderer);


	background->render(true);
	
	

	SDL_SetRenderDrawColor(renderer, 34, 139, 34, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer, 0, 200, 1280, 200);

	SDL_SetRenderDrawColor(renderer, 236, 88, 88, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer, 640, 200, 640, asteroid2Body.position.y);

	asteroid->render();
	asteroid2->render();

	



	SDL_RenderPresent(renderer);
}

void Simulation::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Simulation cleaned..." << std::endl;
}