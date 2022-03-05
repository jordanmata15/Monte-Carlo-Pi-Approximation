#include <omp.h>
#include <random>
#include <sys/time.h>
#include "DataManager.hpp"

/**
 * @brief Simulation of Monte-Carlo algorithm for generating pi using parallelization.
 * 
 */
class MonteCarloApproximation {
  private:
    double radius;
    int numThreads;
    int pointsToPlot;
    DataManager* timeManager;

    /**
     * @brief Check if the x/y values are within the euclidean distance of our radius.
     * 
     * @param x The x coordinate
     * @param y The y coordinate
     * @return true When the x/y have a eudlidean distance less than radius.
     * @return false Otherwise.
     */
    bool isWithinUnitDistance(double x, double y);

  public:
    /**
     * @brief Construct a new Monte Carlo Approximation object
     * 
     * @param numThreads The number of threads to use when parallelizing.
     * @param pointsToPlot The number of random data points to generate for more accurate results.
     * @param manager The data manager for recording the time of the algorithm.
     */
    MonteCarloApproximation(int numThreads, int pointsToPlot, DataManager* manager): radius(1),
                                                                                      numThreads(numThreads), 
                                                                                      pointsToPlot(pointsToPlot),
                                                                                      timeManager(manager){}
    
    /**
     * @brief Run the approximation algorithm and record the time elapsed in our timeManager.
     * 
     * @return double The approximation of pi.
     */
    double runApproximation();
};
