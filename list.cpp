template <typename T>
List<T>::List()
{
    head = tail = nullptr;
    count = 0;
}

template <typename T>
List<T>::List(const List &l)
{
    head = tail = nullptr;
    count = 0;

    Elem<T> *temp = l.head;

    while (temp != nullptr)
    {
        add_tail(temp->data);
        temp = temp->next;
    }
}

template <typename T>
List<T>::~List()
{
    del_all();
}

template <typename T>
void List<T>::add_head(const T &value)
{
    Elem<T> *temp = new Elem<T>;

    temp->prev = nullptr;
    temp->data = value;
    temp->next = head;

    if (head != nullptr)
        head->prev = temp;

    if (count == 0)
        head = tail = temp;
    else
        head = temp;

    count++;
}

template <typename T>
void List<T>::add_tail(const T &value)
{
    Elem<T> *temp = new Elem<T>;
    temp->next = nullptr;
    temp->data = value;
    temp->prev = tail;

    if (tail != nullptr)
        tail->next = temp;

    if (count == 0)
        head = tail = temp;
    else
        tail = temp;

    count++;
}

template <typename T>
void List<T>::insert(int pos)
{
    if (pos == 0)
    {
        cout << "Input position: ";
        cin >> pos;
    }

    if (pos < 1 || pos > count + 1)
    {
        cout << "Incorrect position !!!\n";
        return;
    }

    if (pos == count + 1)
    {
        T value;
        cout << "Input new number: ";
        cin >> value;
        add_tail(value);
        return;
    }
    else if (pos == 1)
    {
        T value;
        cout << "Input new number: ";
        cin >> value;
        add_head(value);
        return;
    }

    int i = 1;
    Elem<T> *ins = head;

    while (i < pos)
    {
        ins = ins->next;
        i++;
    }

    Elem<T> *prev_ins = ins->prev;

    Elem<T> *temp = new Elem<T>;

    cout << "Input new number: ";
    cin >> temp->data;

    if (prev_ins != nullptr && count != 1)
        prev_ins->next = temp;

    temp->next = ins;
    temp->prev = prev_ins;
    ins->prev = temp;

    count++;
}

template <typename T>
void List<T>::del(int pos)
{
    if (pos == 0)
    {
        cout << "Input position: ";
        cin >> pos;
    }

    if (pos < 1 || pos > count)
    {
        cout << "Incorrect position !!!\n";
        return;
    }

    int i = 1;

    Elem<T> *del = head;

    while (i < pos)
    {
        del = del->next;
        i++;
    }

    Elem<T> *prev_del = del->prev;
    Elem<T> *after_del = del->next;

    if (prev_del != nullptr && count != 1)
        prev_del->next = after_del;

    if (after_del != nullptr && count != 1)
        after_del->prev = prev_del;

    if (pos == 1)
        head = after_del;

    if (pos == count)
        tail = prev_del;

    delete del;

    count--;
}

template <typename T>
void List<T>::print(int pos)
{
    if (pos < 1 || pos > count)
    {
        cout << "Incorrect position !!!\n";
        return;
    }

    Elem<T> *temp;

    if (pos <= count / 2)
    {
        temp = head;
        int i = 1;

        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
    }
    else
    {
        temp = tail;
        int i = 1;

        while (i <= count - pos)
        {
            temp = temp->prev;
            i++;
        }
    }

    cout << pos << " element: ";
    cout << temp->data << endl;
}

template <typename T>
void List<T>::print()
{
    if (count != 0)
    {
        Elem<T> *temp = head;
        cout << "( ";
        while (temp->next != nullptr)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }

        cout << temp->data << " )\n";
    }
}

template <typename T>
void List<T>::del_all()
{
    while (count != 0)
        del(1);
}

template <typename T>
int List<T>::get_count()
{
    return count;
}

template <typename T>
Elem<T> *List<T>::get_elem(int pos)
{
    Elem<T> *temp = head;

    if (pos < 1 || pos > count)
    {
        cout << "Incorrect position !!!\n";
        return nullptr;
    }

    int i = 1;

    while (i < pos && temp != nullptr)
    {
        temp = temp->next;
        i++;
    }

    if (temp == nullptr)
        return nullptr;
    else
        return temp;
}

template <typename T>
List<T> &List<T>::operator=(const List &l)
{
    if (this == &l)
        return *this;

    this->~List();

    Elem<T> *temp = l.head;

    while (temp != nullptr)
    {
        add_tail(temp->data);
        temp = temp->next;
    }

    return *this;
}

template <typename T>
List<T> List<T>::operator+(const List &l)
{
    List<T> result(*this);

    Elem<T> *temp = l.head;

    while (temp != nullptr)
    {
        result.add_tail(temp->data);
        temp = temp->next;
    }

    return result;
}

template <typename T>
bool List<T>::operator==(const List &l)
{
    if (count != l.count)
        return false;

    Elem<T> *t1, *t2;

    t1 = head;
    t2 = l.head;

    while (t1 != nullptr)
    {
        if (t1->data != t2->data)
            return false;

        t1 = t1->next;
        t2 = t2->next;
    }

    return true;
}

template <typename T>
bool List<T>::operator!=(const List &l)
{
    return !(*this == l);
}

template <typename T>
bool List<T>::operator>=(const List &l)
{
    if (count > l.count)
        return true;

    if (*this == l)
        return true;

    return false;
}

template <typename T>
bool List<T>::operator<=(const List &l)
{
    if (count < l.count)
        return true;

    if (*this == l)
        return true;

    return false;
}

template <typename T>
bool List<T>::operator>(const List &l)
{
    if (count > l.count)
        return true;

    return false;
}

template <typename T>
bool List<T>::operator<(const List &l)
{
    if (count < l.count)
        return true;

    return false;
}

template <typename T>
List<T> List<T>::operator-()
{
    List<T> result;

    Elem<T> *temp = head;

    while (temp != nullptr)
    {
        result.add_head(temp->data);
        temp = temp->next;
    }

    return result;
}
