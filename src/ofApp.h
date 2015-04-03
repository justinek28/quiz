#pragma once

#include "ofMain.h"

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofPolyline plant ;
        vector <ofPolyline> polylines;
        ofPolyline curvedSegmentPolyline;
        ofColor color1 = ofColor (0, 100, 255, 200) ;
        int position ;
        int position2 ;
        float speed ;
        float speed2 ;
        float leafLength = 0 ;
		
};
