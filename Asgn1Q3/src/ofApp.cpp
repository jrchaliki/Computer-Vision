#include "ofApp.h"

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"

using namespace ofxCv;

//--------------------------------------------------------------
void ofApp::setup(){
    
    img.load("running.jpg");
    imgBg.load("bg.jpg");
    
    img.setImageType(OF_IMAGE_COLOR);
    imgBg.setImageType(OF_IMAGE_COLOR);
    
    mat = toCv(img);
    matBg = toCv(imgBg);
    
    for (int i = 0; i < mat.cols; i++) {
        for (int j=0; j< mat.rows; j++) {
            if (((int(mat.data[(i + j * mat.cols) * 3]) == 57) && (int(mat.data[(i + j * mat.cols) * 3 + 2])) == 46) || (int(mat.data[(i + j * mat.cols) * 3 + 1])) > 228) {
                mat.data[(i + j * mat.cols) * 3] = matBg.data[(i + j * mat.cols) * 3];
                mat.data[(i + j * mat.cols) * 3 + 1] = matBg.data[(i + j * mat.cols) * 3 + 1];
                mat.data[(i + j * mat.cols) * 3 + 2] = matBg.data[(i + j * mat.cols) * 3 + 2];
            }
        }
        
    }
}



//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    ofSetColor(255);
    
    img.draw(0,0);
    imgBg.draw(img.getWidth(), 0);
    drawMat(mat,0,img.getHeight());

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
