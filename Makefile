CC = g++

ai: chess.exe

tests: runTests.exe

all: ai tests

chess.exe: obj/main.o obj/Piece.o obj/Board.o
	$(CC) -o chess.exe obj/main.o obj/Piece.o obj/Board.o

obj/%.o: src/%.cpp
	$(CC) -c $< -o $@

runTests.exe: obj/testsmain.o obj/Piece.o obj/Board.o obj/PieceTests.o obj/BoardTests.o
	$(CC) -o runTests.exe obj/testsmain.o obj/Piece.o obj/Board.o obj/PieceTests.o obj/BoardTests.o 

obj/%.o: tests/%.cpp
	$(CC) -Isrc/ -c $< -o $@

clean:
	rm -f obj/*.o chess.exe runTests.exe
