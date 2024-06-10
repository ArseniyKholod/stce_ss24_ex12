# info@stce.rwth-aachen.de

all :
	cd lotkaVolterra && make
	cd lotkaVolterra/ad && make
	cd lotkaVolterra/visualization && make
	cd linear_ode && make
	cd linear_ode/ad && make
	cd linear_ode/visualization && make
	cd linear_ode/time_measurements && make
	cd fountain_chain && make
	cd fountain_chain/ad && make
	cd fountain_chain/visualization && make
	cd fountain_chain/time_measurements && make
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
	cd fountain_chain && make depend
	cd fountain_chain/ad && make depend
	cd fountain_chain/visualization && make depend
	cd fountain_chain/time_measurements && make depend
clean :
	cd lotkaVolterra && make clean
	cd lotkaVolterra/ad && make clean
	cd lotkaVolterra/visualization && make clean
	cd linear_ode && make clean
	cd linear_ode/ad && make clean
	cd linear_ode/visualization && make clean
	cd linear_ode/time_measurements && make clean
	cd fountain_chain && make clean
	cd fountain_chain/ad && make clean
	cd fountain_chain/visualization && make clean
	cd fountain_chain/time_measurements && make clean
.PHONY: all test depend clean
