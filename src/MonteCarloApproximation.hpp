#include <stdlib.h>
#include <cmath>
#include <omp.h>
#include <random>
#include <sys/time.h>
#include "DataManager.hpp"


class MonteCarloApproximation {
  private:
    double radius = 1;
    int numThreads;
    int pointsToPlot;
    bool isWithinUnitDistance(double x, double y);
    DataManager* timeManager;

  public:
    MonteCarloApproximation(int numThreads, int pointsToPlot):numThreads(numThreads), 
                                                              pointsToPlot(pointsToPlot){}

    MonteCarloApproximation(int numThreads, int pointsToPlot, DataManager* manager): numThreads(numThreads), 
                                                                                    pointsToPlot(pointsToPlot),
                                                                                    timeManager(manager){}
    
    double runApproximation();
};
