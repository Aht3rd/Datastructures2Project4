/***************************************************************
  Student Name: Thomas, Arthur
  File Name: generatedata.hpp
  Assignment number: Project 4

  Class to run the simulation and build the datasets
  ***************************************************************/

#include "runSimulation.hpp"

void RunSimulation::generateDatasets()
{
    srand(time(NULL));
    numBadBatches = numBatchesOfItems * ((double)percentBadBatches / 100);
    numBadItems = numItemsPerBatch * ((double)percentBadItemsPerBatch / 100);
    maxBadItemsPerBatch = 0;
    minBadItemsPerBatch = numItemsPerBatch;
    totalBadItems = 0;
    for (int i = 0; i < numBatchesOfItems; i++)
    {
        string outFile = "ds";
        outFile += to_string(i+1);
        outFile += ".txt";
        ofstream outFS(outFile);
        if (i < numBadBatches)
        {
            int badItemsThisBatch = 0;
            for (int j = 0; j < numItemsPerBatch; j++)
            {
                if ((rand() % numItemsPerBatch) < numBadItems)
                {
                    outFS << "b" << endl;
                    badItemsThisBatch++;
                    totalBadItems++;
                }
                else
                {
                    outFS << "g" << endl;
                }
            }
            if (badItemsThisBatch > maxBadItemsPerBatch)
            {
                maxBadItemsPerBatch = badItemsThisBatch;
            }
            if (badItemsThisBatch < minBadItemsPerBatch)
            {
                minBadItemsPerBatch = badItemsThisBatch;
            }
        }
        else
        {
            for (int k = 0; k < numItemsPerBatch; k++)
            {
                outFS << "g" << endl;
            }
        }
        outFS.close();
    }
}

void RunSimulation::printSimulation(int numSimulation)
{
    cout << "Simulation #" << numSimulation << endl;
    cout << "   Number of batches of items:" << setw(24) << right << numBatchesOfItems << endl;
    cout << "   Number of items in each batch:" << setw(21) << right << numItemsPerBatch << endl;
    cout << "   Percentage of batches containing bad items:" << setw(8) << percentBadBatches << endl;
    cout << "   Percentage of items that are bad in a bad set:" << setw(5) << percentBadItemsPerBatch << endl;
    cout << "   Items sampled from each set:" << setw(23) << right << numItemsSampledPerBatch << endl << endl;
}

void RunSimulation::printData()
{
    cout << "   Generating Data Sets: " << endl;
	cout << "     Total bad sets = " << numBadBatches << endl;
	cout << "     Max number of bad items in a bad set = " << maxBadItemsPerBatch << endl;
	cout << "     Min number of bad items in a bad set = " << minBadItemsPerBatch << endl;
	cout << "     Average number of bad items in a bad set = " << (double)totalBadItems / (double)numBadBatches << endl << endl;    
}

void RunSimulation::printAnalysis(int badBatchesFound)
{
	double base = (100.0 - (double)percentBadItemsPerBatch) / 100.0;
    cout << "     Base = " << base << " exponent = " << numItemsSampledPerBatch << endl;
	cout << "     P(failure to detect bad batch) = " << pow(base, (double)numItemsSampledPerBatch) << endl;
    cout << "     P(batch is good) = " << 1 - pow(base, (double)numItemsSampledPerBatch) << endl;
    cout << "     Percentage of bad batches detected = " << ((double)badBatchesFound / (double)badBatchesFound) * 100.0 << "%" << endl << endl;	
}

RunSimulation::RunSimulation()
{
    MonteCarlo object;
    for (int i = 1; i <= 4; i++)
    {
        string str;
        string inFile = "t";
        inFile += to_string(i);
        inFile += ".txt";
        ifstream inFS(inFile);
        for (int j = 0; j < 5; j++)
        {
            getline(inFS, str);
            switch (j)
            {
            case 0:
                numBatchesOfItems = stoi(str);
                break;
            case 1:
                numItemsPerBatch = stoi(str);
                break;
            case 2:
                percentBadBatches = stoi(str);
                break;
            case 3:
                percentBadItemsPerBatch = stoi(str);
                break;
            case 4:
                numItemsSampledPerBatch = stoi(str);
                break;
            default:
                cout << "Error reading file." << endl;
            }
        }
        inFS.close();
        printSimulation(i);
        generateDatasets();
        printData();
        printAnalysis(object.analysis(numBatchesOfItems, numItemsSampledPerBatch));
    }
}