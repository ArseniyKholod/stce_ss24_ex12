include ../../Makefile.inc
# DO NOT DELETE

main.o: ../cosh.hpp
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

main_difference.exe : main_difference.o
	$(CPPC) $< -o$@

main_difference.o : main_difference.cpp
	$(CPPC) -c $(INC) $(THIRDPARTY_INC) $< -o$@

make plot: 
	cd ../../../../../v2.4/apps/cosh/time_measurements && make 
	cd ../../../../../v2.4/apps/cosh/time_measurements && ./main.exe
	make
	./main.exe
	make main_difference.exe
	./main_difference.exe
	gnuplot run.gnuplot
