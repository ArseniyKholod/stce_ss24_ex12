# info@stce.rwth-aachen.de

all :
	cd sphere && make
	cd sphere/visualization && make
	cd sphere/ad && make
	cd cosh && make
	cd cosh/visualization && make
	cd cosh/ad && make
	cd cosh/time_measurements && make
	cd 4th_order_convex_polynomial && make
	cd 4th_order_convex_polynomial/visualization && make
	cd 4th_order_convex_polynomial/ad && make
	cd 4th_order_convex_polynomial/time_measurements && make
	cd generate_exceptions && make
test :
	cd sphere && make test
	cd sphere/ad && make test
depend :
	cd sphere && make depend
	cd sphere/visualization && make depend
	cd sphere/ad && make depend
	cd cosh && make depend
	cd cosh/visualization && make depend
	cd cosh/ad && make depend
	cd cosh/time_measurements && make depend
	cd 4th_order_convex_polynomial && make depend
	cd 4th_order_convex_polynomial/visualization && make depend
	cd 4th_order_convex_polynomial/ad && make depend
	cd 4th_order_convex_polynomial/time_measurements && make depend
	cd generate_exceptions && make depend
clean :
	cd sphere && make clean
	cd sphere/visualization && make clean
	cd sphere/ad && make clean
	cd cosh && make clean
	cd cosh/visualization && make clean
	cd cosh/ad && make clean
	cd cosh/time_measurements && make clean
	cd 4th_order_convex_polynomial && make clean
	cd 4th_order_convex_polynomial/visualization && make clean
	cd 4th_order_convex_polynomial/ad && make clean
	cd 4th_order_convex_polynomial/time_measurements && make clean
	cd generate_exceptions && make clean

.PHONY: all test depend clean
