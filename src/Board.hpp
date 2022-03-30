#pragma once
#include <cstddef>
#include "Piece.hpp"
#include <cstdio>

class Piece;

class Board{
	void initBoard();
	public:
	Board();
	Board(Piece** initState);
	Piece** tiles; //should be private here for testing purposes
	bool isEmpty(char col, char row);
	Piece* getPiece(char col, char row);
	void addMove(Piece *p, char col, char row);
	void updatePieceMoves(Piece *p);
	void updatePawnMoves(Piece *p);
	void updateRookMoves(Piece *p);
	void updateKnightMoves(Piece *p);
	void updateBishopMoves(Piece *p);
	void updateQueenMoves(Piece *p);
	void updateKingMoves(Piece *p);
	bool whiteKingMoved = false;
	bool blackKingMoved = false;
	bool whiteLeftRookMoved = false;
	bool whiteRightRookMoved = false;
	bool blackLeftRookMoved = false;
	bool blackRightRookMoved = false;
};
