#makefile for NQueen project

runProg: main.o Bstree.o Node.o NQueen.o Board.o
	g++ main.o Bstree.o Node.o NQueen.o Board.o -o runProg

Board.o: Board.cpp Board.h
	g++ -c Board.cpp

NQueen.o: NQueen.cpp NQueen.h Board.h
	g++ -c NQueen.cpp

Node.o: Node.cpp Node.h NQueen.h Board.h
	g++ -c Node.cpp

Bstree.o: Bstree.cpp Bstree.h Node.h NQueen.h Board.h
	g++ -c Bstree.cpp

main.o: main.cpp Bstree.o Node.o NQueen.o Board.o
	g++ -c main.cpp

clean:
	rm -f *.o
	rm -f solutions.txt
	
run: runProg
	./runProg

valgrind: valgrind
	valgrind ./runProg
