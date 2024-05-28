# info@stce.rwth-aachen.de

all :
	cd lotkaVolterra && make
	cd lotkaVolterra/ad && make
	cd lotkaVolterra/visualization && make
test :
	cd lotkaVolterra && make test
	cd lotkaVolterra/ad && make test
depend :
	cd lotkaVolterra && make depend
	cd lotkaVolterra/ad && make depend
	cd lotkaVolterra/visualization && make depend
clean :
	cd lotkaVolterra && make clean
	cd lotkaVolterra/ad && make clean
	cd lotkaVolterra/visualization && make clean

.PHONY: all test depend clean
