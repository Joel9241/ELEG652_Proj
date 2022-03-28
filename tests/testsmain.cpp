#include <stdio.h>
#include <stdlib.h>
#include "Board.hpp"

bool initBoardTest(){
	bool failed = false;
	Board x = Board();
	//White Pieces
	for(int i = 1; i < 3; i++){
		for(int j = 0; j < 8; j++){
			if(x.isEmpty((char)(j + 65), i + '0')){
				printf("Failed on vals %c%d\n", (char)(j + 65), i);
				failed = true;
			}
			else{
				Piece* tmp = x.getPiece((char)(j + 65), i + '0');
				if(!tmp->isWhite()){
					printf("Failed on color %c%d\n", (char)(j + 65), i);
					failed = true;
				}
				if(i == 2){
					if(tmp->getType() != pawn){
						printf("Failed on type %c%d\n", (char)(j + 65), i);
						failed = true;
					}
				}
				else{
					if((j == 0) || (j == 7)){
						if(tmp->getType() != rook){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else if((j == 1) || (j == 6)){
						if(tmp->getType() != knight){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else if((j == 2) || (j == 5)){
						if(tmp->getType() != bishop){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else if(j == 3){
						if(tmp->getType() != queen){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else if(j == 4){
						if(tmp->getType() != king){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else{
						printf("Error with testbench\n");
					}
				}
			}
		}
	}
	//Empty Pieces
	for(int i = 3; i < 7; i++){
		for(int j = 0; j < 8; j++){
			if(!x.isEmpty((char)(j + 65), i + '0')){
				printf("Failed on vals %c%d\n", (char)(j + 65), i);
				failed = true;
			}
		}
	}
	//Black Pieces
	for(int i = 7; i < 9; i++){
		for(int j = 0; j < 8; j++){
			if(x.isEmpty((char)(j + 65), i + '0')){
				printf("Failed on vals %c%d\n", (char)(j + 65), i);
				failed = true;
			}
			else{
				Piece* tmp = x.getPiece((char)(j + 65), i + '0');
				if(tmp->isWhite()){
					printf("Failed on color %c%d\n", (char)(j + 65), i);
					failed = true;
				}
				if(i == 7){
					if(tmp->getType() != pawn){
						printf("Failed on type %c%d\n", (char)(j + 65), i);
						failed = true;
					}
				}
				else{
					if((j == 0) || (j == 7)){
						if(tmp->getType() != rook){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else if((j == 1) || (j == 6)){
						if(tmp->getType() != knight){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else if((j == 2) || (j == 5)){
						if(tmp->getType() != bishop){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else if(j == 3){
						if(tmp->getType() != queen){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else if(j == 4){
						if(tmp->getType() != king){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else{
						printf("Error with testbench\n");
					}
				}
			}
		}
	}
	return !failed;
}

bool updatePawnMovesTest(){
	bool failed = false;
	//Test 1
	Piece** state = new Piece*[64];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			state[(i * 8) + j] = NULL;
		}
	}
	state[(1 * 8) + 1] = new Piece((char*)"B2", true, pawn);
	state[(2 * 8) + 0] = new Piece((char*)"A3", false, pawn);
	state[(2 * 8) + 2] = new Piece((char*)"C3", true, pawn);
	Board x = Board(state);
	Piece *p = x.getPiece('B', 2 + '0');
	x.updatePieceMoves(p);
	int correctNumMoves = 3;
	char *correctMoves = new char[correctNumMoves * 2];
	correctMoves = "B3B4A3";
	for(int i = 0; i < correctNumMoves * 2; i++){
		if(p->availableMoves[i] != correctMoves[i]){
			printf("Failed on comparison %d, value should be %c but is %c \n", i, correctMoves[i], p->availableMoves[i]);
			failed = true;
		}
	}
	if(p->numMoves != correctNumMoves){
		printf("Incorrect number of moves for Test 1\n");
		failed = true;
	}
	
	//Test 2
	state = new Piece*[64];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			state[(i * 8) + j] = NULL;
		}
	}
	state[(6 * 8) + 4] = new Piece((char*)"E7", false, pawn);
	state[(5 * 8) + 3] = new Piece((char*)"D6", false, pawn);
	state[(5 * 8) + 5] = new Piece((char*)"F6", true, pawn);
	x = Board(state);
	p = x.getPiece('E', 7 + '0');
	x.updatePieceMoves(p);
	correctNumMoves = 3;
	correctMoves = new char[correctNumMoves * 2];
	correctMoves = "E6E5F6";
	for(int i = 0; i < correctNumMoves * 2; i++){
		if(p->availableMoves[i] != correctMoves[i]){
			printf("Failed on comparison %d, value should be %c but is %c \n", i, correctMoves[i], p->availableMoves[i]);
			failed = true;
		}
	}
	if(p->numMoves != correctNumMoves){
		printf("Incorrect number of moves for Test 2\n");
		failed = true;
	}
	
	//Test 3
	state = new Piece*[64];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			state[(i * 8) + j] = NULL;
		}
	}
	state[(1 * 8) + 0] = new Piece((char*)"A2", true, pawn);
	state[(2 * 8) + 1] = new Piece((char*)"B3", false, pawn);
	x = Board(state);
	p = x.getPiece('A', 2 + '0');
	x.updatePieceMoves(p);
	correctNumMoves = 3;
	correctMoves = new char[correctNumMoves * 2];
	correctMoves = "A3A4B3";
	for(int i = 0; i < correctNumMoves * 2; i++){
		if(p->availableMoves[i] != correctMoves[i]){
			printf("Failed on comparison %d, value should be %c but is %c \n", i, correctMoves[i], p->availableMoves[i]);
			failed = true;
		}
	}
	if(p->numMoves != correctNumMoves){
		printf("Incorrect number of moves for Test 3\n");
		failed = true;
	}
	
	//Test 4
	state = new Piece*[64];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			state[(i * 8) + j] = NULL;
		}
	}
	state[(6 * 8) + 7] = new Piece((char*)"H7", false, pawn);
	state[(5 * 8) + 6] = new Piece((char*)"G6", true, pawn);
	x = Board(state);
	p = x.getPiece('H', 7 + '0');
	x.updatePieceMoves(p);
	correctNumMoves = 3;
	correctMoves = new char[correctNumMoves * 2];
	correctMoves = "H6H5G6";
	for(int i = 0; i < correctNumMoves * 2; i++){
		if(p->availableMoves[i] != correctMoves[i]){
			printf("Failed on comparison %d, value should be %c but is %c \n", i, correctMoves[i], p->availableMoves[i]);
			failed = true;
		}
	}
	if(p->numMoves != correctNumMoves){
		printf("Incorrect number of moves for Test 4\n");
		failed = true;
	}
	
	//Test 5
	state = new Piece*[64];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			state[(i * 8) + j] = NULL;
		}
	}
	state[(6 * 8) + 7] = new Piece((char*)"H7", false, pawn);
	state[(4 * 8) + 7] = new Piece((char*)"H5", true, pawn);
	x = Board(state);
	p = x.getPiece('H', 7 + '0');
	x.updatePieceMoves(p);
	correctNumMoves = 1;
	correctMoves = new char[correctNumMoves * 2];
	correctMoves = "H6";
	for(int i = 0; i < correctNumMoves * 2; i++){
		if(p->availableMoves[i] != correctMoves[i]){
			printf("Failed on comparison %d, value should be %c but is %c \n", i, correctMoves[i], p->availableMoves[i]);
			failed = true;
		}
	}
	if(p->numMoves != correctNumMoves){
		printf("Incorrect number of moves for Test 5\n");
		failed = true;
	}
	
	//Test 6
	state = new Piece*[64];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			state[(i * 8) + j] = NULL;
		}
	}
	state[(6 * 8) + 7] = new Piece((char*)"H7", false, pawn);
	state[(5 * 8) + 7] = new Piece((char*)"H6", true, pawn);
	x = Board(state);
	p = x.getPiece('H', 7 + '0');
	x.updatePieceMoves(p);
	correctNumMoves = 0;
	if(p->numMoves != correctNumMoves){
		printf("Incorrect number of moves for Test 6\n");
		failed = true;
	}
	return !failed;
}

bool updateRookMovesTest(){
	bool failed = false;
	//Test 1
	Piece** state = new Piece*[64];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			state[(i * 8) + j] = NULL;
		}
	}
	state[(0 * 8) + 0] = new Piece((char*)"A1", true, rook);
	Board x = Board(state);
	Piece *p = x.getPiece('A', 1 + '0');
	x.updatePieceMoves(p);
	int correctNumMoves = 14;
	char *correctMoves = new char[correctNumMoves * 2];
	correctMoves = "B1C1D1E1F1G1H1A2A3A4A5A6A7A8";
	for(int i = 0; i < correctNumMoves * 2; i++){
		if(p->availableMoves[i] != correctMoves[i]){
			printf("Failed on comparison %d, value should be %c but is %c \n", i, correctMoves[i], p->availableMoves[i]);
			failed = true;
		}
	}
	if(p->numMoves != correctNumMoves){
		printf("Incorrect number of moves for Test 1\n");
		failed = true;
	}
	//Test 2
	state = new Piece*[64];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			state[(i * 8) + j] = NULL;
		}
	}
	state[(0 * 8) + 0] = new Piece((char*)"A1", true, rook);
	state[(1 * 8) + 0] = new Piece((char*)"A2", false, pawn);
	state[(0 * 8) + 1] = new Piece((char*)"B1", true, pawn);
	x = Board(state);
	p = x.getPiece('A', 1 + '0');
	x.updatePieceMoves(p);
	correctNumMoves = 1;
	correctMoves = new char[correctNumMoves * 2];
	correctMoves = "A2";
	for(int i = 0; i < correctNumMoves * 2; i++){
		if(p->availableMoves[i] != correctMoves[i]){
			printf("Failed on comparison %d, value should be %c but is %c \n", i, correctMoves[i], p->availableMoves[i]);
			failed = true;
		}
	}
	if(p->numMoves != correctNumMoves){
		printf("Incorrect number of moves for Test 2\n");
		failed = true;
	}
	//Test 3
	state = new Piece*[64];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			state[(i * 8) + j] = NULL;
		}
	}
	state[(3 * 8) + 2] = new Piece((char*)"C4", false, rook);
	state[(4 * 8) + 2] = new Piece((char*)"C5", false, pawn);
	state[(3 * 8) + 3] = new Piece((char*)"D4", true, pawn);
	x = Board(state);
	p = x.getPiece('C', 4 + '0');
	x.updatePieceMoves(p);
	correctNumMoves = 6;
	correctMoves = new char[correctNumMoves * 2];
	correctMoves = "D4B4A4C3C2C1";
	for(int i = 0; i < correctNumMoves * 2; i++){
		if(p->availableMoves[i] != correctMoves[i]){
			printf("Failed on comparison %d, value should be %c but is %c \n", i, correctMoves[i], p->availableMoves[i]);
			failed = true;
		}
	}
	if(p->numMoves != correctNumMoves){
		printf("Incorrect number of moves for Test 3\n");
		failed = true;
	}

	return !failed;
}

int main(){
	if(!initBoardTest()){
		printf("initBoardTest Failed\n");
	}
	if(!updatePawnMovesTest()){
		printf("updatePawnMovesTest Failed\n");
	}
	if(!updateRookMovesTest()){
		printf("updateRookMovesTest Failed\n");
	}
	printf("Finished tests\n");
	return 0;
}
