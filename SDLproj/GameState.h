#pragma once
#include "Ball.h"
#include "Paddle.h"
#include <memory>

class GameState {
public:
	int getScoreOne();
	int getScoreTwo();
	Paddle getLeftPaddle();
	Paddle getRightPaddle();
	Ball getBall();
	GameState();
	~GameState();
	void initGameState();
	void incrementState();
private:
	int playerOneScore = 0;
	int playerTwoScore = 0;
	std::unique_ptr<Ball> ball;
	std::unique_ptr<Paddle> leftPaddle;
	std::unique_ptr<Paddle> rightPaddle;
};