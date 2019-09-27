//Cpp file for Node class

#include "Node.h"

//Null constructor
Node::Node(int temp){
	left = NULL;
	right = NULL;
	height = NULL;
	queen = new NQueen(temp);;
	int boardSize = temp;
}//end null constructor

//Destructor
Node::~Node(){
	delete queen;
}//end destructor

//
//Getter and setter for left
//

Node* Node::getLeft(){
	return left;
}//end getLeft

void Node::setLeft(Node* temp){
	left = temp;
}//end setLeft

//
//Getter and setter for right
//

Node* Node::getRight(){
	return right;
}//end getRight

void Node::setRight(Node* temp){
	right = temp;
}//end setRight

//
//Getter for boardSize
//

int Node::getBoardSize(){
	return boardSize;
}//end getBoardSize

void Node::printBoard(std::ofstream &outfile){
	Node::queen->printQueensBoard(outfile);
}//end printBoard

