#include "main.hpp"

int main(int argc, char** argv){
  ArgParser ap = ArgParser();
  Arguments* args = ap.parseArgs(argc, argv);

  DataManager manager = DataManager();

  MonteCarloApproximation mca = MonteCarloApproximation(args->numThreads, args->numPoints, &manager);
  
  std::cout << mca.runApproximation() << "," << manager.average() << std::endl;

  return 0;
}