#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    
    ofSetCircleResolution(100);
    
    leftEye.pos = ofPoint( ofGetWindowWidth()/2 - 75, ofGetWindowHeight() * 0.5 );
    rightEye.pos = ofPoint( ofGetWindowWidth()/2 + 75, ofGetWindowHeight() * 0.5 );
}

//--------------------------------------------------------------
void testApp::update(){
    ofPoint mousePos( mouseX, mouseY );
    
    leftEye.mousePos = mousePos;
    rightEye.mousePos = mousePos;
}

//--------------------------------------------------------------
void testApp::draw(){

    leftEye.draw();
    rightEye.draw();    
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
