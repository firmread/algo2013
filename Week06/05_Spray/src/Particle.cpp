//
//  Particle.cpp
//  GridParticles
//
//  Created by Charlie Whitney on 9/23/13.
//
//

#include "Particle.h"

Particle::Particle( ofVec2f position, ofVec2f velocity ) {
    pos = position;
    vel = velocity;
    radius = 2;
    age = 0;
    lifespan = floor( ofRandom(60,100) );
}

void Particle::update( const ofImage &img, ofVec2f mousePos ){
    
    pos += vel;
    vel *= 0.97;
    
    age++;
    if( age > lifespan ){
        bIsDead = true;
    }
    
    float agePct = 1.0 - ((float)age / (float)lifespan);
    radius = agePct * 3.0;
}

void Particle::draw() {
    ofSetColor( 255 );
    ofCircle(pos, radius );
}