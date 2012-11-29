#ifndef NEUR_SYNAPSE_H
#define NEUR_SYNAPSE_H

#include "neuron.h"

class Synapse
{
	public:
		Synapse();
		Synapse(Neuron *top);

		void SetInVal(float inp);
		void addOutput(Neuron *o);
	private:
		Neuron *parent;
		vector<Neuron*> outputs;
		float value;
};
#endif
