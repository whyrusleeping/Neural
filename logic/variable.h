#ifndef LOGIC_VARIABLE_H
#define LOGIC_VARIABLE_H
#include "logicObject.h"

class Variable : public LogicObject
{
	public:
		Variable() {}
		Variable(bool truth) : val(truth){};
		bool GetTruth(){return val;};
		
		bool val;
		
		int label;
};

#endif
