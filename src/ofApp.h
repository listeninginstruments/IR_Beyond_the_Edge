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
    float vidwidth = 1920;
    float vidheight = 1080;
    int vidleft;
    int vidtop;
    
    
    ofJson jsn;
    ofJson mainWM;
    
    ofTrueTypeFont ttf;
    ofTrueTypeFont label;
    ofTrueTypeFont smalldata;
    ofTrueTypeFont title;
    std::string title_text;
    
    ofImage title_graphics;
    
    int year;
    int wolves;
    int moose;
    float kill;
    float predation;
    bool icebridge;
    
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
    
    ofSoundPlayer snd3;
    ofSoundPlayer snd4;

};
