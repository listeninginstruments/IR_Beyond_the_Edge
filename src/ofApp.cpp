#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //video.load("videos/Slice 1.mp4");
    
    //ofSetDataPathRoot("../Resources/data/");
    
    
    ofBackground(0, 0, 0);
    
    slice_width = 192;
    how_many_slices = 10;
    icebridge = 0;
    curr_n = 0;
    
    vidleft = (ofGetWindowWidth()/2) - (vidwidth/2);
    vidtop = (ofGetWindowHeight()/2) - (vidheight/2);
    
    ofSetFrameRate(60);
    delayStart(60 * 10);
    
    for(int i=1; i<=how_many_slices; i++){
        lake[i-1].load("videos/Slice " + ofToString(i) + ".mp4");
        //lake[i-1].setSpeed(ofRandom(.2, .9));
        float temp_n = i;
        lake[i-1].setSpeed( 1.5 - ( temp_n/10) );
    }
    
    
     ttf.load("AbrilFatface-Regular.ttf", 128);
    //label.load("AbrilFatface-Regular.ttf", 200);
    label.load("AbrilFatface-Regular.ttf", 45);
    smalldata.load("AbrilFatface-Regular.ttf", 16);
    
    
    ofFile file("1-population_data-b.json");
    if(file.exists()){
        file >> jsn;
        mainWM = jsn["Sheet1"];
        //cout << jsn["Sheet1"] << endl;
        
        for (auto & data: jsn["Sheet1"]){
            //cout << "////////////////////" << endl;
            //cout << data["year"] << " : " << data["wolves"] << " : " << data["moose"] << endl;
        }
    }
    
    
    //E Chicken haunt
    snd1.load("audio/IRAIR-025-Selection1-NR_st.wav");
    snd1.setVolume(0.5);
    //snd1.play();
    snd1.setLoop(true);
    
    //waves
    snd2.load("audio/IRAIR-042-Option2_st.wav");
    snd2.setVolume(0.85);
    //snd2.play();
    snd2.setLoop(true);
    
    //McCargo rich
    snd3.load("audio/IRAIR-062-Rich2_st.wav");
    snd3.setVolume(0);
    //snd3.play();
    snd3.setLoop(true);
    
    //McCargo rich
    snd4.load("audio/IRAIR-061-Rich1_st.wav");
    snd4.setVolume(0);
    //snd4.play();
    snd4.setLoop(true);
    
    
    advanceData();
    drawData();
    
}

//--------------------------------------------------------------
void ofApp::advanceData(){
    
    
   if(curr_n >= mainWM.size()){
       curr_n = 0;
   }
    
    
    
    ofJson entry = mainWM[curr_n];
    
    year = ofToInt(entry["year"]);
    wolves = ofToInt(entry["wolves"]);
    moose = ofToInt(entry["moose"]);
    icebridge = ofToBool(entry["ice bridges"]);
    
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
    
    
    
    
    
    //cout << mainWM.size() << endl;
    setAudioVals();
    
    curr_n++;
    
}

//--------------------------------------------------------------
void ofApp::setAudioVals(){
    snd1.setSpeed( ofMap(wolves, 2, 50, .2, 2.0) );
    snd2.setSpeed( ofMap(moose, 380, 2400, .2, 2.0) );
    snd3.setSpeed( ofMap(kill, 0.2, 1.5, .2, 2.0) );
    snd4.setSpeed( ofMap(predation, 0.007, .25, .2, 2.0) );
    if(kill > 0){
        snd3.setVolume(0.75);
        snd4.setVolume(0.75);
    } else {
        snd3.setVolume(0);
        snd4.setVolume(0);
    }
}


//--------------------------------------------------------------
void ofApp::drawData(){
    
    
    ofSetColor(255);
    
    ofPushMatrix();
    ofTranslate(vidleft, vidtop + 750);
    ofRotateZDeg(-90);
    
    if(icebridge){
        ofSetColor(0,220,255);
    }

    ttf.drawString(ofToString(year), 0, slice_width);
    ofSetColor(255);
    
    ttf.drawString(ofToString(wolves), 0, slice_width*1.83);
    ttf.drawString(ofToString(moose), 0, slice_width*2.83);
    
    
    if(kill > 0){
        smalldata.drawString(ofToString(kill), 0, slice_width*7);
        smalldata.drawString(ofToString(predation), 0, slice_width*8);
        
        ofSetColor(255, 255, 255, 100);
        smalldata.drawString("kill rate", -smalldata.stringWidth("kill rate")-56, slice_width*7);
        smalldata.drawString("predation rate", -smalldata.stringWidth("predation rate")-56, slice_width*8);
        ofSetColor(255);
    }
    
    ofPopMatrix();
    
    if(icebridge){
        ofSetColor(0,220,255);
        string tmpstr = "ice bridge";
        smalldata.drawString(tmpstr, slice_width - smalldata.stringWidth(tmpstr) - 6, vidtop + 825);
        ofSetColor(255);
    }
    
    /*
    label.drawString("W", (slice_width * 1.5) - (label.stringWidth("W")/2), 950);
    label.drawString("W", (slice_width*2.5) - (label.stringWidth("W")/2), 950);
     */
    /*
    ofDrawRectangle(slice_width * .9, 775, label.stringWidth("W"), 2);
    ofDrawRectangle(slice_width * 2, 775, label.stringWidth("W"), 2);
    */
    
    //label.drawString("W", vidleft + slice_width * .9, vidtop + 1000);
    label.drawString("W", vidleft + slice_width * 1.75 - 6, vidtop + 850);
    
    ofPushMatrix();
    
    ofRotateZDeg(180);
    ofTranslate(vidleft + (-slice_width * 2) + 6, -(850 + vidtop));
    label.drawString("W", -label.stringWidth("W"), label.stringHeight("W")-2);
    
    
    ofPopMatrix();
    
    //ofDrawRectangle( 200, 805, 1900, 2);
    
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

    
    for(int i=1; i<=how_many_slices; i++){
        lake[i-1].draw( vidleft + ( (i-1) * slice_width) , vidtop);
        lake[i-1].play();
    }
    
    drawData();
    delayTimer();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 32){
        advanceData();
    }
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
