#pragma once

#include "ofMain.h"

#include "ofxGui.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"

using namespace cv;
using namespace ofxCv;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    ofImage image;
    Mat im;
    
    ofxPanel gui;
    ofxIntSlider threshold;

    Mat mat;
    int adjustedThreshold;
    
    
//    Detecting edge
    
    vector<cv::Point> points;
    int point;
    Boolean notFinished;
    
    int adjusted;
		
};
