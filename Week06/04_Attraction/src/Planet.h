//
//  Planet.h
//  Attraction
//
//  Created by Charlie Whitney on 9/30/13.
//
//

#pragma once

#include "ofMain.h"

class Planet {
  public:
    Planet();
    
    void applyForce( ofVec2f force );
    
    void update();
    void draw();
    
    ofVec2f attract( Planet p );
    
    ofVec2f pos, vel, accel;
    
    const static float G = 0.4;
    float mass;
};