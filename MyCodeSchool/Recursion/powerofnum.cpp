#include <iostream>
#include <ctime>

using namespace std;

#define VALUE 2
#define POWEROF 27

int powerofnum_recursive(int value, int num)
{
    if(num == 0)
    {
        return 1;
    }

    return value * powerofnum_recursive(value, (num -1));
}

int powerofnum_recursive_optimized(int value, int num)
{
    if(num == 0)
    {
        return 1;
    }
    else if(num % 2 == 0) // even number
    {
        int temp = powerofnum_recursive_optimized(value, num/2);
        return temp * temp;
    }
    else 
    {
        return value * powerofnum_recursive_optimized(value, (num - 1));
    }

}

int main()
{
    const clock_t begin_time = clock();
    int result = powerofnum_recursive(VALUE, POWEROF);
    cout << VALUE << " the power of " << POWEROF << " is equal to --> " << result << " Time Taken " << float(clock() - begin_time)/CLOCKS_PER_SEC << endl;
    
    const clock_t begin_time1 = clock();
    result = powerofnum_recursive_optimized(VALUE, POWEROF);
    cout << VALUE << " the power of " << POWEROF << " (opimized) is equal to --> " << result << " Time Taken " << float(clock() - begin_time)/CLOCKS_PER_SEC << endl;
    
    return 0;
}
