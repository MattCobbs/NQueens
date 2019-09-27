//Cpp file for NQueen class

#include "NQueen.h"
#include "Board.h"
#include <fstream>

//constructor
NQueen::NQueen(int temp){
	
	NQueen::gameBoard = new Board(temp);

	NQueen::addQueens();

}//end NQueen constructor 

//Destructor
NQueen::~NQueen(){
	delete gameBoard;
}//end destructor

//Control methods for gameBoard
void NQueen::printQueensBoard(std::ofstream &outfile){
	gameBoard->printBoard(outfile);
}//end printQueensBoard


void NQueen::addQueens(){
	NQueen::addQueen(0);

}//end addQueen

bool NQueen::addQueen(int location){
	int bs = ( NQueen::getBoardSize() - 1 );
	int bl = NQueen::getBoardSize();

	if(location > bs){
		return true;
	}//end if
	
	int lastRow =  (bs + 1);
	for(int i = 0; i < lastRow; i++){
		int placement = location + (i*bl);
		bool keepGoing = NQueen::checkAttack(placement);		

	
		//if there are no queens conflicting with this location
		//place a queen there
		if(keepGoing == true){
			NQueen::placeBoardElement(placement);

			int nxtLoc = location + 1;
			
			bool outcome = NQueen::addQueen(nxtLoc);
			if( outcome == true ){
				return true;
			}//end if
				
			NQueen::removeBoardElement(placement);
		}//end if
	}//end for
	return false;
}//end addQueen


int NQueen::getBoardSize(){
	return gameBoard->getBoardLength();
}//end getBoardSize

int NQueen::checkBoardElement(int temp){
	return gameBoard->getGameSquare(temp);
}//end checkBoardElement

void NQueen::placeBoardElement(int temp){
	gameBoard->placeGamePiece(temp);
}//end placeBoardElement

void NQueen::removeBoardElement(int temp){
	gameBoard->removeGamePiece(temp);
}//end removeBoardElement	


//Will need to call two other methods to check slope, and the row
bool NQueen::checkAttack(int location){
	bool slope = checkSlope(location);
	bool horz = checkHorz(location);

	//if either methods return false, return false 
	if(slope == false){
		return false;
	}//end if

	else if(horz == false){
		return false;
	}//end else if

	else{
		return true;
	}//end else
}//end checkAttack

bool NQueen::checkSlope(int location){
	int bs = NQueen::getBoardSize();

	int rowLoc = (location/bs);
	int rowLeft = ( (bs - 1) - rowLoc);
	int rowBhnd = ( (bs - 1) - rowLeft); 

	int colLoc = (location%bs);
	int colLeft = ( (bs - 1) - colLoc);
	int colBhnd = ( (bs - 1) - colLeft);

	int qCount = 0;

	if( (rowLoc >= bs) ){
		return false;
	}//end if

	//check positive slope
	//use the smaller of the value of either rows behind the current location or 
	//columns left in the board
	if(rowLeft <= colBhnd){
		for(int i = 1; i <= rowLeft; i++){
			int slopePoint = ( location + (bs * i) - i );
			
			if( NQueen::checkBoardElement(slopePoint) == 1 ){
				qCount++;
			}//end if
		}//end for
	}//end if

	else if(colBhnd < rowLeft){
		for( int i = 1; i <= colBhnd; i++){
			int slopePoint = ( location + (bs * i) - i);
	
			if( NQueen::checkBoardElement(slopePoint) == 1){
				qCount++;
			}//end if
		}//end for
	}//end else if 
	
	else{
		std::cout << "check pos slope not working" << std::endl;
	}//end else


	//check neg slope
	//use the smaller value of either rows behind the current location or
	//columns behind the current location to check for queens
	if(rowBhnd <= colBhnd){
		for( int j = 1; j <= rowBhnd; j++){
			int negSlope = ( location - (bs * j) - j);

			if( NQueen::checkBoardElement(negSlope) == 1){
				qCount++;
			}//end if 
		}//end for
	}//end if

	else if(colBhnd < rowBhnd){
		for( int j = 1; j <= colBhnd; j++){
			int negSlope = ( location - (bs * j) - j);

			if( NQueen::checkBoardElement(negSlope) == 1){
				qCount++;
			}//end if
		}//end for
	}//end else if
	
	else{
		std::cout << "check neg slope not working" << std::endl;
	}//end else

	//check the number of queens present, if zero return true
	if(qCount == 0){
		return true;
	}//end if

	else{
		return false;
	}//end else
}//end checkSlope

bool NQueen::checkHorz(int location){
	int bs = NQueen::getBoardSize();	

	int rowLoc =  ( (location/bs)*bs );
	int nxtRow = ( ( (location/bs) +1)*bs);

	int qCount = 0;

	for(int i = rowLoc; i < nxtRow; i++){
		int hasQueen = NQueen::checkBoardElement(i);

		if(hasQueen == 1){
			qCount++;
		}//end if
	}//end for

	if(qCount > 0){
		return false;
	}//end if

	else{
		return true;
	}//end else
}//end checkHorz



/*
int main(){

	NQueen* test = new NQueen(8);

	test->printQueensBoard();

	//test->addQueens();
	
	//std::cout << std::endl;	

	//test->printQueensBoard();
}//end main
*/

