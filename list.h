#include "list.cpp"

template <typename T>
struct Elem
{
    T data;
    Elem *next, *prev;
};

template <typename T>
class List
{
private:
    Elem<T> *head, *tail;
    int count;

public:
    List();
    List(const List &);
    ~List();

    int get_count();
    Elem<T> *get_elem(int);

    void del_all();
    void del(int pos = 0);
    void insert(int pos = 0);

    void add_tail(const T &value);
    void add_head(const T &value);

    void print();
    void print(int pos);

    List<T> &operator=(const List &);
    List<T> operator+(const List &);

    bool operator==(const List &);
    bool operator!=(const List &);
    bool operator<=(const List &);
    bool operator>=(const List &);
    bool operator<(const List &);
    bool operator>(const List &);

    List<T> operator-();
};
