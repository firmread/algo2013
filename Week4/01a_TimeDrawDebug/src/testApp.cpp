#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);
	ofBackground(0);
	
	bIsRecording = false;
	playbackStartTime = 0;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(255);
	ofNoFill();
	
	ofDrawBitmapString("Elapsed time: " + ofToString(ofGetElapsedTimef()), 20, 20);
	
	if (points.size() >= 2) {
		float time = ofGetElapsedTimef() - playbackStartTime;
		while (time > points[points.size()-1].t) {
			time -= points[points.size()-1].t;
		}
		ofDrawBitmapString("Playback time: " + ofToString(time), 20, 30);
	}

	// draw line
	ofBeginShape();
	for (vector <TimePoint>::iterator it = points.begin(); it != points.end(); it++) {
		ofVertex(it->x, it->y);
		ofDrawBitmapString(ofToString(it->t), it->x+5, it->y-15);
		
	}
	ofEndShape();
	
	// draw playback through line
	ofPoint pos = getPositionForTime( ofGetElapsedTimef() - playbackStartTime );
	ofFill();
	ofSetColor(255, 0, 0);
	ofCircle(pos.x, pos.y, 10);

}

ofPoint testApp::getPositionForTime(float time) {
	
	// return empty point if we're recording or if we have less than 2 points
	if (bIsRecording || points.size() < 2) {
		return ofPoint(0, 0, 0);
	}

	// normalize time variable to duration of path
	while (time > points[points.size()-1].t) {
		time -= points[points.size()-1].t;
	}
	
	ofPoint pos;
	
	for (int i = 0; i < points.size() - 1; i++) {
		if (time >= points[i].t && time < points[i+1].t) {
			float part = time - points[i].t;
			float whole = points[i+1].t - points[i].t;
			float pct = part/whole;
			
			pos.x = (1-pct) * points[i].x + pct * points[i+1].x;
			pos.y = (1-pct) * points[i].y + pct * points[i+1].y;
			
			return pos;
		}
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
	
	bIsRecording = true;

	TimePoint t;
	t.x = x;
	t.y = y;
	t.t = ofGetElapsedTimef() - startTime;
	points.push_back(t);
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

	points.clear();
	
	TimePoint t;
	t.x = x;
	t.y = y;
	t.t = 0;
	points.push_back(t);
	
	startTime = ofGetElapsedTimef();
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	bIsRecording = false;
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
