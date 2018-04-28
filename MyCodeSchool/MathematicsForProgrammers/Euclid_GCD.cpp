#include <iostream>

using namespace std;

int euclid_gcd(int a, int b)
{
    int dividend = a >= b ? a : b;
    int divisor = a <= b ? a : b;

    while(divisor != 0)
    {
        int remainder = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    }
    return dividend;
}

int main()
{
    int num1 = 400, num2 = 124;
    cout << "GCD of " << num1 << " and " << num2 << " is " << euclid_gcd(num1, num2) << endl;
    return 0;
}
