#ifndef J_NEURON_H
#define J_NEURON_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>

using std::cout;
using std::vector;

class Network;

class TNeuron
{
	public:
		friend Network;
		TNeuron();
		TNeuron(int numInputs,float learn);
		int snap(vector<int> inputs);

		void addToWeight(int wi, float delta);
		void updateWeights(vector<int> inp, int expect);
		void setNumInputs(int numInputs);
		void setThreshold(int thr);
		void resetWeights(int range);
		void print();
		int sigmoid(int val);
		vector<float> weights;
	private:
		int result;
		int error;
		vector<int> lastInp;
		float learningRate;

};

#endif
