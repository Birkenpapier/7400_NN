#include "IC_data.cpp"
#include "IC_neuron.cpp"
#include "IC_nnetwork.cpp"
#include "IC_util.cpp"

using namespace std;

int main(int argc, char *argv[])
{
	Data data("./src/nand.txt");

	// network topology
	vector<unsigned> topology;
	topology.push_back(2); // two input nodes
	topology.push_back(4); // two hidden nodes
	topology.push_back(1); // one output node

	NNetwork nnet(topology);

	vector<double> inputVals, targetVals, resultVals;
	int epoch = 0;
	
    bool printWeights = false;

	if ((argc == 2) && strcmp(argv[1], "saveEpoch") == 0)
        printWeights = true;
    
	while(!data.isEof())
	{
		epoch++;
		cout << endl << "Epoch: " << epoch << "\n";

		// Get new input data and feed it forward:
		if(data.getNextInputs(inputVals) != topology[0])
			break;

		printVector("Input:", inputVals);
		nnet.feedForward(inputVals);

		// Collect the actual results of the network:
		nnet.getResults(resultVals);
		printVector("Outputs:", resultVals);

		// Train the net what the outputs should have been:
		data.getTargetOutputs(targetVals);
		printVector("Targets:", targetVals);
		assert(targetVals.size() == topology.back());

		nnet.backProp(targetVals, epoch, printWeights);

		// Report how well the training is working, average over recnet
		cout << "NNetwork recent average error: "
		     << nnet.getRecentAverageError() << endl;
	}
    
	cout << endl << "Done" << endl;

	return 0;
}
