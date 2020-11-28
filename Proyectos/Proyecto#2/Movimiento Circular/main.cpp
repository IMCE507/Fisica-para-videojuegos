#include "Simulation.h"

int main(int argc, char* args[])
{
	const int FPS = 60;
	const float frameDelay = 1000 / FPS;

	Uint32 frameStart;
	Uint32 frameEnd;
	float frameTime = 0.0f;

	Simulation* simulation = nullptr;
	simulation = new Simulation();

	simulation->init("Movimiento Circular", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

	//FRAME
	while (simulation->running()) {

		frameStart = SDL_GetTicks();

		simulation->handleEvents();
		simulation->update(frameTime / 1000.0f);
		simulation->render();

		frameEnd = SDL_GetTicks();

		frameTime = frameEnd - frameStart;

		if (frameTime < frameDelay)
		{
			SDL_Delay(frameDelay - frameTime);
		}

		frameTime = SDL_GetTicks() - frameStart;

	}

	simulation->clean();

	return 0;
}