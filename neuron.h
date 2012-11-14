#ifndef J_NEURON_H
#define J_NEURON_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>

using std::cout;
using std::vector;

class Network;

///
//An Artificial, sigmoid activated neuron 
///
class Neuron
{
	public:
		friend Network;
		Neuron();
		Neuron(int numInputs,float learn);
		float snap(vector<float> inputs);

		void setLearningRate(float nLearn);
		void addToWeight(int wi, float delta);
		void updateWeights(vector<float> inp, float expect);

		void adjustForError();

		void setNumInputs(int numInputs);
		void resetWeights(int range);
		void print();
		float sigmoid(float val);
		vector<float> weights;
	private:
		float zWeight;
		float result;
		float error;
		vector<float> lastInp;
		float learningRate;
};

#endif
