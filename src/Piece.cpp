#include "Piece.hpp"

Piece::Piece(char* position1, bool white1, PieceType type1){
	position = position1;
	white = white1;
	type = type1;
	numMoves = 0;
	if(type == pawn){
		availableMoves = new char[4 * 2];
	}
	else if(type == rook){
		availableMoves = new char[14 * 2];
	}
	else if(type == knight){
		availableMoves = new char[8 * 2];
	}
	else if(type == bishop){
		availableMoves = new char[13 * 2];
	}
	else if(type == king){
		availableMoves = new char[8 * 2];
	}
	else if(type == queen){
		availableMoves = new char[27 * 2];
	}
}

char* Piece::getPosition(){
	return position;
}

bool Piece::isWhite(){
	return white;
}

PieceType Piece::getType(){
	return type;
}

