#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <omp.h>
#include <random>

class MonteCarloApproximation {
  private:
    double radius = 1;
    int numThreads;
    bool isWithinUnitDistance(double x, double y);

  public:
    MonteCarloApproximation(int numThreads){this->numThreads = numThreads; }
    
    void runApproximation();
};
