test : tt.o
	g++ -o test -g -Wall test.cpp tt.o

tt.o: ternaryTree.cpp
	g++ -o tt.o -c -g -Wall ternaryTree.cpp 

clean:
	rm *.o test
