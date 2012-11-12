#include <iostream>
#include "network.h"

using std::cout;

int main()
{
	srand(time(NULL));



	Network n;
	n.SetDepth(2);
	n.SetNodeCountAtLevel(3,0);
	n.SetNodeCountAtLevel(1,1);
	n.SetNumOutputs(1);
	n.SetNumInputs(2);
	n.LinkNeurons();

	vector<float> expect(1);
	expect[0] = 0.667;
	vector<float> test(2);
	test[0] = 0.334;
	test[1] = 0.248;

	vector<float> testb(2);
	testb[0] = 0.868;
	testb[1] = 0.512;
	vector<float> expectb(1);
	expectb[0] = 0.114;

	n.ResetNetwork();
	n.PrintNetwork();
	vector<float> o = n.Query(test);
	

	cout << "Expected: " << expect[0] << " " << expectb[0] <<  "\n";
	std::cin.ignore();

	cout << "Initial result: " << o[0] << "\n";
	o = n.Query(testb);
	cout << "Initial result: " << o[0] << "\n";

	int qwe = 300;
	while(qwe--)
	{
		n.Train(test, expect);
		n.Train(testb, expectb);
	}

	o = n.Query(test);
	cout << "Trained Result: " << o[0] << "\n";
	o = n.Query(testb);
	cout << "Trained Result: " << o[0] << "\n";
	return 0;
}
