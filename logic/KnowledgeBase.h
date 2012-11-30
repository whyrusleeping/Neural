#ifndef LOGIC_KNOWLEDGE_BASE_H
#define LOGIC_KNOWLEDGE_BASE_H
#include <string>
#include <vector>
#include <map>
#include "function.h"
#include "statement.h"
#include "variable.h"

#include <iostream>
using std::cout;

using std::map;
using std::vector;
using std::string;

class KnowledgeBase
{
	public:
		KnowledgeBase();
		void AddRule(LogicObject *rule);
		void AddRule(string rule);
	private:
		vector<LogicObject*> rules;
		map<string, LogicObject*> variables;
		void parse(string phrase);
		LogicObject *parseStatement(string s);
};

#endif
