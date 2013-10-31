//
//  Rectangle.h
//  xenoTrail
//
//  Created by Charlie Whitney on 9/3/13.
//
//

#pragma once 

#include "ofMain.h"

class Rectangle {
  public:
    Rectangle();
    
    void xenoToPoint( float catchX, float catchY );
    void draw();
    
    ofPoint pos, targetPos;
    
    float catchUpSpeed;
};