all: neuron.o network.o
	g++ simpleTest.cpp neuron.o network.o -o test

neuron.o: neuron.cpp
	g++ -c neuron.cpp

network.o: network.cpp
	g++ -c network.cpp

hw: 
	g++ hwtest.cpp ThreshNeuron.cpp -o hwork

clean:
	rm *.o
