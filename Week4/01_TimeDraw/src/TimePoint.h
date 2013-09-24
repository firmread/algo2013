//
//  TimePoint.h
//  TimeDraw
//
//  Created by Charlie Whitney on 9/17/13.
//
//

#pragma once

#include "ofMain.h"

class TimePoint {
  public:
    TimePoint(){
        cout << "Constructed!" << endl;
    };
    ~TimePoint(){
        cout << "Denstructed!" << endl;
    }
    ;
    
    float x, y;
    float t;
};
