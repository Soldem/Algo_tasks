#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  unsigned n, k, A0, A1;
  std::cin >> n >> k >> A0 >> A1;

  unsigned first;
  unsigned second;
  unsigned temp;
  first = A0;
  second = A1;
  std::vector<unsigned> vector;
  vector.push_back(A0);
  vector.push_back(A1);

  for (unsigned i = 0; i < n - 2; i++) {
    temp = (second * 123 + first * 45) % (10004321);

    vector.push_back(temp);

    first = second;
    second = temp;
  }

  std::nth_element(vector.begin(), vector.begin() + k - 1, vector.end());
  std::cout << vector[k - 1];
}