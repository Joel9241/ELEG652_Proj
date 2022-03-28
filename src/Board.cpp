#include "Board.hpp"

Board::Board(){
	initBoard();	
}

Board::Board(Piece** initState){
	tiles = initState;
}

void Board::initBoard(){
	tiles = new Piece*[64];
	tiles[(0 * 8) + 0] = new Piece((char*)"A1", true, rook);	
	tiles[(0 * 8) + 7] = new Piece((char*)"H1", true, rook);
	tiles[(7 * 8) + 0] = new Piece((char*)"A8", false, rook);
	tiles[(7 * 8) + 7] = new Piece((char*)"A8", false, rook);
	tiles[(0 * 8) + 1] = new Piece((char*)"B1", true, knight);
	tiles[(0 * 8) + 6] = new Piece((char*)"G1", true, knight);
	tiles[(7 * 8) + 1] = new Piece((char*)"B8", false, knight);
	tiles[(7 * 8) + 6] = new Piece((char*)"G8", false, knight);
	tiles[(0 * 8) + 2] = new Piece((char*)"C1", true, bishop);
	tiles[(0 * 8) + 5] = new Piece((char*)"F1", true, bishop);
	tiles[(7 * 8) + 2] = new Piece((char*)"C8", false, bishop);
	tiles[(7 * 8) + 5] = new Piece((char*)"F8", false, bishop);
	tiles[(0 * 8) + 3] = new Piece((char*)"D1", true, queen);
	tiles[(0 * 8) + 4] = new Piece((char*)"E1", true, king);
	tiles[(7 * 8) + 3] = new Piece((char*)"D8", false, queen);
	tiles[(7 * 8) + 4] = new Piece((char*)"E8", false, king);
	tiles[(1 * 8) + 0] = new Piece((char*)"A2", true, pawn);
	tiles[(1 * 8) + 1] = new Piece((char*)"B2", true, pawn);
	tiles[(1 * 8) + 2] = new Piece((char*)"C2", true, pawn);
	tiles[(1 * 8) + 3] = new Piece((char*)"D2", true, pawn);
	tiles[(1 * 8) + 4] = new Piece((char*)"E2", true, pawn);
	tiles[(1 * 8) + 5] = new Piece((char*)"F2", true, pawn);
	tiles[(1 * 8) + 6] = new Piece((char*)"G2", true, pawn);
	tiles[(1 * 8) + 7] = new Piece((char*)"H2", true, pawn);
	tiles[(6 * 8) + 0] = new Piece((char*)"A7", false, pawn);
	tiles[(6 * 8) + 1] = new Piece((char*)"B7", false, pawn);
	tiles[(6 * 8) + 2] = new Piece((char*)"C7", false, pawn);
	tiles[(6 * 8) + 3] = new Piece((char*)"D7", false, pawn);
	tiles[(6 * 8) + 4] = new Piece((char*)"E7", false, pawn);
	tiles[(6 * 8) + 5] = new Piece((char*)"F7", false, pawn);
	tiles[(6 * 8) + 6] = new Piece((char*)"G7", false, pawn);
	tiles[(6 * 8) + 7] = new Piece((char*)"H7", false, pawn);
	for(int i = 2; i < 6; i++){
		for(int j = 0; j < 8; j++){
			tiles[(i * 8) + j] = NULL;
		}
	}
}

bool Board::isEmpty(char col, char row){
	return tiles[(((int) row - 49) * 8) + (((int) col) - 65)] == NULL;
}

Piece* Board::getPiece(char col, char row){
	if(isEmpty(col, row)){
		return NULL;
	}
	return tiles[(((int) row - 49) * 8) + (((int) col) - 65)];
}

//Don't forget to check for checks
void Board::updatePieceMoves(Piece* p){
	PieceType type = p->getType();
	if(type == pawn){
		updatePawnMoves(p);
	}
	else if(type == rook){
		updateRookMoves(p);	
	}
	else if(type == knight){

	}
	else if(type == bishop){
		updateBishopMoves(p);
	}
	else if(type == king){

	}
	else if(type == queen){

	}

}

void Board::updatePawnMoves(Piece* p){
	char column = p->getPosition()[0];
	char row = p->getPosition()[1];
	if(p->isWhite()){
		if(row == '2'){
			if(isEmpty(column, '3')){
				p->availableMoves[(p->numMoves * 2)] = column;
				p->availableMoves[(p->numMoves * 2) + 1] = '3';
				p->numMoves++;
				if(isEmpty(column, '4')){
					p->availableMoves[(p->numMoves * 2)] = column;
					p->availableMoves[(p->numMoves * 2) + 1] = '4';
					p->numMoves++;
				}
			}
		}
		else{
			if(isEmpty(column, (char) (((int)row) + 1))){
				p->availableMoves[(p->numMoves * 2)] = column;
				p->availableMoves[(p->numMoves * 2) + 1] = (char)(((int)row) + 1);
				p->numMoves++;
			}

		}
		if(column != 'H'){
			if(!isEmpty((char)((int)column + 1), (char)((int)row + 1))){
				if(!getPiece((char)((int)column + 1), (char)((int)row + 1))->isWhite()){
					p->availableMoves[(p->numMoves * 2)] = (char)((int)column + 1);
					p->availableMoves[(p->numMoves * 2) + 1] = (char)((int)row + 1);
					p->numMoves++;
				}
			}
		
		}
		if(column != 'A'){
			if(!isEmpty((char)((int)column - 1), (char)((int)row + 1))){
				if(!getPiece((char)((int)column - 1), (char)((int)row + 1))->isWhite()){
					p->availableMoves[(p->numMoves * 2)] = (char)((int)column - 1);
					p->availableMoves[(p->numMoves * 2) + 1] = (char)((int)row + 1);
					p->numMoves++;
				}
			}
		}
	}
	else{
		if(row == '7'){
			if(isEmpty(column, '6')){
				p->availableMoves[(p->numMoves * 2)] = column;
				p->availableMoves[(p->numMoves * 2) + 1] = '6';
				p->numMoves++;
				if(isEmpty(column, '5')){
					p->availableMoves[(p->numMoves * 2)] = column;
					p->availableMoves[(p->numMoves * 2) + 1] = '5';
					p->numMoves++;
				}
			}
		}
		else{
			if(isEmpty(column, (char) (((int)row) - 1))){
				p->availableMoves[(p->numMoves * 2)] = column;
				p->availableMoves[(p->numMoves * 2) + 1] = (char)(((int)row) - 1);
				p->numMoves++;
			}
		}
		if(column != 'H'){
			if(!isEmpty((char)((int)column + 1), (char)((int)row - 1))){
				if(getPiece((char)((int)column + 1), (char)((int)row - 1))->isWhite()){
					p->availableMoves[(p->numMoves * 2)] = (char)((int)column + 1);
					p->availableMoves[(p->numMoves * 2) + 1] = (char)((int)row - 1);
					p->numMoves++;
				}
			}
		
		}
		if(column != 'A'){
			if(!isEmpty((char)((int)column - 1), (char)((int)row - 1))){
				if(getPiece((char)((int)column - 1), (char)((int)row - 1))->isWhite()){
					p->availableMoves[(p->numMoves * 2)] = (char)((int)column - 1);
					p->availableMoves[(p->numMoves * 2) + 1] = (char)((int)row - 1);
					p->numMoves++;
				}
			}
		}
	}
}

void Board::updateRookMoves(Piece *p){
	char col = (int)p->getPosition()[0];
	char row = (int)p->getPosition()[1];
	int colOffset = 1;
	int rowOffset = 0;
	while(isEmpty((char)((int)col + colOffset), (char)((int)row + rowOffset)) && ((int)col - 65 + colOffset < 8)){
		p->availableMoves[p->numMoves * 2] = (char)(col + colOffset);
		p->availableMoves[p->numMoves * 2 + 1] = (char)(row + rowOffset);
		p->numMoves++;
		colOffset++;
	}
	if((int)col - 65 + colOffset < 8){
		if(!isEmpty((char)((int)col + colOffset), (char)((int)row + rowOffset))){
			if(getPiece((char)((int)col + colOffset), (char)((int)row + rowOffset))->isWhite() != p->isWhite()){
				p->availableMoves[p->numMoves * 2] = (char)(col + colOffset);
				p->availableMoves[p->numMoves * 2 + 1] = (char)(row + rowOffset);
				p->numMoves++;
			}
		}
	}
	colOffset = 1;
	while(isEmpty((char)((int)col - colOffset), (char)((int)row + rowOffset)) && ((int)col - 65 - colOffset >= 0)){
		p->availableMoves[p->numMoves * 2] = (char)(col - colOffset);
		p->availableMoves[p->numMoves * 2 + 1] = (char)(row + rowOffset);
		p->numMoves++;
		colOffset++;
	}
	if((int)col - 65 - colOffset >= 0){
		if(!isEmpty((char)((int)col - colOffset), (char)((int)row + rowOffset))){
			if(getPiece((char)((int)col - colOffset), (char)((int)row + rowOffset))->isWhite() != p->isWhite()){
				p->availableMoves[p->numMoves * 2] = (char)(col + colOffset);
				p->availableMoves[p->numMoves * 2 + 1] = (char)(row + rowOffset);
				p->numMoves++;
			}
		}
	}
	colOffset = 0;
	rowOffset = 1;
	while(isEmpty((char)((int)col + colOffset), (char)((int)row + rowOffset)) && ((int)row - 49 + rowOffset < 8)){
		p->availableMoves[p->numMoves * 2] = (char)(col + colOffset);
		p->availableMoves[p->numMoves * 2 + 1] = (char)(row + rowOffset);
		p->numMoves++;
		rowOffset++;
	}
	if(((int)row - 49 + rowOffset < 8)){
		if(!isEmpty((char)((int)col + colOffset), (char)((int)row + rowOffset))){
			if(getPiece((char)((int)col + colOffset), (char)((int)row + rowOffset))->isWhite() != p->isWhite()){
				p->availableMoves[p->numMoves * 2] = (char)(col + colOffset);
				p->availableMoves[p->numMoves * 2 + 1] = (char)(row + rowOffset);
				p->numMoves++;
			}
		}
	}
	rowOffset = 1;
	while(isEmpty((char)((int)col + colOffset), (char)((int)row - rowOffset)) && ((int)row - 49 - rowOffset >= 0)){
		p->availableMoves[p->numMoves * 2] = (char)(col + colOffset);
		p->availableMoves[p->numMoves * 2 + 1] = (char)(row - rowOffset);
		p->numMoves++;
		rowOffset++;
	}
	if(((int)row - 49 - rowOffset >= 0)){
		if(!isEmpty((char)((int)col + colOffset), (char)((int)row - rowOffset))){
			if(getPiece((char)((int)col + colOffset), (char)((int)row - rowOffset))->isWhite() != p->isWhite()){
				p->availableMoves[p->numMoves * 2] = (char)(col + colOffset);
				p->availableMoves[p->numMoves * 2 + 1] = (char)(row + rowOffset);
				p->numMoves++;
			}
		}
	}
}

void Board::updateBishopMoves(Piece *p){
	char col = (int)p->getPosition()[0];
	char row = (int)p->getPosition()[1];
	int colOffset = 1;
	int rowOffset = 1;
	while(isEmpty((char)((int)col + colOffset), (char)((int)row + rowOffset)) && ((int)col - 65 + colOffset < 8)){
		p->availableMoves[p->numMoves * 2] = (char)(col + colOffset);
		p->availableMoves[p->numMoves * 2 + 1] = (char)(row + rowOffset);
		p->numMoves++;
		colOffset++;
		rowOffset++;
	}
	if(((int)col - 65 + colOffset < 8) && ((int)row - 49 + rowOffset < 8)){
		if(!isEmpty((char)((int)col + colOffset), (char)((int)row + rowOffset))){
			if(getPiece((char)((int)col + colOffset), (char)((int)row + rowOffset))->isWhite() != p->isWhite()){
				p->availableMoves[p->numMoves * 2] = (char)(col + colOffset);
				p->availableMoves[p->numMoves * 2 + 1] = (char)(row + rowOffset);
				p->numMoves++;
			}
		}
	}
	colOffset = 1;
	rowOffset = 1;
	while(((int)col - 65 - colOffset >= 0) && ((int)row - 49 - rowOffset >= 0) && isEmpty((char)((int)col - colOffset), (char)((int)row - rowOffset))){
		p->availableMoves[p->numMoves * 2] = (char)(col - colOffset);
		p->availableMoves[p->numMoves * 2 + 1] = (char)(row - rowOffset);
		p->numMoves++;
		colOffset++;
		rowOffset++;
	}
	if(((int)col - 65 - colOffset >= 0) && ((int)row - 49 - rowOffset >= 0)){
		if(!isEmpty((char)((int)col - colOffset), (char)((int)row - rowOffset))){
			if(getPiece((char)((int)col - colOffset), (char)((int)row - rowOffset))->isWhite() != p->isWhite()){
				p->availableMoves[p->numMoves * 2] = (char)(col - colOffset);
				p->availableMoves[p->numMoves * 2 + 1] = (char)(row - rowOffset);
				p->numMoves++;
			}
		}
	}
	colOffset = 1;
	rowOffset = 1;
	while(((int)col - 65 + colOffset < 8) && ((int)row - 49 - rowOffset >= 0) && isEmpty((char)((int)col + colOffset), (char)((int)row - rowOffset))){
		p->availableMoves[p->numMoves * 2] = (char)(col + colOffset);
		p->availableMoves[p->numMoves * 2 + 1] = (char)(row - rowOffset);
		p->numMoves++;
		colOffset++;
		rowOffset++;
	}
	if(((int)col - 65 + colOffset < 8) && ((int)row - 49 - rowOffset >= 0)){
		if(!isEmpty((char)((int)col + colOffset), (char)((int)row - rowOffset))){
			if(getPiece((char)((int)col + colOffset), (char)((int)row - rowOffset))->isWhite() != p->isWhite()){
				p->availableMoves[p->numMoves * 2] = (char)(col + colOffset);
				p->availableMoves[p->numMoves * 2 + 1] = (char)(row - rowOffset);
				p->numMoves++;
			}
		}
	}
	colOffset = 1;
	rowOffset = 1;
	while(((int)col - 65 - colOffset >= 0) && ((int)row - 49 + rowOffset < 8) && isEmpty((char)((int)col - colOffset), (char)((int)row + rowOffset))){
		p->availableMoves[p->numMoves * 2] = (char)(col - colOffset);
		p->availableMoves[p->numMoves * 2 + 1] = (char)(row + rowOffset);
		p->numMoves++;
		colOffset++;
		rowOffset++;
	}
	if(((int)col - 65 - colOffset >= 0) && ((int)row - 49 + rowOffset < 8)){
		if(!isEmpty((char)((int)col - colOffset), (char)((int)row + rowOffset))){
			if(getPiece((char)((int)col - colOffset), (char)((int)row + rowOffset))->isWhite() != p->isWhite()){
				p->availableMoves[p->numMoves * 2] = (char)(col - colOffset);
				p->availableMoves[p->numMoves * 2 + 1] = (char)(row + rowOffset);
				p->numMoves++;
			}
		}
	}
}
