#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    gui.setup();
    gui.add(threshold.setup("Line Threshold", 50, 0, 100));


//    image.load("img1.jpg");
    image.load("img2.jpeg");
//    image.load("img3.jpeg");

    image.resize(480, 640);
    im = toCv(image);
    
    adjusted = threshold;
    ofResetElapsedTimeCounter();
    point = 0;
    
    cvtColor(im, im, CV_BGR2GRAY);
    GaussianBlur(im, im, 3);
    Canny(im, mat, threshold, threshold*3);
    
    for(int i = 0; i < mat.cols; i++){
        for(int j = 0; j < mat.rows; j++){
            if((int)mat.at<uchar>(j, i) == 255){
                cv::Point p(i,j);
                points.push_back(p);
                break;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    Canny(im, mat, threshold, threshold*3);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    ofSetColor(255, 255, 255);
    image.draw(0, 0);

    ofSetColor(255);
    if(ofGetElapsedTimeMillis() > 100){
        if(point < points.size() && !notFinished){
            point += 1;
        }else{
            point -= 1;
        }
        if(point >= points.size()){
            point = points.size()-1;
            notFinished = !notFinished;
        }
        if(point <= 0){
            point = 0;
            notFinished = !notFinished;
        }
    }
    
    ofDrawCircle(points[point].x, points[point].y, 15);
    
//    Update the path when threshold slider is adjusted
    if(threshold != adjusted){
        adjusted = threshold;
        while(!points.empty()){
            points.pop_back();
        }
        for(int i = 0; i < mat.cols; i++){
            for(int j = 0; j < mat.rows; j++){
                if((int)mat.at<uchar>(j, i) ==255){
                    cv::Point p(i,j);
                    points.push_back(p);
                    break;
                }
            }
        }
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

