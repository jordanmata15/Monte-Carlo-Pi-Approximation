#include "ArgParser.hpp"

int ArgParser::readInt(char flag, char* value){
  // https://stackoverflow.com/questions/46208837/c-using-isdigit-to-check-if-optarg-is-a-digit
  char *end;
  errno = 0;
  int intValue = strtol(value, &end, 10);
  while (isspace(*end)) ++end;
  if (errno || *end) {
      fprintf(stderr,"Flag -%c expects an integer input. Found: '%s'\n", flag, value);
      exit(2);
  }
  return intValue;
}

Arguments* ArgParser::parseArgs(int argc, char** argv){
  int option;

  while ( (option=getopt(argc,argv,"n:p:")) != -1 ){
    switch(option){
      case 'n':
        args->numThreads = this->readInt(option, optarg);
        break;
      case 'p':
        args->numPoints = this->readInt(option, optarg);
        break;
      case '?':
        printUsage();
        exit(1);
    }
  }

  return args;
}