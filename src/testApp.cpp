#include "testApp.h"

string name;
string printLine;

//--------------------------------------------------------------
void testApp::setup(){
    ofSetWindowTitle("helloWorld");
	name = "/ofYarpReader";
    NameConfig nc;
    Address addr("10.0.1.14", 10000);
    nc.setAddress(addr);
    nc.setMode("yarp");
    if (nc.toFile()) {
        printf("written nameconfig to file\n");
    }
    else {
        printf("error writing to nameconfig file\n");
    }
    nc.fromFile();
    
	port.open(name.c_str());
	printLine = "";

}

//--------------------------------------------------------------
void testApp::update(){
	if (port.getPendingReads()) {
		//printf("port read!\n");
		yarp::os::Bottle *input = port.read();
        double x = input->get(1).asDouble();
        double y = input->get(2).asDouble();
        double z = input->get(3).asDouble();
		printLine = ofToString(x) + " " + ofToString(y) + " " + ofToString(z);
        //printf("%s\n", input->toString().c_str());
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	string str;
	str = "Registered address: "+name;
	ofSetColor(255, 0, 255);
	ofDrawBitmapString(str, 25, 25, 0);
	ofSetColor(0, 0, 255);
	ofDrawBitmapString(printLine, 35, 75, 0);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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