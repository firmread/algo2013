#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(255);
    
//    for (int i = 0; i < 1000; i++){
//        addParticle();
//    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    // on every frame
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	for (int i=0; i < particleList.size(); i++){
		particleList[i].resetForces();
//		particleList[i].addForce( ofVec2f(0,0.04));  // gravity
		particleList[i].addDampingForce();
		particleList[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofFill();
    ofSetColor(0);
    for (int i=0; i < particleList.size(); i++){
        particleList[i].draw();
    }
    
//    ofNoFill();
    
	ofBeginShape();
	for (int i = 0; i < particleList.size(); i++){
		ofVertex(particleList[i].pos.x, particleList[i].pos.y);
	}
	ofEndShape();
}

void testApp::addParticle() {
    Particle myParticle;
    
    float vx = ofRandom(-4,4);
    float vy = ofRandom(-4,4);
    myParticle.setParams(300,300,vx, vy);
    
    // more interesting with diversity :)
    // uncomment this:
    //		myParticle.damping = ofRandom(0.01, 0.05);
    particleList.push_back(myParticle);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    
    ofPoint difference = ofPoint(x,y) - lastMousePos;
    
    Particle myParticle;
    
//    float vx = ofRandom(-4,4);
//    float vy = ofRandom(-4,4);
    myParticle.setParams(x, y, difference.x, difference.y);
    
    // more interesting with diversity :)
    // uncomment this:
    //		myParticle.damping = ofRandom(0.01, 0.05);
    particleList.push_back(myParticle);
    
    
    lastMousePos.set(x, y);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
//    for (int i = 0; i < particleList.size(); i++){
//        //		float vx = ofRandom(-4,4);
//        //		float vy = ofRandom(-4,4);
//        
//        float circVal = ofRandom(TWO_PI);
//        
//        float vx = cos( circVal ) * ofRandom(0,4);
//        float vy = sin( circVal ) * ofRandom(0,4);
//        
//		particleList[i].setParams(mouseX,mouseY,vx, vy);
//        
//	}
    
    particleList.clear();
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
