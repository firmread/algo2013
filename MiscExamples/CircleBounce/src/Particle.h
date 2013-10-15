//
//  Particle.h
//  CircleBounce
//
//  Created by Charlie Whitney on 10/12/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
  public:
    Particle();
    
    void update( ofVec2f circleCenter, float circleRadius );
    void draw();
    
    ofVec2f     pos, vel;
};