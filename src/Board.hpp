#pragma once
#include <cstddef>
#include "Piece.hpp"
#include <cstdio>
#include <cstring>

class Piece;

class Board{
	void initBoard();
	public:
	Board();
	Board(Piece** initState);
	Board(Board* b);
	int getScore();
	Board* pickSuccessor();
	Board** makeBoards();
	Piece** tiles; 
	Piece** whitePieces;
	Piece** blackPieces;
	int numWhitePieces = 0;
	int numBlackPieces = 0;
	Piece* whiteKing = NULL;
	Piece* blackKing = NULL;;
	int score = 0;
	bool whiteTurn = true;
	int depth;
	bool isEmpty(char col, char row);
	Piece* getPiece(char col, char row);
	void addMove(Piece *p, char col, char row);
	Board *makeMove(Piece *p, char* loc);
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
	void updateAllPieceMoves();
	void printBoard();
};
