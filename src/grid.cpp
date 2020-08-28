#include "grid.h"
#include "debugger.h"

grid::grid(){}

bool grid::getDoUpdate(){ return doUpdate; }
std::vector<std::vector<tile>> grid::getGameSpace(){ return gameSpace; }
int grid::getGH(){ return gH; }
int grid::getGW(){ return gW; }
int grid::getOffsetX(){ return offsetX; }
int grid::getOffsetY(){ return offsetY; }
ofColor grid::getLineColour(){ return lineColour; }

void grid::setDoUpdate( bool _doUpdate){ doUpdate = _doUpdate; }
void grid::setGameSpace( std::vector<std::vector<tile>> _gameSpace){ gameSpace = _gameSpace; }
void grid::setGH( int _gH){ gH = _gH; }
void grid::setGW( int _gW){ gW = _gW; }
void grid::setOffsetX( int _offsetX){ offsetX = _offsetX; }
void grid::setOffsetY( int _offsetY){ offsetY = _offsetY; }
void grid::setLineColour( ofColor _lineColour){ lineColour = _lineColour; }

void grid::createGrid(){
	//Log starting
	debugger::log("Creating new grid...");

	debugger::log("Setting vars");
	offsetX = (ofGetWidth()/2) - ((gW/2) * tile::getSize());
	offsetY = (ofGetHeight()/2) - ((gH/2) * tile::getSize());

	std::string msg = "Height = "; msg += std::to_string(gH);
	debugger::log(msg);
	msg = "Width = "; msg += std::to_string(gW);
	debugger::log(msg);
	msg = "X offset = "; msg += std::to_string(offsetX);
	debugger::log(msg);
	msg = "Y offset = "; msg += std::to_string(offsetY);
	debugger::log(msg);
	msg = "Tile Size = "; msg += std::to_string(tile::getSize());
	debugger::log(msg);


	//Clear gameSpace
	gameSpace.clear();

	for(int i = 0; i < gH; i++){
		std::vector<tile> tmp;
		for(int j = 0; j < gW; j++){
			//Create tile and assign X/Y/black
			tile a = tile(((tile::getSize()*j) + offsetX), ((tile::getSize()*i) + offsetY), ofColor::black);

			//Push to back of tile queue
			tmp.push_back(a);
		}
		//Push completed "row" to back of tile vector
		gameSpace.push_back(tmp);
	}

	//Grid created
	debugger::log("Game created");
}

void grid::drawGrid(){
	//Tiles drawing setup
	ofFill();
	ofSetLineWidth(5);

	//Draw the tiles
	for(int i = 0; i < gW; i++){
		for(int j = 0; j < gH; j++){
			gameSpace[j][i].draw();
		}
	}

	//Lines drawing setup
	ofNoFill();
	ofSetLineWidth(5);
	ofSetColor(grid::getLineColour());
	float s = tile::getSize();

	//Draw the lines
	for(int i = 0; i < gH; i++){
		for(int j = 0; j < gW; j++){
			ofDrawRectangle(
						((s*j) + offsetX)-(s/2), //X
						((s*i) + offsetY)-(s/2), //Y
						s,    //Width
						s );  //Height
		}
	}
}
