#include "ofApp.h"

using namespace ofxCv;

//--------------------------------------------------------------
void ofApp::setup(){
    
    lena.load("lena.jpg");
    circuit.load("circuit.tif");
    
    lena.setImageType(OF_IMAGE_GRAYSCALE);
    circuit.setImageType(OF_IMAGE_GRAYSCALE);
    
    matLena = toCv(lena);
    matCircuit = toCv(circuit);
    
    gui.setup();
    
    gui.add(kernelSize.setup("Kernel Size",3,3,27));
    gui.add(variance.setup("Variance",2,1,30));



}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Gaussain Filter
    
    if(kernelSize % 2 != 0) {    //Odd matrix condition
        
    GaussianBlur(matLena, gaussianResult, cv::Size(kernelSize,kernelSize), variance);
    GaussianBlur(matCircuit, gaussianResult2, cv::Size(kernelSize,kernelSize), variance);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    ofSetColor(255);
    
    drawMat(gaussianResult, 0, 0);
    drawMat(gaussianResult2, lena.getWidth(), 0);
    gui.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
