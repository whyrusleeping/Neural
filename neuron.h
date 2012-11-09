#ifndef J_NEURON_H
#define J_NEURON_H

#include <vector>
#include <iostream>
#include <cstdlib>

using std::cout;
using std::vector;

class Neuron
{
	public:
		Neuron();
		Neuron(int numInputs, float thr);
		int snap(vector<int> inputs);

		void setNumInputs(int numInputs);
		void setThreshold(float thr);
		void resetWeights(int range);
		void print();
	private:
		float thresh;
		vector<float> weights;

};

#endif
