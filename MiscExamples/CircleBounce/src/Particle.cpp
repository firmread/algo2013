//
//  Particle.cpp
//  CircleBounce
//
//  Created by Charlie Whitney on 10/12/13.
//
//

#include "Particle.h"

Particle::Particle() {

}

void Particle::update(ofVec2f circleCenter, float circleRadius) {
    pos += vel;
    
    // This is the code that bounces off of a curved surface.  It's hard to understand, but feel free to use it if you like!
    if( pos.distance(circleCenter) > circleRadius ){
        ofVec2f tmpPos = pos - circleCenter;
        pos = tmpPos.normalized() * circleRadius + circleCenter;
        
        ofVec2f circleNormal( tmpPos.x, tmpPos.y );
        float twiceProjFactor = 2.0 * vel.dot( circleNormal ) / (circleRadius * circleRadius);
        ofVec2f velBounced = vel - ofVec2f(twiceProjFactor, twiceProjFactor) * tmpPos;
        vel.set( velBounced );
    }
}

void Particle::draw() {
    ofCircle( pos, 5 );
}