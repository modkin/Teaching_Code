#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <likwid.h>
#include <chrono>
#include <omp.h>

int main(){

  LIKWID_MARKER_INIT;


  int size = 1000 * 1000 * 1000;
  int vecSize = 8;
  int pos = 7;
  
  std::vector< std::vector<double> >  vectors;
  
  for(int i = 0; i < vecSize; ++i){
    vectors.push_back(std::vector<double>(size));
  }
  std::chrono::high_resolution_clock::time_point begin;
  std::chrono::high_resolution_clock::time_point end;

  LIKWID_MARKER_THREADINIT;
  begin = std::chrono::high_resolution_clock::now();
  LIKWID_MARKER_START("0");
  std::fill(vectors[0].begin(),vectors[0].end(),13);
  LIKWID_MARKER_STOP("0");
  end = std::chrono::high_resolution_clock::now();
  std::cout << "idx 0 time (ms): " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<std::endl;

  begin = std::chrono::high_resolution_clock::now();
  LIKWID_MARKER_START("7");
  std::fill(vectors[7].begin(),vectors[7].end(),13);
  LIKWID_MARKER_STOP("7");
  end = std::chrono::high_resolution_clock::now();    
  std::cout << "idx 7 time (ms): " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<std::endl;
  
  LIKWID_MARKER_CLOSE;
}
