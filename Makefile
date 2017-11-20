all: numa numa_fixed

numa: numa.cpp
	g++ -std=c++11 -O3 -fopenmp -Wall numa.cpp -o numa

numa_fixed: numa_fixed.cpp
	g++ -std=c++11 -O3 -fopenmp -Wall numa_fixed.cpp -o numa_fixed

clean:
	rm -f numa_fixed numa
