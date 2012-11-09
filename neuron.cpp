#include "neuron.h"

Neuron::Neuron()
{
	thresh = 1;
}

Neuron::Neuron(int numInputs, float thr)
{
	weights.resize(numInputs);
	thresh = thr;
}

int Neuron::snap(vector<int> inputs)
{
	float sum = 0;
	for(int i = 0; i < inputs.size(); i++)
	{
		sum += inputs[i] * weights[i];
	}
	if (sum > thresh)
		return 1;
	else
		return 0;
}

void Neuron::setNumInputs(int numinputs)
{
	weights.resize(numinputs);
}

void Neuron::resetWeights(int range=1)
{
	for(int i = 0; i < weights.size(); i++)
	{
		weights[i] = (float)((rand() % (range * 2000)) - (range * 1000)) / 1000.0;
	}
}

void Neuron::print()
{
	cout << "Neuron:\n";
	cout << "Threshold: " << thresh << "\n";
	for(int i = 0; i < weights.size(); i++)
		cout << "Weight #" << i << ": " << weights[i] << "\n";
}
