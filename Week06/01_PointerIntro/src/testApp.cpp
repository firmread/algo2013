#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    int tmp = 5;
    int *myPtr = &tmp;  // Assign the address of tmp to our pointer.  They now have the same address in memory.
    int val = *myPtr;   // This is saying that we want to copy the value of myPtr (since we dereferenced it). Not the same address in memory!
    
    // & is known as the reference operator
    
    
    cout << "The address of tmp is " << &tmp << endl;
    cout << "The address of myPtr is " << myPtr << " / " << (*myPtr) << endl;       // display the address, then dereference it to get the value
    cout << "The address of val is " << &val << " / " << val << endl;
    
    cout << "------" << endl;
    
    // Now assign 8 to tmp. Since tmp and myPtr point to the same address in memory, both change!
    // When we assigned val however, we copied the value, not the address.  It's value remains unchanged.
    tmp = 8;
    
    cout << "The address of tmp is " << &tmp << endl;
    cout << "The address of myPtr is " << myPtr << " / " << (*myPtr) << endl;
    cout << "The address of val is " << &val << " / " << val << endl;
    
    cout << "------" << endl;

    // Reassign the address of myPtr so now it's pointing to the same thing as val
    // Both val and myPtr should now be 5! (tmp will still be 8)
    myPtr = &val;
    
    cout << "The address of tmp is " << &tmp << endl;
    cout << "The address of myPtr is " << myPtr << " / " << (*myPtr) << endl;
    cout << "The address of val is " << &val << " / " << val << endl;
    
    testFunction( tmp );
    
    
    // this is how you make memory leaks
//    int *leaky = new int;
//    leaky = &tmp;
}

void testApp::testFunction(const int &input){
    
//    input = 8;        // you can't do this!
    const int *internalPtr = &input;
    
    int myInt = input;
    myInt = 10;
    
    cout << "\nFrom testFunction " << *internalPtr << endl;
    cout << "We can change this var though " << myInt << endl;
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
