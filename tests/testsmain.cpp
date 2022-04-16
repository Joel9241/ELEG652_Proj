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

bool pieceMoveTest(Piece** pieces, int numPieces, Piece* tpiece, char* correctMoves, int correctNumMoves){
	bool failed = false;
	Piece** state = new Piece*[64];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			state[(i * 8) + j] = NULL;
		}
	}
	Piece* tmp;
	for(int i = 0; i < numPieces; i++){
		tmp = pieces[i];
		int col = (int)pieces[i]->getPosition()[0] - 65;
		int row = (int)pieces[i]->getPosition()[1] - 49;
		state[(row * 8) + col] = tmp;
	}
	Board x = Board(state);
	x.updatePieceMoves(tpiece);
	for(int i = 0; i < correctNumMoves * 2; i++){
		if(tpiece->availableMoves[i] != correctMoves[i]){
			printf("Failed on comparison %d, value should be %c but is %c \n", i, correctMoves[i], tpiece->availableMoves[i]);
			failed = true;
		}
	}
	if(tpiece->numMoves != correctNumMoves){
		printf("Incorrect number of moves\n");
		failed = true;
	}
	return failed;
}

bool updatePawnMovesTest(){
	bool failed = false;
	//Test 1
	int numPieces = 3;
	Piece** pieces = new Piece*[numPieces];
	pieces[0] = new Piece((char*)"B2", true, pawn);
	pieces[1] = new Piece((char*)"A3", false, pawn);
	pieces[2] = new Piece((char*)"C3", true, pawn);
	Piece* tpiece = pieces[0];
	int correctNumMoves = 3;
	char *correctMoves = new char[correctNumMoves * 2];
	correctMoves = "B3B4A3";
	failed |= pieceMoveTest(pieces, numPieces, tpiece, correctMoves, correctNumMoves);
	
	//Test 2
	numPieces = 3;
	pieces = new Piece*[numPieces];
	pieces[0] = new Piece((char*)"E7", false, pawn);
	pieces[1] = new Piece((char*)"D6", false, pawn);
	pieces[2] = new Piece((char*)"F6", true, pawn);
	tpiece = pieces[0];
	correctNumMoves = 3;
	correctMoves = new char[correctNumMoves * 2];
	correctMoves = "E6E5F6";
	failed |= pieceMoveTest(pieces, numPieces, tpiece, correctMoves, correctNumMoves);

	//Test 3
	numPieces = 2;
	pieces = new Piece*[numPieces];
	pieces[0] = new Piece((char*)"A2", true, pawn);
	pieces[1] = new Piece((char*)"B3", false, pawn);
	tpiece = pieces[0];
	correctNumMoves = 3;
	correctMoves = new char[correctNumMoves * 2];
	correctMoves = "A3A4B3";
	failed |= pieceMoveTest(pieces, numPieces, tpiece, correctMoves, correctNumMoves);

	//Test 4
	numPieces = 2;
	pieces = new Piece*[numPieces];
	pieces[0] = new Piece((char*)"H7", false, pawn);
	pieces[1] = new Piece((char*)"G6", true, pawn);
	tpiece = pieces[0];
	correctNumMoves = 3;
	correctMoves = new char[correctNumMoves * 2];
	correctMoves = "H6H5G6";
	failed |= pieceMoveTest(pieces, numPieces, tpiece, correctMoves, correctNumMoves);
	
	//Test 5
	numPieces = 2;
	pieces = new Piece*[numPieces];
	pieces[0] = new Piece((char*)"H7", false, pawn);
	pieces[1] = new Piece((char*)"H5", true, pawn);
	tpiece = pieces[0];
	correctNumMoves = 1;
	correctMoves = new char[correctNumMoves * 2];
	correctMoves = "H6";
	failed |= pieceMoveTest(pieces, numPieces, tpiece, correctMoves, correctNumMoves);
	
	//Test 6
	numPieces = 2;
	pieces = new Piece*[numPieces];
	pieces[0] = new Piece((char*)"H7", false, pawn);
	pieces[1] = new Piece((char*)"H6", true, pawn);
	tpiece = pieces[0];
	correctNumMoves = 0;
	correctMoves = NULL;
	correctMoves = "H6";
	failed |= pieceMoveTest(pieces, numPieces, tpiece, correctMoves, correctNumMoves);
	
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

bool updateKnightMovesTest(){
	bool failed = false;
	//Test 1
	int numPieces = 2;
	Piece** pieces = new Piece*[numPieces];
	pieces[0] = new Piece((char*)"C5", true, knight);
	pieces[1] = new Piece((char*)"D7", false, knight);
	Piece* tpiece = pieces[0];
	int correctNumMoves = 8;
	char *correctMoves = new char[correctNumMoves * 2];
	correctMoves = "D7B7D3B3E6E4A6A4";
	failed |= pieceMoveTest(pieces, numPieces, tpiece, correctMoves, correctNumMoves);
	
	//Test 2
	numPieces = 2;
	pieces = new Piece*[numPieces];
	pieces[0] = new Piece((char*)"C5", true, knight);
	pieces[1] = new Piece((char*)"D7", true, knight);
	tpiece = pieces[0];
	correctNumMoves = 7;
	correctMoves = new char[correctNumMoves * 2];
	correctMoves = "B7D3B3E6E4A6A4";
	failed |= pieceMoveTest(pieces, numPieces, tpiece, correctMoves, correctNumMoves);
	
	return !failed;
}

bool updateBishopMovesTest(){
	bool failed = false;
	//Test 1
	Piece** state = new Piece*[64];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			state[(i * 8) + j] = NULL;
		}
	}
	state[(4 * 8) + 4] = new Piece((char*)"E5", true, bishop);
	Board x = Board(state);
	Piece *p = x.getPiece('E', 5 + '0');
	x.updatePieceMoves(p);
	int correctNumMoves = 13;
	char *correctMoves = new char[correctNumMoves * 2];
	correctMoves = "F6G7H8D4C3B2A1F4G3H2D6C7B8";
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
	//Test2
	state = new Piece*[64];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			state[(i * 8) + j] = NULL;
		}
	}
	state[(3 * 8) + 4] = new Piece((char*)"E4", false, bishop);
	state[(4 * 8) + 5] = new Piece((char*)"F5", false, pawn);
	state[(2 * 8) + 5] = new Piece((char*)"F3", true, pawn);
	x = Board(state);
	p = x.getPiece('E', 4 + '0');
	x.updatePieceMoves(p);
	correctNumMoves = 8;
	correctMoves = new char[correctNumMoves * 2];
	correctMoves = "D3C2B1F3D5C6B7A8";
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
	return !failed;
}

bool updateQueenMovesTest(){
	bool failed = false;
	//Test 1
	int numPieces = 2;
	Piece** pieces = new Piece*[numPieces];
	pieces[0] = new Piece((char*)"C5", true, queen);
	pieces[1] = new Piece((char*)"A7", false, knight);
	Piece* tpiece = pieces[0];
	int correctNumMoves = 25;
	char *correctMoves = new char[correctNumMoves * 2];
	correctMoves = "D6E7F8B4A3D4E3F2G1B6A7D5E5F5G5H5B5A5C6C7C8C4C3C2C1";
	failed |= pieceMoveTest(pieces, numPieces, tpiece, correctMoves, correctNumMoves);

	//Test 2
	numPieces = 2;
	pieces = new Piece*[numPieces];
	pieces[0] = new Piece((char*)"C5", true, queen);
	pieces[1] = new Piece((char*)"A7", true, knight);
	tpiece = pieces[0];
	correctNumMoves = 24;
	correctMoves = new char[correctNumMoves * 2];
	correctMoves = "D6E7F8B4A3D4E3F2G1B6D5E5F5G5H5B5A5C6C7C8C4C3C2C1";
	failed |= pieceMoveTest(pieces, numPieces, tpiece, correctMoves, correctNumMoves);
	
	return !failed;
}

bool updateKingMovesTest(){
	bool failed = false;
	//Test 1
	int numPieces = 3;
	Piece** pieces = new Piece*[numPieces];
	pieces[0] = new Piece((char*)"E1", true, king);
	pieces[1] = new Piece((char*)"A1", true, rook);
	pieces[2] = new Piece((char*)"H1", true, rook);
	Piece* tpiece = pieces[0];
	int correctNumMoves = 7;
	char *correctMoves = new char[correctNumMoves * 2];
	correctMoves = "F1D1E2F2D2B1G1";
	failed |= pieceMoveTest(pieces, numPieces, tpiece, correctMoves, correctNumMoves);

	//Test 2
	numPieces = 2;
	pieces = new Piece*[numPieces];
	pieces[0] = new Piece((char*)"E8", false, king);
	pieces[1] = new Piece((char*)"A8", false, rook);
	pieces[2] = new Piece((char*)"H8", false, rook);
	tpiece = pieces[0];
	correctNumMoves = 7;
	correctMoves = new char[correctNumMoves * 2];
	correctMoves = "F8D8E7D7F7B8G8";
	failed |= pieceMoveTest(pieces, numPieces, tpiece, correctMoves, correctNumMoves);
	return !failed;
}

bool checkTest(){
	bool failed = false;
	//Test 1
	Piece** state = new Piece*[64];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			state[(i * 8) + j] = NULL;
		}
	}
	state[(1 * 8) + 4] = new Piece((char*)"E2", true, rook);
	state[(0 * 8) + 4] = new Piece((char*)"E1", true, king);
	state[(7 * 8) + 4] = new Piece((char*)"E8", false, rook);
	Piece* tpiece = state[(1 * 8) + 4];
	Board* x = new Board(state);
	x->updatePieceMoves(tpiece);
	Board* newBoard = new Board(x);
	if(newBoard->score != 999){
		printf("Incorrect score %d, should be 999\n", newBoard->score);

	}
	//Test 2
	/*
	numPieces = 2;
	pieces = new Piece*[numPieces];
	pieces[0] = new Piece((char*)"E8", false, king);
	pieces[1] = new Piece((char*)"A8", false, rook);
	pieces[2] = new Piece((char*)"H8", false, rook);
	tpiece = pieces[0];
	correctNumMoves = 7;
	correctMoves = new char[correctNumMoves * 2];
	correctMoves = "F8D8E7D7F7B8G8";
	failed |= pieceMoveTest(pieces, numPieces, tpiece, correctMoves, correctNumMoves);
	*/
	return !failed;
}

bool makeBoardsTest(){
	bool failed = false;
	Board* x = new Board();
	Board** suc = x->makeBoards();
	int i = 0;
	while(suc[i] != NULL){
		i += 1;
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
	if(!updateKnightMovesTest()){
		printf("updateKnightMovesTest Failed\n");
	}
	if(!updateBishopMovesTest()){
		printf("updateBishopMovesTest Failed\n");
	}
	if(!updateQueenMovesTest()){
		printf("updateQueenMovesTest Failed\n");
	}
	if(!updateKingMovesTest()){
		printf("updateKingMovesTest Failed\n");
	}
	if(!checkTest()){
		printf("checkTestFailed\n");
	}
	if(!makeBoardsTest()){
		printf("makeBoardsTest failed\n");
	}
	printf("Finished tests\n");
	return 0;
}
