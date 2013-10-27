#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    loadXml();
}

void testApp::loadXml() {
    if( myXml.load("text.xml") ){
        cout << "Load successful" << endl;
        
        myXml.setTo("points");
        
        int numPoints = myXml.getNumChildren();
        
        myXml.setTo("vec");
        
        for( int i=0; i< numPoints; i++ ){
            cout << myXml.getValue("x") << endl;
            cout << myXml.getValue("y") << endl;
            cout << myXml.getValue("z") << endl;

            myXml.setToSibling();
        }
    }
}

void testApp::saveXml() {
    myXml.addChild("points");
    myXml.setTo("points");
    
    for( int i=0; i<5; i++ ){
        ofXml tmp;
        tmp.addChild("vec");
        tmp.setTo("vec");
        
        tmp.addValue("x", i+0.1 );
        tmp.addValue("y", i+0.2 );
        tmp.addValue("z", i+0.3 );
        
        myXml.addXml( tmp );
    }
    
    myXml.save("text.xml");
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

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
