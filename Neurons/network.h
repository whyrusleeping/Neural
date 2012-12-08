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
		void SetLearningRate(float rate);

		void ResetNetwork();

		vector<float> Query(vector<float> inputs);
		void Train(const vector<float> &inputs,const vector<float> &expected);
		vector<vector<float> > TrainC(const vector<float> &inputs,const vector<float> &expected) const;
		void PrintNetwork();
	private:
		vector<vector<Neuron> > _network;
		int numInputs;
		int numOutputs;
		float learningRate;
};
#endif 
