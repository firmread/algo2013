#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    mSender.setup( "localhost", 12345 );        // we can also use 127.0.0.1, which is the same as 'localhost'
    mReceiver.setup( 12346 );
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
}

void testApp::checkOsc() {

	while(mReceiver.hasWaitingMessages()){
		ofxOscMessage m;
		mReceiver.getNextMessage(&m);
        
        string addr = m.getAddress();
        
        if( addr == "/bgColor" ){
            float bg = m.getArgAsInt32(0);
            ofBackground( bg );
        }else if( addr == "/ball/pos" ){
            receivedPos.set( m.getArgAsFloat(0), m.getArgAsFloat(1) );
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();
        ofTranslate( -ofGetWindowWidth(), 0);
        ofCircle( receivedPos, 20 );
    ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    pos.set(x, y );
    
    ofxOscMessage m;
    m.setAddress("/mouse/pos");
    m.addIntArg( x );
    m.addIntArg( y );
    mSender.sendMessage(m);
    
    ofxOscMessage mCol;
    mCol.setAddress("/bgColor");
    mCol.addFloatArg( (float)x / (float)ofGetWindowHeight() );
    mSender.sendMessage( mCol );
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    vel = lastPos - ofVec2f(x, y);
    
    lastPos.set( x, y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    ofxOscMessage mVel;
    mVel.setAddress("/vel");
    mVel.addFloatArg( 0 );
    mVel.addFloatArg( 0 );
    mSender.sendMessage( mVel );
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    vel *= -1;
    
    ofxOscMessage mVel;
    mVel.setAddress("/vel");
    mVel.addFloatArg( vel.x );
    mVel.addFloatArg( vel.y );
    mSender.sendMessage( mVel );
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
