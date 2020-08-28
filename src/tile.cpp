#include "tile.h"

tile::tile(){}

tile::tile(float _x, float _y){
	x = _x;
	y = _y;
}
tile::tile(float _x, float _y, ofColor _c){
	x = _x;
	y = _y;
	colour = _c;
}
tile::~tile(){}

float tile::getX(){ return x; }
float tile::getY(){ return y; }
ofColor tile::getColour(){ return colour; }
float tile::getSize(){ return size; }

void tile::setX( float _x){ x = _x; }
void tile::setY( float _y){ y = _y; }
void tile::setSize(float _size){ size = _size; }
void tile::setColour( ofColor _colour){ colour = _colour; }

void tile::draw(){
	//Set to correct colour and draw square
	ofSetColor(colour);
	ofDrawRectangle(x-(size/2.0),y-(size/2.0),size,size);
}

void tile::copyProperties(tile* trg){
	this->setColour(trg->getColour());
}
