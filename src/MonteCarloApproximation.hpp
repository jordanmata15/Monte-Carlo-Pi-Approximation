#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <omp.h>
#include <random>
#include "ArgParser.hpp"

class MonteCarloApproximation {
  private:
    double radius = 1;
    int numThreads;
    int pointsToPlot;
    bool isWithinUnitDistance(double x, double y);

  public:
    MonteCarloApproximation(int numThreads, int pointsToPlot):numThreads(numThreads), 
                                                              pointsToPlot(pointsToPlot){}
    
    double runApproximation();
};
