#pragma once
class Paddle
{
public:
	const int WIDTH = 20;
	const int HEIGHT = 80;
	Paddle();
	~Paddle();
	int getXPos();
	int getYPos();
	void setXPos(int val);
	void setYPos(int val);
private:
	int xPos;
	int yPos;
};