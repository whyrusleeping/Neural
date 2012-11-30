#ifndef LOGIC_STATEMENT_H
#define LOGIC_STATEMENT_H
#include "logicObject.h"

typedef enum Operator
{
	AND, OR, IMPLIES, IFF, XOR, NAND
}Operator;

class Statement : public LogicObject
{
	public:

		bool GetTruth();
		void setLeft(LogicObject *l);
		void setRight(LogicObject *r);
		void setOp(Operator nop);
	private:
		Operator op;
		LogicObject *left;
		LogicObject *right;
};

#endif
