#include<iostream>
#include<stdio.h>
using namespace std;
class Parser
{
public:
	char token_buffer[2];
	char c_t;
	int f;
	void init()
	{
		token_buffer[0] = 'n';
		token_buffer[1] = ')';
		//token_buffer[2] = ')';

		/*token_buffer[3] = '*'; 
		token_buffer[4] = 'n'; 
		token_buffer[5] = '-'; 
		token_buffer[6] = 'n';*/
		
	}
	Parser()
	{
		init();
		f = 0;
		c_t = token_buffer[f];
	}
	void GetNextToken()
	{
		f++;
		c_t = token_buffer[f];
	}
	void ErrorHandler()
	{
		cout << "Syntax Error found\n";
		exit(0);
	}
	void E()
	{
		//    initialize();
		T();
		E_();
	}
	void T()
	{
		F();
		T_();
	}
	void E_()
	{

		switch (c_t)
		{
		case '+':
			GetNextToken();
			T();
			E_();
			break;

		case '-':
			GetNextToken();
			T();
			E_();
			break;

		default:
			//Errorhandler
			break;
		}

	}
	void F()
	{
		switch (c_t)
		{
		case 'n':
			GetNextToken();
			break;

		case '(':
			GetNextToken();
			E();
			if (c_t == ')')
			{
				GetNextToken();
			}
			else
			{
				ErrorHandler();
			}
			break;

		default:
			ErrorHandler();
			break;
		}

	}
	void T_()
	{
		switch (c_t)
		{
		case '*':
			GetNextToken();
			F();
			T_();
			break;

		default:
			//Errorhandler
			break;
		}
	}

};
int main()
{
	Parser p = Parser();
	p.E();
	cout << "Syntax is correct\n";
	return 0;
}