#include <iostream>

using namespace std;

template <typename T>
class Node {
 private:
  T value_;
  Node<T>* next_;

 public:
  Node(T value, Node<T>* next);

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
      stack.push(iq);
    } else if (command == "pop") {
      stack.pop();
    }

    else if (command == "back") {
      stack.back();
    }

    else if (command == "size") {
      stack.size();
    }

    else if (command == "clear") {
      stack.clear();
    }

    else if (command == "exit") {
      stack.exit();
      break;
    } else
      cout << "error command" << endl;
  }
}

template <typename T>
Node<T>::Node(T value, Node<T>* next) {
  value_ = value;
  next_ = next;
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
  cout << "ok" << endl;
}

template <typename T>
T Stack<T>::Pop() {
  if (size_ <= 0 || !head_) {
    cout << "error" << endl;
    return 0;
  }
  Node<T>* current = head_;
  head_ = current->next();
  T elem = current->GetValue();
  delete current;
  size_--;
  cout << elem << endl;
  return elem;
}

template <typename T>
T Stack<T>::Back() {
  if (size_ <= 0 || !head_) {
    cout << "error" << endl;
    return 0;
  }
  cout << head_->GetValue() << endl;
  return head_->GetValue();
}

template <typename T>
int Stack<T>::Size() {
  cout << size_ << endl;
  return size_;
}

template <typename T>
void Stack<T>::Clear() {
  Node<T>* next = head_;
  while (next) {
    Node<T>* current = next;
    next = current->next();
    delete current;
  }
  head_ = nullptr;
  size_ = 0;
  cout << "ok" << endl;
}

template <typename T>
void Stack<T>::Exit() {
  cout << "bye" << endl;
}