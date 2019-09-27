//Header file for Node class

#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS

#include "NQueen.h"
#include <fstream>

class Node{
	
	private:
		Node* left;
		Node* right;

		int height;
		int boardSize;

		NQueen* queen;


	public:
		Node(int temp);

		~Node();

		void setLeft(Node* temp);
		Node* getLeft();

		void setRight(Node* temp);
		Node* getRight();

		//public methods that manipulate queen
		void printBoard(std::ofstream &outfile);		

		int getBoardSize();

};//end Node class

#endif		

