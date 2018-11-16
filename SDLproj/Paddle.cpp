#include "Paddle.h"

Paddle::Paddle()
{

}

Paddle::~Paddle()
{

}

int Paddle::getXPos()
{
	return xPos;
}

int Paddle::getYPos()
{
	return yPos;
}

void Paddle::setXPos(int val)
{
	xPos = val;
}

void Paddle::setYPos(int val)
{
	yPos = val;
}
