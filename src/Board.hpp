#pragma once
#include "Piece.hpp"

class Piece;

class Board{
	Board();
	void initBoard();
	public:
	bool isEmpty(char col, char row);
};
