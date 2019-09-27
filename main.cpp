//main for final project

#include "Board.h"
#include "NQueen.h"
#include "Node.h"
#include "Bstree.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

int userAnswer();

int main(){

	std::ofstream solutions;
	solutions.open("solutions.txt");

	if( solutions.is_open() ){

		bool keepgoing = true;

		Bstree* tree = new Bstree();

		while(keepgoing){
			std::cout << "What would you like to do?" << std::endl;
			std::cout << "1)Add a solution of N-Queens" << std::endl;
			std::cout << "2)Save all of your solutions" << std::endl;
			std::cout << "3)Quit" << std::endl;
			
			int response = userAnswer();

			if(response == 1){
				std::cout << "What numbers would you like to choose from?" << std::endl;
				std::cout << "For run time considerations do not pick a number higher than 25" << std::endl;
				std::cout << "2 and 3 do not have solutions so you may pick from the range of [4,25]" << std::endl;
				
				int userResponse = userAnswer();

				if( (userResponse >= 4)  && (userResponse <= 25) ){
					tree->addNode(userResponse, tree->getRoot());
				}//end if

				else{
					std::cout << "You did not pick a number in the correct range" << std::endl;
				}//end else;

			}//end if
			
			else if(response == 2){
				tree->ofTree(tree->getRoot(), solutions);
				std::cout << "There is a text file waiting for you in the directory" << std::endl;
			}//end else if

			else if(response == 3){
				keepgoing = false;
			}//end else if

			else{
				std::cout << "Only put 1, 2, or 3" << std::endl;
			}//end else

		}//end while	
		
		delete tree;		
	
	}//end if

	else{
		std::cout << "A text file could not be opened to save your solutions" << std::endl;
	}//end else
	
	solutions.close();

}//end main

int userAnswer(){
	std::string userRes;
	std::stringstream ss;
	int userNum;

	getline(std::cin, userRes);

	ss << userRes;
	ss >> userNum;
	ss.clear();

	return userNum;
}//end userAnswer
