#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    gui.add(threshold.setup("Low Threshold Value", 50, 0, 100));
    vid.initGrabber(320, 240);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    vid.update();
    mat = toCv(img);
    if(vid.isFrameNew()){
        img.setFromPixels(vid.getPixels());
        }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    ofSetColor(255, 255, 255);
    drawMat(mat, 0, 0);
    
    mat = toCv(vid);
    
    cvtColor(mat, mat, CV_BGR2GRAY);
    GaussianBlur(mat, mat, 3);
    Canny(mat, mat, threshold, threshold*2);
    
    vector<Vec3f> circle;
    HoughCircles(mat, circle, CV_HOUGH_GRADIENT, 2, 50, threshold*2, 100, 30, 50);
    
    for(int i = 0; i < circle.size(); i++){
        ofSetColor(255, 255, 255);
        ofDrawCircle(circle[i][0], circle[i][1], circle[i][2]);
        
        ofSetColor(0, 0, 0);
        ofDrawCircle(circle[i][0], circle[i][1], circle[i][2]/2);
    }
    
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
