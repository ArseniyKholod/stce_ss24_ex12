# info@stce.rwth-aachen.de

all :
	cd intersection && make
	cd intersection/ad && make
	cd intersection/visualization && make
test :
	cd intersection && make test
	cd intersection/ad && make test
depend :
	cd intersection && make depend
	cd intersection/ad && make depend
	cd intersection/visualization && make depend
clean :
	cd intersection && make clean
	cd intersection/ad && make clean
	cd intersection/visualization && make clean

.PHONY: all test depend clean
