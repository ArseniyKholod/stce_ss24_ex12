include ../../Makefile.inc
# DO NOT DELETE

main.o: ../4th_order_convex_polynomial.hpp
main.o: $(BASE_DIR)/cppNum/convexObjective/objective.hpp
main.o: $(BASE_DIR)/cppNum/convexObjective/newton.hpp
main.o: $(BASE_DIR)/cppNum/convexObjective/minimizer.hpp
main.o: $(BASE_DIR)/cppNum/approximation.hpp
main.o: $(BASE_DIR)/cppNum/iteration.hpp
main.o: $(BASE_DIR)/cppNum/linearAlgebra.hpp
main.o: $(BASE_DIR)/cppNum/derivative.hpp
main.o: $(BASE_DIR)/cppNum/exceptions/cppNum_exception.hpp
main.o: $(BASE_DIR)/cppNum/exceptions/logic_error.hpp
main.o: $(BASE_DIR)/cppNum/exceptions/math_error.hpp

plot: 
	make
	cd ../../../../../v2.4/apps/4th_order_convex_polynomial/time_measurements && make
	./main.exe
	cd ../../../../../v2.4/apps/4th_order_convex_polynomial/time_measurements && ./main.exe
	gnuplot run.gnuplot

.PHONY: plot
