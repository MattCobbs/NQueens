//Header file for NQueen class

#ifndef NQUEEN_H_INCLUDED
#define NQUEEN_H_INCLUDED

#include "Board.h"
#include <iostream>
#include <fstream>

class NQueen{
	
	private:
		Board* gameBoard;

		bool addQueen(int location);
	public:
		NQueen(int temp);	
	
		~NQueen();		
	
		void addQueens();

		int getBoardSize();
		void printQueensBoard(std::ofstream &outfile);
		int checkBoardElement(int temp);
		void placeBoardElement(int temp);
		void removeBoardElement(int temp);

		bool checkAttack(int location);
		bool checkSlope(int location);
		bool checkHorz(int location);
	
};//end NQueen class

#endif		
