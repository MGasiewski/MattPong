#include "Ball.h"

int Ball::getXPos()
{
	return xPos;
}

int Ball::getYPos()
{
	return yPos;
}

int Ball::getDirDeg()
{
	return dirDeg;
}

void Ball::setXPos(int val)
{
	xPos = val;
}

void Ball::setYPos(int val)
{
	yPos = val;
}

void Ball::setDirDeg(int val)
{
	dirDeg = val;
}

Ball::Ball()
{

}

Ball::~Ball()
{

}