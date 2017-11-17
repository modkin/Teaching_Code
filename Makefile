main: main.cpp
	g++ -std=c++11 $(LIKWID_INC) -fopenmp main.cpp -o main

numa: numa.cpp
	g++ -std=c++11 -fopenmp numa.cpp -o numa


main_likwid: main.cpp
	g++ -std=c++11 -fopenmp -DLIKWID_PERFMON $(LIKWID_INC) $(LIKWID_LIB) -llikwid -lm -pthread main.cpp -o main	

clean:
	rm -f main numa
