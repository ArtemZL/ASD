#include <iostream>
#include <stack>
#include <string>
using namespace std;

int check_priority(char x)
{
	switch (x)
	{
	case'#': case'(': case')':
		return 0;
		break;

	case'-': case'+':
		return 1;
		break;

	case'/': case'*':
		return 2;
		break;

	default:
		return -10;
		break;
	}
}

bool check_is_operation(char x)
{
	if (x == '*' || x == '+' || x == '-' || x == '/')
	{
		return true;
	}
	else
	{
		return false;
	}
}
string calculation(string ex)
{
	stack<char> operations;
	stack<char> pnotation;

	//перевід у польску нотацію
	for (int i = 0; i < ex.length(); i++)
	{
		if (isdigit(ex[i]))
		{
			pnotation.push(ex[i]);
		}

		else if (check_is_operation(ex[i])) // перевіряємо чи символ є операцією
		{
			if (!operations.empty())
			{
				while (check_priority(ex[i]) <= check_priority(operations.top()))
				{
					pnotation.push(operations.top());
					operations.pop();
					if (operations.empty())
					{
						break;
					}
				}
				operations.push(ex[i]);
			}
			else
			{
				operations.push(ex[i]);
			}
		}

		else if (ex[i] == '(')
		{
			operations.push(ex[i]);
		}

		else if (ex[i] == ')')
		{
			while (operations.top() != '(')
			{
				pnotation.push(operations.top());
				operations.pop();
			}
			operations.pop();
		}
	}
	while (!operations.empty())
	{
		pnotation.push(operations.top());
		operations.pop();
	}


	stack<char> pnotation2;
	stack<string> ressult;

	int temp_size = pnotation.size();
	for (int i = 0; i < temp_size; i++)
	{
		pnotation2.push(pnotation.top());
		pnotation.pop();
	}

	/*підрахування польскої нотації*/
	while (!pnotation2.empty())
	{
		if (check_is_operation(pnotation2.top()))
		{
			int a, b, res;
			a = stoi(ressult.top());
			ressult.pop();

			b = stoi(ressult.top());
			ressult.pop();

			if (pnotation2.top() == '+')
			{
				res = a + b;
				ressult.push(to_string(res));
			}
			if (pnotation2.top() == '-')
			{
				res = a - b;
				ressult.push(to_string(abs(res)));
			}
			if (pnotation2.top() == '/')
			{
				res = a / b;
				ressult.push(to_string(res));
			}
			if (pnotation2.top() == '*')
			{
				res = a * b;
				ressult.push(to_string(res));
			}
			pnotation2.pop();
		}
		else
		{
			char x = pnotation2.top();
			string y(1, x);
			ressult.push(y);
			pnotation2.pop();
		}
	}
	return ressult.top();
}


int main()
{
	string expression;
	cout << "Enter an arithmetic expression: ";
	getline(cin, expression);

	string result = calculation(expression);
	cout << "Result: " << result << endl;


	return 0;
}