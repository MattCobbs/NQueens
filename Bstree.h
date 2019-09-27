//Header file for Bstree class

#ifndef BSTREE_H_EXISTS
#define BSTREE_H_EXISTS

#include "Node.h"

class Bstree{
	
	protected:
		Node* root;
	
	public:
		//Constructor
		Bstree();

		//Destructor
		~Bstree();
		//Method for the destructor to use to delete all of the nodes
		void deleteTree(Node* temp);

		Node* getRoot();

		Node* createNode(int temp);

		void addNode(int temp, Node* a);

		void ofTree(Node* temp, std::ofstream &outfile);

};//end Bstree

#endif
