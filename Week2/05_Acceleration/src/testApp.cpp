#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
    ofBackground( 100 );
    
    for( int i=0; i<1; i++){
        Mover myMover;
        moverList.push_back( myMover );
    }
    
}

//--------------------------------------------------------------
void testApp::update(){

    for( int i=0; i<moverList.size(); i++ ){
        moverList[i].mousePos.x = mouseX;
        moverList[i].mousePos.y = mouseY;
        
        moverList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for( int i=0; i<moverList.size(); i++ ){
        moverList[i].draw();
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
