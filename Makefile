CC = g++
CCFLAGS = -g

ai: chess.exe

tests: runTests.exe

all: ai tests

chess.exe: obj/main.o obj/Piece.o obj/Board.o
	$(CC) $(CCFLAGS) -o chess.exe obj/main.o obj/Piece.o obj/Board.o

obj/%.o: src/%.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

runTests.exe: obj/testsmain.o obj/Piece.o obj/Board.o obj/PieceTests.o obj/BoardTests.o
	$(CC) $(CCFLAGS) -o runTests.exe obj/testsmain.o obj/Piece.o obj/Board.o obj/PieceTests.o obj/BoardTests.o 

obj/%.o: tests/%.cpp
	$(CC) $(CCFLAGS) -Isrc/ -c $< -o $@

clean:
	rm -f obj/*.o chess.exe runTests.exe
