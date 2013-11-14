#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
	ofBackground(255);
    
    box2d.init();
	box2d.setGravity(0, 10);
	box2d.setFPS(30.0);
	box2d.registerGrabbing();
    
    anchor.setup(box2d.getWorld(), ofGetWidth()/2, 20, 4);
    
    for (int i=0; i<3; i++) {
		ofxBox2dCircle circle;
		circle.setPhysics(3.0, 0.53, 0.1);
		circle.setup(box2d.getWorld(), ofGetWidth()/2, 100+(i*20), 8);
		circles.push_back(circle);
	}
    
    for (int i=0; i<circles.size(); i++) {
		
		ofxBox2dJoint joint;
		
		// if this is the first point connect to the top anchor.
		if(i == 0) {
			joint.setup(box2d.getWorld(), anchor.body, circles[i].body);
		}
		else {
			joint.setup(box2d.getWorld(), circles[i-1].body, circles[i].body);
		}
		
		joint.setLength(25);
		joints.push_back(joint);
	}

}

//--------------------------------------------------------------
void testApp::update(){
    box2d.update();
    
    if( freeCircles.size() && freeCircles.back().getPosition().y > ofGetWindowHeight() ){
        freeCircles.back().destroy();
        freeCircles.pop_back();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetHexColor(0xf2ab01);
	anchor.draw();
	
	for(int i=0; i<circles.size(); i++) {
		ofFill();
		ofSetHexColor(0x01b1f2);
		circles[i].draw();
	}
    
    for(int i=0; i<freeCircles.size(); i++) {
		ofFill();
		ofSetHexColor(0x01b1f2);
		freeCircles[i].draw();
	}
	
	for(int i=0; i<joints.size(); i++) {
		ofSetHexColor(0x444342);
		joints[i].draw();
	}
	
	string info = "";
	info += "Press [n] to add a new joint\n";
	info += "click and pull the chain around\n";
	info += "FPS: "+ofToString(ofGetFrameRate(), 1)+"\n";
	ofSetHexColor(0x444342);
	ofDrawBitmapString(info, 30, 30);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'n') {
		// add a new circle
		ofxBox2dCircle circle;
		circle.setPhysics(3.0, 0.53, 0.1);
		circle.setup(box2d.getWorld(), circles.back().getPosition().x + ofRandom(-30, 30), circles.back().getPosition().y-30, 8);
		circles.push_back(circle);
        
		// get this cirlce and the prev cirlce
		int a = (int)circles.size()-2;
		int b = (int)circles.size()-1;
        
		// now connect the new circle with a joint
		ofxBox2dJoint joint;
		joint.setup(box2d.getWorld(), circles[a].body, circles[b].body);
		joint.setLength(25);
		joints.push_back(joint);
	}else if( key == 'd' ){
        joints.back().destroy();
        joints.pop_back();
        
        freeCircles.push_back( circles.back() );
        circles.pop_back();
    }
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
