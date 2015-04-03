#include "ofApp.h"

//part of the SeaWeed Quiz 1

//--------------------------------------------------------------
void ofApp::setup(){
    // I set the frame rate 
    ofSetFrameRate(50) ;
    position = 450 ;
    speed = 1.4 ;
    position2 = 550 ;
    speed2 = 1.4 ;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Here I set my boundries for the moving curve
    if (position >= 600)  speed*= -1 ;
    if (position <= 300)  speed*= -1 ;
    if (position2 >= 600)  speed2*= -1 ; 
    if (position2 <= 300)  speed2*= -1 ;
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    int counter = 230 ;
    color1.setHue( 50 ) ;
    color1.setSaturation( 200 ) ;
    color1.setBrightness( 200 ) ;
    ofSetColor(ofColor::greenYellow) ;
    ofSetLineWidth(3) ;
    
    //here is the start of my curve
    plant.curveTo(position+=speed, 270);
    plant.curveTo(position+=speed, 270);
    plant.curveTo(position2+=speed2, 400);
    plant.curveTo(500, 670);
    plant.curveTo(500, 750);
    plant.curveTo(500, 750);
    //curve ends
    
    polylines.push_back(plant) ;
    //return
    plant.clear() ;
    
    
    //goes into array for polylines, creates poly lines
    for (int i=0; i<polylines.size(); i++) {
        
        ofPolyline polyline = polylines[i];
        polyline.draw();
        
         //scales the leaves
        float numPoints = polyline.size();
        for (int a=0; a<500; a+=5) {
            leafLength = (a * -1) / 3.5 ;
            
            //I made a counter to control a gradient
            //the brightness is controlled by the counter
            counter-- ;
            color1.setBrightness(counter) ;
            ofSetColor(color1) ;
            
            //creates polylines at points in the plant polyline
            ofVec3f point = polyline.getPointAtPercent(a/500.0);
            float floatIndex = a/500.0 * (numPoints-1);
            ofVec3f normal = polyline.getNormalAtIndexInterpolated(floatIndex) * leafLength;
            ofLine(point-normal/2, point+normal/2);
        }
        //this is where I spawn my polylines
    }
    for (int i=0; i<polylines.size(); i++) {
        polylines.pop_back() ;
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
