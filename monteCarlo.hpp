/***************************************************************
  Student Name: Thomas, Arthur
  File Name: monteCarlo.hpp
  Assignment number: Project 4

  Header file for the monteCarlo class
***************************************************************/

#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>

using namespace std;

class MonteCarlo
{
private:
  int numBadBatchesFound = 0;

public:
  MonteCarlo();
  int analysis(int numBatches, int numSampledPerBatch);
};

#endif