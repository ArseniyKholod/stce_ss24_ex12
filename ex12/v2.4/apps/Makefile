# info@stce.rwth-aachen.de

all :
	cd sphere && make
	cd sphere/visualization && make
	cd sphere/ad && make
	cd parabola && make
	cd parabola/visualization && make
	cd parabola/ad && make
test :
	cd sphere && make test
	cd sphere/ad && make test
depend :
	cd sphere && make depend
	cd sphere/visualization && make depend
	cd sphere/ad && make depend
	cd parabola && make depend
	cd parabola/visualization && make depend
	cd parabola/ad && make depend

clean :
	cd sphere && make clean
	cd sphere/visualization && make clean
	cd sphere/ad && make clean
	cd parabola && make clean
	cd parabola/visualization && make clean
	cd parabola/ad && make clean


.PHONY: all test depend clean
