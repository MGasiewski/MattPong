#include <iostream>
#include <SDL.h>
#include <string>
#include "RenderingEngine.h"

void RenderingEngine::logSDLError(std::ostream &os, const std::string &msg)
{
	os << msg << " error: " << SDL_GetError() << std::endl;
}

void RenderingEngine::initialize()
{
	win = createWindow();
	ren = createRenderer(win);
}

RenderingEngine::RenderingEngine()
{
}

RenderingEngine::~RenderingEngine()
{
}

SDL_Rect RenderingEngine::getRect(Paddle paddle)
{
	SDL_Rect rect;
	rect.x = paddle.getXPos();
	rect.y = paddle.getYPos();
	rect.h = paddle.HEIGHT;
	rect.w = paddle.WIDTH;
	return rect;
}

SDL_Rect RenderingEngine::getRect(Ball ball)
{
	SDL_Rect rect;
	rect.x = ball.getXPos();
	rect.y = ball.getYPos();
	rect.h = ball.HEIGHT;
	rect.w = ball.WIDTH;
	return rect;
}

GameState & RenderingEngine::getState()
{
	return *state;
}

void RenderingEngine::setState(std::shared_ptr<GameState>& val)
{
	state = val;
}

SDL_Window* RenderingEngine::createWindow()
{
	SDL_Window* win = SDL_CreateWindow("Pong", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (win == nullptr)
	{
		logSDLError(std::cout, "Window creation");
		SDL_Quit();
		throw 1;
	}
	return win;
}

SDL_Renderer* RenderingEngine::createRenderer(SDL_Window* win)
{
	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr)
	{
		SDL_DestroyWindow(win);
		logSDLError(std::cout, "Renderer creation");
		SDL_Quit();
		throw 1;
	}
	return ren;
}

void RenderingEngine::draw()
{
	//Render background
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_RenderClear(ren);
	//Render foreground
	SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
	//draw left paddle
	SDL_Rect lRect = getRect(state->getLeftPaddle());
	SDL_RenderFillRect(ren, &lRect);
	//draw right paddle
	SDL_Rect rRect = getRect(state->getRightPaddle());
	SDL_RenderFillRect(ren, &rRect);
	//draw ball
	SDL_Rect bRect = getRect(state->getBall());
	SDL_RenderFillRect(ren, &bRect);
	SDL_RenderPresent(ren);
	SDL_Delay(17);
}

void RenderingEngine::cleanUp()
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

