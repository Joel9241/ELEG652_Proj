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
	char* availableMoves;
	int numMoves;
	static constexpr char cols[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	public:
	Piece(char* position1, bool white1, PieceType type1);
	char* getPosition();
	bool isWhite();
	PieceType getType();
};
