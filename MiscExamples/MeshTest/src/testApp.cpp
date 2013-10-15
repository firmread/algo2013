#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    testImage.loadImage("test.png");
    
    int w = testImage.getWidth();
    int h = testImage.getHeight();
    
    
    // Typically we think of UVs in terms of 0-1, but of defines them as 0-imageWidth
        
    mesh.addVertex( ofVec3f(0,100,0) );     // make a new vertex
    mesh.addTexCoord( ofVec2f(0,h) );       // these are our UV coords
    
    mesh.addVertex( ofVec3f(0,0,0) );       // make a new vertex
    mesh.addTexCoord( ofVec2f(0,0) );       // these are our UV coords
    
    mesh.addVertex( ofVec3f(100,0,0) );     // make a new vertex
    mesh.addTexCoord( ofVec2f(w,0) );       // these are our UV coords
    
    mesh.addVertex( ofVec3f(100,100,0) );   // make a new vertex
    mesh.addTexCoord( ofVec2f(w,h) );       // these are our UV coords
    
    mesh.addIndex( 0 );
    mesh.addIndex( 1 );
    mesh.addIndex( 2 );
    
    // you can also just say mesh.addTringle(0,1,2);
    // if you look at the definition for the funciton, it's just calling addIndex 3 times
    
    mesh.addIndex( 2 );
    mesh.addIndex( 3 );
    mesh.addIndex( 0 );
    
    ofBackground(0);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor( 255 );
    
    ofPushMatrix();
    
    ofTranslate( ofGetWindowSize() / 2 );
    ofRotateY( ofGetElapsedTimef() * 50 );
    ofTranslate( ofVec2f(-50, -50) );
    
    // when we 'bind' it jsut means that when we draw a mesh next time, use this image
    testImage.getTextureReference().bind();
    mesh.draw();
    
    // the unbind is very important!
    testImage.getTextureReference().unbind();
    
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
