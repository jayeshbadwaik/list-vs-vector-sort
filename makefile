all:	list.cc vector.cc
	clang++ -DSIZE=$(SIZE) -DNELEM=$(NELEM) -o list list.cc -O3 -std=c++17
	clang++ -DSIZE=$(SIZE) -DNELEM=$(NELEM) -o vector vector.cc -O3 -std=c++17

clean: list vector
	rm -r list vector
