#include <stdlib.h>
#include <cmath>
#include <omp.h>
#include <random>
#include <sys/time.h>
#include "DataManager.hpp"


class MonteCarloApproximation {
  private:
    double radius;
    int numThreads;
    int pointsToPlot;
    bool isWithinUnitDistance(double x, double y);
    DataManager* timeManager;

  public:
    /**
     * @brief Construct a new Monte Carlo Approximation object
     * 
     * @param numThreads The number of threads to use when parallelizing.
     * @param pointsToPlot The number of random data points to generate for more accurate results.
     * @param manager The data manager for recording the time of the algorithm.
     */
    MonteCarloApproximation(int numThreads, int pointsToPlot, DataManager* manager): numThreads(numThreads), 
                                                                                      pointsToPlot(pointsToPlot),
                                                                                      timeManager(manager),
                                                                                      radius(1){}
    
    /**
     * @brief Run the approximation algorithm and record the time elapsed in our timeManager.
     * 
     * @return double The approximation of pi.
     */
    double runApproximation();
};
