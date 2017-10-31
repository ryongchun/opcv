#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    
    bSendSerialMessage = false;
    ofBackground(255);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    font.load("DIN.otf", 64);
    
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    serial.setup(0, 9600); //open the first device
    
    nTimesRead = 0;
    nBytesRead = 0;
    readTime = 0;
    memset(bytesReadString, 0, 4);

}

//--------------------------------------------------------------
void ofApp::update(){

    if(serial.available() != 0) //serial신호를 존재여부를 확인하고 0이 아니면 실행
        data = serial.readByte(); //date 1byte를 읽는다
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(60, 90, 200);  //배경 색을 설정
    
    ofDrawCircle(300 +100*cos(angle), 150 + 100*sin(angle), data, data);
    angle += 0.05f;
    
    ofDrawCircle(500, 400, data, data); //원을 그리는데 원의 중심은 (500,400)에 있으며
                                      //반지름은 아두이노에게 받은 수치값이 지정되어 있는
                                      //변수를 사용합니다.
    ofDrawCircle(300, 400, data, data);
    
    if (nBytesRead > 0 && ((ofGetElapsedTimef() - readTime) < 0.5f)){
        ofSetColor(0);
    } else {
        ofSetColor(220);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
