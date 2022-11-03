// C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
using namespace std;

class BST
{
	int data;
	BST *left, *right;

public:
	// Default constructor.
	BST();

	// Parameterized constructor.
	BST(int);

	// Insert function.
	BST* Insert(BST*, int);

    BST* Delete(BST*, int);

	// Inorder traversal.
	void Inorder(BST*);

    // Preorder traversal.
    void Preorder(BST*);
    
    // Postorder traversal.
    void Postorder(BST*);

    
};

// Default Constructor definition.
BST ::BST()
	: data(0)
	, left(NULL)
	, right(NULL)
{
}

// Parameterized Constructor definition.
BST ::BST(int value)
{
	data = value;
	left = right = NULL;
}

// Insert function definition.
BST* BST ::Insert(BST* root, int value)
{
    if (!root) return new BST(value);

    if (value <= (root->data))
        root->left = Insert(root->left,value);
    else
        root->right = Insert(root->right,value);
    return root;
}

BST* BST::Delete(BST* root, int k)
{   
    if (root == NULL)   return root;

    if (k < (root->data))
    {
        root->left = Delete(root->left,k);
        return root;
    }
    else if (k > (root->data) ){
        root->right = Delete(root->right,k);
        return root;
    }

    // if only right child or no children exist
    if (root->left == NULL)
    {
        BST* temp = root->right;
        delete root;
        return temp;
    }
    // if only left child exist
    else if (root->right == NULL)
    {
        BST* temp = root->left;
        delete root;
        return temp;
    }
    // if both children exist------------------------------------------
    // If the right child of the searched node has left child,
    // then replace the searched node with the mim child of the left child.
    // If the right child of the searched node has left child,
    // then the left child will replace the position of searched node.
    else {
        BST* succParent = root;

        // find successor
        BST* succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        root->data = succ->data;

        delete succ;
        return root;
    }

}

// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST* root)
{
    if(root == NULL) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

// Preorder traversal function.
// This gives data in sorted order.
void BST ::Preorder(BST* root)
{
    if(root == NULL) return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

// Postorder traversal function.
// This gives data in sorted order.
void BST ::Postorder(BST* root)
{
    if(root == NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

// Driver code
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
	BST b, *root = NULL;
	root = b.Insert(root, 50);
	b.Insert(root, 30);
	b.Insert(root, 20);
	b.Insert(root, 40);
	b.Insert(root, 70);
	b.Insert(root, 60);
	b.Insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    b.Inorder(root);

    printf("\nPreorder traversal of the given tree \n");
    b.Preorder(root);

    printf("\nPostorder traversal of the given tree \n");
    b.Postorder(root);
 
    printf("\nDelete 20\n");
    root = b.Delete(root, 20);
    printf("Inorder traversal of the modified tree \n");
    b.Inorder(root);
 
    printf("\nDelete 30\n");
    root = b.Delete(root, 30);
    printf("Inorder traversal of the modified tree \n");
    b.Inorder(root);
 
    printf("\nDelete 50\n");
    root = b.Delete(root, 50);
    printf("Inorder traversal of the modified tree \n");
    b.Inorder(root);
}

// This code is contributed by pkthapa
// This is a test for onedrive
