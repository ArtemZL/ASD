#include <iostream>
#include <queue>
#include <string>
using namespace std;

bool check_argument_1(string x)
{
	bool check_bool = true;
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] != '0' && x[i] != '1')
		{
			check_bool = false;
		}
	}
	return check_bool;
}

bool check_argument_2(string x)
{
	bool check_bool = true;
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] != '|' && x[i] != '*')
		{
			check_bool = false;
		}
	}
	return check_bool;
}

// конвертую бінарні числа в унарні
string convert_binary(string expression)
{
	if (!check_argument_1(expression))
	{
		throw invalid_argument("This string can not be operated.");
	}

	string ressult = expression;
link:
	for (int i = 0; i < ressult.size(); i++)
	{
		if (ressult[i] == '1')
		{
			ressult.erase(i, 1);
			ressult.insert(i, "0|");
		}
	}
	for (int i = 0; i < ressult.size() - 1; i++)
	{
		if (ressult[i] == '|' && ressult[i + 1] == '0')
		{
			ressult.erase(i, 2);
			ressult.insert(i, "0||");
			goto link;
		}
	}
	for (int i = 0; i < ressult.size(); i++)
	{
		if (ressult[i] == '0')
		{
			ressult.erase(i, 1);
			goto link;
		}
	}
	return ressult;
}

//множення унарних чисел
string multiply(string expression)
{
	if (!check_argument_2(expression))
	{
		throw invalid_argument("This string can not be operated.");
	}
	string ressult = expression;
link:
	for (int i = 0; i < ressult.size() - 1; i++)
	{
		if (ressult[i] == '|' && ressult[i + 1] == 'b')
		{
			ressult.erase(i, 2);
			ressult.insert(i, "ba|");
			goto link;
		}
	}
	for (int i = 0; i < ressult.size() - 1; i++)
	{
		if (ressult[i] == 'a' && ressult[i + 1] == 'b')
		{
			ressult.erase(i, 2);
			ressult.insert(i, "ba");
			goto link;
		}
	}
	for (int i = 0; i < ressult.size(); i++)
	{
		if (ressult[i] == 'b')
		{
			ressult.erase(i, 1);
			goto link;
		}
	}
	for (int i = 0; i < ressult.size() - 1; i++)
	{
		if (ressult[i] == '*' && ressult[i + 1] == '|')
		{
			ressult.erase(i, 2);
			ressult.insert(i, "b*");
			goto link;
		}
	}
	for (int i = 0; i < ressult.size(); i++)
	{
		if (ressult[i] == '*')
		{
			ressult.erase(i, 1);
			ressult.insert(i, "c");
			goto link;
		}
	}
	for (int i = 0; i < ressult.size() - 1; i++)
	{
		if (ressult[i] == '|' && ressult[i + 1] == 'c')
		{
			ressult.erase(i, 2);
			ressult.insert(i, "c");;
			goto link;
		}
	}
	for (int i = 0; i < ressult.size() - 1; i++)
	{
		if (ressult[i] == 'a' && ressult[i + 1] == 'c')
		{
			ressult.erase(i, 2);
			ressult.insert(i, "c|");
			goto link;
		}
	}
	for (int i = 0; i < ressult.size(); i++)
	{
		if (ressult[i] == 'c')
		{
			ressult.erase(i, 1);
			goto link;
		}
	}
	return ressult;
}


int main()
{
	string binary_expression = "101";
	string unary_result;
	try
	{
		unary_result = convert_binary(binary_expression);
		cout << "Unary representation of " << binary_expression << ": " << unary_result << endl;
	}
	catch (const invalid_argument& e)
	{
		cerr << "Error: " << e.what() << endl;
	}

	string unary_expression = "a|b|";
	string multiplication_result;
	try
	{
		multiplication_result = multiply(unary_expression);
		cout << "Multiplication result of " << unary_expression << ": " << multiplication_result << endl;
	}
	catch (const invalid_argument& e)
	{
		cerr << "Error: " << e.what() << endl;
	}
	return 0;
}