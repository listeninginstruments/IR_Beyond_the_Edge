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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofVideoPlayer video;
		
    ofVideoPlayer lake[10];
    int how_many_slices;
    float slice_width;
    
    
    ofJson jsn;
    ofJson mainWM;
    ofTrueTypeFont ttf;
    ofTrueTypeFont label;
    
    int year;
    int wolves;
    int moose;
    
    void advanceData();
    void drawData();
    int curr_n;
    
    std::string text;
    
    ofFile file;
    
    
    // --- | Timer
    void delayStart(float s);
      void delayTimer();
      void delayFire();
      float delay_time;
      float count;
    
    
    void setAudioVals();
    ofSoundPlayer snd1;
    ofSoundPlayer snd2;
    

};
