CPPFLAGS= -c -g -Wall -pedantic -std=c++17 

_start__: sortowanie
	./sortowanie

sortowanie: main.o 
	g++ -o sortowanie main.o  


main.o: main.cpp film.hh sort.hh Statystyka.hh
	g++ ${CPPFLAGS} -o main.o main.cpp



clear:
	rm -rf sortowanie main.o 