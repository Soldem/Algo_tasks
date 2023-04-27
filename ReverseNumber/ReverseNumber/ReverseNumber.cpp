#include <iostream>
int main(){
    unsigned long long number;
    std::cin >> number;
    unsigned long long reverse = 0;
    for(; number > 0; ){
        reverse *= 10;
        reverse += number % 10;
        number /= 10;
    }
    std::cout << reverse << endl;
    system("pause");
}
