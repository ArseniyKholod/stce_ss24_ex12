all:
	cd apps && make

test:
	cd apps && make test

depend:
	cd apps && make depend

doc:
	tree cppNum apps > tree.out
	doxygen

clean:
	cd apps && make clean
	rm -fr html tree.out

.PHONY: all test depend doc clean
