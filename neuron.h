#ifndef J_NEURON_H
#define J_NEURON_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>

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

		void updateWeight(int wi, float delta);
		void setNumInputs(int numInputs);
		void setThreshold(float thr);
		void resetWeights(int range);
		void print();
		float sigmoid(float val);
	private:
		float result;
		float error;
		vector<float> weights;
		vector<float> lastInp;

};

#endif
