#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    
    // F=M*A
    // A=F/M
    
    /*
     Newton's Laws of Motion
     
     First law: When viewed in an inertial reference frame, an object either is at rest or moves at a constant velocity, unless acted upon by an external force.[2][3]
     Second law: The acceleration of a body is directly proportional to, and in the same direction as, the net force acting on the body, and inversely proportional to its mass. Thus, F = ma, where F is the net force acting on the object, m is the mass of the object and a is the acceleration of the object.
     Third law: When one body exerts a force on a second body, the second body simultaneously exerts a force equal in magnitude and opposite in direction to that of the first body.
     
     */
    
    for( int i=0; i<100; i++){
        Particle p;
        p.mass = ofRandom(0.2, 3.0);
        mParticleList.push_back( p );
    }
    
    ofBackground( 0 );
    ofSetBackgroundAuto(false);
    
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){

    
    ofVec2f gravity( 0.0, 0.1);
    ofVec2f wind( 0.1, 0.0);
    
    for( int i=0; i<100; i++){
//        mParticleList[i].applyForce( gravity );
        mParticleList[i].applyForce( gravity * mParticleList[i].mass );
        
//        mParticleList[i].applyForce( wind );
//        mParticleList[i].applyForce( ofVec2f(ofRandom(-3,3), 0) );
        mParticleList[i].applyForce( ofVec2f( ofNoise(mParticleList[i].pos.y) - 0.5, 0) );
        
        mParticleList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofFill();
    
    ofSetColor(0,0,0, 255*0.1);
    ofRect( ofGetWindowRect() );
    
    ofNoFill();
    
    for( int i=0; i<100; i++){
        ofSetColor( 255, 255, 255, 255 * 0.2 );
        mParticleList[i].draw();
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
