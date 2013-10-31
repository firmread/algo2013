#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground(0);
    
    gui = new ofxUICanvas;
    gui->addLabel("test");
    gui->addSpacer();
    gui->addButton("myButton", false, 44, 44);
    
    gui->setColorBack(ofColor(255,100));
    gui->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(255,100));
    gui->addSlider("mySlider", 0, 100, 50);
    
    ofAddListener(gui->newGUIEvent,this,&testApp::onGuiEvent);
    
    circleRadius = 50.0;
    circleColor.set(255, 0, 255);
    
    gui->loadSettings("guiSettings.xml");
}

void testApp::exit() {
    gui->saveSettings("guiSettings.xml");
    delete gui;
}

void testApp::onGuiEvent(ofxUIEventArgs &e) {
    
    
    string name = e.widget->getName();
	int kind = e.widget->getKind();
    
    if( name == "mySlider" ){
        ofxUISlider *mySlider = (ofxUISlider *)e.widget;
        circleRadius = mySlider->getScaledValue();
        
        cout << "Got a message! " << name << " - " << mySlider->getValue() << endl;
    }else if( name == "myButton"){
        
        ofxUIButton *myButton = (ofxUIButton *)e.widget;
        
        if( myButton->getValue() == 0){
            circleColor.set( ofRandom(255), ofRandom(255), ofRandom(255) );
        }
    }
    
    
    //    cout << "Got a message! " << name  << " - " << kind << endl;
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor( circleColor );
    ofCircle( ofGetWindowSize()/2, circleRadius );
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
