#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSeedRandom();

    ofSetVerticalSync(true);
    ofSetFrameRate(60);

    pos = ofGetWindowSize() / 2;
    dest = ofVec2f( ofRandomWidth(), ofRandomHeight() );

    car.setParams( pos, ofVec2f(10, -5) );

    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){

    car.seek( dest );
    car.update();

    if( car.pos.distance(dest) < 5){
        dest = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    car.draw();

    ofSetColor(255,0,0);
    ofCircle( dest, 4 );
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
