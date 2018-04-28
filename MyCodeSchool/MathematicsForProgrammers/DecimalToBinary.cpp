#include <iostream>

using namespace std;

// function to convert decimal to binary
void decimaltobinary(int num)
{
    // array to store binary number
    int binlist[1000];
    
    // counter for binary array
    int i = 0;
    while(num > 0)
    {
        // storing remainder in binary array
        binlist[i] = num % 2;
        num = num / 2;
        i++;
    }

    // printing binary array in reverse order
    cout << "|";
    for(int j = i -1; j >= 0; j--)
    {
        cout << binlist[j] << "|";
    }
    cout << endl;
}

int main()
{
    int decnum = 125;
    decimaltobinary(decnum);
    return 0;
}

