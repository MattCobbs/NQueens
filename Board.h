//Header file for Board class

#ifndef BOARD_H_EXISTS
#define BOARD_H_EXISTS

#include <vector>
#include <fstream>

class Board{

	private:
		//vector
		std::vector<int> boardVec;
		int boardLength;

	public:
		Board(int temp);

		int getBoardLength();
		
		int getGameSquare(int temp);
		void placeGamePiece(int temp);
		void removeGamePiece(int temp);		

		void printBoard(std::ofstream &outfile);

};//end Board class

#endif
