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
    radius = 4;
    grayValue = 255;
//    radius = ofRandom(1.0, 5.0);
//    radius = cos( pos.y * 0.1 ) + sin( pos.x * 0.1 ) + 2;
//    radius = ( sin( pos.y * pos.x ) + 1.0f ) * 2.0f;
}

void Particle::update( const ofImage &img ){
    
    grayValue = img.getColor( pos.x, pos.y ).g;
    radius = ((float)grayValue / 255.0) * 7.0;
    
    radius = 4;
}

void Particle::draw() {
    ofSetColor( grayValue );
//    ofSetColor(255);
    ofCircle( pos, radius );
}