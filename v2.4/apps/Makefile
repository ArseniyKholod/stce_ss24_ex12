# info@stce.rwth-aachen.de

all :
	cd sphere && make
	cd sphere/visualization && make
	cd sphere/ad && make
test :
	cd sphere && make test
	cd sphere/ad && make test
depend :
	cd sphere && make depend
	cd sphere/visualization && make depend
	cd sphere/ad && make depend
clean :
	cd sphere && make clean
	cd sphere/visualization && make clean
	cd sphere/ad && make clean

.PHONY: all test depend clean
