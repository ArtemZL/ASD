#include <iostream>
#include <vector>

using namespace std;

struct Element
{
	Element* upper_element = this;
	Element* left_element = this;
	//from 1 to N
	size_t row = 0;
	//from 1 to N
	size_t column = 0;
	double value;
};

class SparseMatrix
{
	size_t rows_count;
	size_t cols_count;
	vector<Element> cols;
	vector<Element> rows;

	Element* get_previous_by_row(size_t row, size_t column)
	{
		Element* prev = &rows[row];
		while (prev->left_element->column > column)
		{
			prev = prev->left_element;
		}
		return prev;
	}
	Element* get_previous_by_col(size_t row, size_t column)
	{
		Element* prev = &cols[column];
		while (prev->upper_element->row > row)
		{
			prev = prev->upper_element;
		}
		return prev;
	}
	//element does not exists
	//add it
	void add_value_impl(Element* previous_by_row, Element* previous_by_col, size_t row, size_t column, double value)
	{
		Element* new_element = new Element();
		new_element->row = row;
		new_element->column = column;
		new_element->value = value;
		new_element->left_element = previous_by_row->left_element;
		previous_by_row->left_element = new_element;
		new_element->upper_element = previous_by_col->upper_element;
		previous_by_col->upper_element = new_element;
	}
	void change_value_impl(Element* previous_by_row, Element* previous_by_col, size_t row, size_t column, double value)
	{
		if (value == 0)
		{
			Element* elem_to_del = previous_by_row->left_element;
			previous_by_row->left_element = elem_to_del->left_element;
			previous_by_col->upper_element = elem_to_del->upper_element;
			delete elem_to_del;
		}
		else
		{
			previous_by_row->left_element->value = value;
		}
	}

public:
	SparseMatrix(size_t _rows_count, size_t _cols_count) :rows_count(_rows_count), cols_count(_cols_count)
	{
		cols.resize(cols_count + 1);
		rows.resize(rows_count + 1);
	}
	//set a[row, column]
	//row = 1..row_count
	//column = 1..column_count
	void set_value(size_t row, size_t column, double value)
	{
		//get element that is previous by row and column
		Element* previous_by_row = get_previous_by_row(row, column);
		Element* previous_by_col = get_previous_by_col(row, column);
		//is there element in matrix?
		bool element_in_matrix = previous_by_col->upper_element->row == row && previous_by_col->upper_element->column == column;
		if (element_in_matrix)
		{
			change_value_impl(previous_by_row, previous_by_col, row, column, value);
		}
		else
		{
			add_value_impl(previous_by_row, previous_by_col, row, column, value);
		}
	}
	//get a[row, column]
	//row = 1..row_count
	//column = 1..column_count
	double get_value(size_t row, size_t column)
	{
		double ret_value = 0;
		Element* previous_by_col = get_previous_by_col(row, column);
		bool element_in_matrix = previous_by_col->upper_element->row == row &&
			previous_by_col->upper_element->column == column;
		if (element_in_matrix)
		{
			ret_value = previous_by_col->upper_element->value;
		}
		return ret_value;
	}

	void add(SparseMatrix& arg2)
	{
		for (size_t i = 1; i <= rows_count; i++)
		{
			for (size_t j = 1; j <= cols_count; j++)
			{
				double value = get_value(i, j) + arg2.get_value(i, j);
				set_value(i, j, value);
			}
		}
	}
	void Subtraction(SparseMatrix& arg2)
	{
		for (size_t i = 1; i <= rows_count; i++)
		{
			for (size_t j = 1; j <= cols_count; j++)
			{
				double value = get_value(i, j) - arg2.get_value(i, j);
				set_value(i, j, value);
			}
		}
	}

	void multiply(SparseMatrix& arg2)
	{
		double temp_value = 0;
		SparseMatrix x(rows_count, arg2.cols_count);

		for (int i = 1; i <= rows_count; i++)
		{
			for (int j = 1; j <= arg2.cols_count; j++)
			{
				for (int r = 1; r <= arg2.rows_count; r++)
				{
					temp_value += get_value(i, r) * arg2.get_value(r, j);
				}

				x.set_value(i, j, temp_value);
				temp_value = 0;
			}
		}

		cols_count = arg2.cols_count;
		for (int i = 1; i <= rows_count; i++)
		{
			for (int j = 1; j <= cols_count; j++)
			{
				set_value(i, j, x.get_value(i, j));
			}
		}
	}

	void transposition()
	{
		size_t t_rows = cols_count;
		size_t t_cols = rows_count;
		SparseMatrix temp_matrix(t_rows, t_cols);

		for (int i = 1; i <= cols_count; i++)
		{
			for (int j = 1; j <= rows_count; j++)
			{
				temp_matrix.set_value(j, i, get_value(i, j));
			}
		}

		rows_count = t_rows;
		cols_count = t_cols;
		for (int i = 1; i <= t_rows; i++)
		{
			for (int j = 1; j <= t_cols; j++)
			{
				set_value(i, j, temp_matrix.get_value(i, j));
			}
		}
	}

	void ptint_matrix()
	{
		for (int i = 1; i <= rows_count; i++)
		{
			for (int j = 1; j <= cols_count; j++)
			{
				cout << get_value(i, j) << " ";
				if (j == cols_count)
				{
					cout << endl;
				}
			}
		}
	}
};


int main()
{
	SparseMatrix matrix1(3, 3);
	SparseMatrix matrix2(3, 3);

	// Заповнення матриць значеннями
	matrix1.set_value(1, 1, 1.0);
	matrix1.set_value(2, 2, 2.0);
	matrix1.set_value(3, 3, 3.0);

	matrix2.set_value(1, 1, 4.0);
	matrix2.set_value(2, 2, 5.0);
	matrix2.set_value(3, 3, 6.0);
	cout << "Matrix1: " << endl;
	matrix1.ptint_matrix();
	cout << "Matrix2: " << endl;
	matrix2.ptint_matrix();
	cout << endl;

	// Додавання матриць
	cout << "Matrix1 + Matrix2:" << endl;
	matrix1.add(matrix2);
	matrix1.ptint_matrix();
	cout << endl;

	// Віднімання матриць
	cout << "Matrix1 - Matrix2:" << endl;
	matrix1.Subtraction(matrix2);
	matrix1.ptint_matrix();
	cout << endl;

	// Множення матриць
	cout << "Matrix1 * Matrix2:" << endl;
	matrix1.multiply(matrix2);
	matrix1.ptint_matrix();
	cout << endl;

	// Транспонування матриці
	cout << "Transpose of Matrix1:" << endl;
	matrix1.transposition();
	matrix1.ptint_matrix();
	cout << endl;

	return 0;
}