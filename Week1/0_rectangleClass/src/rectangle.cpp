#include "rectangle.h"


//------------------------------------------------------------------
Rectangle::Rectangle(){
  
}

void Rectangle::update(){

	pos.x = pos.x + ofRandom(-1,1);
    pos.y = pos.y + ofRandom(-1,1);
}

//------------------------------------------------------------------
void Rectangle::draw() {
	ofFill();
    ofEnableAlphaBlending();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(255,0,255,255);
    
    ofRect(pos.x, pos.y, 20,20);
}
