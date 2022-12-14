#include "IC_main.hpp"

using namespace std;

void printVector(string label, vector<double> &v)
{
	cout << label << " ";
	for(uint8_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void saveEpochs(Layer &prevLayer, int epoch)
{
    std::cout << "start saving epoch " << epoch << std::endl;
    std::string epochN = "../epochs/epoch_" + std::to_string(epoch) + ".txt";
    std::ofstream epochTxt(epochN);

	for(unsigned n = 0; n < prevLayer.size(); ++n)
	{
		Neuron &neuron = prevLayer[n];
        for (Connection i: neuron.m_outputWeights)
        {
            epochTxt << "neuronID: " << n << std::endl;
            epochTxt << "weight: " << i.weight << std::endl;
            epochTxt << "deltaWeight: " << i.deltaWeight << std::endl;
        }
    }
}