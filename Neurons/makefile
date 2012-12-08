OPTFLAG=-O3

all: neuron.o network.o
	g++ simpleTest.cpp neuron.o network.o $(OPTFLAG) -o test

neuron.o: neuron.cpp
	g++ $(OPTFLAG) -c neuron.cpp

network.o: network.cpp
	g++ $(OPTFLAG) -c network.cpp

hw: 
	g++ hwtest.cpp ThreshNeuron.cpp $(OPTFLAG) -o hwork

clean:
	rm *.o
