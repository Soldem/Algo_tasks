#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

class TheSortingHat {
  std::stack<std::pair<unsigned, unsigned>> mas1_;
  std::stack<std::pair<unsigned, unsigned>> mas2_;
  unsigned current_minimum_;

 public:
  void Enqueue(unsigned value) {
    int minima = mas1_.empty() ? value : std::min(value, mas1_.top().second);
    mas1_.push(std::make_pair(value, minima));
    std::cout << "ok" << std::endl;
  }

  void Dequeue() {
    if ((mas1_.empty() && mas2_.empty())) {
      std::cout << "error" << std::endl;
      return;
    }
    if (mas2_.empty()) {
      while (!mas1_.empty()) {
        unsigned element = mas1_.top().first;
        mas1_.pop();
        unsigned minima =
            mas2_.empty() ? element : std::min(element, mas2_.top().second);
        mas2_.push(std::make_pair(element, minima));
      }
    }

    std::cout << mas2_.top().first << std::endl;
    mas2_.pop();
  }

  void Front() {
    if ((mas1_.empty() && mas2_.empty())) {
      std::cout << "error" << std::endl;
      return;
    }

    if (mas2_.empty()) {
      while (!mas1_.empty()) {
        unsigned element = mas1_.top().first;
        mas1_.pop();
        unsigned minima =
            mas2_.empty() ? element : std::min(element, mas2_.top().second);
        mas2_.push(std::make_pair(element, minima));
      }
    }

    std::cout << mas2_.top().first << std::endl;
  }

  void Size() { std::cout << mas1_.size() + mas2_.size() << std::endl; }

  void Clear() {
    while (!mas1_.empty()) {
      mas1_.pop();
    }
    while (!mas2_.empty()) {
      mas2_.pop();
    }

    std::cout << "ok" << std::endl;
  }

  void Min() {
    if (mas1_.empty() && mas2_.empty()) {
      std::cout << "error" << std::endl;
      return;
    }

    if (mas1_.empty() || mas2_.empty()) {
      current_minimum_ =
          mas1_.empty() ? mas2_.top().second : mas1_.top().second;
    } else {
      current_minimum_ = std::min(mas1_.top().second, mas2_.top().second);
    }
    std::cout << current_minimum_ << std::endl;
  }
};

int main() {
  unsigned n, value;
  std::cin >> n;
  TheSortingHat student;
  std::string command;
  for (unsigned i = 0; i < n; i++) {
    std::cin >> command;
    if (command == "enqueue") {
      std::cin >> value;
      student.Enqueue(value);
    } else if (command == "size") {
      student.Size();
    } else if (command == "clear") {
      student.Clear();
    } else if (command == "front") {
      student.Front();
    } else if (command == "dequeue") {
      student.Dequeue();
    } else if (command == "min") {
      student.Min();
    }
  }
  return 0;
}