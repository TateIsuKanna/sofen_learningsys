CFLAGS=-Wall -g -std=c++11

lkk:AA main.cpp
	g++ $(CFLAGS) -o $@ $^
AA:AA.cpp
	g++ $(CFLAGS) -c -o $@ $^

run:lkk
	./lkk

clean:
	rm lkk* AA
