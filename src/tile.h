#ifndef TILE_H
#define TILE_H

#include "ofMain.h"

class tile{
public:
	tile();
	tile(float _x, float _y);
	tile(float _x, float _y, ofColor _c);
	~tile();

	float getX();
	float getY();
	ofColor getColour();
	static float getSize();

	void setX( float _x );
	void setY( float _y );
	static void setSize( float _size );
	void setColour( ofColor _colour );

	void draw();
	void copyProperties(tile* trg);


private:

	float x;
	float y;
	ofColor colour;

	inline static float size = 30;

};

#endif // TILE_H
