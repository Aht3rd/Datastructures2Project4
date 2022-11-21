/***************************************************************
  Student Name: Thomas, Arthur
  File Name: generatedata.hpp
  Assignment number: Project 4

  Header file for the runSimulation class
***************************************************************/

#ifndef RUNSIMULATION_HPP
#define RUNSIMULATION_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <time.h>
#include <iomanip>
#include "monteCarlo.hpp"

using namespace std;

class RunSimulation
{
private:
    int numBatchesOfItems = 0;
    int numItemsPerBatch = 0;
    int percentBadBatches = 0;
    int percentBadItemsPerBatch = 0;
    int numItemsSampledPerBatch = 0;
    int numBadBatches = 0;
    int numBadItems = 0;
    int maxBadItemsPerBatch = 0;
    int minBadItemsPerBatch = 0;
    int totalBadItems = 0;
    void generateDatasets();
    void printSimulation(int numSimulation);
    void printData();
    void printAnalysis(int badBatchesFound);

public:
    RunSimulation();
};

#endif