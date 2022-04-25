#include "Board.hpp"

Board::Board(){
	initBoard();
	updateAllPieceMoves();
}

Board::Board(Piece** initState){
	tiles = initState;
	whitePieces = new Piece*[16];
	blackPieces = new Piece*[16];
	int wIndex = 0;
	int bIndex = 0;
	Piece *tmp;
	int tmpScore;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			tmpScore = 1;
			if(!isEmpty(i + 65, j + 49)){
				tmp = getPiece(i + 65, j + 49);	
				if(tmp->isWhite()){
					whitePieces[wIndex] = tmp;
					wIndex++;
					if(tmp->type == king){
						whiteKing = tmp;
					}
				}
				else{
					tmpScore = -1;
					blackPieces[bIndex] = tmp;
					bIndex++;
					if(tmp->type == king){
						blackKing = tmp;
					}
				}
				score += tmpScore * tmp->value;
			}
		}
	}
	numWhitePieces = wIndex;
	numBlackPieces = bIndex;
}

Board::Board(Board* b){
	tiles = new Piece*[64];
	//needs to make full copy of piece
	for(int i = 0; i < 64; i++){
		if(b->tiles[i] == NULL){
			tiles[i] = NULL;
		}
		else{
			tiles[i] = new Piece(b->tiles[i]);
		}
		//tiles[i] = b->tiles[i];
	}
	whitePieces = new Piece*[16];
	blackPieces = new Piece*[16];
	int wIndex = 0;
	int bIndex = 0;
	Piece *tmp;
	int tmpScore;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			tmpScore = 1;
			if(!isEmpty(i + 65, j + 49)){
				tmp = getPiece(i + 65, j + 49);	
				if(tmp->isWhite()){
					whitePieces[wIndex] = tmp;
					wIndex++;
					if(tmp->type == king){
						whiteKing = tmp;
					}
				}
				else{
					tmpScore = -1;
					blackPieces[bIndex] = tmp;
					bIndex++;
					if(tmp->type == king){
						blackKing = tmp;
					}
				}
				score += tmpScore * tmp->value;
			}
		}
	}
	numWhitePieces = wIndex;
	numBlackPieces = bIndex;
}

Board** Board::makeBoards(){
	int numboards = 0;
	for(int i = 0; i < numWhitePieces; i++){
		numboards += whitePieces[i]->numMoves;
	}
	for(int i = 0; i < numBlackPieces; i++){
		numboards += blackPieces[i]->numMoves;
	}
	Board** successors = new Board*[numboards + 1];
	successors[numboards] = NULL;
	int i = 0;
	int wPieceIndex = 0;
	int bPieceIndex = 0;
	while(i < numboards){
		int tmp;
		if(wPieceIndex != numWhitePieces){
			tmp = whitePieces[wPieceIndex]->numMoves;
		}
		else{
			tmp = blackPieces[bPieceIndex]->numMoves;
		}
		int j = 0; 
		while(j < tmp){
			if(wPieceIndex != numWhitePieces){
				successors[i] = makeMove(whitePieces[wPieceIndex], whitePieces[wPieceIndex]->getIthMove(j));
			}
			else{
				successors[i] = makeMove(blackPieces[bPieceIndex], blackPieces[bPieceIndex]->getIthMove(j));
			}
			j += 1;
			i += 1;
		}
		if(wPieceIndex != numWhitePieces){
			wPieceIndex += 1;
		}
		else{
			bPieceIndex += 1;	
		}
	}
	return successors;
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
	whitePieces = new Piece*[16];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 2; j++){
			whitePieces[(j * 8) + i] = tiles[(j * 8) + i];
		}
	}
	blackPieces = new Piece*[16];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 2; j++){
			blackPieces[(j * 8) + i] = tiles[((7 - j) * 8) + i];
		}
	}
	score = 0;
	whiteKing = tiles[(0 * 8) + 4];
	blackKing = tiles[(7 * 8) + 4];
	numWhitePieces = 16;
	numBlackPieces = 16;
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

void Board::addMove(Piece *p, char col, char row){
	p->availableMoves[(p->numMoves * 2)] = col;
	p->availableMoves[(p->numMoves * 2) + 1] = row;
	p->numMoves++;
}


//function does not work
Board* Board::makeMove(Piece* p, char* loc){
	Board* newBoard = new Board(this);
	char* pos = p->getPosition();
	char col = pos[0];
	char row = pos[1];
	Piece* newP = newBoard->getPiece(col, row);
	if(isEmpty(loc[0], loc[1])){
		newP->position = new char[2];
		newP->position[0] = col;
		newP->position[1] = row;
	}
	else{
		Piece* del = newBoard->getPiece(loc[0], loc[1]);
		int delIndex;
		int numPieces;
		Piece** tmp;
		int tmpScore = 1;
		if(del->isWhite()){
			numPieces = numWhitePieces;
			tmp = newBoard->whitePieces;
			newBoard->numWhitePieces--;
			tmpScore = -1;
		}
		else{
			numPieces = numBlackPieces;
			tmp = newBoard->blackPieces;
			newBoard->numBlackPieces--;
		}
		for(int i = 0; i < numPieces; i++){
			if(strcmp(del->getPosition(), tmp[i]->getPosition()) == 0){
				delIndex = i;
				break;
			}
		}
		for(int i = delIndex; i < numPieces; i++){
			tmp[i] = tmp[i + 1];
		}
		newBoard->score += (tmpScore * del->value);
	}
	
	//Piece* tmp;
	//char* tmpPosition;
	//char* kingPosition;
	//should just be call to all updatePieceMoves
	newBoard->updateAllPieceMoves();
	return newBoard;
	/*
	if(newP->isWhite()){
		for(int i = 0; i < newBoard->numWhitePieces; i++){
			newBoard->updatePieceMoves(newBoard->whitePieces[i]);
		}
		for(int i = 0; i < newBoard->numBlackPieces; i++){
			tmp = newBoard->blackPieces[i];
			newBoard->updatePieceMoves(tmp);
			for(int j = 0; j < tmp->numMoves; j++){
				tmpPosition = tmp->getPosition();
				kingPosition = newBoard->whiteKing->getPosition();
				if((tmpPosition[0] == kingPosition[0]) && (tmpPosition[1] == kingPosition[1])){
					newBoard->score = -99999;
					return newBoard;
				}
			}
		}

	}
	else{
		for(int i = 0; i < newBoard->numWhitePieces; i++){
			tmp = newBoard->whitePieces[i];
			newBoard->updatePieceMoves(tmp);
			for(int j = 0; j < tmp->numMoves; j++){
				tmpPosition = tmp->getPosition();
				kingPosition = newBoard->blackKing->getPosition();
				if((tmpPosition[0] == kingPosition[0]) && (tmpPosition[1] == kingPosition[1])){
					newBoard->score = 99999;
					return newBoard;
				}
			}
		}
		for(int i = 0; i < newBoard->numBlackPieces; i++){
			newBoard->updatePieceMoves(newBoard->blackPieces[i]);
			return newBoard;
		}
	}
	*/
	return newBoard;
}

void Board::updateAllPieceMoves(){
	for(int i = 0; i < numWhitePieces; i++){
		updatePieceMoves(whitePieces[i]);
	}
	for(int i = 0; i < numBlackPieces; i++){
		updatePieceMoves(blackPieces[i]);
	}
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
		updateKnightMoves(p);
	}
	else if(type == bishop){
		updateBishopMoves(p);
	}
	else if(type == king){
		updateKingMoves(p);
	}
	else if(type == queen){
		updateBishopMoves(p);
		updateRookMoves(p);
	}
}

void Board::updatePawnMoves(Piece* p){
	char column = p->getPosition()[0];
	char row = p->getPosition()[1];
	if(p->isWhite()){
		if(row == '2'){
			if(isEmpty(column, '3')){
				addMove(p, column, '3');
				if(isEmpty(column, '4')){
					addMove(p, column, '4');
				}
			}
		}
		else{
			if(isEmpty(column, (char) (((int)row) + 1))){
				addMove(p, column, (char)(((int)row) + 1));
			}

		}
		if(column != 'H'){
			if(!isEmpty((char)((int)column + 1), (char)((int)row + 1))){
				if(!getPiece((char)((int)column + 1), (char)((int)row + 1))->isWhite()){
					addMove(p, (char)((int)column + 1), (char)((int)row + 1));
				}
			}
		}
		if(column != 'A'){
			if(!isEmpty((char)((int)column - 1), (char)((int)row + 1))){
				if(!getPiece((char)((int)column - 1), (char)((int)row + 1))->isWhite()){
					addMove(p, (char)((int)column - 1), (char)((int)row + 1));
				}
			}
		}
	}
	else{
		if(row == '7'){
			if(isEmpty(column, '6')){
				addMove(p, column, '6');
				if(isEmpty(column, '5')){
					addMove(p, column, '5');
				}
			}
		}
		else{
			if(isEmpty(column, (char) (((int)row) - 1))){
				addMove(p, column, (char)(((int)row) - 1));
			}
		}
		if(column != 'H'){
			if(!isEmpty((char)((int)column + 1), (char)((int)row - 1))){
				if(getPiece((char)((int)column + 1), (char)((int)row - 1))->isWhite()){
					addMove(p, (char)((int)column + 1), (char)((int)row - 1));
				}
			}
		}
		if(column != 'A'){
			if(!isEmpty((char)((int)column - 1), (char)((int)row - 1))){
				if(getPiece((char)((int)column - 1), (char)((int)row - 1))->isWhite()){
					addMove(p, (char)((int)column - 1), (char)((int)row - 1));
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
		addMove(p, (char)(col + colOffset), (char)(row + rowOffset));
		colOffset++;
	}
	if((int)col - 65 + colOffset < 8){
		if(!isEmpty((char)((int)col + colOffset), (char)((int)row + rowOffset))){
			if(getPiece((char)((int)col + colOffset), (char)((int)row + rowOffset))->isWhite() != p->isWhite()){
				addMove(p, (char)(col + colOffset), (char)(row + rowOffset));
			}
		}
	}
	colOffset = 1;
	while(isEmpty((char)((int)col - colOffset), (char)((int)row + rowOffset)) && ((int)col - 65 - colOffset >= 0)){
		addMove(p, (char)(col - colOffset), (char)(row + rowOffset));
		colOffset++;
	}
	if((int)col - 65 - colOffset >= 0){
		if(!isEmpty((char)((int)col - colOffset), (char)((int)row + rowOffset))){
			if(getPiece((char)((int)col - colOffset), (char)((int)row + rowOffset))->isWhite() != p->isWhite()){
				addMove(p, (char)(col - colOffset), (char)(row + rowOffset));
			}
		}
	}
	colOffset = 0;
	rowOffset = 1;
	while(isEmpty((char)((int)col + colOffset), (char)((int)row + rowOffset)) && ((int)row - 49 + rowOffset < 8)){
		addMove(p, (char)(col + colOffset), (char)(row + rowOffset));
		rowOffset++;
	}
	if(((int)row - 49 + rowOffset < 8)){
		if(!isEmpty((char)((int)col + colOffset), (char)((int)row + rowOffset))){
			if(getPiece((char)((int)col + colOffset), (char)((int)row + rowOffset))->isWhite() != p->isWhite()){
				addMove(p, (char)(col + colOffset), (char)(row + rowOffset));
			}
		}
	}
	rowOffset = 1;
	while(isEmpty((char)((int)col + colOffset), (char)((int)row - rowOffset)) && ((int)row - 49 - rowOffset >= 0)){
		addMove(p, (char)(col + colOffset), (char)(row - rowOffset));
		rowOffset++;
	}
	if(((int)row - 49 - rowOffset >= 0)){
		if(!isEmpty((char)((int)col + colOffset), (char)((int)row - rowOffset))){
			if(getPiece((char)((int)col + colOffset), (char)((int)row - rowOffset))->isWhite() != p->isWhite()){
				addMove(p, (char)(col + colOffset), (char)(row - rowOffset));
			}
		}
	}
}

void Board::updateKnightMoves(Piece *p){
	char col = (int)p->getPosition()[0];
	char row = (int)p->getPosition()[1];
	int colOffsets[8] = {1, -1, 1, -1, 2, 2, -2, -2};
	int rowOffsets[8] = {2, 2, -2, -2, 1, -1, 1, -1};
	int colOffset;
	int rowOffset;
	int icol;
	int irow;
	for(int i = 0; i < 8; i++){
		colOffset = colOffsets[i];
		rowOffset = rowOffsets[i];
		icol = (int)col - 65 + colOffset;
		irow = (int)row - 49 + rowOffset;
		if((icol < 8) && (icol >= 0) && (irow < 8) && (irow >= 0)){
			if(isEmpty((char)((int)col + colOffset), (char)((int)row + rowOffset))){
				addMove(p, (char)(col + colOffset), (char)(row + rowOffset));
			}
			else if(getPiece((char)((int)col + colOffset), (char)((int)row + rowOffset))->isWhite() != p->isWhite()){
				addMove(p, (char)(col + colOffset), (char)(row + rowOffset));
			}
		}
	}
}

void Board::updateBishopMoves(Piece *p){
	char col = (int)p->getPosition()[0];
	char row = (int)p->getPosition()[1];
	int colOffset = 1;
	int rowOffset = 1;
	while(((int)col - 65 + colOffset < 8) && ((int)row - 49 + rowOffset < 8) && isEmpty((char)((int)col + colOffset), (char)((int)row + rowOffset))){
		addMove(p, (char)(col + colOffset), (char)(row + rowOffset));
		colOffset++;
		rowOffset++;
	}
	if(((int)col - 65 + colOffset < 8) && ((int)row - 49 + rowOffset < 8)){
		if(!isEmpty((char)((int)col + colOffset), (char)((int)row + rowOffset))){
			if(getPiece((char)((int)col + colOffset), (char)((int)row + rowOffset))->isWhite() != p->isWhite()){
				addMove(p, (char)(col + colOffset), (char)(row + rowOffset));
			}
		}
	}
	colOffset = 1;
	rowOffset = 1;
	while(((int)col - 65 - colOffset >= 0) && ((int)row - 49 - rowOffset >= 0) && isEmpty((char)((int)col - colOffset), (char)((int)row - rowOffset))){
		addMove(p, (char)(col - colOffset), (char)(row - rowOffset));
		colOffset++;
		rowOffset++;
	}
	if(((int)col - 65 - colOffset >= 0) && ((int)row - 49 - rowOffset >= 0)){
		if(!isEmpty((char)((int)col - colOffset), (char)((int)row - rowOffset))){
			if(getPiece((char)((int)col - colOffset), (char)((int)row - rowOffset))->isWhite() != p->isWhite()){
				addMove(p, (char)(col - colOffset), (char)(row - rowOffset));
			}
		}
	}
	colOffset = 1;
	rowOffset = 1;
	while(((int)col - 65 + colOffset < 8) && ((int)row - 49 - rowOffset >= 0) && isEmpty((char)((int)col + colOffset), (char)((int)row - rowOffset))){
		addMove(p, (char)(col + colOffset), (char)(row - rowOffset));
		colOffset++;
		rowOffset++;
	}
	if(((int)col - 65 + colOffset < 8) && ((int)row - 49 - rowOffset >= 0)){
		if(!isEmpty((char)((int)col + colOffset), (char)((int)row - rowOffset))){
			if(getPiece((char)((int)col + colOffset), (char)((int)row - rowOffset))->isWhite() != p->isWhite()){
				addMove(p, (char)(col + colOffset), (char)(row - rowOffset));
			}
		}
	}
	colOffset = 1;
	rowOffset = 1;
	while(((int)col - 65 - colOffset >= 0) && ((int)row - 49 + rowOffset < 8) && isEmpty((char)((int)col - colOffset), (char)((int)row + rowOffset))){
		addMove(p, (char)(col - colOffset), (char)(row + rowOffset));
		colOffset++;
		rowOffset++;
	}
	if(((int)col - 65 - colOffset >= 0) && ((int)row - 49 + rowOffset < 8)){
		if(!isEmpty((char)((int)col - colOffset), (char)((int)row + rowOffset))){
			if(getPiece((char)((int)col - colOffset), (char)((int)row + rowOffset))->isWhite() != p->isWhite()){
				addMove(p, (char)(col - colOffset), (char)(row + rowOffset));
			}
		}
	}
}

void Board::updateKingMoves(Piece* p){
	char col = (int)p->getPosition()[0];
	char row = (int)p->getPosition()[1];
	int colOffsets[8] = {1, -1, 0, 0, 1, -1, -1, 1};
	int rowOffsets[8] = {0, 0, 1, -1, 1, -1, 1, -1};
	int colOffset;
	int rowOffset;
	int icol;
	int irow;
	for(int i = 0; i < 8; i++){
		colOffset = colOffsets[i];
		rowOffset = rowOffsets[i];
		icol = (int)col - 65 + colOffset;
		irow = (int)row - 49 + rowOffset;
		isEmpty((char)((int)col + colOffset), (char)((int)row + rowOffset));
		if((icol < 8) && (icol >= 0) && (irow < 8) && (irow >= 0)){ 
			if(isEmpty((char)((int)col + colOffset), (char)((int)row + rowOffset))){
				addMove(p, (char)(col + colOffset), (char)(row + rowOffset));
			}
			else if(getPiece((char)((int)col + colOffset), (char)((int)row + rowOffset))->isWhite() != p->isWhite()){
				addMove(p, (char)(col + colOffset), (char)(row + rowOffset));
			}
		}
	}
	if(p->isWhite() && !whiteKingMoved){
		if(!whiteLeftRookMoved && isEmpty('B', '1') && isEmpty('C', '1') && isEmpty('D', '1')){
			addMove(p, 'B', '1');
		}
		if(!whiteRightRookMoved && isEmpty('F', '1') && isEmpty('G', '1')){
			addMove(p, 'G', '1');
		}
	}
	else if(!p->isWhite() && !blackKingMoved){
		if(!blackLeftRookMoved && isEmpty('B', '8') && isEmpty('C', '8') && isEmpty('D', '8')){
			addMove(p, 'B', '8');
		}
		if(!whiteRightRookMoved && isEmpty('F', '8') && isEmpty('G', '8')){
			addMove(p, 'G', '8');
		}
	}
}
