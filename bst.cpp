/* Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path from root
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at every
node
v. Search a value */

#include <iostream>

struct node
{
    int data;
    node *left, *right;
};

class BST
{
    node *root;
    public:
    BST()
    {
        root = NULL;
    }
    void create();
    node* insert(node* t, int d);
    void display(node* t);
    void menu();
};

void BST::create()
{
    int noOfElements, data;
    std::cout << "How many elements to be inserted for initializing the binary search tree: ";
    std::cin >> noOfElements;
    std::cout << "Enter the first element (ROOT): ";
    std::cin >> data;
    root = insert(root, data);
    for(int i = 1; i < noOfElements; i++)
    {
        std::cout << "Enter (" << i+1 << ")th element: ";
        std::cin >> data;
        insert(root, data);
    }
}

node* BST::insert(node* t, int d)
{
    if(t != NULL)
    {
        if(t->data > d)
            t->left = insert(t->left, d);
        else
            t->right = insert(t->right, d);
    }
    node* p = new node;
    p->data = d;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void BST::display(node* t)
{
    if(t != NULL)
    {
        display(t->left);
        std::cout << t->data << "   ";
        display(t->right);
    }
}

void BST::menu()
{
    create();
    display(root);
    std::cout << std::endl;
}

int main()
{
    BST tree;
    tree.menu();
    return 0;
}