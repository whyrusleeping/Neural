#include "KnowledgeBase.h"

int main()
{
	KnowledgeBase kb;
	string rule = "((A & B) | C) -> D";
	cout << "breaking up " << rule << "\n";
	kb.AddRule(rule);

}
