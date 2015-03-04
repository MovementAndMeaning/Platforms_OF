#pragma once

#include "ofMain.h"
#undef check //needed for OSX oF integration
#include "yarp/os/all.h"
#include <yarp/os/impl/NameConfig.h>
using namespace yarp::os;
using namespace yarp::os::impl;

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		//yarp specific:

        Network yarp;
		BufferedPort<Bottle> port;
};
