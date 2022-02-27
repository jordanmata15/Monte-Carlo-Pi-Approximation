#include "MonteCarloApproximation.hpp"


double MonteCarloApproximation::runApproximation(){
  double innerCount = 0;
  double x;
  double y;

  #pragma omp parallel for private(x,y) reduction(+:innerCount) num_threads(this->numThreads)
  for (int i=0; i<this->pointsToPlot; ++i){
    // https://stackoverflow.com/questions/29709897/c-thread-safe-uniform-distribution-random-number-generation
    int thread_num = omp_get_thread_num();
    thread_local std::mt19937 generator(thread_num); // generator(time(0));
    std::uniform_real_distribution<> uniform_dist(0, this->radius);

    x = uniform_dist(generator);
    y = uniform_dist(generator);
    if (this->isWithinUnitDistance(x,y)) ++innerCount;
  }

  return 4*(innerCount/this->pointsToPlot);
}

bool MonteCarloApproximation::isWithinUnitDistance(double x, double y){
  return sqrt((x*x)+(y*y)) <= this->radius;
}