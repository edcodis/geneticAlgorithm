CP = g++
CPFLAG = -std=c++11 -Wall

gen: main.o genetic.o userinput.o
	$(CP) $(CPFLAG) -o gen main.o genetic.o userinput.o

main.o: main.cpp genetic.o userinput.o
	$(CP) $(CPFLAG) -c main.cpp

userinput.o: userinput.h userinput.cpp
	$(CP) $(CPFLAG) -c userinput.cpp


genetic.o: genetic.h genetic.cpp
	$(CP) $(CPFLAG) -c genetic.cpp



clean:
	rm *.o
