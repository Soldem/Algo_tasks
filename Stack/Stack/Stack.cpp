#include <iostream>

using namespace std;

template<typename T>
class Node
{
private:
    T _value;
    Node<T>* _next;

public:
    Node(T value, Node<T>* next);

    void set_value(T value);

    T get_value();

    Node<T>* next();
};

template<typename T>
class Stack
{
private:
    Node<T>* _head;
    int _size;

public:
    Stack();

    void push(T elem);

    T pop();

    T back();

    int size();

    void clear();

    void exit();
};

int main()
{
    Stack<int> stack;

    int iq;
    std::string command;

    while (true)
    {
        cin >> command;
        if (command == "push")
        {
            cin >> iq;
            stack.push(iq);
        }
        else if (command == "pop")
            stack.pop();
        else if (command == "back")
            stack.back();
        else if (command == "size")
            stack.size();
        else if (command == "clear")
            stack.clear();
        else if (command == "exit") {
            stack.exit();
            break;
        }
        else
            cout << "error command" << endl;
    }
}

template<typename T>
Node<T>::Node(T value, Node<T>* next)
{
    _value = value;
    _next = next;
}

template<typename T>
void Node<T>::set_value(T value)
{
    _value = value;
}

template<typename T>
T Node<T>::get_value()
{
    return _value;
}

template<typename T>
Node<T>* Node<T>::next()
{
    return _next;
}

template<typename T>
Stack<T>::Stack()
{
    _head = nullptr;
    _size = 0;
}

template<typename T>
void Stack<T>::push(T elem)
{
    Node<T>* current = new Node<T>(elem, _head);
    _head = current;
    _size++;
    cout << "ok" << endl;
}

template<typename T>
T Stack<T>::pop()
{
    if (_size <= 0 || !_head)
    {
        cout << "error" << endl;
        return 0;
    }
    Node<T>* current = _head;
    _head = current->next();
    T elem = current->get_value();
    delete current;
    _size--;
    cout << elem << endl;
    return elem;
}

template<typename T>
T Stack<T>::back()
{
    if (_size <= 0 || !_head)
    {
        cout << "error" << endl;
        return 0;
    }
    cout << _head->get_value() << endl;
    return _head->get_value();
}

template<typename T>
int Stack<T>::size()
{
    cout << _size << endl;
    return _size;
}

template<typename T>
void Stack<T>::clear()
{
    Node<T>* next = _head;
    while (next)
    {
        Node<T>* current = next;
        next = current->next();
        delete current;
    }
    _head = nullptr;
    _size = 0;
    cout << "ok" << endl;
}

template<typename T>
void Stack<T>::exit()
{
    cout << "bye" << endl;
}
