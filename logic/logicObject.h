#ifndef LOGIC_OBJECT_H
#define LOGIC_OBJECT_H

class LogicObject
{
	public:
		virtual bool GetTruth()=0;
	protected:
		bool negated;
};
#endif
