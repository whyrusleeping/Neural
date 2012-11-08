#ifndef J_NEURON_H
#define J_NEURON_H

#include <vector>

using std::vector;

class Neuron
{
	public:
		Neuron(int numInputs, int thr);
		int snap(vector<short> inputs);
	private:
		int thresh;
		vector<int> weights;

};

#endif
