CC = g++

chess.exe: obj/main.o obj/Piece.o obj/Board.o
	$(CC) -o chess.exe main.o

obj/%.o: src/%.cpp
	$(CC) -c $< -o $@

clean:
	rm -f obj/*.o chess.exe
