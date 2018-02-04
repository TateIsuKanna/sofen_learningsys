CXXFLAGS=-Wall -g -std=c++11

lkk:main.o quiz.o AA.o
	$(CXX) $(CXXFLAGS) -o $@ $+

run:lkk
	./lkk

clean:
	rm -f lkk* *.o
