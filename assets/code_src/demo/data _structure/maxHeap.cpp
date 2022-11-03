#include <iostream>
#include <vector>    

using namespace std;

class solution{
    int parent(int i) {return (i - 1) / 2;} 
    int left(int i) {return 2 * i + 1;}
    int right(int i) {return 2 * i + 2;}

    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }

    void sink_down(vector<int> &arr, int i){
        int maxIndex = i;
        int l = arr.size();
        if (left(i) < l && arr[left(i)] > arr[maxIndex]) maxIndex = left(i);
        if (right(i) < l && arr[right(i)] > arr[maxIndex]) maxIndex = right(i);
        if (maxIndex != i){
            swap(arr[i], arr[maxIndex]);
            sink_down(arr, maxIndex);
        }

    }

public:
    void max_heap(vector<int> & arr) {
        for (int i = arr.size() - 1; i >= 0; i--){
            sink_down(arr, i);
        }
    }
};

int main(){
    solution s;
    vector<int> v = {1,2,3,4,5,6};
    s.max_heap(v);
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << ',';
    }
}