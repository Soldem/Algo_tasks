#include <iostream>
#include <string>

using namespace std;

template<typename T>
class DynamicArray
{
private:
    T* _mas;
    int _size;
    int _capacity;

public:
    DynamicArray();

    ~DynamicArray();

    void push(T elem);

    T pop();

    T at_i(int i);

    void resize(int size);

    int size();

    int capacity();

    void clear();

    void exit();
};

int main()
{
    DynamicArray<int> arr;

    string command;
    int num;
    while (true)
    {
        cin >> command;

        if (command == "push")
        {
            cin >> num;
            arr.push(num);
        }
        else if (command == "at")
        {
            cin >> num;
            arr.at_i(num);
        }
        else if (command == "capacity")
        {
            arr.capacity();
        }
        else if (command == "pop")
        {
            arr.pop();
        }
        else if (command == "size")
        {
            arr.size();
        }
        else if (command == "resize")
        {
            cin >> num;
            arr.resize(num);
        }
        else if (command == "clear")
        {
            arr.clear();
        }
        else if (command == "exit")
        {
            arr.exit();
            break;
        }
    }
}

template<typename T>
DynamicArray<T>::DynamicArray()
{
    _mas = new T[1];
    _size = 0;
    _capacity = 1;
}

template<typename T>
void DynamicArray<T>::push(T elem)
{
    if (_size >= _capacity)
    {
        _capacity *= 2;
        T* tmp = new T[_capacity];
        for (int i = 0; i < _size; i++)
        {
            tmp[i] = _mas[i];
        }
        if (_mas) delete[] _mas;
        _mas = tmp;
    }

    _mas[_size] = elem;
    _size++;
    cout << "ok" << endl;
}

template<typename T>
T DynamicArray<T>::pop()
{
    if (_size == 0)
    {
        cout << "error" << endl;
        return 0;
    }
    T elem = _mas[_size - 1];

    _size--;
    _capacity = _size;
    
    T* tmp = new T[_capacity];
    for (int i = 0; i < _size; i++)
    {
        tmp[i] = _mas[i];
    }
    if (_mas) delete[] _mas;
    _mas = tmp;

    cout << elem << endl;
    return elem;
}

template<typename T>
T DynamicArray<T>::at_i(int i)
{
    if (i < 0 || i >= _size)
    {
        cout << "error" << endl;
        return 0;
    }
    cout << _mas[i] << endl;
    return _mas[i];
}

template<typename T>
void DynamicArray<T>::resize(int size)
{
    if (size < 0)
    {
        cout << "error" << endl;
        return;
    }
    T* tmp = new T[size];
    int new_size = (_size < size ? _size : size);
    for (int i = 0; i < new_size; i++)
    {
        tmp[i] = _mas[i];
    }
    if (_mas) delete[] _mas;
    _mas = tmp;
    _size = new_size;
    _capacity = size;
    cout << "ok" << endl;
}

template<typename T>
int DynamicArray<T>::size()
{
    cout << _size << endl;
    return _size;
}

template<typename T>
int DynamicArray<T>::capacity()
{
    cout << _capacity << endl;
    return _capacity;
}

template<typename T>
void DynamicArray<T>::clear()
{
    if (_mas) delete[] _mas;
    _mas = new T[1];
    _capacity = 1;
    _size = 0;
    cout << "ok" << endl;
}

template<typename T>
DynamicArray<T>::~DynamicArray() {

    clear();
}

template<typename T>
void DynamicArray<T>::exit()
{
    cout << "bye" << endl;
}
