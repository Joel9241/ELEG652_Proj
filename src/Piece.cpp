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

Piece::Piece(Piece* p){
	char* tmp = p->getPosition();
	position = new char[2];
	position[0] = tmp[0];
	position[1] = tmp[1];
	white = p->isWhite();
	type = p->getType();
	numMoves = p->numMoves;
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
	for(int i = 0; i < 2 * numMoves; i++){
		availableMoves[i] = p->availableMoves[i];
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

char* Piece::getIthMove(int i){
	char* tmp = new char[2];
	tmp[0] = availableMoves[2 * i];
	tmp[1] = availableMoves[(2 * i) + 1];
	return tmp;
}


