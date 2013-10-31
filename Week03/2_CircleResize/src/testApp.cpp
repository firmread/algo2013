#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    amplitudeX = ofGetWindowWidth() / 2.0f;
    amplitudeY = ofGetHeight() / 2.0f;
    period = 5000.0;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPoint p;
    
    p.x = amplitudeX * sin( (ofGetElapsedTimeMillis() / period ) * TWO_PI );
    p.y = amplitudeY * cos( (ofGetElapsedTimeMillis() / period ) * TWO_PI );;
    
    ofPushMatrix();{
        ofTranslate( ofGetWindowSize() / 2.0 );
        ofCircle( p, 20);
    
    }ofPopMatrix();
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
    amplitudeX = w / 2.0f;
    amplitudeY = h / 2.0f;
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
