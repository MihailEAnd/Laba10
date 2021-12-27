#include <iostream>
#include <iostream>
#include <stdlib.h>
using namespace std;
using std::cout;
using std::cin;

struct Node
{
    int x;
    Node* Next;
};
class Array
{
    Node* Head, * Tail;
public:
    Array() :Head(NULL), Tail(NULL) {};
    ~Array();
    void Push(int x);
    void Peek();
    void Pop();
    friend ostream& operator << (ostream& stream, const Array& a);
};
Array::~Array()
{
    Node* temp = Head;
    while (temp != 0)
    {
        temp = Head->Next;
        delete Head;
        Head = temp;
    }
}
void Array::Push(int x)
{
    Node* temp = new Node;
    temp->x = x;
    temp->Next = NULL;

    if (Head != NULL)
    {
        Tail->Next = temp;
        Tail = temp;
    }
    else Head = Tail = temp;
}
ostream& operator << (ostream& stream, const Array& a)
{
    Node* temp = a.Head;
    while (temp != NULL)
    {
        stream << temp->x << "";
        temp = temp->Next;
    }
    return stream << endl;
}
void Array::Peek()
{
    cout << Head->x;
}
void Array::Pop()
{
    Head = Head->Next;
}

class Exception
{
public:
    virtual const string GetError() const = 0;
};

inline const string Exception::GetError() const
{
    return "\n ERROR ";
}

class OverflowException : public Exception
{
public:
    virtual const string GetError() const override
    {
        return Exception::GetError() + "NOT ENOUGH FREE SPACE";
    }
};

class NoElementsException : public Exception
{
public:
    virtual const string GetError() const override
    {
        return Exception::GetError() + "NO ELEMENTS";
    }
};

void main()
{
    Array arr;
    int size, count;
    cout << "Size = ";
    cin >> size;
    try {
        if (size >= 30) throw OverflowException();
        else {
            for (int i = 1; i <= size; i++)
            {
                cout << "Count " << i << "/" << size << " = ";
                cin >> count;
                arr.Push(count);
            }
            cout << arr;
            if (NULL) throw OverflowException();
            else {
            arr.Peek();
            arr.Pop();
        }
    }
}
    catch (Exception& exception)
    {
        exception.GetError();
    }
    cout << endl;
    cout << arr;
}

