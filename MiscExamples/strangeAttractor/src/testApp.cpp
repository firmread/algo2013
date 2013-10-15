#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){
    
    seedList.push_back( "VBWNBDELYHUL" );
    seedList.push_back( "CVQKGHQTPHTE" );
    seedList.push_back( "FIRCDERRPVLD" );
    seedList.push_back( "GIIETPIQRRUL" );
    currentSeed = 0;
    
    createFractal( seedList[currentSeed] );
    
    ofBackground(0);
}

void test( int n ){
    glutTimerFunc(1000, &test, 1);
    cout << "TEST" << endl;
}

void testApp::createFractal( string seed ){
    float   a[12];
    
    for( int i=0; i<seed.length(); i++ ){
        a[i] = (seed[i]-77) / 10.0;
    }
    
    ofVec3f p(0.1, 0.1);
    
    pointList.clear();
    for( int i=0; i<100000; i++ ){
        ofVec3f pos;
        pos.x = a[0] + a[1] * p.x + a[2] * p.x * p.x + a[3] * p.x * p.y + a[4] * p.y + a[5] * p.y * p.y;
        pos.y = a[6] + a[7] * p.x + a[8] * p.x * p.x + a[9] * p.x * p.y + a[10] * p.y + a[11] * p.y * p.y;
        
        pointList.push_back( pos );
        p = pos;
    }
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
        
    ofPushMatrix();
    
    ofTranslate( ofGetWindowSize() / 2.0 );
    ofRotateY( ofGetElapsedTimef() * 50.0 );
    ofTranslate( 100/-2, 0);
    
    for( auto p : pointList ){
        ofSetColor( p.x * 255, p.y * 100, (sin(ofGetElapsedTimef())*0.5+1)*255.0 );
        
        ofRect( p*100, 1,1 );
    }
    
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
    currentSeed++;
    if( currentSeed >= seedList.size() ){
        currentSeed = 0;
    }
    
    createFractal( seedList[currentSeed] );
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
