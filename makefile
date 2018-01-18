CFLAGS=-Wall -g -std=c++11

lkk:main.cpp
	g++ $(CFLAGS) -o lkk main.cpp

run:lkk
	./lkk

clean:
	rm lkk*
