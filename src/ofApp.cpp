#include "ofApp.h"

void ofApp::setup(){
	debugger::setDebug(debug);
	debugger::log("App started");

	tile::setSize(30);
	g.setGH(30);
	g.setGW(60);
	g.setLineColour(ofColor::fromHex(0xCCCCCC));

	g.createGrid();

}

void ofApp::update(){

}

void ofApp::draw(){
	g.drawGrid();
}

void ofApp::handleKeypresses(){}

void ofApp::keyPressed(int key){
	//Mitigate key repeat
	if(!keys[key]){

		//Set key to true
		keys[key] = true;

		//Log the keypress
		std::string msg = "Key "; msg += key; msg += "("; msg += std::to_string(key); msg += ")"; msg += " pressed";
		debugger::log(msg);
	}
}

void ofApp::keyReleased(int key){
	//Mitigate key repeat
	if(keys[key]){

		//Set key to false
		keys[key] = false;

		//Log the keypress
		std::string msg = "Key "; msg += key; msg += "("; msg += std::to_string(key); msg += ")"; msg += " released";
		debugger::log(msg);
	}
}

//Not used
void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}
