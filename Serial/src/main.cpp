#include <stdio.h>
#include <stdlib.h>
#include "Board.hpp"

int main(){
	Board x = Board();
	printf("isEmpty %d\n", x.isEmpty('A', 2));
	printf("isEmpty %d\n", x.isEmpty('C', 2));
	return 0;
}
