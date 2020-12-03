#include "ofApp.h"

using namespace ofxCv;
//--------------------------------------------------------------




void ofApp::setup(){
    
    vid.initGrabber(width, height);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Setting up histogram
    int size = 256;
    float range[] = {0, 256};
    const float* histRange = {range};
    bool uniform = true, accumulate = false;
    
    //Check for updates and new frames
    vid.update();
    
    if(vid.isFrameNew()){
        
        img.setFromPixels(vid.getPixels());
        matImg = toCv(img);
        cvtColor(matImg, matImg, CV_BGR2GRAY);
    }

    // Check for mouse click and invert
    if(clicked){
        int intensity = matImg.data[mousex*mousey];
        for(int i = 0; i < matImg.rows*matImg.cols; i++){
            if(matImg.data[i] == intensity){
                matImg.data[i] = 255 - matImg.data[i];
            }
        }
    }
    
    //Calculate Histogram
    calcHist(&matImg, 1, 0, Mat(), hist, 1, &size, &histRange);
    
    normalize(hist, hist, 0, 300, NORM_MINMAX);
    for(int i = 0; i< size; i++){
        histCols[i].clear();
        histCols[i].addVertex(i,768);
        histCols[i].addVertex(i, 768-cvRound(hist.at<float>(i)));
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255, 255, 255);
    ofSetColor(255);
    drawMat(matImg, 0, 0);
    
    ofSetColor(0, 0, 0);
    for(int i = 0; i<256; i++){
        histCols[i].draw();
    }
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
    
    clicked = true;
    mousex = x;
    mousey = y;
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
