#include <iostream>

using namespace std;

// Swap data by point
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement selection sort
void selection_sort(int arr[], int size)
{
    int i,sele,comp;
    for (i=0;i<size-1;i++)
    {
        sele = i;
        
        for (comp=sele+1;comp<size;comp++){
            if (arr[sele] > arr[comp])
            {
                sele = comp;
            }
        }
        swap(&arr[i],&arr[sele]);
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
    selection_sort(arr,n);
    printArray(arr,n);
    return 0;
}