#include "neuron.h"

Neuron::Neuron()
{
	thresh = 1;
}

Neuron::Neuron(int numInputs)
{
	setNumInputs(numInputs);
}

float Neuron::snap(vector<float> inputs)
{
	lastInp = inputs;
	result = 0;
	for(int i = 0; i < inputs.size(); i++)
	{
		result += inputs[i] * weights[i];
	}
	return result;
}

void Neuron::setNumInputs(int numinputs)
{
	weights.resize(numinputs);
}

void Neuron::resetWeights(int range=1)
{
	for(int i = 0; i < weights.size(); i++)
	{
		weights[i] = (float)((rand() % (range * 200)) - (range * 100)) / 100.0;
	}
}

void Neuron::print()
{
	cout << "Neuron:\n";
	for(int i = 0; i < weights.size(); i++)
		cout << "Weight #" << i << ": " << weights[i] << "\n";
}
