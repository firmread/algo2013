//
//  Particle.cpp
//  GridParticles
//
//  Created by Charlie Whitney on 9/23/13.
//
//

#include "Particle.h"

Particle::Particle( ofVec2f position ) {
    pos = position;
    radius = 2;
    grayValue = 255;
//    radius = ofRandom(1.0, 5.0);
//    radius = cos( pos.y * 0.1 ) + sin( pos.x * 0.1 ) + 2;
//    radius = ( sin( pos.y * pos.x ) + 1.0f ) * 2.0f;
}

void Particle::update( const ofImage &img, ofVec2f mousePos ){
    
    // this gives us a vector of the direction from the mouse, to our particle
    dirToCursor = mousePos - pos;
    dirToCursor.normalize();
    newLoc = pos + dirToCursor * 50.0;
    
    
//    float timeOffset = ofGetElapsedTimef() * 4.0;
//    dirToCursor = mousePos - pos;
//    float dist = dirToCursor.length() * 0.05;
//    float sinOffset = sin( dist - timeOffset ) * 100.0;
//    dirToCursor.normalize();
//    
//    newLoc = pos + dirToCursor * sinOffset;
    
    newLoc.x = ofClamp( newLoc.x, 0.0, img.width );
    newLoc.y = ofClamp( newLoc.y, 0.0, img.height );
    
    grayValue = img.getColor( newLoc.x, newLoc.y ).r;
}

void Particle::draw() {
    ofSetColor( grayValue );
    ofRect(pos, radius, radius );
}