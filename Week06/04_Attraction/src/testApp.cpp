#include "testApp.h"


/**
 * The formula we are following is a real gravitational equation
 *  F = (( G * m1 * m2 ) / r^2) * r(dir)
 * 
 * Where:
 *  G is a gravitational constant
 *  m1 and m2 are the masses of 2 objects
 *  r^2 is the distance between them squared
 *  and r(dir) is a directional vector between the two objects. It is normalized
 */


//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    earth.pos = ofGetWindowSize() / 2;
    earth.mass = 2;
    
    moon.mass = 3.0;
    
    moon.pos = ofVec2f( 100, 300 );
    moon.vel = ofVec2f( 0, 2);
    
    ofSetCircleResolution(100);
    
    ofBackground( 0 );
}

//--------------------------------------------------------------
void testApp::update(){
    
    ofVec2f grav = earth.attract( moon );
    
    moon.applyForce( grav );
    moon.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    earth.draw();
    moon.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
