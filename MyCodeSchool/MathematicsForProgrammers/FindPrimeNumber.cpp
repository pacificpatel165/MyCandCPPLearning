#include <iostream>

using namespace std;

bool isPrime(int num)
{
    if(num <= 1)
        return false;

    for(int i = 2; i < num/2; i++)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}


int main()
{
    int num = 21;
    if(isPrime(num))
    {
        cout << "Number " << num << " is a Prime number." << endl;
    }
    else
    {
        cout << "Number " << num << " is not a Prime number." << endl;
    }
    return 0;
}

