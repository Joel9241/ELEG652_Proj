#pragma once
#include "Board.hpp"

class Board;

enum PieceType{
	pawn, rook, knight, bishop, queen, king
};

class Piece{
	char* position;
	bool white;
	PieceType type; 
	Board* board;
	char* availableMoves;
	int numMoves;
	static const char cols[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	Piece(char* position1, bool white1, PieceType type1, Board* board);
	void updateAvailableMoves();
};
