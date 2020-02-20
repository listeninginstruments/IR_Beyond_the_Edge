#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //video.load("videos/Slice 1.mp4");
    
    slice_width = 192;
    how_many_slices = 10;
    curr_n = 0;
    
    vidleft = (ofGetWindowWidth()/2) - (vidwidth/2);
    vidtop = (ofGetWindowHeight()/2) - (vidheight/2);
    
    ofSetFrameRate(60);
    delayStart(60);
    
    for(int i=1; i<=how_many_slices; i++){
        lake[i-1].load("videos/Slice " + ofToString(i) + ".mp4");
        //lake[i-1].setSpeed(ofRandom(.2, .9));
        float temp_n = i;
        lake[i-1].setSpeed( 1.5 - ( temp_n/10) );
    }
    
    
     ttf.load("AbrilFatface-Regular.ttf", 128);
    
    
    //label.load("AbrilFatface-Regular.ttf", 200);
    label.load("AbrilFatface-Regular.ttf", 45);
    
    
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
    
    if(entry["kill rate"] != "N/A"){
        //cout << entry["kill rate"] << endl;
        kill = ofToFloat(entry["kill rate"]);
    } else {
        kill = 0;
    }
    
    if(entry["predation rate"] != "N/A"){
        //cout << entry["predation rate"] << endl;
        predation = ofToFloat(entry["predation rate"]);
    } else {
        predation = 0;
    }
    
    ofSetColor(255);
    
    ofPushMatrix();
    ofTranslate(vidleft, vidleft + 750);
    ofRotateZDeg(-90);
    ttf.drawString(ofToString(year), 0, slice_width);
    ttf.drawString(ofToString(wolves), 0, slice_width*1.83);
    ttf.drawString(ofToString(moose), 0, slice_width*2.83);
    ofPopMatrix();
    
    /*
    label.drawString("W", (slice_width * 1.5) - (label.stringWidth("W")/2), 950);
    label.drawString("W", (slice_width*2.5) - (label.stringWidth("W")/2), 950);
     */
    /*
    ofDrawRectangle(slice_width * .9, 775, label.stringWidth("W"), 2);
    ofDrawRectangle(slice_width * 2, 775, label.stringWidth("W"), 2);
    */
    
    //label.drawString("W", vidleft + slice_width * .9, vidtop + 1000);
    label.drawString("W", vidleft + slice_width * 1.75 - 6, vidtop + 900);
    
    ofPushMatrix();
    
    ofRotateZDeg(180);
    ofTranslate(vidleft + (-slice_width * 2) + 6, -(900 + vidtop));
    label.drawString("W", -label.stringWidth("W"), label.stringHeight("W")-2);
    
    
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
        lake[i-1].draw( vidleft + ( (i-1) * slice_width) , vidtop);
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
