#include "neuron.h"

Neuron::Neuron()
{
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
	result = sigmoid(result);
	return result;
}

void Neuron::updateWeight(int wi, float delta)
{
	weights[wi] += delta;
}

void Neuron::setNumInputs(int numinputs)
{
	weights.resize(numinputs);
}

void Neuron::resetWeights(int range=1)
{
	for(int i = 0; i < weights.size(); i++)
	{
		weights[i] = (float)((rand() % (range * 100))+1) / 100.0;
	}
}

float Neuron::sigmoid(float val)
{
	return 1 / (1 + pow(2.71828, (val * -1)));
}

void Neuron::print()
{
	cout << "Neuron:\n";
	for(int i = 0; i < weights.size(); i++)
		cout << "Weight #" << i << ": " << weights[i] << "\n";
}
