#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);

	ofDisableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (int x = 0; x < ofGetWidth(); x += 50) {

		for (int y = 0; y < ofGetHeight(); y += 50) {

			ofPushMatrix();
			ofTranslate(x, y);

			auto noise_value = ofNoise(x * 0.005, y * 0.005, ofGetFrameNum() * 0.01);
			ofRotateZ(ofMap(noise_value, 0, 1, 0, 360));
			ofRotateX(ofMap(noise_value, 0, 1, 0, 360));
			ofRotateY(ofMap(noise_value, 0, 1, 0, 360));

			ofFill();
			ofSetColor(50);
			ofDrawBox(50);

			ofNoFill();
			ofSetColor(239);
			ofDrawBox(50);

			ofPopMatrix();
		}
	}

	/*
	int start = 30;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}