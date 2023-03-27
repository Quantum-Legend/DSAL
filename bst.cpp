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
    node *insert(node *t, int d);
    void search(int d);
    void display(node *temp);
    int min();
    node *swappedTree();
    void menu();
};

node *BST::insert(node *t, int d)
{
    if (t == NULL)
    {
        node* p = new node;
        p->data = d;
        p->left = p->right = NULL;
        t = p;
        return t;
    }
    else if(t->data > d)
    {
        t->left = insert(t)
    }
}

void BST::display(node *temp)
{
    if (temp != NULL)
    {
        display(temp->left);
        std::cout << temp->data << "   ";
        display(temp->right);
    }
}

void BST::menu()
{
    while (true)
    {
        char ch;
        int d;
        std::cout << "Insert first element: ";
        std::cin >> d;
        root = insert(root, d);
        std::cout << "Insert new element? (Y/N):  ";
        std::cin >> ch;
        if (ch == 'Y')
        {
            std::cout << "Enter data: ";
            std::cin >> d;
            insert(root, d);
        }
        else
            break;
    }
    this->display(root);
}

int main()
{
    BST tree1;
    tree1.menu();
    return 0;
}
