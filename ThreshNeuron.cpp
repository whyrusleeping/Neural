#include "ThreshNeuron.h"

TNeuron::TNeuron()
{
	learningRate = 0.5;
}

TNeuron::TNeuron(int numInputs, float learn)
{
	setNumInputs(numInputs);
	learningRate = learn;
}

//Evaluate the neuron with given inputs
int TNeuron::snap(vector<int> inputs)
{
	lastInp = inputs;
	result = 0;
	for(int i = 0; i < inputs.size(); i++)
	{
		result += inputs[i] * weights[i];
	}
	//result = sigmoid(result);
	//return result
	return (result > 0 ? 1 : 0);
}

void TNeuron::addToWeight(int wi, float delta)
{
	weights[wi] += delta;
}

//For Threshold TNeurons
void TNeuron::updateWeights(vector<int> inp, int expect)
{
	int out = snap(inp);
	for(int i = 0; i < weights.size(); i++)
	{
		//W = W + (a * (y - hw(X)) * Xi)
		weights[i] += learningRate * (float)(expect - out) * (float)inp[i];
	}
}

void TNeuron::setNumInputs(int numinputs)
{
	weights.resize(numinputs);
}

void TNeuron::resetWeights(int range=1)
{
	for(int i = 0; i < weights.size(); i++)
	{
		weights[i] = (float)((rand() % (range * 100))+1) / 100.0;
	}
}


void TNeuron::print()
{
	cout << "TNeuron:\n";
	for(int i = 0; i < weights.size(); i++)
		cout << "Weight #" << i << ": " << weights[i] << "\n";
}
