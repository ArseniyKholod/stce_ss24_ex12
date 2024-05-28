# edit according to your environment
BASE_DIR=/home/uwe/Documents/git/stce/cppNum/v1.4

CPPC=g++ -Wall -Wextra -pedantic -O3 
INC=-I$(BASE_DIR) 
THIRDPARTY_INC=-I$(BASE_DIR)/../thirdParty/ad 

main.exe : main.o
	$(CPPC) $< -o$@

main.o : main.cpp 
	$(CPPC) -c $(INC) $(THIRDPARTY_INC) $< -o$@

depend : 
	makedepend $(INC) main.cpp

test: main.exe
	./$< > main.out
	diff main.out refOutput/ref.out

clean:
	rm -f *.o *.exe *.plt Makefile.bak *.out

.PHONY: depend test clean 
