#ifndef IC_MAIN_H
#define IC_MAIN_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

// --------- class Data ---------

// consumes the data for the training process
// Example:
//		Data data("./src/nand.txt");
class Data
{
public:
	Data(const string filename);
	bool isEof(void)
	{
		return m_trainingDataFile.eof();
	}

	// Returns the number of input values read from the file:
	unsigned getNextInputs(vector<double> &inputVals);
	unsigned getTargetOutputs(vector<double> &targetOutputVals);

private:
	ifstream m_trainingDataFile;
};

// --------- class Neuron ---------
struct Connection
{
	double weight;
	double deltaWeight;
};

class Neuron;
typedef vector<Neuron> Layer;

// creates a neuron of the neural network
// Example:
//		Neuron::Neuron(unsigned numOutputs, unsigned myIndex)
//		{
//			for(unsigned c = 0; c < numOutputs; ++c){
//				m_outputWeights.push_back(Connection());
//				m_outputWeights.back().weight = randomWeight();
//			}
//		
//			m_myIndex = myIndex;
//		}
class Neuron
{
public:
	Neuron(unsigned numOutputs, unsigned myIndex);
	void setOutputVal(double val) { m_outputVal = val; }
	double getOutputVal(void) const { return m_outputVal; }
	void feedForward(const Layer &prevLayer);
	void calcOutputGradients(double targetVals);
	void calcHiddenGradients(const Layer &nextLayer);
	void updateInputWeights(Layer &prevLayer);
private:
	static double eta; // [0.0...1.0] overall net training rate
	static double alpha; // [0.0...n] multiplier of last weight change [momentum]
	static double transferFunction(double x);
	static double transferFunctionDerivative(double x);
	// randomWeight: 0 - 1
	static double randomWeight(void) { return rand() / double(RAND_MAX); }
	double sumDOW(const Layer &nextLayer) const;
	double m_outputVal;
	vector<Connection> m_outputWeights;
	unsigned m_myIndex;
	double m_gradient;
};

double Neuron::eta = 0.15; // overall net learning rate
double Neuron::alpha = 0.5; // momentum, multiplier of last deltaWeight, [0.0..n]

// --------- class NNetwork ---------

// creates a neural network
// Example:
//    NNetwork nnet(topology);
class NNetwork
{
public:
	NNetwork(const vector<unsigned> &topology);
	void feedForward(const vector<double> &inputVals);
	void backProp(const vector<double> &targetVals);
	void getResults(vector<double> &resultVals) const;
	double getRecentAverageError(void) const { return m_recentAverageError; }

private:
	vector<Layer> m_layers; //m_layers[layerNum][neuronNum]
	double m_error;
	double m_recentAverageError;
	static double m_recentAverageSmoothingFactor;
};

double NNetwork::m_recentAverageSmoothingFactor = 100.0; // Number of training samples to average over

void printVector(string label, vector<double> &v);

#endif