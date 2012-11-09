#ifndef J_NEURAL_NETWORK_H
#define J_NEURAL_NETWORK_H
#include "neuron.h"

class Network
{
	public:
		Network();
		
		void Init();

		void LinkNeurons();
		void SetNumInputs(int ninp);
		void SetNumOutputs(int noutp);
		void SetDepth(int depth);
		void SetNodeCountAtLevel(int count, int level);
	
		void ResetNetwork();

		vector<int> Query(vector<int> inputs);
	private:
		vector<vector<Neuron> > _network;
		int numInputs;
		int numOutputs;
};
#endif 
