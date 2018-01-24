CXXFLAGS=-Wall -g -std=c++11

lkk:main.o quiz.o AA.o
	g++ $(CXXFLAGS) -o $@ $+

run:lkk
	./lkk

clean:
	rm -f lkk* *.o
