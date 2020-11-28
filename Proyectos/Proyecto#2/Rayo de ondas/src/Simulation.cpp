#include "Simulation.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* background;
GameObject* asteroid;

const float VELOCIDAD_ASTEROIDE = 70.0F;

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


	asteroidBody.position = vec2D(100.0f, 360.0f);

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
	asteroid->update(VELOCIDAD_ASTEROIDE * timeCount + asteroidBody.position.x - 50, asteroidBody.position.y + 200 * sin(3 * timeCount) - 50, 100, 100);

}

void Simulation::render()
{
	SDL_RenderClear(renderer);

	background->render(true);
	asteroid->render();


	SDL_RenderPresent(renderer);
}

void Simulation::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Simulation cleaned..." << std::endl;
}