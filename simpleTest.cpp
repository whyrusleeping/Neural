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
	n.SetNodeCountAtLevel(4,0);
	n.SetNodeCountAtLevel(1,1);
	n.SetNumOutputs(1);
	n.SetNumInputs(2);
	n.LinkNeurons();

	vector<float> expect(1);
	expect[0] = 0.2;
	vector<float> test(2);
	test[0] = 0.35;
	test[1] = 0.9;

	vector<float> testb(2);
	testb[0] = 0.7;
	testb[1] = 0.12;
	vector<float> expectb(1);
	expectb[0] = 0.8;

	n.ResetNetwork();
	n.PrintNetwork();
	vector<float> o = n.Query(test);
	
	float a = 5.4;
	a -= 5.4;
	cout << 0.0 * 5.4 << "\n";

	cout << "Expected: " << expect[0] << " " << expectb[0] <<  "\n";
	std::cin.ignore();

	cout << "Initial result: " << o[0] << "\n";
	o = n.Query(testb);
	cout << "Initial result: " << o[0] << "\n";

	int qwe = 200;
	while(qwe--)
	{
		n.Train(test, expect);
		n.Train(testb, expectb);
		n.PrintNetwork();
		std::cin.ignore();
	}

	o = n.Query(test);
	cout << "Trained Result: " << o[0] << "\n";
	o = n.Query(testb);
	cout << "Trained Result: " << o[0] << "\n";
	n.PrintNetwork();
	return 0;
}
