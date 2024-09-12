#include <iostream>
#include <set>

using namespace std;

class NumberList
{
public:
    multiset<int> numbers;

    void insertNumber(int value)
    {
        numbers.insert(value);
        printMinValue();
    }

    void printMinValue() const
    {
        if (numbers.empty())
        {
            cout << "Empty" << endl;
        }
        else
        {
            cout << *numbers.begin() << endl;
        }
    }

    void deleteMinValue()
    {
        if (numbers.empty())
        {
            cout << "Empty" << endl;
        }
        else
        {
            numbers.erase(numbers.begin());
            printMinValue();
        }
    }
};

int main()
{
    int N;
    cin >> N;

    NumberList numberList;

    for (int i = 0; i < N; ++i)
    {
        int value;
        cin >> value;
        numberList.numbers.insert(value);
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i)
    {
        int command;
        cin >> command;

        if (command == 0)
        {
            int value;
            cin >> value;
            numberList.insertNumber(value);
        }
        else if (command == 1)
        {
            numberList.printMinValue();
        }
        else if (command == 2)
        {
            numberList.deleteMinValue();
        }
    }

    return 0;
}
