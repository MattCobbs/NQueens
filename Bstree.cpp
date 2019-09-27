//Cpp file for Bstree class

#include "Bstree.h"
#include "Node.h"

//Constructor
Bstree::Bstree(){
	root = NULL;
}//end constructor

//Destructor
Bstree::~Bstree(){
	deleteTree(root);
}//end destructor

//Method for Destructor to call to delete nodes from the bottom up
void Bstree::deleteTree(Node* root){
	if(root != NULL){
		if(root->getLeft() != NULL){
			deleteTree(root->getLeft());
		}//end if
	
		if(root->getRight() != NULL){
			deleteTree(root->getRight());
		}//end if

		delete root;

	}//end if
}//end deleteTree

Node* Bstree::getRoot(){
	if(root == NULL){
		return NULL;
	}//end if

	else{
		return root;
	}//end else
}//end getRoot

Node* Bstree::createNode(int temp){
	Node* tempNode = new Node(temp);
	return tempNode;
}//end createNode

void Bstree::addNode(int temp, Node* rNode){
	
	if(root == NULL){
		root = createNode(temp);
	}//end if

	else if(temp > rNode->getBoardSize()){
		//if the new number is larger check the current node's 
		//left pointer, if null make a new node using the new number
		//if not null, recursively call this method until an empty pointer
		//is found

		if(rNode->getLeft() == NULL){
			Node* child = new Node(temp);
			rNode->setLeft(child);
		}//end if

		else if(rNode->getLeft() != NULL){
			addNode(temp, rNode->getLeft());
		}//end else if
	}//end else if

	else if(temp < rNode->getBoardSize()){
		//if the new number is smaller, check the current node's right
		//pointer, if null make a new node using the new number if not
		//null, recursively call this method until an empty pointer
		//is found

		if(rNode->getRight() == NULL){
			Node* child = new Node(temp);
			rNode->setRight(child);
		}//end if

		else if(rNode->getRight() != NULL){
			addNode(temp, rNode->getRight());
		}//end else if
	}//end else if

}//end addNode

void Bstree::ofTree(Node* temp, std::ofstream &outfile){
	if(Bstree::getRoot() != NULL){
		if(temp->getLeft() != NULL){
			ofTree(temp->getLeft(), outfile);
			temp->printBoard(outfile);

		}//end if

		else{
			temp->printBoard(outfile);
		}//end else

		if(temp->getRight() != NULL){
			ofTree(temp->getRight(), outfile);
			temp->printBoard(outfile);
		}//end if
	}//end if
	
	else{
		outfile << "There were no game boards completed" << std::endl;
	}//end else
}//end printTree

	 
