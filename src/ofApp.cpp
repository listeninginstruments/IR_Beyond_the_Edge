#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //video.load("videos/Slice 1.mp4");
    
    slice_width = 192;
    how_many_slices = 10;
    curr_n = 0;
    
    ofSetFrameRate(60);
    delayStart(60);
    
    for(int i=1; i<=how_many_slices; i++){
        lake[i-1].load("videos/Slice " + ofToString(i) + ".mp4");
        //lake[i-1].setSpeed(ofRandom(.2, .9));
        float temp_n = i;
        lake[i-1].setSpeed( 1.5 - ( temp_n/10) );
    }
    
    
     ttf.load("AbrilFatface-Regular.ttf", 128);
    
    
    
    ofFile file("1-population_data.json");
    if(file.exists()){
        file >> jsn;
        mainWM = jsn["Sheet1"];
        //cout << jsn["Sheet1"] << endl;
        
        for (auto & data: jsn["Sheet1"]){
            //cout << "////////////////////" << endl;
            //cout << data["year"] << " : " << data["wolves"] << " : " << data["moose"] << endl;
        }
    }
    
    
    //IRAIR-025-Selection1-NR_st.wav
    snd2.load("audio/IRAIR-025-Selection1-NR_st.wav");
    snd2.setVolume(0.75);
    snd2.play();
    snd2.setLoop(true);
    
    snd1.load("audio/IRAIR-042-Option2.wav");
    snd1.setVolume(0.75);
    snd1.play();
    snd1.setLoop(true);
    
}

//--------------------------------------------------------------
void ofApp::advanceData(){
    curr_n++;
   if(curr_n >= mainWM.size()){
       curr_n = 0;
   }
    
    //cout << mainWM.size() << endl;
    
    setAudioVals();
}

//--------------------------------------------------------------
void ofApp::setAudioVals(){
    snd1.setSpeed( ofMap(moose, 380, 2400, .2, 2.0) );
    snd2.setSpeed( ofMap(wolves, 2, 50, .2, 2.0) );
}


//--------------------------------------------------------------
void ofApp::drawData(){
    ofJson entry = mainWM[curr_n];
    
    year = ofToInt(entry["year"]);
    wolves = ofToInt(entry["wolves"]);
    moose = ofToInt(entry["moose"]);
    
    
    
    ofSetColor(255);
    
    ofPushMatrix();
    ofTranslate(0, 750);
    ofRotateZDeg(-90);
    ttf.drawString(ofToString(year), 0, slice_width);
    ttf.drawString(ofToString(wolves), 0, slice_width*2);
    ttf.drawString(ofToString(moose), 0, slice_width*3);
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::delayStart(float s){
    count = 0;
    delay_time = s;
}

//--------------------------------------------------------------
void ofApp::delayTimer(){
    count++;
    if(count > delay_time){
        delayFire();
        count = 0;
    }
}

//--------------------------------------------------------------
void ofApp::delayFire(){
    //cout << "////////////////////////////////////////////////" << endl;
    advanceData();
    //cout << "////////////////////////////////////////////////" << endl;
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
    
    
    drawData();
    delayTimer();
    
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
