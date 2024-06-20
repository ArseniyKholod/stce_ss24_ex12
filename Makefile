# info@stce.rwth-aachen.de

all:
	cd v1.1 && make
	cd v1.2 && make
	cd v1.3 && make
	cd v1.4 && make
	cd v1.5 && make
	cd v2.1 && make
	cd v2.2 && make
	cd v2.3 && make
	cd v2.4 && make
	cd v2.5 && make
	cd ex12 && make
	cd talk && make
	cd talk/livedemo && make
test:
	cd v1.1 && make test
	cd v1.2 && make test
	cd v1.3 && make test
	cd v1.4 && make test
	cd v1.5 && make test
	cd v2.1 && make test
	cd v2.2 && make test
	cd v2.3 && make test
	cd v2.4 && make test
	cd v2.5 && make test
	cd ex12 && make test
clean:
	cd v1.1 && make clean
	cd v1.2 && make clean
	cd v1.3 && make clean
	cd v1.4 && make clean
	cd v1.5 && make clean
	cd v2.1 && make clean
	cd v2.2 && make clean
	cd v2.3 && make clean
	cd v2.4 && make clean
	cd v2.5 && make clean
	cd ex12 && make clean
	cd talk && make clean
	cd talk/livedemo && make clean
.PHONY: all test clean
