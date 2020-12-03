#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"
#include "ofxCv.h"

#include "ofxPanel.h"


using namespace cv;



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
    
    ofImage img; //Man
    ofImage imgBg; // Background
    
    Mat mat, matBg, rgb[3];
        
};
