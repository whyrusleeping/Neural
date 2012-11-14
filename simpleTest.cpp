#include <iostream>
#include "network.h"

using std::cout;

int main()
{
	srand(time(NULL));

	Network n;
	n.SetDepth(3);
	n.SetNodeCountAtLevel(2,0);
	n.SetNodeCountAtLevel(3,1);
	n.SetNodeCountAtLevel(1,2);
	n.SetNumOutputs(1);
	n.SetNumInputs(2);
	n.LinkNeurons();

	vector<float> expect(1);
	expect[0] = 0.06;
	vector<float> test(2);
	test[0] = 0.2;
	test[1] = 0.3;

	vector<float> expectb(1);
	expectb[0] = 0.2;
	vector<float> testb(2);
	testb[0] = 0.4;
	testb[1] = 0.5;

	n.ResetNetwork(); //Randomize Weights
	n.PrintNetwork();
	vector<float> o = n.Query(test);
	

	cout << "Expected: " << expect[0] << " " << expectb[0] <<  "\n";
	//std::cin.ignore();

	float resA = o[0];
	cout << "Initial result: " << o[0] << "\n";
	o = n.Query(testb);
	cout << "Initial result: " << o[0] << "\n";

	float resB = o[0];
	float erA = 0;
	float minErA = 1000;
	float erB = 0;
	float minErB = 1000;
	float minErr = 1000;
	int qwe = 300;
	while(qwe--)
	{
		n.Train(test, expect);
		n.Train(testb, expectb);
		o = n.Query(testb);
		erB = 0.5 * pow(expectb[0] - o[0], 2);
		if(erB < minErB)
		{
			minErB = erB;
		}
		o = n.Query(test);
		erA = 0.5 * pow(expect[0] - o[0],2);
		if(erA < minErA)
		{
			minErA = erA;
		}

		if(erA + erB < minErr)
		{
			minErr = erA + erB;
		}
		else
		{
			cout << "Total Error increasing from " << minErr << " " << erA + erB << "\n";
		}
	}

	o = n.Query(test);
	cout << "Trained Result: " << o[0] << "\n";
	o = n.Query(testb);
	cout << "Trained Result: " << o[0] << "\n";
	return 0;
}
