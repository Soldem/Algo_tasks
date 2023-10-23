#include <iostream>

using namespace std;

template <typename T>
class Stack {
 private:
  T arr_[10000];
  int size_;

 public:
  Stack();

  void Push(T elem);

  T Pop();

  T Back();

  int Size();

  void Clear();
};

int Command(std::string command, Stack<int>& stack) {
  int iq;

  try {
    if (command == "push") {
      cin >> iq;
      stack.Push(iq);
      cout << "ok" << endl;
    } else if (command == "pop") {
      cout << stack.Pop() << endl;
    } else if (command == "back") {
      cout << stack.Back() << endl;
    } else if (command == "size") {
      cout << stack.Size() << endl;
    } else if (command == "clear") {
      stack.Clear();
      cout << "ok" << endl;
    } else if (command == "exit") {
      stack.Clear();
      cout << "bye" << endl;
      return 0;
    } else {
      cout << "error command" << endl;
    }
  } catch (const char* message) {
    cout << "error" << endl;
  }
  return 1;
}

int main() {
  Stack<int> stack;
  std::string command;

  while (true) {
    std::cin >> command;
    if (Command(command, stack) == 0) {
      break;
    }
  }
}

template <typename T>
Stack<T>::Stack() {
  size_ = 0;
}

template <typename T>
void Stack<T>::Push(T elem) {
  if (size_ == 10000) {
    throw "error";
  }

  arr_[size_++] = elem;
}

template <typename T>
T Stack<T>::Pop() {
  if (size_ <= 0) {
    throw "error";
  }
  T value = arr_[size_ - 1];
  size_--;
  return value;
}

template <typename T>
T Stack<T>::Back() {
  if (size_ == 0) {
    throw "error";
  }
  return arr_[size_ - 1];
  ;
}

template <typename T>
int Stack<T>::Size() {
  return size_;
}

template <typename T>
void Stack<T>::Clear() {
  size_ = 0;
}