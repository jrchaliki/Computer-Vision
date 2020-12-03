#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"
#include "ofxCv.h"
#include "ofxPanel.h"
#include "ofxGui.h"

using  namespace cv;

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
		
    
    ofVideoPlayer vid;
    ofImage vidFrame;
    Mat vidFrameMat;
    Mat vidFrameMatGray;
    Mat vidFrameMatEdge;
    
    
    ofxPanel gui;
    ofxIntSlider lowThreshold;
    ofxIntSlider lineVoteThreshold;

    
    
    // Region of Interest
    
    Mat mask;
    vector<cv::Point> keyPoints;
    vector<Vec4i> lines;
};
