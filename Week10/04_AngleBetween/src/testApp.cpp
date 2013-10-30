#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    lookVec.set(0,-1);
    angle = 90;
    
    lSide = lookVec.rotated(angle * -0.5);
    rSide = lookVec.rotated(angle * 0.5);
    
    ofBackground(0);
    
    ofDegToRad(<#float degrees#>)
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofVec2f center = ofGetWindowSize()/2;
    
    ofVec2f mouseVec( ofVec2f(mouseX, mouseY) - center );
    
    float angle = lookVec.angle( mouseVec );
//    float angle = acos( lookVec.dot(mouseVec) / (lookVec.length() * mouseVec.length() ) );
//    angle = ofRadToDeg( angle );
    
    if( angle > -45 && angle < 45 ){
        ofSetColor(255);
    }else{
        ofSetColor( 255, 0, 0 );
    }
    
    ofLine( center, center + lSide.normalized()*1000 );
    ofLine( center, center + rSide.normalized()*1000 );
    
    
    ofDrawBitmapStringHighlight( "Angle between: "+ofToString(angle), ofVec2f(20,20) );
    
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
