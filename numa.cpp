#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <omp.h>

int main(){
  int size = 1000 * 1000 * 10;
  int vecSize = 2;
  std::vector< std::vector<double> >  vectors;
  
  for(int i = 0; i < vecSize; ++i){
    vectors.push_back(std::vector<double>(size));
  }


  std::chrono::high_resolution_clock::time_point begin;
  std::chrono::high_resolution_clock::time_point end;
#pragma omp parallel num_threads(2)
  {

    for(int i = 0; i < vecSize; ++i){
      if(omp_get_thread_num() == i % omp_get_num_threads()){
	begin = std::chrono::high_resolution_clock::now();
	std::fill(vectors[i].begin(),vectors[i].end(),13);
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Thread: " << omp_get_thread_num() << " on CPU: " << sched_getcpu() << "; Time (ms): " ;
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<std::endl;
      }
#pragma omp barrier
    } 
  }
}
