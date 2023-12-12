#include <iostream>
using namespace std;

void prim(int m, int n)
{
    if (m >= n)
    {
        while (m % n != 0) n++;
        m = m / n;
        prim(m, n);
        cout << n << endl;
    }
}

void primeFactors(int n) {
    // 找出所有的2的因子
    while (n % 2 == 0) {
        std::cout << 2 << " ";
        n = n / 2;
    }

    // n现在一定是奇数，可以从3开始遍历
    for (int i = 3; i*i <= n; i = i + 2) {
        while (n % i == 0) {
            std::cout << i << " ";
            n = n / i;
        }
    }

    // 如果n是一个大于2的质数
    if (n > 2) {
        std::cout << n << " ";
    }
}

int main() {
    //cout<< min(2,4)<<endl;

    int number = 60;
    cout << "The prime factors of " << number << " are: " << endl;
    prim(number, 2);

    int num = 315;
    std::cout << "The prime factors of " << num << " are: ";
    primeFactors(num);
    return 0;
}
