#include <iostream>
using namespace std;
int main()
{
    unsigned long long number;
    cin >> number;
    unsigned long long reverse = 0;
    for(; number > 0; )
    {
        reverse *= 10;
        reverse += number % 10;
        number /= 10;
    }
    cout << reverse << endl;
    system("pause");
}
