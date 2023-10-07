#include <iostream>
using namespace std;

template <typename T>
void Stack<T>::push(const T &value)
{
    list.add_head(value);
}

template <typename T>
T Stack<T>::pop()
{
    if (is_empty())
    {
        cout << "Stack is empty!" << endl;
    }

    T value = list.getElem(1)->data;
    list.del(1);

    return value;
}

template <typename T>
bool Stack<T>::is_empty() const
{
    return list.get_count() == 0;
}

template <typename T>
int Stack<T>::size() const
{
    return list.get_count();
}
