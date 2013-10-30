#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    pos = ofGetWindowSize() / 2;
    vel.set( 20, 10, 0 );
    
    mFbo.allocate( ofGetWindowWidth(), ofGetWindowHeight() );
    
    ofBackground(0);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
    pos += vel;
    
    if( pos.x < 0 || pos.x > ofGetWindowWidth() ){
        vel.x *= -1;
    }
    
    if( pos.y < 0 || pos.y > ofGetWindowHeight() ){
        vel.y *= -1;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    mFbo.begin();
    
    // to prevent uncleared video memory!
    ofSetColor(255, 255, 255, 0);
    ofClear(255, 255, 255, 0);
    
    ofSetColor(255, 255, 255, 255);
    ofPushMatrix();{
        
        ofTranslate( pos );
         ofSetRectMode( OF_RECTMODE_CENTER );
        ofRotate( ofGetElapsedTimef() * 90 );
        ofRect(-50, -50, 50, 50);
        
         ofSetRectMode( OF_RECTMODE_CORNER );
    }ofPopMatrix();
    mFbo.end();
    
    mFbo.draw(0,0);
    mFbo.draw(0,200);
    mFbo.draw(200,200);
    mFbo.draw(200,0);
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
