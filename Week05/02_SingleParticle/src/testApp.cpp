#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(255);
    
    myParticle.setParams(300, 300, ofRandom(-1,1), ofRandom(-1,1) );
}

//--------------------------------------------------------------
void testApp::update(){

    myParticle.resetForces();
    
    myParticle.addForce( ofVec2f(0, 0.1) );
    myParticle.addDampingForce();
    
    myParticle.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(0);
    myParticle.draw();
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
    myParticle.setParams(x, y, ofRandom(-1, 1) * 10, ofRandom(-1, 1) * 10 );
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
