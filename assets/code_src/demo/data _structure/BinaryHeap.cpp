// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
using namespace std;

// A utility function to swap two elements
// void swap(int *x, int *y)
// {
// 	int temp = *x;
// 	*x = *y;
// 	*y = temp;
// }

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
    y = temp;
}

// A class for Min Heap
class MinHeap
{
	int *harr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int heap_size; // Current number of elements in min heap
public:
	// Constructor
	MinHeap(int capacity);

	// to heapify a subtree with the root at given index, i.e. large number sink_downs
	void sink_down(int i);

	void float_up(int i);

	int parent(int i) { return (i-1)/2; }

	// to get index of left child of node at index i
	int left(int i) { return (2*i + 1); }

	// to get index of right child of node at index i
	int right(int i) { return (2*i + 2); }

	// to extract the root which is the minimum element
	int extractMin();

	// Decreases key value of key at index i to new_val
	void decreaseKey(int i, int new_val);

	// Returns the minimum key (key at root) from min heap
	int getMin() { return harr[0]; }

	// Deletes a key stored at index i
	void deleteKey(int i);

	// Inserts a new key 'k'
	void insertKey(int k);

	//
};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::sink_down(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l<heap_size && harr[l]<harr[i])
	{
		smallest = l;
	}
	if (r<heap_size && harr[r]<harr[smallest])
	{
		smallest = r;
	}
	if (smallest!=i)
	{
		swap(harr[i],harr[smallest]);
		sink_down(smallest);
	}
}

void MinHeap::float_up(int i)
{
	while ( i!=0 && harr[parent(i)]>harr[i])
	{	
		swap(harr[i],harr[parent(i)]);
		i = parent(i);
	}
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
	if (heap_size==capacity)
	{
		cout << "overflow" << endl;
		return;
	}

	heap_size++;
	int i = heap_size-1;
	harr[i] = k;
	// the smallest number floats up
	float_up(i);
}

// Decreases value of key at index 'i' to new_val. It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val;
	float_up(i);
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
	if (heap_size == 0)
	{
		return INT_MIN;
	}
	else if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}
	else{
		int root = harr[0];
		harr[0] = harr[heap_size-1];
		heap_size--;
		sink_down(0);
		return root;
	}

}


// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
	harr[i] = INT_MIN;
	float_up(i);
	extractMin();	
}


// Driver program to test above functions
int main()
{
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout << h.extractMin() << " ";
	cout << h.getMin() << " ";
	h.decreaseKey(2, 1);
	cout << h.getMin();
	return 0;
}
