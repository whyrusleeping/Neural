#include "neuron.h"

Neuron::Neuron(int numInputs, int thresh)
{
	weights.resize(numInputs);
	thr = thresh;
}

int Neuron::snap(vector<short> inputs)
{
	int sum = 0;
	for(int i = 0; i < inputs.size(); i++)
	{
		sum += inputs[i] * weights[i];
	}
	if (sum > thr)
		return 1;
	else
		return 0;
}
