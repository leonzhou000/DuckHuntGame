#include "FDuck.h"

FDuck::FDuck() { duckSkin.load("Ducks.gif"); }
int FDuck::getXsize() { return xSize; }
int FDuck::getYsize() { return ySize; }
void FDuck::Quack() { quack.play(); }

void FDuck::flipImage()
{
	bool vertical = false;
	bool horizontal = true;
	duckSkin.mirror(vertical,horizontal);
}

void FDuck::setup()
{
	//position
	xp = ofRandom(0, ofGetWidth() - xSize);
	yp = ofGetHeight();
	//speed
	xSpeed = ofRandom(-10, 10);
	ySpeed = ofRandom(-1, -10);
	//load sound
	quack.load("99 - Quack! (SFX).mp3");
	quack.setMultiPlay(true);
	//checks duck facing
	if (xSpeed < 0) { flipImage(); }
}

void FDuck::update()
{
	//boundary check width & height
	if (xp < 0 || xp > ofGetWidth() - xSize)
	{
		xSpeed *= -1.1;
		flipImage();
		Quack();
	}
	//speed
	xp += xSpeed;
	yp += ySpeed;
	
}

void FDuck::draw()
{
	duckSkin.draw(xp, yp);
}
