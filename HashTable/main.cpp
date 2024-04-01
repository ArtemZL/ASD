#include <iostream>
using namespace std;

struct TableElem
{
    char key = char(0);
    int value = 0;

    TableElem(char xkey = ' ', int xvalue = 0) : key(xkey), value(xvalue) {}

    void print_table_elem()
    {
        cout << "Elements key: " << key << "; value: " << value << endl;
    }

    bool is_not_empty_row()
    {
        bool x = false;
        if (key != '0')
        {
            x = true;
        }
        return x;
    }
};

class HashTable
{
private:
    unsigned int Size = 10;
    TableElem* table = new TableElem[Size];
public:
    HashTable()
    {
        TableElem empty_element('0', 0);
        for (int i = 0; i < Size; i++)
        {
            table[i] = empty_element;
        }
    }

    int get_hash(char key)
    {
        int hash = key % Size;
        return hash;
    }

    void add_row(TableElem new_row)
    {
        int hash = get_hash(new_row.key);
        int rehash = 0;
        int cycle_index = 0;

        while (table[(hash + rehash) % Size].key != '0')
        {
            if (cycle_index == Size)
            {
                cout << "The table is full." << endl;
                break;
            }

            cycle_index++;
            rehash++;
        }


        if (cycle_index != Size)
        {
            table[(hash + rehash) % Size] = new_row;
        }
    }

    bool find_by_key(char key)
    {
        bool found = false;
        int hash = get_hash(key);
        int rehash = 0;
        int cycle_index = 0;

        while (table[(hash + rehash) % Size].key != key)
        {
            if (cycle_index == Size)
            {
                break;
            }

            cycle_index++;
            rehash++;
        }


        if (cycle_index != Size)
        {
            found = true;
        }
        return found;
    }


    void find_and_print_elem(char key)
    {
        int hash = get_hash(key);
        int rehash = 0;
        int cycle_index = 0;

        while (table[(hash + rehash) % Size].key != key)
        {
            if (cycle_index == Size)
            {
                cout << "The element is not found." << endl;
                break;
            }

            cycle_index++;
            rehash++;
        }


        if (cycle_index != Size)
        {
            cout << "The founded element: ";
            table[(hash + rehash) % Size].print_table_elem();
        }
    }

    bool full_check()
    {
        bool check_bool = true;
        for (int i = 0; i < Size; i++)
        {
            if (table[i].key == '0')
            {
                check_bool = false;
                break;
            }
        }
        return check_bool;
    }
    unsigned int get_size()
    {
        return Size;
    }
};


int main()
{
    HashTable hash_table;

    hash_table.add_row(TableElem('A', 10));
    hash_table.add_row(TableElem('B', 20));
    hash_table.add_row(TableElem('C', 30));
    hash_table.add_row(TableElem('D', 40));
   
    hash_table.find_and_print_elem('B');
    hash_table.find_and_print_elem('E');

    if (hash_table.full_check())
    {
        cout << " The table is full " << endl;
    }
    else
    {
        cout << " The table isn't full " << endl;
    }
    unsigned table_size = hash_table.get_size();
    cout << "The size of the table is: " << table_size << endl;

    return 0;
}