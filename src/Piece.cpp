#include "Piece.hpp"

Piece::Piece(char* position1, bool white1, PieceType type1, Board* board1){
	position = position1
	white = white1;
	type = type1;
	board = board1;
	if(type == pawn){
		availableMoves = new char[4 * 2];
		numMoves = 2;
	}
	else if(type == rook){
		availableMoves = new char[14 * 2];
		numMoves = 0;
	}
	else if(type == knight){
		availableMoves = new char[8 * 2];
		numMoves = 0;
	}
	else if(type == bishop){
		availableMoves = new char[13 * 2];
		numMoves = 0;
	}
	else if(type == king){
		availableMoves = new char[8 * 2];
		numMoves = 0;
	}
	else if(type == queen){
		availableMoves = new char[27 * 2];
		numMoves = 0;
	}
}

void Piece::updateAvailableMoves(){
	char column = position[0];
	char row = position[1];
	int numMoves = 0;
	//DONT FORGET TO SEE IF MOVE WOULD PUT IN CHECK BEFORE ALLOWING
	if(type == pawn){
		if(white){
			if(row == '2'){
				if(board->isEmpty(column, '3')){
					availableMoves[(numMoves * 2) + 1] = column;
					availableMoves[(numMoves * 2) + 2] = '3';
					numMoves++;
				}
				if(board->isEmpty(column, '4')){
					availableMoves[(numMoves * 2) + 1] = column;
					availableMoves[(numMoves * 2) + 2] = '4';
					numMoves++;
				}
			}
			else{
				if(board->isEmpty(column,  (char) (((int)row) + 1))){
					availableMoves[(numMoves * 2) + 1] = column;
					availableMoves[(numMoves * 2) + 2] = (char)(((int)row) + 1);
					numMoves++;
				}

			}
			if(column != '7'){
				if(board->isEmpty((char)((int)column + 1), (char)((int)row + 1))){
					availableMoves[(numMoves * 2) + 1] = 1;
					availableMoves[(numMoves * 2) + 2] = (char)((int)row + 1);
					numMoves++;
				}
			
			}
			else if(column != '0'){
				if(board->isEmpty((char)((int)column - 1), (char)((int)row + 1))){
					availableMoves[(numMoves * 2) + 1] = 6;
					availableMoves[(numMoves * 2) + 2] = (char)((int)row + 1);
					numMoves++;
				}

			}
		}
		else{
			if(row == '7'){
				if(board->isEmpty(column, '6')){
					availableMoves[(numMoves * 2) + 1] = column;
					availableMoves[(numMoves * 2) + 2] = '6';
					numMoves++;
				}
				if(board->isEmpty(column, '5')){
					availableMoves[(numMoves * 2) + 1] = column;
					availableMoves[(numMoves * 2) + 2] = '5';
					numMoves++;
				}
			}
			else{
				if(board->isEmpty(column, (char) (((int)row) - 1))){
					availableMoves[(numMoves * 2) + 1] = column;
					availableMoves[(numMoves * 2) + 2] = (char)(((int)row) - 1);
					numMoves++;
				}

			}
			if(column != '7'){
				if(board->isEmpty((char)((int)column + 1), (char)((int)row - 1))){
					availableMoves[(numMoves * 2) + 1] = (char)((int)column + 1);
					availableMoves[(numMoves * 2) + 2] = (char)((int)row - 1);
					numMoves++;
				}
			
			}
			else if(column != '0'){
				if(board->isEmpty((char)((int)column - 1), (char)((int)row - 1))){
					availableMoves[(numMoves * 2) + 1] = (char)((int)column - 1);
					availableMoves[(numMoves * 2) + 2] = (char)((int)row - 1);
					numMoves++;
				}

			}

		}
	}
	else if(type == rook){
		int col = (int)position[0];
		int row = (int)position[1];
		int colOffset = 1;
		int rowOffset = 0;
		while(board->isEmpty((char)(col + colOffset), (char)(row + rowOffset)) && (col + colOffset < 8)){
			availableMoves[(numMoves * 2) + 1] = (char)(col + colOffset);
			availableMoves[(numMoves * 2) + 2] = (char)(row + rowOffset);
			numMoves++;
			colOffset++;
		}
		colOffset = 1;
		while(board->isEmpty((char)(col - colOffset), (char)(row + rowOffset)) && (col - colOffset > 0)){
			availableMoves[(numMoves * 2) + 1] = (char)(col - colOffset);
			availableMoves[(numMoves * 2) + 2] = (char)(row + rowOffset);
			numMoves++;
			colOffset++;
		}
		colOffset = 0;
		rowOffset = 1;
		while(board->isEmpty((char)(col + colOffset), (char)(row + rowOffset)) && (row + rowOffset < 8)){
			availableMoves[(numMoves * 2) + 1] = (char)(col + colOffset);
			availableMoves[(numMoves * 2) + 2] = (char)(row + rowOffset);
			numMoves++;
			rowOffset++;
		}
		rowOffset = 1;
		while(board->isEmpty((char)(col + colOffset), (char)(row - rowOffset)) && (row - rowOffset > 0)){
			availableMoves[(numMoves * 2) + 1] = (char)(col + colOffset);
			availableMoves[(numMoves * 2) + 2] = (char)(row - rowOffset);
			numMoves++;
			rowOffset++;
		}
	}
	else if(type == knight){

	}
	else if(type == bishop){

	}
	else if(type == king){

	}
	else if(type == queen){

	}
}
