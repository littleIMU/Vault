#include <iostream>

using namespace std;

// Swap data by point
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(int arr[], int low, int high)
{
    int i = low-1;
    for (int j=low; j<high; j++)
    {
        if (arr[j] < arr[high])
        { 
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quick_sort(int arr[],int low, int high)
{
    if(low<high){
        int pivot = partition(arr,low,high);
        quick_sort(arr,low,pivot-1);
        quick_sort(arr,pivot+1,high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    // for input
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Data after selection sort:" << endl;
    quick_sort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}