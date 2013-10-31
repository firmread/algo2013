#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
	ofBackground(255, 255, 255);
    
    // initialize all of our variables
	bIsRecording = false;
	playbackStartTime = 0;
	startTime = 0;
    
    TimePoint *myPointer = new TimePoint();
    delete myPointer;
}


//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
	// -------------------------- draw the line
	ofSetColor(0,0,0);
	ofNoFill();
	ofBeginShape();
	for (int i = 0; i < pointList.size(); i++){
		ofVertex(pointList[i].x, pointList[i].y);
	}

    /* // alternate way using iterators!
     for( vector<TimePoint>::iterator it=pointList.begin(); it!=pointList.end(); it++ ){
        ofVertex( it->x, it->y );
     }
     //*/
    
	ofEndShape();
	
	// -------------------------- draw the point at the current time
	ofPoint pos = getPositionForTime(ofGetElapsedTimef() - playbackStartTime);
	ofFill();
	ofSetColor(255,0,0);
	ofCircle(pos.x, pos.y, 10);
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
    
    // startTime is reset every time we press the mouse, so we're recornding the time since we've pressed the mouse
    
	TimePoint temp;
	temp.x = x;
	temp.y = y;
	temp.t = ofGetElapsedTimef() - startTime;
	pointList.push_back(temp);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    // reset all of our points
	
	bIsRecording = true;
	pointList.clear();
	startTime = ofGetElapsedTimef();
	TimePoint temp;
	temp.x = x;
	temp.y = y;
	temp.t = 0;
	pointList.push_back(temp);
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
	bIsRecording = false;
	playbackStartTime = ofGetElapsedTimef();
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
ofPoint testApp::getPositionForTime(float time){
	
	// are we recording or do we have less than 2 points? If so return a blank placeholder point.
	if (bIsRecording == true){
		return ofPoint(0,0,0);
	} else if (pointList.size() < 2){
		return ofPoint(0,0,0);
	}
	
	// Now we figure out where we are time-wise in the drawing
	
    // The variable "time" we are passing in is relative to how long the program has been running, not relative to
    // our timeframe.  We essentially need a modulus operator (%).  Instead we'll mimic is.
    
    // This function acts like a big modulus. The last element in our list (pointList.size()-1) is how long the whole drawing took.
    // We'll keep subtracting it from time until it's smaller than "time".  Now we can work with it on the right time scale. This also
    // allows it to loop!
    
	while (time > pointList[pointList.size()-1].t){
		time -= pointList[pointList.size()-1].t;
	}
	
	
    // Create our point we'll return
	ofPoint pos;
	
	for (int i = 0; i < pointList.size()-1; i++){
        
        // find out which two points we're between
		if (time >= pointList[i].t && time < pointList[i+1].t){
			
			// Since we want a smooth playback, we'll interpolate between these two points
			float part = time - pointList[i].t;
			float whole = pointList[i+1].t - pointList[i].t;
			float pct = part / whole;
			
			// Figure out where we are between a and b
            // We've done this before with our linear interpolation where we take a percentage of both, where both
            // percentages add up to 100.  We do this by taking "pct" from one of them and "1-pct" from the other.
			pos.x = (1-pct) * pointList[i].x + (pct) * pointList[i+1].x;
			pos.y = (1-pct) * pointList[i].y + (pct) * pointList[i+1].y;
		}
	}
	
    // return our point which represents a position interpolated between two other points
	return pos;
}


