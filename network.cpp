#include "network.h"

//Initialize network with one layer and 0 input/outputs
Network::Network()
{
	_network.resize(1);
	numOutputs = 0;
	numInputs = 0;
	learningRate = 0.3;
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
void Network::Train(vector<float> inputs, vector<float> expected)
{
	//Feed forward for results
	vector<float> results = Query(inputs);


	//Calculate output error.
	for(int i = 0; i < results.size(); i++)
	{
		//O * (1 - O) * (A - O) = error
		//Something to do with the derivative of the sigmoid function
		_network[_network.size() - 1][i].error = results[i] * (1 - results[i]) * (expected[i] - results[i]);
	}

	//Update the output weights
	int i = _network.size() - 1;
	for(int j = 0; j < _network[i].size(); j++) //for each neuron in the output layer...
	{
		_network[i][j].adjustForError();
	}

	//Back propogate the error
	//decrement i to move back to correct layer
	for(i--; i >= 0; i--)
	{
		for(int hid = 0; hid < _network[i].size(); hid++)
		{
			float backPropVal = 0;
			for(int bpvI = 0; bpvI < _network[i+1].size(); bpvI++)
			{
				//Summation of: (W_i * Err_i)
				backPropVal += (_network[i+1][bpvI].weights[hid] * _network[i+1][bpvI].error);
			}
			//Error = O * (1 - O) * E(W_i * Err_i)
			_network[i][hid].error = _network[i][hid].result * (1 - _network[i][hid].result) * backPropVal;

			//Update weights for hidden layer
			_network[i][hid].adjustForError();
		}
	}
}
