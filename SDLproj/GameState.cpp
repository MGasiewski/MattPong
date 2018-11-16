#include "GameState.h"
#include <memory>
#include <stdlib.h>
#include <time.h>
#include "Ball.h"
#include "Paddle.h"


void GameState::initGameState()
{
	this->ball = std::make_unique<Ball>();
	this->leftPaddle = std::make_unique<Paddle>();
	this->rightPaddle = std::make_unique<Paddle>();
	//Set initial values
	leftPaddle->setXPos(10);
	leftPaddle->setYPos(10);
	rightPaddle->setXPos(610);
	rightPaddle->setYPos(10);
	ball->setXPos(320);
	ball->setYPos(240);
	//get initial directional value and set
	srand(time(NULL));
	int direction = rand() % 360;
	ball->setDirDeg(direction);
}

void GameState::incrementState()
{
	//calculate new ball state
	int yChg = 5 * sin(ball->getDirDeg()); //Should ball update own state?
	int xChg = 5 * cos(ball->getDirDeg());
	ball->setXPos(ball->getXPos() + xChg);
	ball->setYPos(ball->getYPos() + yChg);
}

int GameState::getScoreOne()
{
	return playerOneScore;
}

int GameState::getScoreTwo()
{
	return playerTwoScore;
}

Paddle GameState::getLeftPaddle()
{
	return *leftPaddle;
}

Paddle GameState::getRightPaddle()
{
	return *rightPaddle;
}

Ball GameState::getBall()
{
	return *ball;
}

GameState::GameState()
{

}

GameState::~GameState()
{

}