/* Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path from root
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at every node
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
    node *insert(node *t, int d);
    void display(node *t);
    int min();
    int max();
    bool search(int d);
    node *swap(node *t);
    int longestPath(node *t);
    friend void menu(BST tree);
};

void BST::create()
{
    int noOfElements, data;
    std::cout << "How many elements to be inserted for initializing the binary search tree: ";
    std::cin >> noOfElements;
    std::cout << "\nEnter the first element (ROOT): ";
    std::cin >> data;
    root = insert(root, data);
    for (int i = 1; i < noOfElements; i++)
    {
        std::cout << "Enter (" << i + 1 << ")th element: ";
        std::cin >> data;
        root = insert(root, data);
    }
}

node *BST::insert(node *t, int d)
{
    if (t == NULL)
    {
        node *p = new node;
        p->data = d;
        p->left = NULL;
        p->right = NULL;
        t = p;
    }
    else if (t->data > d)
    {
        t->left = insert(t->left, d);
    }
    else
    {
        t->right = insert(t->right, d);
    }
    return t;
}

void BST::display(node *t)
{
    if (t != NULL)
    {
        display(t->left);
        std::cout << t->data << "   ";
        display(t->right);
    }
}

int BST::min()
{
    node *t = root;
    while (t->left != NULL)
    {
        t = t->left;
    }
    return t->data;
}

int BST::max()
{
    node *t = root;
    while (t->right != NULL)
    {
        t = t->right;
    }
    return t->data;
}

bool BST::search(int d)
{
    node *temp = root;
    while (temp != NULL)
    {
        if (d == temp->data)
            return true;
        else if (d > temp->data)
            temp = temp->right;
        else
            temp = temp->left;
    }
    return false;
}

node *BST::swap(node *p)
{
    if (p != NULL)
    {
        node *temp;
        temp = swap(p->left);
        p->left = swap(p->right);
        p->right = temp;
    }
    return p;
}

int BST::longestPath(node *t)
{
    int leftHeight = 0, rightHeight = 0;
    if (t != NULL)
    {
        leftHeight = 1 + longestPath(t->left);
        rightHeight = 1 + longestPath(t->right);
        if (leftHeight > rightHeight)
            return leftHeight;
        return rightHeight;
    }
    return 0;
}

void menu(BST tree)
{
    std::cout << "\tStarting creation of binary search tree..." << std::endl;
    tree.create();
    std::cout << "\tBinary Search tree created and initialized!" << std::endl;
    int ch = 0;
    do
    {
        std::cout << "\n***MENU***" << std::endl;
        std::cout << "1 - Insert a number" << std::endl;
        std::cout << "2 - Display the ordered sequence" << std::endl;
        std::cout << "3 - Find minimum and maximum value" << std::endl;
        std::cout << "4 - Search a number" << std::endl;
        std::cout << "5 - Swap left and right roles of the tree" << std::endl;
        std::cout << "6 - Number of nodes in the longest path" << std::endl;
        std::cout << "7 - Exit" << std::endl;
        std::cout << "\tEnter your choice - ";
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            int n;
            std::cout << "Enter the number you want to insert - ";
            std::cin >> n;
            tree.root = tree.insert(tree.root, n);
            break;
        case 2:
            std::cout << "The ordered sequnce of the numbers (inorder ttraversal of BST): " << std::endl;
            tree.display(tree.root);
            std::cout << std::endl;
            break;
        case 3:
            std::cout << "Minimum value is: ";
            std::cout << tree.min() << std::endl;
            std::cout << "Maximum value is: ";
            std::cout << tree.max() << std::endl;
            break;
        case 4:
            std::cout << "Enter what to search: ";
            int x;
            std::cin >> x;
            if (tree.search(x))
                std::cout << "Element is present" << std::endl;
            else
                std::cout << "Element is not present" << std::endl;
            break;
        case 5:
            tree.swap(tree.root);
            std::cout << "The swapped tree is: " << std::endl;
            tree.display(tree.root);
            std::cout << std::endl;
            tree.swap(tree.root);
            /* tree.display(tree.root);
            std::cout << std::endl; */
            break;
        case 6:
            std::cout << "The number of nodes in the longest path of the binary search tree are: " << tree.longestPath(tree.root) << std::endl;
            break;
        case 7:
            std::cout << "Now exiting the program..." << std::endl;
            break;
        default:
            std::cout << "Enter valid choice" << std::endl;
        }
    } while (ch != 7);
}

int main()
{
    BST tree;
    menu(tree);
    return 0;
}
