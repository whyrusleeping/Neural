#include "neuron.h"

Neuron::Neuron()
{
	learningRate = 0.5;
}

Neuron::Neuron(int numInputs, float learn)
{
	setNumInputs(numInputs);
	learningRate = learn;
}

//Evaluate the neuron with given inputs
float Neuron::snap(vector<float> inputs)
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

void Neuron::addToWeight(int wi, float delta)
{
	weights[wi] += delta;
}

//For Threshold Neurons
void Neuron::updateWeights(vector<float> inp, float expect)
{
	float out = snap(inp);
	for(int i = 0; i < weights.size(); i++)
	{
		//W = W + (a * (y - hw(X)) * Xi)
		weights[i] += learningRate * (expect - out) * inp[i];
	}
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
