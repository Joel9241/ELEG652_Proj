#pragma once
#include "Board.hpp"

class Board;

enum PieceType{
	pawn, rook, knight, bishop, queen, king
};

class Piece{
	bool white;
	static constexpr char cols[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	public:
	char* position;
	PieceType type; 
	char* availableMoves;
	char* getIthMove(int i);
	Piece(char* position1, bool white1, PieceType type1);
	Piece(Piece* p);
	char* getPosition();
	bool isWhite();
	PieceType getType();
	int numMoves;
	int value;
};
