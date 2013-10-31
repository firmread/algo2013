//
//  Particle.h
//  GridParticles
//
//  Created by Charlie Whitney on 9/23/13.
//
//

#pragma once 

#include "ofMain.h"

class Particle {
  public:
    Particle( ofVec2f position );
  
    void update( const ofImage &img, ofVec2f mousePos );
    void draw();
    
    ofVec2f pos;
    
    
    //
    float   radius;
    float   grayValue;
    ofVec2f dirToCursor, newLoc;
};