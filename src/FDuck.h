#pragma once

#include "ofMain.h"
#include <vector>

class FDuck
{
public:
	FDuck();

	void setup();
	void update();
	void draw();
	//Getters
	int getXsize();
	int getYsize();
	//methods
	void Quack();
	void flipImage();
	//varables
	float xp, yp, xSpeed, ySpeed;
	int xSize = 60;
	int	ySize = 72;
	//image
	ofImage duckSkin;
	//sound
	ofSoundPlayer quack;

};

