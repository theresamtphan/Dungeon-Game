all:
	g++ -std=c++11 itemSpace.cpp main.cpp Monster.cpp monsterSpace.cpp trapSpace.cpp Player.cpp Space.cpp -o main
clean:
	rm main