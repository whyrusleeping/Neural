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
	for(int i = 0; i < weights.size(); i++)
	{
		//W = W + (a * (y - hw(X)) * Xi)
		if(!i) //This case for the special 'W0'
			weights[i] += learningRate * (float)(expect - out);
		else
			weights[i] += learningRate * (float)(expect - out) * (float)inp[i-1];
	}
}

void TNeuron::setNumInputs(int numinputs)
{
	weights.resize(numinputs);
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
