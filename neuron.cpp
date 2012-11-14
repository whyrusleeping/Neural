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
	result = sigmoid(result + zWeight);
	return result;
}

void Neuron::setLearningRate(float Nlearn)
{
	learningRate = Nlearn;
}

//This function is here in case i want to track changes to the weight as they are applied.
void Neuron::addToWeight(int wi, float delta)
{
	weights[wi] += delta;
}

void Neuron::setNumInputs(int numinputs)
{
	weights.resize(numinputs);
}

//Randomizes the the weights to a number between -range and range
void Neuron::resetWeights(int range=1)
{
	for(int i = 0; i < weights.size(); i++)
	{
		weights[i] = (float)((rand() % (range * 200)) - (100 * range)) / 100.0;
	}
	zWeight = (float)((rand() % (range * 200)) - (100 * range)) / 100.0;
}

//Sigmoid Activation Function
float Neuron::sigmoid(float val)
{
	return 1 / (1 + pow(2.71828, (val * -1)));
}

void Neuron::adjustForError()
{
	for(int wt = 0; wt < weights.size(); wt++) //for each weight
	{
		//update the weight
		//W = W + (n * error * IN)
		weights[wt] += learningRate * error * lastInp[wt]; 
	}
	zWeight += learningRate * error;
}

//Prints out all the neurons weights
void Neuron::print()
{
	cout << "Neuron:\n";
	for(int i = 0; i < weights.size(); i++)
		cout << "Weight #" << i << ": " << weights[i] << "\n";
}
