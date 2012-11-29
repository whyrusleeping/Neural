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
	result = weights[0]; //Add in the 'zero'th weight
	for(int i = 0; i < inputs.size(); i++)
	{
		//Summation of (Wi * Xi)
		result += inputs[i] * weights[i+1];
	}
	return (result > 0 ? 1 : 0);
}

void TNeuron::addToWeight(int wi, float delta)
{
	weights[wi+1] += delta;
}

//For Threshold TNeurons
void TNeuron::updateWeights(vector<int> inp, int expect)
{
	int out = snap(inp);
	weights[0] += learningRate * (expect - out);
	for(int i = 1; i < weights.size(); i++)
	{
		//W = W + (a * (y - hw(X)) * Xi)
		weights[i] += learningRate * (float)(expect - out) * (float)inp[i-1];
	}

}

void TNeuron::setNumInputs(int numinputs)
{
	weights.resize(numinputs+1);
}

//Randomizes the the weights to a number between .01 and 'range'
void TNeuron::resetWeights(int range=1)
{
	for(int i = 0; i < weights.size(); i++)
	{
		weights[i] = (float)((rand() % (range * 100))+1) / 100.0;
	}
}

void TNeuron::setLearningRate(float Nlearn)
{
	learningRate = Nlearn;
}

void TNeuron::print()
{
	cout << "TNeuron:\n";
	for(int i = 0; i < weights.size(); i++)
		cout << "Weight #" << i << ": " << weights[i] << "\n";
}
