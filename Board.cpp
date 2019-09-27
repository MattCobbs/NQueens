//Cpp file for Board class

#include "Board.h"
#include <iostream>

Board::Board(int temp){
	Board::boardLength = temp;

	int boardArea = temp*temp;
	Board::boardVec.assign(boardArea,0);

}//end constructor

int Board::getBoardLength(){
	return Board::boardLength;
}//end getBoardLength

int Board::getGameSquare(int temp){
	return Board::boardVec.at(temp);
}//end getBoardVal

void Board::placeGamePiece(int temp){
	Board::boardVec[temp] = 1;
}//end placeGamePiece

void Board::removeGamePiece(int temp){
	Board::boardVec[temp] = 0;
}//end removeGamePiece

void Board::printBoard(std::ofstream &outfile){
	int MAX = Board::getBoardLength();

	outfile << "Solution for board size " << MAX << "." << std::endl;
	for(int i = 0; i < MAX; i++){
		outfile << "|";
		for(int j = 0; j < MAX; j++){
			int gameSquare = (i*MAX) + j;
			outfile << Board::getGameSquare(gameSquare) << "|";
		}//end for j
		outfile << std::endl;
	}//end for
	outfile << std::endl;
	outfile << std::endl;
}//end printBoard	
	
/*
int main(){
	Board* test = new Board(4);

	test->printBoard();

}//end main
*/
