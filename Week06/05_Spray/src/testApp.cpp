#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    sampler.loadImage("richard_feynman.jpg");
    
    bMouseIsDown = false;
    ofBackground(0);
}

void testApp::addParticle(float x, float y) {
    
    // offset the start position a little bit
    float xPos = x + ofRandom(10) - 5;
    float yPos = y + ofRandom(10) - 5;
    
    // now offset the initial velocity a good amount too
    ofVec2f velOffset( ofRandom(-1,1), ofRandom(-1,1) );
    velOffset *= ofRandom(1,5);
    ofVec2f newVel = mouseVel * 0.3 + velOffset;
    
    // spawn a new particle with position and velocity based on the mouse with a bit of randomness sprinkled in
    particleList.push_back( Particle( ofVec2f( xPos, yPos ), newVel ) );
}

//--------------------------------------------------------------
void testApp::update(){
    
    if( bMouseIsDown ){
        for( int i=0; i<25; i++){
            addParticle( lastMousePos.x, lastMousePos.y );
        }
    }
    
    for( vector<Particle>::iterator it=particleList.begin(); it!=particleList.end();){
        
        if( it->bIsDead ){
            it = particleList.erase( it );
        }else{
            it->update( sampler, lastMousePos );
            it++;
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for( vector<Particle>::iterator it=particleList.begin(); it!=particleList.end(); it++ ){
        it->draw();
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
    mouseVel = ofVec2f(x,y) - lastMousePos;
    
    lastMousePos.set(x, y);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    mouseMoved(x, y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    bMouseIsDown = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    bMouseIsDown = false;
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
