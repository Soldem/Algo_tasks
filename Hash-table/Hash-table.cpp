#include <iostream>
#include <map>

class Set {
  std::map<int, int> m_;

 public:
  void Add(int value) { m_[value] = 1; }
  void Remove(int value) { m_[value] = 0; }
  std::string Find(int value) {
    if (m_[value] == 1) {
      return "YES";
    }
    return "NO";
  }
};

int main() {
  Set set;
  int n;
  std::cin >> n;
  char command;
  int value;
  for (int i = 0; i < n; i++) {
    std::cin >> command >> value;
    if (command == '+') {
      set.Add(value);
    }
    if (command == '-') {
      set.Remove(value);
    }
    if (command == '?') {
      std::cout << set.Find(value) << std::endl;
    }
  }
  return 0;
}
