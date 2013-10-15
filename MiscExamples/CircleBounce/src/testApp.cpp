#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    
    circleCenter = ofGetWindowSize() / 2;
    circleRadius = 200;
    
    addParticle();
}

void testApp::addParticle() {
    Particle p;
    p.pos = ofVec2f( circleCenter - ofVec2f(-50,20) );
    p.vel = ofVec2f( ofRandom(-5,5), ofRandom(-5,5) );
    
    particleList.push_back( p );
}

//--------------------------------------------------------------
void testApp::update(){
    for( int i=0; i<particleList.size(); i++ ){
        particleList[i].update( circleCenter, circleRadius );
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // draw the outer circle
    ofNoFill();
    ofCircle( circleCenter, 200 );
    
    // draw the particles
    ofFill();
    for( int i=0; i<particleList.size(); i++ ){
        particleList[i].draw();
    }
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
    addParticle();
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
