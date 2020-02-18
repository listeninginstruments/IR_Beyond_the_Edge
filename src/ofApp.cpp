#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //video.load("videos/Slice 1.mp4");
    
    slice_width = 192;
    how_many_slices = 10;
    
    for(int i=1; i<=how_many_slices; i++){
        lake[i-1].load("videos/Slice " + ofToString(i) + ".mp4");
        //lake[i-1].setSpeed(ofRandom(.2, .9));
        float temp_n = i;
        lake[i-1].setSpeed( 1.5 - ( temp_n/10) );
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //video.update();
    for(int i=1; i<=how_many_slices; i++){
        lake[i-1].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //video.draw(0,0);
    //video.play();
    
    for(int i=1; i<=how_many_slices; i++){
        
        lake[i-1].draw( (i-1) * slice_width , 0);
        lake[i-1].play();
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
