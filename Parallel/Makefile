CC = g++
#CCFLAGS = -g -lboost_thread -lpthread -L /usr/lib/ -DNUM_THREADS=24
CCFLAGS = -g -lboost_thread -lpthread -L /usr/lib/ -DNUM_THREADS=4 -O3 -flto -march=native -std=c++17


ai: chess.exe

tests: runTests.exe

all: ai tests

chess.exe: obj/main.o obj/Piece.o obj/Board.o
	$(CC) -o chess.exe obj/main.o obj/Piece.o obj/Board.o $(CCFLAGS)

obj/%.o: src/%.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

runTests.exe: obj/testsmain.o obj/Piece.o obj/Board.o obj/PieceTests.o obj/BoardTests.o
	$(CC) -o runTests.exe obj/testsmain.o obj/Piece.o obj/Board.o obj/PieceTests.o obj/BoardTests.o $(CCFLAGS)

obj/%.o: tests/%.cpp
	$(CC) $(CCFLAGS) -Isrc/ -c $< -o $@

clean:
	rm -f obj/*.o chess.exe runTests.exe
