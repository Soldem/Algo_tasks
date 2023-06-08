#include <iostream>

using namespace std;

template <typename T>
class Node {
private:
    T value_;
    Node<T>* next_;

public:
    Node(T value, Node<T>* Next);

    void SetValue(T value);

    T GetValue();

    Node<T>* Next();
};

template <typename T>
class Stack {
private:
    Node<T>* head_;
    int size_;

public:
    Stack();

    void Push(T elem);

    T Pop();

    T Back();

    int Size();

    void Clear();

    void Exit();
};

int main() {
    Stack<int> stack;

    int iq;
    std::string command;

    while (true) {
        cin >> command;
        if (command == "push") {
            cin >> iq;
            stack.Push(iq);
            cout << "ok" << endl;
        }
        else if (command == "pop") {
            try {
                cout << stack.Pop() << endl;
            }
            catch (exception e) {
                cout << "error" << endl;
            }
        }
        else if (command == "back") {
            try {
                cout << stack.Back() << endl;
            }
            catch (exception e) {
                cout << "error" << endl;
            }
        }
        else if (command == "size") {
            cout << stack.Size() << endl;
        }
        else if (command == "clear") {
            stack.Clear();
            cout << "ok" << endl;
        }
        else if (command == "exit") {
            stack.Clear();
            cout << "bye" << endl;
            break;
        }
        else
            cout << "error command" << endl;
    }
}

template <typename T>
Node<T>::Node(T value, Node<T>* Next) {
    value_ = value;
    next_ = Next;
}

template <typename T>
void Node<T>::SetValue(T value) {
    value_ = value;
}

template <typename T>
T Node<T>::GetValue() {
    return value_;
}

template <typename T>
Node<T>* Node<T>::Next() {
    return next_;
}

template <typename T>
Stack<T>::Stack() {
    head_ = nullptr;
    size_ = 0;
}

template <typename T>
void Stack<T>::Push(T elem) {
    Node<T>* current = new Node<T>(elem, head_);
    head_ = current;
    size_++;
}

template <typename T>
T Stack<T>::Pop() {
    if (size_ == 0) {
        throw exception("error");
    }
    Node<T>* current = head_;

    head_ = current->Next();

    T elem = current->Next()->GetValue();
    delete current;
    size_--;

    return elem;
}

template <typename T>
T Stack<T>::Back() {
    if (size_ == 0) {
        throw exception("error");
    }
    return head_->GetValue();
}

template <typename T>
int Stack<T>::Size() {
    return size_;
}

template <typename T>
void Stack<T>::Clear() {
    Node<T>* temp;
    while (head_) {
        Node<T>* current = head_;
        head_ = head_->Next();
        delete current;
    }
    size_ = 0;
}
