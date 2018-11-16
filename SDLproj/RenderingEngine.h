#pragma once
#include <SDL.h>
#include <memory>
#include <vector>
#include "GameState.h"
#include "Paddle.h"
#include "Ball.h"


class RenderingEngine
{
public:
	void logSDLError(std::ostream & os, const std::string & msg);
	void initialize();
	RenderingEngine();
	~RenderingEngine();
	SDL_Rect getRect(Paddle paddle);
	SDL_Rect getRect(Ball ball);
	GameState& getState();
	void setState(std::shared_ptr<GameState>& val);
	SDL_Window* createWindow();
	SDL_Renderer* createRenderer(SDL_Window* win);
	void draw();
	void cleanUp();
private:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	std::shared_ptr<GameState> state;
	SDL_Window* win;
	SDL_Renderer* ren;
};