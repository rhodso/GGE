#ifndef GRID_H
#define GRID_H

#include "ofMain.h"
#include "tile.h"

class grid
{
public:
    grid();

	bool getDoUpdate();
	std::vector<std::vector<tile>> getGameSpace();
	int getGH();
	int getGW();
	int getOffsetX();
	int getOffsetY();
	static ofColor getLineColour();

	void setDoUpdate( bool _doUpdate );
	void setGameSpace( std::vector<std::vector<tile>> _gameSpace );
	void setGH( int _gH );
	void setGW( int _gW );
	void setOffsetX( int _offsetX );
	void setOffsetY( int _offsetY );
	static void setLineColour( ofColor _lineColour );

	void createGrid();
	void drawGrid();

private:
	bool doUpdate;
	std::vector<std::vector<tile>> gameSpace;
	int gH = 30;
	int gW = 30;
	int offsetX;
	int offsetY;

	inline static ofColor lineColour = ofColor::white;

};

#endif // GRID_H
