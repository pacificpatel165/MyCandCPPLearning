#include <iostream>

using namespace std;

void primefactorization(int num)
{
    for(int i = 2; i <= num; i++)
    {
        int count = 0;
        // cout << "Number is --> " << num << " and i " << i << endl;
        if(num % i == 0)
        {
            // cout << "Number is ---> " << num << " and i " << i << endl;
            while(num % i == 0)
            {
                num = num / i;
                count++;
            }
            // cout << "Number is ----> " << num << " and i " << i << endl;
            cout << "count of number " << i << " is " << count << " times." << endl;
        }
    }
}

int main()
{
    int num = 69300;
    primefactorization(num);
    return 0;
}
