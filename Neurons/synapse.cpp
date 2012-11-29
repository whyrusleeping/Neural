#include "synapse.h"

Synapse::Synapse()
{

}

Synapse::Synapse(Neuron *top)
{
	this->parent = top;
}

void Synapse::addOutput(Neuron *o)
{ 
	outputs.push_back(o);	
}

void Synapse::SetInVal(float inp)
{
	value = inp;
	for(int i = 0; i < outputs.size(); i++)
	{
		
	}
}
