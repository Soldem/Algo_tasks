#include <algorithm>
#include <iostream>
#include <vector>

void quik_sort(int* s_arr, int first, int last) {
  if (first < last) {
    int left = first, right = last, middle = s_arr[(left + right) / 2];
    do {
      while (s_arr[left] < middle) left++;
      while (s_arr[right] > middle) right--;
      if (left <= right) {
        int tmp = s_arr[left];
        s_arr[left] = s_arr[right];
        s_arr[right] = tmp;
        left++;
        right--;
      }
    } while (left <= right);
    quik_sort(s_arr, first, right);
    quik_sort(s_arr, left, last);
  }
}

int main() {
  int n;
  std::cin >> n;
  int* a = new int[n];

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  quik_sort(a, 0, n - 1);
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " ";
  }

  delete[] a;
}