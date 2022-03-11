#include <stdio.h>
#include <stdlib.h>
#include "Board.hpp"

bool initBoardTest(){
	bool failed = false;
	Board x = Board();
	//White Pieces
	for(int i = 1; i < 3; i++){
		for(int j = 0; j < 8; j++){
			if(x.isEmpty((char)(j + 65), i + '0')){
				printf("Failed on vals %c%d\n", (char)(j + 65), i);
				failed = true;
			}
			else{
				Piece* tmp = x.getPiece((char)(j + 65), i + '0');
				if(!tmp->isWhite()){
					printf("Failed on color %c%d\n", (char)(j + 65), i);
					failed = true;
				}
				if(i == 2){
					if(tmp->getType() != pawn){
						printf("Failed on type %c%d\n", (char)(j + 65), i);
						failed = true;
					}
				}
				else{
					if((j == 0) || (j == 7)){
						if(tmp->getType() != rook){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else if((j == 1) || (j == 6)){
						if(tmp->getType() != knight){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else if((j == 2) || (j == 5)){
						if(tmp->getType() != bishop){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else if(j == 3){
						if(tmp->getType() != queen){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else if(j == 4){
						if(tmp->getType() != king){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else{
						printf("Error with testbench\n");
					}
				}
			}
		}
	}
	//Empty Pieces
	for(int i = 3; i < 7; i++){
		for(int j = 0; j < 8; j++){
			if(!x.isEmpty((char)(j + 65), i + '0')){
				printf("Failed on vals %c%d\n", (char)(j + 65), i);
				failed = true;
			}
		}
	}
	//Black Pieces
	for(int i = 7; i < 9; i++){
		for(int j = 0; j < 8; j++){
			if(x.isEmpty((char)(j + 65), i + '0')){
				printf("Failed on vals %c%d\n", (char)(j + 65), i);
				failed = true;
			}
			else{
				Piece* tmp = x.getPiece((char)(j + 65), i + '0');
				if(tmp->isWhite()){
					printf("Failed on color %c%d\n", (char)(j + 65), i);
					failed = true;
				}
				if(i == 7){
					if(tmp->getType() != pawn){
						printf("Failed on type %c%d\n", (char)(j + 65), i);
						failed = true;
					}
				}
				else{
					if((j == 0) || (j == 7)){
						if(tmp->getType() != rook){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else if((j == 1) || (j == 6)){
						if(tmp->getType() != knight){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else if((j == 2) || (j == 5)){
						if(tmp->getType() != bishop){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else if(j == 3){
						if(tmp->getType() != queen){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else if(j == 4){
						if(tmp->getType() != king){
							printf("Failed on type %c%d\n", (char)(j + 65), i);
							failed = true;
						}
					}
					else{
						printf("Error with testbench\n");
					}
				}
			}
		}
	}
	return !failed;
}

int main(){
	if(!initBoardTest()){
		printf("initBoardTest Failed\n");
	}
	return 0;
}
