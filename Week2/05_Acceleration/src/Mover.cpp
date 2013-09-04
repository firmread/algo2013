//
//  Mover.cpp
//  Acceleration
//
//  Created by Charlie Whitney on 9/2/13.
//
//

#include "Mover.h"

Mover::Mover() {
    pos.x = ofGetWindowWidth() / 2.0;
    pos.y = ofGetWindowHeight() / 2.0;
    
    velocity.x = ofRandom(-5.0, 5.0);
    velocity.y = ofRandom(-5.0, 5.0);
}

void Mover::update() {
    ofVec2f accel = (mousePos - pos) * 0.01f;
    velocity += accel;
    
    pos += velocity;
    velocity *= 0.97;
}

void Mover::draw() {
    ofCircle( pos, 10 );
}