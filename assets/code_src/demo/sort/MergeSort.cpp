#include <iostream>
#include <vector>
using namespace std;

// Swap data by point
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement selection sort
void merge_operation(int arr[], int l, int m, int r)
{
    // the number of left-divided array: n1
    // the number of right-divided array: n2
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    // give value to left array and tight array
    for (int i=0; i<n1; i++) L[i] = arr[l+i];
    for (int i=0; i<n2; i++) R[i] = arr[m+1+i];

    int i = 0;
    int j = 0;
    int k = l;
    while (i<n1&&j<n2)
    {
        if (L[i]<=R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

	// Copy the remaining elements
    for (i;i<n1;i++)
    {
        arr[k] = L[i];
        k++;
    }

    for (j;j<n2;j++)
    {
        arr[k] = R[j];
        k++;
    }
}

void merge2(vector<int>& arr, vector<int>& tmp, int l, int h){
    if (l >= h) return;
    int m = (l + h) / 2;
    merge2(arr, tmp, l, m);
    merge2(arr, tmp, m + 1, h);
    int i = l, j = m + 1;
    for (int k = l; k <= h; k++)   
        tmp[k] = arr[k];
    for (int k = l; k <= h; k++)  {
        if (i == m + 1) arr[k] = tmp[j++];
        else if (j == h + 1 || tmp[i] < tmp[j]) arr[k] = tmp[i++];
        else {
            arr[k] = tmp[j++];
        }
    } 
    return;
}

void merge3(vector<int>& arr, vector<int>& tmp, int l, int h){
    if (l >= h) return;
    int m = (l + h) / 2;
    merge3(arr, tmp, l, m);
    merge3(arr, tmp, m + 1, h);
    int i = l, j = m + 1;
    for (int k = l; k <= h; k++) tmp[k] = arr[k];
    for (int k = l; k <= h; k++){
        if (i == m + 1) arr[k] = tmp[j++];
        else if (j == h + 1 || tmp[i] < tmp[j]) arr[k] = tmp[i++];
        else arr[k] = tmp[j++];
    } 
    return;

}


void merge_sort(int arr[], int l, int r)
{
    if (l<r)
    {
        /* code */
        int m = (r+l)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge_operation(arr,l,m,r);
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
    merge_sort(arr,0,n-1);
    printArray(arr,n);
    vector<int> x = {64, 34, 25, 12, 22, 11, 90};
    int s = x.size();
    vector<int> y(s);
    merge3(x, y, 0, s - 1);
    for (int i = 0; i < s; i++){
        cout << x[i] << ",";
    }
    return 0;
}
