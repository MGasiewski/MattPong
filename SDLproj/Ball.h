#pragma once
class Ball
{
public:
	const int HEIGHT = 20;
	const int WIDTH = 20;
	int getXPos();
	int getYPos();
	int getDirDeg();
	void setXPos(int val);
	void setYPos(int val);
	void setDirDeg(int val);
	Ball();
	~Ball();
private:
	int xPos;
	int yPos;
	int dirDeg;
};