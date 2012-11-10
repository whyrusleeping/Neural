#include <iostream>
#include "network.h"

using std::cout;

int main()
{
	//The goal for this test is to get the following input/output pairs
	//0101 = 00
	//1001 = 10
	//1010 = 11
	//0110 = 01

	srand(time(NULL));

	Network n;
	n.SetDepth(2);
	n.SetNodeCountAtLevel(2,0);
	n.SetNodeCountAtLevel(1,1);
	n.SetNumOutputs(1);
	n.SetNumInputs(2);
	n.LinkNeurons();

	vector<float> expect(1);
	expect[0] = 0.5;
	vector<float> test(2);
	test[0] = 0.35;
	test[1] = 0.9;

	n.ResetNetwork();
	n.PrintNetwork();
	vector<float> o = n.Query(test);

	cout << "result:\n";
	for(int i = 0; i < o.size(); i++)
	{
		cout << o[i] << "\n";
	}

	int qwe = 100;
	while(qwe--)
		n.Train(test, expect);

	o = n.Query(test);
	cout << "Result: " << o[0] << "\n";


	return 0;
}
