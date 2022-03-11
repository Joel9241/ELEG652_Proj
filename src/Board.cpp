#include "Board.hpp"

Board::Board(){
	initBoard();	
}

void Board::initBoard(){
	tiles[(0 * 8) + 0] = new Piece((char*)"A1", true, rook);	
	tiles[(0 * 8) + 7] = new Piece((char*)"H1", true, rook);
	tiles[(7 * 8) + 0] = new Piece((char*)"A8", false, rook);
	tiles[(7 * 8) + 7] = new Piece((char*)"A8", false, rook);
	tiles[(0 * 8) + 1] = new Piece((char*)"B1", true, knight);
	tiles[(0 * 8) + 6] = new Piece((char*)"G1", true, knight);
	tiles[(7 * 8) + 1] = new Piece((char*)"B8", false, knight);
	tiles[(7 * 8) + 6] = new Piece((char*)"G8", false, knight);
	tiles[(0 * 8) + 2] = new Piece((char*)"C1", true, bishop);
	tiles[(0 * 8) + 5] = new Piece((char*)"F1", true, bishop);
	tiles[(7 * 8) + 2] = new Piece((char*)"C8", false, bishop);
	tiles[(7 * 8) + 5] = new Piece((char*)"F8", false, bishop);
	tiles[(0 * 8) + 3] = new Piece((char*)"D1", true, queen);
	tiles[(0 * 8) + 4] = new Piece((char*)"E1", true, king);
	tiles[(7 * 8) + 3] = new Piece((char*)"D8", false, queen);
	tiles[(7 * 8) + 4] = new Piece((char*)"E8", false, king);
	tiles[(1 * 8) + 0] = new Piece((char*)"A2", true, pawn);
	tiles[(1 * 8) + 1] = new Piece((char*)"B2", true, pawn);
	tiles[(1 * 8) + 2] = new Piece((char*)"C2", true, pawn);
	tiles[(1 * 8) + 3] = new Piece((char*)"D2", true, pawn);
	tiles[(1 * 8) + 4] = new Piece((char*)"E2", true, pawn);
	tiles[(1 * 8) + 5] = new Piece((char*)"F2", true, pawn);
	tiles[(1 * 8) + 6] = new Piece((char*)"G2", true, pawn);
	tiles[(1 * 8) + 7] = new Piece((char*)"H2", true, pawn);
	tiles[(6 * 8) + 0] = new Piece((char*)"A7", false, pawn);
	tiles[(6 * 8) + 1] = new Piece((char*)"B7", false, pawn);
	tiles[(6 * 8) + 2] = new Piece((char*)"C7", false, pawn);
	tiles[(6 * 8) + 3] = new Piece((char*)"D7", false, pawn);
	tiles[(6 * 8) + 4] = new Piece((char*)"E7", false, pawn);
	tiles[(6 * 8) + 5] = new Piece((char*)"F7", false, pawn);
	tiles[(6 * 8) + 6] = new Piece((char*)"G7", false, pawn);
	tiles[(6 * 8) + 7] = new Piece((char*)"H7", false, pawn);
	for(int i = 2; i < 6; i++){
		for(int j = 0; j < 8; j++){
			tiles[(i * 8) + j] = NULL;
		}
	}
}

bool Board::isEmpty(char col, char row){
	return tiles[(((int) row - 49) * 8) + (((int) col) - 65)] == NULL;
}

Piece* Board::getPiece(char col, char row){
	if(isEmpty(col, row)){
		return NULL;
	}
	return tiles[(((int) row - 49) * 8) + (((int) col) - 65)];
}
