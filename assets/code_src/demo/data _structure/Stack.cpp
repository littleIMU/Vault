// C++ program for linked list implementation of stack
#include <bits/stdc++.h>
using namespace std;
 
// A structure to represent a stack
class StackNode {
public:
    int data = 0;
    StackNode* next = NULL;

    StackNode(int _data){
        data = _data;
    }
};
 
 
int isEmpty(StackNode* root)
{
    return !root;
}
 
void push(StackNode** root, int data)
{
    StackNode* node = new StackNode(data);
    node->next = *root;
    *root = node;
    cout << data << " pushed to stack" << endl;
}
 
int pop(StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    StackNode* node = *root;
    int poped = node->data;
    *root = node->next;
    // destruct the node ?
    free(node);
    return poped;
}
 
int peek(StackNode* root)
{
    if (isEmpty(root))
    return INT_MIN;
   return root->data;
}
 
// Driver code
int main()
{
    StackNode* root = NULL;
 
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
 
    cout << pop(&root) << " popped from stack\n";
 
    cout << "Top element is " << peek(root) << endl;
     
    cout<<"Elements present in stack : ";
     //print all elements in stack :
    while(!isEmpty(root))
    {
        // print top element in stack
        cout<<peek(root)<<" ";
        // remove top element in stack
        pop(&root);
    }
 
    return 0;
}
 
// This is code is contributed by rathbhupendra