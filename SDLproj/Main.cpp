#include <iostream>
#include <string>
#include <SDL.h>
#include <memory>
#include "GameState.h"
#include "RenderingEngine.h"
#include <vector>

int main(int argc, char* argv[]) 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "Could not initialize SDL\n";
		throw 1;
	}
	std::shared_ptr<GameState> state = std::make_shared<GameState>();
	std::unique_ptr<RenderingEngine> engine = std::make_unique<RenderingEngine>();
	engine->setState(state);
	engine->initialize();
	state->initGameState();
	for (int i = 0; i < 600; i++)
	{
		engine->draw();
		state->incrementState();
	}
	engine->cleanUp();
	return 0;
}