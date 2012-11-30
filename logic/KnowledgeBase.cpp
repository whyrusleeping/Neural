#include "KnowledgeBase.h"

KnowledgeBase::KnowledgeBase()
{

}

void KnowledgeBase::AddRule(string rule)
{
	parseStatement(rule);
}

void KnowledgeBase::parse(string phrase)
{

}

LogicObject *KnowledgeBase::parseStatement(string s)
{
	int depth = 0;
	vector<string> pieces(3);
	int part = 0;

	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '(')
		{
			depth++;
			if(depth != 1)
				pieces[part] += s[i];
		}
		else if(s[i] == ')')
		{
			depth--;
			if(depth != 0)
				pieces[part] += s[i];
		}		
		else if(s[i] != ' ')
		{
			if(!isalpha(s[i]) && part == 0 && depth == 0)
			{
				part++;
			}
			else if(isalpha(s[i]) && part == 1)
			{
				part++;
			}
			pieces[part] += s[i];
		}

	}

	if(part == 0)
	{
		variables[pieces[0]] = new Variable();
		return variables[pieces[0]];
	}

	cout << "left: " << pieces[0] << "\n";
	cout << "oper: " << pieces[1] << "\n";
	cout << "right: " << pieces[2] << "\n";
	

	Statement *st = new Statement();

	bool LisText = true;
	for(int i = 0; i < pieces[0].length() && LisText; i++)
		LisText &= isalpha(pieces[0][i]);

	bool RisText = true;
	for(int i = 0; i < pieces[2].length() && RisText; i++)
		RisText &= isalpha(pieces[2][i]);
	
	if(LisText)
	{
		variables[pieces[0]] = new Variable();
		st->setLeft(variables[pieces[0]]);
	}
	else
	{
		st->setLeft(parseStatement(pieces[0]));
	}

	if(RisText)
	{
		variables[pieces[2]] = new Variable();
		st->setRight(variables[pieces[2]]);
	}
	else
	{
		st->setRight(parseStatement(pieces[2]));
	}

	return st;
}


