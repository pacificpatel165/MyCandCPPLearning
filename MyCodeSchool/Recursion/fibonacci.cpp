#include <iostream>
#include <ctime>

using namespace std;

#define VALUE 43

int F[VALUE]; // global

int fib_recursive_memoization(int num)
{
    if(num <= 1)
    {
        return num;
    }
    if(F[num] != -1)
    {
        return F[num];
    }
    else
    {
        F[num] = fib_recursive_memoization(num -1) + fib_recursive_memoization(num - 2);
        return F[num];
    }
}

int fib_recursive(int num)
{
    if(num <= 1)
    {
        return num;
    }

    return fib_recursive(num -1) + fib_recursive(num - 2);
}

int fib_iterator(int num)
{
    if(num <= 1)
    {
        return num;
    }

    int F1, F2, F;
    F1 = 0;
    F2 = 1;
    for(int i = 2; i <= num; i++)
    {
        F = F1 + F2;
        F1 = F2;
        F2 = F;
    }
    return F;
}

int main()
{
    int val = VALUE;
    // Initialize the global array with -1
    for(int i = 0; i < val; i++)
    {
        F[i] = -1;
    }

    const clock_t begin_time = clock();
    int fibval = fib_iterator(val);
    cout << "Fibonacci(iterate) value of " << val << " is --> " << fibval << " Time Taken " << float(clock() - begin_time)/CLOCKS_PER_SEC << endl;
    
    const clock_t begin_time1 = clock();
    fibval = fib_recursive(val);
    cout << "Fibonacci(recursive) value of " << val << " is --> " << fibval << " Time Taken " << float(clock() - begin_time1)/CLOCKS_PER_SEC << endl;
    
    const clock_t begin_time2 = clock();
    fibval = fib_recursive_memoization(val);
    cout << "Fibonacci(recursive_memoization) value of " << val << " is --> " << fibval << " Time Taken " << float(clock() - begin_time2)/CLOCKS_PER_SEC << endl;

    return 0;
}
