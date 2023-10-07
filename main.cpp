#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack<int> intStack;

    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    cout << "Stack Size: " << intStack.size() << endl;

    while (!intStack.is_empty())
    {
        cout << "Pop: " << intStack.pop() << endl;
    }

    return 0;
}
