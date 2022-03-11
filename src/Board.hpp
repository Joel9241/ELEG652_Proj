#pragma once
#include <cstddef>
#include "Piece.hpp"
#include <cstdio>

class Piece;

class Board{
	void initBoard();
	public:
	Board();
	Piece** tiles = new Piece*[64]; //should be private here for testing purposes
	bool isEmpty(char col, char row);
	Piece* getPiece(char col, char row);
};
