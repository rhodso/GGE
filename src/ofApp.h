#pragma once

#include "ofMain.h"
#include "grid.h"
#include "tile.h"
#include "debugger.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void handleKeypresses();

    //oF used
    void keyPressed(int key);
    void keyReleased(int key);

    //Unused, but if we take them out then oF throws a hissy fit
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

private:
    bool keys[65535];
    bool debug = true;

    grid g;

};
