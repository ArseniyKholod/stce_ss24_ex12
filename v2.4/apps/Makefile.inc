# edit according to your environment
BASE_DIR=/home/uwe/Documents/git/stce/cppNum/v2.4
CPPC=g++ -Wall -Wextra -pedantic -O3 
INC=-I$(BASE_DIR) 
THIRDPARTY_INC=-I$(BASE_DIR)/../thirdParty/ad -I$(BASE_DIR)/../thirdParty/eigen-3.4.0 

main.exe : main.o
	$(CPPC) $< -o$@

main.o : main.cpp 
	$(CPPC) -c $(INC) $(THIRDPARTY_INC) $< -o$@

test : main.exe
	./$< 10 > main.out
	diff main.out refOutput/ref.out

depend : 
	makedepend $(INC) main.cpp

clean:
	rm -f *.o *.exe *.plt Makefile.bak *.out

.PHONY: test depend clean 
