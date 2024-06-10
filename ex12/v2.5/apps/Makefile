# info@stce.rwth-aachen.de

all :
	cd lotkaVolterra && make
	cd lotkaVolterra/ad && make
	cd lotkaVolterra/visualization && make
	cd linear_ode && make
	cd linear_ode/ad && make
	cd linear_ode/visualization && make
	cd linear_ode/time_measurements && make
test :
	cd lotkaVolterra && make test
	cd lotkaVolterra/ad && make test
depend :
	cd lotkaVolterra && make depend
	cd lotkaVolterra/ad && make depend
	cd lotkaVolterra/visualization && make depend
	cd linear_ode && make depend
	cd linear_ode/ad && make depend
	cd linear_ode/visualization && make depend
	cd linear_ode/time_measurements && make depend
clean :
	cd lotkaVolterra && make clean
	cd lotkaVolterra/ad && make clean
	cd lotkaVolterra/visualization && make clean
	cd linear_ode && make clean
	cd linear_ode/ad && make clean
	cd linear_ode/visualization && make clean
	cd linear_ode/time_measurements && make clean

.PHONY: all test depend clean
