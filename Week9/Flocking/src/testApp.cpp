#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    int i=0;
    while( ++i < 100 ){
        addParticle();
    }
    
    ofBackground(0);
}

void testApp::addParticle(){
    ofVec2f initVel( ofRandom(-5,5), ofRandom(-5,5) );
    
    Boid b( ofGetWindowSize() * 0.5, initVel );
    boidList.push_back( b );
}

//--------------------------------------------------------------
void testApp::update(){
    for( int i=0; i<boidList.size(); i++ ){
        boidList[i].pullToCenter( ofGetWindowSize() * 0.5 );
        boidList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for( int i=0; i<boidList.size(); i++ ){
        boidList[i].draw();
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
