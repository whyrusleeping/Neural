#include "network.h"

//Initialize network with one layer and 0 input/outputs
Network::Network()
{
	_network.resize(1);
	numOutputs = 0;
	numInputs = 0;
	learningRate = 0.3;
	SetLearningRate(learningRate);
}

//Set the networks learning rate
void Network::SetLearningRate(float rate)
{
	for(int i = 0; i < _network.size(); i++)
	{
		for(int j = 0; j < _network[i].size(); j++)
		{
			_network[i][j].setLearningRate(rate);
		}
	}
}

//Set the number of output nodes in the network
void Network::SetNumOutputs(int noutp)
{
	numOutputs = noutp;
	_network[_network.size() -1].resize(noutp);
}

//Set the number of inputs to the network
void Network::SetNumInputs(int ninp)
{
	numInputs = ninp;
	for(int i = 0; i < _network[0].size(); i++)
	{
		_network[0][i].setNumInputs(ninp);
	}
}

//Set the depth of the network
void Network::SetDepth(int depth)
{
	_network.resize(depth);
}

//Set the height of the network at a given layer
void Network::SetNodeCountAtLevel(int count, int level)
{
	_network[level].resize(count);
}

//This function sets the number of inputs in each layer to the number of neruons in the previous layer
void Network::LinkNeurons()
{
	for(int i = 1; i < _network.size(); i++)
	{
		for(int j = 0; j < _network[i].size(); j++)
		{
			_network[i][j].setNumInputs(_network[i-1].size());
		}
	}
}

//Prints each neuron in each layer and the weights of each
void Network::PrintNetwork()
{
	for(int i = 0; i < _network.size(); i++)
	{
		cout << "Layer " << i << "\n";
		for(int j = 0; j < _network[i].size(); j++)
		{
			_network[i][j].print();
		}
	}
}

//Randomly sets the weights for each connection
void Network::ResetNetwork()
{
	for(int i = 0; i < _network.size(); i++)
	{
		for(int j = 0; j < _network[i].size(); j++)
		{
			_network[i][j].resetWeights(1);
		}
	}
}

//Applies the inputs to the network and returns the output
vector<float> Network::Query(vector<float> inputs)
{
	for(int i = 0; i < _network.size(); i++)
	{
		vector<float> lInp(_network[i].size());
		for(int j = 0; j < _network[i].size(); j++)
		{
			lInp[j] = _network[i][j].snap(inputs);
		}
		inputs = lInp;
	}
	return inputs;
}

//Train using back propogation
void Network::Train(const vector<float> &inputs,const vector<float> &expected)
{
	//Feed forward for results
	vector<float> results = Query(inputs);

	//Calculate output error.
	//O * (1 - O) * (A - O) = error
	for(int i = 0; i < results.size(); i++)
	{
		_network[_network.size() - 1][i].error = results[i] * (1 - results[i]) * (expected[i] - results[i]);
		//Update the output weights
		_network[_network.size() - 1][i].adjustForError();
	}	
	
	//Back propogate the error
	//decrement i to move back to the second to last layer
	for(int i = _network.size() - 2; i >= 0; i--)
	{
		for(int hid = 0; hid < _network[i].size(); hid++)
		{
			float backPropVal = 0;
			//Summation of: (W_i * Err_i)
			for(int bpvI = 0; bpvI < _network[i+1].size(); bpvI++)
				backPropVal += (_network[i+1][bpvI].weights[hid] * _network[i+1][bpvI].error);

			//Error = O * (1 - O) * E(W_i * Err_i)
			_network[i][hid].error = _network[i][hid].result * (1 - _network[i][hid].result) * backPropVal;

			//Update weights for hidden layer
			_network[i][hid].adjustForError();
		}
	}
}

//[Async]
//Train using back propogation without modifying the network during training.
vector<vector<float> > Network::TrainC(const vector<float> &inputs, const vector<float> &expected) const
{

	//Feed forward for results
	vector<float> results = inputs;
	for(int i = 0; i < _network.size(); i++)
	{
		vector<float> lInp(_network[i].size());
		for(int j = 0; j < _network[i].size(); j++)
		{
			lInp[j] = _network[i][j].snapC(results);
		}
		results = lInp;
	}

	//Calculate output error.
	//O * (1 - O) * (A - O) = error
	vector<vector<float> > error(_network.size());
	for(int i = 0; i < error.size(); i++)
		error[i].resize(_network[i].size());
	
	for(int i = 0; i < results.size(); i++)
	{
		error[error.size() - 1][i] = results[i] * (1 - results[i]) * (expected[i] - results[i]);
		//Update the output weights
		//_network[_network.size() - 1][i].adjustForError(); //dont update weights for async
	}	
	
	//Back propogate the error
	//decrement i to move back to the second to last layer
	for(int i = _network.size() - 2; i >= 0; i--)
	{
		for(int hid = 0; hid < _network[i].size(); hid++)
		{
			float backPropVal = 0;
			//Summation of: (W_i * Err_i)
			for(int bpvI = 0; bpvI < _network[i+1].size(); bpvI++)
				backPropVal += (_network[i+1][bpvI].weights[hid] * error[i+1][bpvI]);

			//Error = O * (1 - O) * E(W_i * Err_i)
			error[i][hid] = _network[i][hid].result * (1 - _network[i][hid].result) * backPropVal;

			//Update weights for hidden layer
			//_network[i][hid].adjustForError();
		}
	}
}
