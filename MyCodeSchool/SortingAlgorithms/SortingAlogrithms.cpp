#include <iostream>

using namespace std;

void SelectionSort(int A[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int iMin = i; // Assume this is minimum index
        for(int j = i+1; j < n; j++)
        {
            if(A[j] < A[iMin])
            {
                iMin = j;
            }
        }
        // Swap the items
        swap(A[i], A[iMin]);
    }
}

void BubbleSort(int A[], int n)
{
    for(int i = 0; i < n; i++)
    {
        bool flag = false;
        for(int j = 0; j < n - (i+1); j++)
        {
            if(A[j] > A[j+1])
            {
                // Swap the items
                swap(A[j], A[j+1]);
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
    }
}

void InsertionSort(int A[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int value = A[i];
        int hole = i;

        while(hole > 0 && A[hole-1] > value)
        {
            A[hole]  = A[hole -1];
            hole--;
        }
        A[hole] = value;
    }
}

// Function to Merge Arrays L and R into A. 
// lefCount = number of elements in L
// rightCount = number of elements in R. 
void Merge(int A[], int L[], int leftCount, int R[], int rightCount)
{
    int i = 0, j = 0, k =0;

    // i - to mark the index of left aubarray (L)
    // j - to mark the index of right sub-raay (R)
    // k - to mark the index of merged subarray (A)
    
    while((i < leftCount) && (j < rightCount)) 
    {
        if(L[i]  < R[j])
        {
            A[k++] = L[i++];
        }
        else
        {
            A[k++] = R[j++];
        }
    }
    while(i < leftCount)
    {
        A[k++] = L[i++];
    }
    while(j < rightCount)
    {
        A[k++] = R[j++];
    }
}

// Recursive function to sort an array of integers. 
void MergeSort(int A[], int n)
{
    if(n < 2)
    {
        return; // base condition. If the array has less than two element, do nothing. 
    }
    int mid = n/2;  // find the mid index.
    // create left and right subarrays
    // mid elements (from index 0 till mid-1) should be part of left sub-array 
    // and (n-mid) elements (from mid to n-1) will be part of right sub-array
    int left = mid;
    int right = n-mid;
    int L[left];
    int R[right];

    for(int i = 0; i < mid; i++) 
    {
        L[i] = A[i]; // creating left subarray
    }
    for(int i = mid; i < n; i++) 
    {
        R[i-mid] = A[i]; // creating right subarray
    }
    MergeSort(L, left);  // sorting the left subarray
    MergeSort(R, right);  // sorting the right subarray
    Merge(A, L, left, R, right);  // Merging L and R into A as sorted list.
}

int Partition(int A[], int start, int end)
{
    int pivot = A[end]; // Take the right most value as pivot
    int partitionIndex = start;

    for(int i = start; i < end; i++)
    {
        if(A[i] <= pivot)
        {
            // Swap the elements
            swap(A[i], A[partitionIndex]);
            partitionIndex++;
        }
    }
    // Swap the partitionIndex element eith last right element
    swap(A[partitionIndex], A[end]);

    // Return partitioning index
    return partitionIndex;
}

void QuickSort(int A[], int start, int end)
{
    if(start < end)
    {
        int partitionIndex = Partition(A, start, end);
        QuickSort(A, start, partitionIndex -1);
        QuickSort(A, partitionIndex, end);
    }
}

void printArray(int A[], int n)
{
    cout << "[";

    for(int i = 0; i < n; i++)
    {
        if(i == n -1)
        {
            cout << A[i];
        }
        else
        {
            cout << A[i] << " ";
        }
        
    }
    cout << "]" << endl;
}

int main()
{
    int array[] = {2, 7, 1, 8, 4, 9, 0, 5, 6, 3};
    int arraySize = sizeof(array)/sizeof(int);
    cout << "Given Array " << endl;
    cout << "=====================" << endl;
    printArray(array, arraySize);
    cout << "=====================" << endl;

    SelectionSort(array, arraySize);
    cout << "---------------------" << endl;
    cout << "After Selection Sort " << endl;
    cout << "---------------------" << endl;
    printArray(array, arraySize);
    cout << endl;

    int array1[] = {2, 7, 1, 8, 4, 9, 0, 5, 6, 3};
    arraySize = sizeof(array1)/sizeof(int);
    BubbleSort(array1, arraySize);
    cout << "---------------------" << endl;
    cout << "After Bubble Sort " << endl;
    cout << "---------------------" << endl;
    printArray(array1, arraySize);
    cout << endl;

    int array2[] = {2, 7, 1, 8, 4, 9, 0, 5, 6, 3};
    arraySize = sizeof(array2)/sizeof(int);
    InsertionSort(array2, arraySize);
    cout << "---------------------" << endl;
    cout << "After Insertion Sort " << endl;
    cout << "---------------------" << endl;
    printArray(array2, arraySize);
    cout << endl;

    int array3[] = {2, 7, 1, 8, 4, 9, 0, 5, 6, 3};
    arraySize = sizeof(array3)/sizeof(int);
    MergeSort(array3, arraySize);
    cout << "---------------------" << endl;
    cout << "After Merge Sort " << endl;
    cout << "---------------------" << endl;
    printArray(array3, arraySize);
    cout << endl;

    int array4[] = {2, 7, 1, 8, 4, 9, 0, 5, 6, 3};
    arraySize = sizeof(array4)/sizeof(int);
    QuickSort(array4, 0, (arraySize -1));
    cout << "---------------------" << endl;
    cout << "After Quick Sort " << endl;
    cout << "---------------------" << endl;
    printArray(array4, arraySize);

    return 0;
}
