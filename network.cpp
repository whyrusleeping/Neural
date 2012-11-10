#include "network.h"

//Initialize network with one layer and 0 input/outputs
Network::Network()
{
	_network.resize(1);
	numOutputs = 0;
	numInputs = 0;
	learningRate = 0.5;
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

/*
void Network::Train(vector<float> inputs, vector<float> expected)
{
	//First, run the given inputs through the network and get the output
	vector<float> actual = Query(inputs);

	//Next, Calculate the error. That is, the difference between the actual and expected for each output node
	vector<float> error(actual.size());
	for(int i = 0; i < expected.size(); i++)
	{
		error[i] = actual[i] * (1 - actual[i]) * (expected[i] - actual[i]);
	}

	//Now update the weights
	for(int i = _network.size() - 1; i > 0; i--) //for each layer..
	{
		for(int j = 0; j < _network[i].size(); j++) //for each neuron in that layer...
		{
			for(int wt = 0; wt < _network[i][j].weights.size(); wt++) //for each weight in that 
			{
				_network[i][j].weights[wt] += learningRate * error[j] * _network[i][j].result; //update the weight
			}
		}

		//now, for each neuron in the parent layer, calculate the new error
		//back propogate the errors
		vector<float> nError(_network[i-1].size());
		for(int ne = 0; ne < _network[i-1].size(); ne++)
		{			
			float ernum = 0; //Sum up the errors for one layer back
			for(int lno = 0; lno < _network[i].size(); lno++)
				ernum += (_network[i][lno].weights[ne] * error[lno]);
			
			nError[ne] = _network[i-1][ne].result * (1 - _network[i-1][ne].result) * ernum;
			
			//Now that we have the error for a given node, use it to modify the weights
			for(int ner = 0; ner < _network[i-1][ne].weights.size(); ner++)
			{
				
			}
		}

	}

}*/


void Network::Train(vector<float> inputs, vector<float> expected)
{
	vector<float> results = Query(inputs);

	vector<float> error(results.size());

	//Calculate output error.
	for(int i = 0; i < results.size(); i++)
	{
		error[i] = results[i] * (1 - results[i]) * (expected[i] - results[i]);
	}

	//Update the output weights
	int i = _network.size() - 1;
	for(int j = 0; j < _network[i].size(); j++) //for each neuron in the output layer...
	{
		for(int wt = 0; wt < _network[i][j].weights.size(); wt++) //for each weight in that 
		{
			_network[i][j].weights[wt] += learningRate * error[j] * _network[i][j].lastInp[wt]; //update the weight
		}
	}

	//Back propogate the error
	i--; //decrement i to move back to correct layer
	for(int hid = 0; hid < _network[i].size(); hid++)
	{
		float backPropVal = 0;
		for(int bpvI = 0; bpvI < _network[i+1].size(); bpvI++)
			backPropVal += (_network[i+1][bpvI].weights[hid] * error[bpvI]);
		_network[i][hid].error = _network[i][hid].result * (1 - _network[i][hid].result) * backPropVal;

		//Update weights for hidden layer
		for(int hidW = 0; hidW < _network[i][hid].weights.size(); hidW++)
		{
			_network[i][hid].weights[hidW] += learningRate * _network[i][hid].error * _network[i][hid].lastInp[hidW];
		}
	}
}
