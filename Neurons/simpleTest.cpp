#include <iostream>
#include "network.h"

using std::cout;

int main()
{
	srand(time(NULL));

	Network n;
	n.SetDepth(2);
	n.SetNodeCountAtLevel(500,0);
	n.SetNodeCountAtLevel(3,1);
	//n.SetNodeCountAtLevel(1,2);
	n.SetNumOutputs(1);
	n.SetNumInputs(2);
	n.LinkNeurons();
	n.SetLearningRate(0.2);

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

	vector<float> expectc(1);
	expectc[0] = 0.64;
	vector<float> testc(2);
	testc[0] = 0.8;
	testc[1] = 0.8;

	n.ResetNetwork(); //Randomize Weights
	n.PrintNetwork();
	vector<float> o = n.Query(test);
	

	cout << "Expected: " << expect[0] << " " << expectb[0] << " " << expectc[0] << "\n";

	float resA = o[0];
	cout << "Initial result: " << o[0] << "\n";
	o = n.Query(testb);
	cout << "Initial result: " << o[0] << "\n";


	int qwe = 100000;
	//while(qwe--)
	//{
	//	n.Train(test, expect);
	//	n.Train(testb, expectb);
	//}
	vector<float> rexp(1);
	vector<float> rinp(2);
	while(qwe--)
	{
		rinp[0] = (rand() % 200) / 100.0;
		rinp[1] = (rand() % 200) / 100.0;
		rexp[0] = rinp[0] * rinp[1];
		n.Train(rinp, rexp);
	}

	o = n.Query(test);
	cout << "Trained Result: " << o[0] << "\n";
	o = n.Query(testb);
	cout << "Trained Result: " << o[0] << "\n";

	o = n.Query(testc);
	cout << "Trained Result: " << o[0] << "\n";
	return 0;
}
