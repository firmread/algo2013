#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSeedRandom(0);
    ofEnableDepthTest();
    ofSetVerticalSync(true);
    ofSetFrameRate(60.0);

    ofBackground(0);

    noiseCol = ofColor(255);
    noisePt = ofPoint(0,0);
    smoothing = 0.002;

    bDraw2D = true;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    if( bDraw2D ){
        draw2D();
    }else{
        draw3D();
    }
}

void testApp::draw2D(){
    ofSetColor( noiseCol );
    ofRect( 310, 0, 300, 300 );

    ofSetColor( 255, 0, 255 );
    ofCircle( noisePt, 2);

    for( int y=0; y<300; y++){
        for( int x=0; x<300; x++){

            float noiseVal = ofNoise(x * smoothing, y * smoothing);
            int col = floor(noiseVal * 255.0);

            ofSetColor( col );
            ofRect(x, y, 1, 1);
        }
    }
}

void testApp::draw3D(){
//    ofNoFill();
    int cubeSize = 10;  // make this even
    int bounds = floor( cubeSize / 2 );

    ofPushMatrix();

    ofTranslate( ofGetWindowSize() * 0.5 );

    ofRotate( ofGetElapsedTimef() * 100.0, 30, -15, 0);
    ofScale( 20, 20, 20 );

    for( int z=-bounds; z<bounds; z++){
        for( int y=-bounds; y<bounds; y++){
            for( int x=-bounds; x<bounds; x++){

                float smoothing = 0.05;
                float noiseVal = ofNoise(x * smoothing, y * smoothing, z * smoothing);
                int col = floor(noiseVal * 255.0);

                // little optimize hack to make sure we're only drawing the visible boxes on the outside
                if( x==bounds-1 || x == -bounds || y==bounds-1 || y == -bounds || z==bounds-1 || z == -bounds ){
                    ofSetColor( col );
                    ofDrawBox(x, y, z, 1.0);
                }
            }
        }
    }

    ofPopMatrix();

    ofSetColor(255);
    ofDrawBitmapString( ofToString( ofGetFrameRate() ), ofPoint(10,10) );
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    bDraw2D = !bDraw2D;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    noiseCol = ofColor( floor( ofNoise(x*smoothing, y*smoothing)*255.0) );
    noisePt.set(x, y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    noiseCol = ofColor( floor( ofNoise(x*smoothing, y*smoothing)*255.0) );
    noisePt.set(x, y);
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
