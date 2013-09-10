#pragma once

#include "ofMain.h"

class Eyeball {
public:
    ofPoint pos, mousePos;
    float angle;
    
    void draw() {
        ofPushMatrix();{
            ofTranslate( pos );
            
            float dx = mousePos.x - pos.x;
            float dy = mousePos.y - pos.y;
            
            angle = atan2( dy , dx );
            
            ofRotate( ofRadToDeg(angle) );

            ofSetColor( 0 );
            
            // outline
            ofNoFill();
            ofCircle(0, 0, 50);
            
            // pupil
            ofFill();
            ofCircle(25, 0, 25);
        }ofPopMatrix();
    }
    
};


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
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void drawEye();

    Eyeball leftEye, rightEye;
};

