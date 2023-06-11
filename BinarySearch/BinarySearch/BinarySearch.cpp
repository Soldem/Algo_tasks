#include <iostream>
int* MAS;
int SIZE;
bool BinarySearch(const int* begin, const int* end, int target){
    int left = *begin;
    int rigth = *end;
    while (left < rigth - 1){
        int middle = (left + rigth) / 2;
        if (MAS[middle] == target) return true;

        if (MAS[middle] < target) left = middle;
        else rigth = middle;
    }
    if (MAS[left] == target) return true;
    else return false;
}

int main(){
    int q, i, j, t;
    std::cin >> SIZE;
    MAS = new int[SIZE];
    for (int i = 0; i < SIZE; i++){
        std::cin >> MAS[i];
    }
    std::cin >> q;
    for (int k = 0; k < q; k++){
        std::cin >> i >> j >> t;
        std::cout << (BinarySearch(&i, &j, t) ? "YES" : "NO") << std::endl;
    }
}
