#pragma once

#include "ofMain.h"
#include "TimePoint.h"

class testApp : public ofBaseApp{

  public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
		
    vector<TimePoint>   pointList;      // we called this "points" during class. Renamed for clarity.
    float               startTime;
    float               playbackStartTime;
    bool                bIsRecording;
    ofPoint             getPositionForTime( float time );
    ofVec2f             getVelocityForTime( float time );
    
    ofSoundPlayer       loopingSound;
};
