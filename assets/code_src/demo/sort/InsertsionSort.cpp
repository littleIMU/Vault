#include <iostream>

using namespace std;

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement insertsion sort
void insertsion_sort(int arr[], int size)
{
    for (int i=1;i<size;i++)
    {
        for (int j=i;j>0;j--){
            if (arr[j-1] > arr[j])
            {
                swap(arr[j-1],arr[j]);
            }
            else
                continue;
        }
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
    insertsion_sort(arr,n);
    printArray(arr,n);
    return 0;
}