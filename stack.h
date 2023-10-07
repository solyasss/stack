#include "list.h"
#include "stack.cpp"

template <typename T>
class Stack
{
private:
    List<T> list;

public:
    void push(const T &value);
    T pop();
    bool is_empty() const;
    int size() const;
};
