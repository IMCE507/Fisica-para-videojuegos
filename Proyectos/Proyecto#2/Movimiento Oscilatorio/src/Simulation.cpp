#include "Simulation.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* background;
GameObject* asteroid;
GameObject* asteroid2;
GameObject* asteroid3;
GameObject* asteroid4;

const float LOCALIZACION_ASTEROIDES_X = 400.0f;

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

	asteroidBody.position = vec2D(LOCALIZACION_ASTEROIDES_X, 100.0f);
	asteroid2Body.position = vec2D(LOCALIZACION_ASTEROIDES_X, 250.0f);
	asteroid3Body.position = vec2D(LOCALIZACION_ASTEROIDES_X, 400.0f);
	asteroid4Body.position = vec2D(1000.0f, 360.0f);
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
	asteroid->update(asteroidBody.position.x + 350 * cos(10 * timeCount) - 50, asteroidBody.position.y - 50, 100, 100);
	asteroid2->update(asteroid2Body.position.x + 350 * cos(3 * timeCount) - 50, asteroid2Body.position.y - 50, 100, 100);
	asteroid3->update(asteroid3Body.position.x + 350 * cos(1 * timeCount) - 50, asteroid3Body.position.y - 50, 100, 100);
	asteroid4->update(asteroid4Body.position.x - 50, asteroid4Body.position.y + 350 * sin(2 * timeCount) - 50, 100, 100);
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