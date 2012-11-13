#include "ThreshNeuron.h"

using std::cin;

int main()
{
	TNeuron n;
	n.setNumInputs(3);
	for(int i = 0; i < 3; i++) {n.weights[i] = 1;};

	vector<vector<int> > inps;
	vector<int> exps(8);

	inps.resize(8);
	for(int i = 0; i < 8; i++) {inps[i].resize(4);};
	for(int i = 0; i < 8; i++)
	{
		if(i & 1)
			inps[i][0] = 1;
		if(i & 2)
			inps[i][1] = 1;
		if(i & 4)
			inps[i][2] = 1;
	}

	exps[0] = 1;
	exps[1] = 0;
	exps[2] = 1;
	exps[3] = 0;
	exps[4] = 1;
	exps[5] = 0;
	exps[6] = 0;
	exps[7] = 0;

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			n.updateWeights(inps[j], exps[j]);

			int tsum = 0;
			for(int k = 0; k < 8; k++)
			{
				tsum += abs(exps[k] - n.snap(inps[k]));
			}
			if(tsum == 0)
			{
				cout << i << " " << j << "\n";
				n.print();
				cin.ignore();
			}
		}
	}

	for(int i = 0; i < 8; i++)
	{
		cout << inps[i][0] << " " << inps[i][1] << " " << inps[i][2] << " output: " << n.snap(inps[i]) << "\n";

	}

	n.print();


}
