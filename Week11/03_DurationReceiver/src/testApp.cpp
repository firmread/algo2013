#include "testApp.h"



/**
 *  This app is set up to receive a 'bangs' track from Duration.  It simply makes a flash of light when it gets a signal.
 *
 */

//--------------------------------------------------------------
void testApp::setup(){
    mReceiver.setup(12345);
    
    bgColor = 0;
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
    
    
    bgColor *= 0.95;
}

void testApp::checkOsc() {
    
	while(mReceiver.hasWaitingMessages()){
        
		ofxOscMessage m;
		mReceiver.getNextMessage(&m);
        string addr = m.getAddress();
        
        cout << "got a message " << addr << endl;
        
        if( addr == "/bangs" ){
            bgColor = 255;
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground( floor( bgColor ) );
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
