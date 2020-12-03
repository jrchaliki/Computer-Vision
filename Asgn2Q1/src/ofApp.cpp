#include "ofApp.h"

using namespace ofxCv;


//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    gui.add(lowThreshold.setup("Low Threshold", 50, 0, 100));
    gui.add(lineVoteThreshold.setup("Line Vote Threshold", 150, 0, 200));
    
    vid.load("solidWhiteRight.mp4");
    vid.play();
    
    //Mask
    mask = Mat::zeros(cv::Size(vid.getWidth(), vid.getHeight()), CV_8U);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    vid.update();
    vid.getCurrentFrame();
    
    if(vid.isFrameNew()){
        ofPixels pix = vid.getPixels();
        vidFrame.setFromPixels(pix);
        vidFrameMat = toCv(vidFrame);
        cvtColor(vidFrameMat, vidFrameMatGray, CV_BGR2GRAY);
        GaussianBlur(vidFrameMatGray, vidFrameMatGray, 3);
        Canny(vidFrameMatGray, vidFrameMatEdge, lowThreshold, lowThreshold*3);
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    
    ofSetColor(255, 255, 255);
    drawMat(vidFrameMat, 0, 0);
    
   
    
    //Point
    for (int i = 0; i< keyPoints.size(); i++)
    {
        ofSetColor(255, 0, 0);
        ofDrawCircle(keyPoints[i].x, keyPoints[i].y, 5);
    }
    
    // Convex Polygon
    if(keyPoints.size()>=3)
    {
        fillConvexPoly(mask, keyPoints.data(), keyPoints.size(), Scalar(255,255,255));
        bitwise_and(vidFrameMatEdge, mask, vidFrameMatEdge);
    }
        
    // Hough Transform Lines
    HoughLinesP(vidFrameMatEdge, lines, 2, CV_PI/180, lineVoteThreshold, 15, 20);
    
    ofSetColor(255,0,0);
    
    for(int i = 0; i < lines.size(); i++){
        float x1 = lines[i][0];
        float y1 = lines[i][1];
        float x2 = lines[i][2];
        float y2 = lines[i][3];
        ofPolyline l;
        l.addVertex(x1, y1);
        l.addVertex(x2, y2);
        
        l.draw();
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
    
    if(x>=0&&x< vid.getWidth()&&y>=0&&y< vid.getHeight()){
        cv::Point p(x,y);
        keyPoints.push_back(p);
    }
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
