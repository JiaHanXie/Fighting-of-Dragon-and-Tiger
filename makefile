CW: main.o MainHeader.o

	g++ main.o MainHeader.o -o CW

main.o: main.cpp MainHeader.hpp

	g++ -c main.cpp -o main.o

MainHeader.o: MainHeader.cpp MainHeader.hpp

	g++ -c MainHeader.cpp -o MainHeader.o

clean:

	rm *.o CW