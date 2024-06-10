include ../../Makefile.inc

# DO NOT DELETE

main.o: ../linear_ode.hpp
main.o: $(BASE_DIR)/cppNum/differentialSystem/system.hpp
main.o: $(BASE_DIR)/cppNum/differentialSystem/implicitEuler.hpp
main.o: $(BASE_DIR)/cppNum/differentialSystem/integrator.hpp
main.o: $(BASE_DIR)/cppNum/evolution.hpp
main.o: $(BASE_DIR)/cppNum/iteration.hpp
main.o: $(BASE_DIR)/cppNum/linearAlgebra.hpp
main.o: $(BASE_DIR)/cppNum/differentialSystem/system.hpp
main.o: $(BASE_DIR)/cppNum/exceptions/cppNum_exception.hpp
main.o: $(BASE_DIR)/cppNum/exceptions/math_error.hpp
main.o: $(BASE_DIR)/cppNum/exceptions/logic_error.hpp

main_difference.exe : main_difference.o
	$(CPPC) $< -o$@

main_difference.o : main_difference.cpp
	$(CPPC) -c $(INC) $(THIRDPARTY_INC) $< -o$@

make plot:
	make
	./main.exe
	cd ../../../../../v2.5/apps/linear_ode/time_measurements && make
	cd ../../../../../v2.5/apps/linear_ode/time_measurements && ./main.exe
	make main_difference.exe
	./main_difference.exe
	gnuplot run.gnuplot

