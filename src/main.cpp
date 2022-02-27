#include "main.hpp"

int main(int argc, char** argv){
  ArgParser ap = ArgParser();
  Arguments* args = ap.parseArgs(argc, argv);

  MonteCarloApproximation mca = MonteCarloApproximation(args->numThreads, args->numPoints);
  std::cout << "Using " << args->numThreads << " threads and " << args->numPoints << " random points:\n";
  std::cout << "Pi: " << mca.runApproximation() << std::endl;

  return 0;
}