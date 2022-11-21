/***************************************************************
  Student Name: Thomas, Arthur
  File Name: monteCarlo.cpp
  Assignment number: Project 4

  Class to implement Monte Carlo algorithm to determine which batches are bad
***************************************************************/
#include "monteCarlo.hpp"

MonteCarlo::MonteCarlo()
{
}

int MonteCarlo::analysis(int numBatches, int numSampledPerBatch)
{
    cout << "   Analyizing Data Sets:" << endl;
    numBadBatchesFound = 0;
    for(int i = 1; i < numBatches; i++)
    {
        string str = "";
        string inFile = "ds";
        inFile += to_string(i);
        inFile += ".txt";
        ifstream inFS(inFile);
        for(int j = 0; j < numSampledPerBatch; j++)
        {
            getline(inFS, str);
            if(str == "b")
            {
                numBadBatchesFound++;
                break;
            }
        }
        inFS.close();
    }
    return numBadBatchesFound;
}