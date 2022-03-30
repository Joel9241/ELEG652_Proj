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
	static constexpr char cols[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	public:
	char* availableMoves;
	Piece(char* position1, bool white1, PieceType type1);
	char* getPosition();
	bool isWhite();
	PieceType getType();
	int numMoves;
};
