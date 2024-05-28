# edit according to your environment
BASE_DIR=/home/stce/Documents/git/stce/cppNum/stce_ss24_ex12/v1.1

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
	rm -f *.o *.exe Makefile.bak *.plt *.out

.PHONY: depend test clean 
