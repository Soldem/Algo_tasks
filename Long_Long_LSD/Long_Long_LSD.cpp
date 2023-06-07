#include <iostream>

using namespace std;
long long sorted_arr[1000000];

void RadixSortLsd(long long arr[], int n) {
  int size = 8;  // количество байт в каждом числе
  for (int i = 0; i < size; i++) {
    int counters[256] = {};  // создаем счетчики
    // выполняем подсчет количества чисел для каждого значения байта
    for (int j = 0; j < n; j++) {
      int byte_value = (arr[j] >> (i * 8)) & 0xFF;
      counters[byte_value]++;
    }
    // вычисляем позиции элементов в массиве
    for (int j = 1; j < 256; j++) {
      counters[j] += counters[j - 1];
    }

    // создаем промежуточный отсортированный массив
    for (int j = n - 1; j >= 0; j--) {
      int byte_value = (arr[j] >> (i * 8)) & 0xFF;
      sorted_arr[--counters[byte_value]] = arr[j];
    }

    // копирование отсортированного массива обратно в исходный
    for (int j = 0; j < n; j++) {
      arr[j] = sorted_arr[j];
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  long long* arr = new long long[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  RadixSortLsd(arr, n);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;

  delete[] arr;
}