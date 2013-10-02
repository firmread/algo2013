//
//  Planet.cpp
//  Attraction
//
//  Created by Charlie Whitney on 9/30/13.
//
//

#include "Planet.h"

Planet::Planet() {
    mass = 1.0;
}

ofVec2f Planet::attract(Planet p){
    
    ofVec2f forceDir = pos - p.pos;
    float dist = forceDir.length();
    forceDir.normalize();
    
    float pullStrength = (G * mass * p.mass) / dist * dist;
    forceDir *= pullStrength;
    
    return forceDir;
}

void Planet::applyForce(ofVec2f force){
    //    accel += force;
    accel += (force / mass);
}

void Planet::update(){
    vel += accel;
    pos += vel;
//    
//    if( pos.x < 0 || pos.x > ofGetWindowWidth() ){
//        vel.x = -vel.x;
//    }
//    if( pos.y < 0 || pos.y > ofGetWindowHeight() ){
//        vel.y = -vel.y;
//    }
    
    
    accel.set(0);
    // we could also do accel *= 0;
}

void Planet::draw() {
    ofCircle( pos, mass * 10 );
}