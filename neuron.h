#ifndef J_NEURON_H
#define J_NEURON_H

#include <vector>
#include <iostream>
#include <cstdlib>

using std::cout;
using std::vector;

class Network;

class Neuron
{
	public:
		friend Network;
		Neuron();
		Neuron(int numInputs);
		float snap(vector<float> inputs);

		void setNumInputs(int numInputs);
		void setThreshold(float thr);
		void resetWeights(int range);
		void print();
	private:
		float result;
		vector<float> weights;
		vector<float> lastInp;

};

#endif
