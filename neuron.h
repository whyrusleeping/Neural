#ifndef J_NEURON_H
#define J_NEURON_H

#include <vector>

using std::vector;

class Neuron
{
	public:
		Neuron();
		Neuron(int numInputs, float thr);
		int snap(vector<short> inputs);

		void setNumInputs(int numInputs);
		void setThreshold(float thr);
		void resetWeights(int range);
	private:
		float thresh;
		vector<float> weights;

};

#endif
