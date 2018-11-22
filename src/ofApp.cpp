#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetBackgroundColor(250);
	ofSetFrameRate(30);
	//LOAD images
	crossHair.load("crosshair.png");
	//load sounds
	Start.load("99 - Laugh (SFX).mp3");
	Start.play();
	Gun.load("gun.wav");
	Gun.setMultiPlay(true);
	End.load("07 - You Failed.mp3");
	for (int i = 0; i < maxbirds; i++)
	{
		birds.push_back(new FDuck());
		birds[i]->setup();
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	birds[count]->update();
	if(birds[count]->yp < -(birds[count]->getYsize()))
	{
		birds.erase(birds.begin() + count);
		birds.push_back(new FDuck());
		birds[count]->Quack();
		misses++;
	}
	

}

//--------------------------------------------------------------
void ofApp::draw()
{
	birds[count]->draw();
	crossHair.draw(ofGetMouseX() - 50, ofGetMouseY() - 50);
	printStats();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) 
{
	switch (key) 
	{
	case(' '):
		//checks for hit
		if ((ofGetMouseX() > birds[count]->xp && ofGetMouseX() < (birds[count]->xp+ birds[count]->getXsize())) &&
				(ofGetMouseY() > birds[count]->yp && ofGetMouseY() < (birds[count]->yp + birds[count]->getYsize()))) 
		{
			Gun.play();
			birds[count]->Quack();
			birds.erase(birds.begin()+ count);
			hits++;
			shots++;
			count++;
			birds.push_back(new FDuck());
		}
		else //missing
		{
			Gun.play();
			Start.play();
			birds[count]->xSpeed *= -1;
			birds[count]->ySpeed *= 1.5;
			birds[count]->flipImage();
			misses++;
			shots++;
		}
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

void ofApp::printStats()
{
	ofSetColor(0, 255, 0);
	ofDrawBitmapString("Shots: " + ofToString(shots), 5, 30);
	ofDrawBitmapString("Hits: " + ofToString(hits), 5, 45);
	ofDrawBitmapString("Misses: " + ofToString(misses), 5, 60);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {	
}
