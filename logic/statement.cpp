#include "statement.h"

bool Statement::GetTruth()
{
	if(!(left && right))
		return false;

	switch(op)
	{
		case AND:
			return left->GetTruth() && right->GetTruth();
		case OR:
			return left->GetTruth() || right->GetTruth();	
		case XOR:
			return left->GetTruth() != right->GetTruth();
		case IMPLIES:
			return right->GetTruth() || !left->GetTruth();
		case IFF:
			return left->GetTruth() == right->GetTruth();
		case NAND:
			return !(left->GetTruth() && right->GetTruth());
	}
}

void Statement::setRight(LogicObject *r)
{
	right = r;
}

void Statement::setLeft(LogicObject *l)
{
	left = l;
}

void Statement::setOp(Operator nop)
{
	op = nop;
}
