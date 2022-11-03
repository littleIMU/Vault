#include <iostream>

using namespace std;

// Swap data by point
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void quick_sort(int arr[],int l, int r)
{
    if(l >= r) return;
    int i = l, j = r;
    while(i < j) {
        while(arr[j] >= arr[l] && i < j) j--;
        while(arr[i] <= arr[l] && i < j) i++;
        swap(arr[i], arr[j]);
    }
    swap(&arr[i], &arr[l]);
    quick_sort(arr, l, i - 1);
    quick_sort(arr, i + 1, r);
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