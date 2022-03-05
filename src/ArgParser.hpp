#ifndef ARG_PARSER_HPP
#define ARG_PARSER_HPP

#include <iostream>
#include <string>
#include <getopt.h>

#define DEFAULT_THREADS 1
#define DEFAULT_POINTS 1000000
#define USAGE "\nusage: ./MonteCarloApproximation -n NUMTHREADS -p NUMPOINTS\n"\
              "\t-n optional flag that reads in NUMTHREADS (NUMTHREADS > 0, integer)\n"\
              "\t-p optional flag that reads in NUMPOINTS (NUMPOINTS > 0, integer)\n"

/**
 * Arguments object to hold the values of the desired inputs given by the user.
 */
class Arguments{
  public:
    int numThreads;
    int numPoints;

    /**
     * Basic constructor. Sets default values.
     */
    Arguments():numThreads(DEFAULT_THREADS), 
                numPoints(DEFAULT_POINTS){}
};


/**
 * Class to continuously prompt the user for input and validate it. Fills an 
 * Arguments object with the users desired input.
 */
class ArgParser {

  private:
    int readInt(char flag, char* value);

    void printUsage(){ std::cout << USAGE << std::endl; }
  
  public:
    Arguments* args;

    /**
     * Simple constructor that dynamically allocates memory for the arguments.
     */
    ArgParser() { args = new Arguments(); }

    /**
     * Simple destructor that frees the arguments once we're done with them.
     */
    ~ArgParser(){ delete args; }

    /**
     * Method used to parse the flags from the user. Validates integer arguments
     * and exits if invalid.
     * 
     * @param argc The argument count provided to main().
     * @param argv The argument list provided to main().
     * @return A pointer to an argument structure from which the user inputs
     *         can be read.
     */
    Arguments* parseArgs(int argc, char** argv);
};

#endif // ARG_PARSER_HPP
