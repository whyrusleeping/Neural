#ifndef LOGIC_FUNCTION_H
#define LOGIC_FUNCTION_H
#include "logicObject.h"

class Function : public LogicObject
{
	public:
		Function(bool (*func)(void), int Label)
		{
			tfunc = func;
		}
		bool GetTruth()
		{
			return (*tfunc)();
		}

		int label;
	private:
		bool (*tfunc) (void);
};

#endif
