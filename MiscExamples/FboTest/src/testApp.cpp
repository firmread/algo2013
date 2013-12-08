#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    myFbo.allocate( ofGetWindowWidth(), ofGetWindowHeight() );
    
    myFbo.begin();
        ofClear(255, 255, 255, 0);
    myFbo.end();
    
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    myFbo.begin();
        ofSetColor(255, 0, 0);
    
    if( mouseX != 0 && mouseY != 0){
        ofCircle( mouseX, mouseY, 10);
    }
    myFbo.end();
    
    ofSetColor(255, 255, 255);
    
    myFbo.draw(0,0);
    ofCircle( mouseX, mouseY, 10);
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
