CFLAGS=-Wall -g -std=c++11

lkk:main.o quiz.o AA.o
	g++ $(CFLAGS) -o $@ $+


main.o:main.cpp
	g++ $(CFLAGS) -c $+

quiz.o:quiz.cpp
	g++ $(CFLAGS) -c $+

AA.o:AA.cpp
	g++ $(CFLAGS) -c $+

run:lkk
	./lkk

clean:
	rm -f lkk* *.o
