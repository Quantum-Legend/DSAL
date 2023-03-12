// A book consists of chapters, chapters consist of sections and sections consist of
// subsections. Construct a tree and print the nodes. Find the time and space requirements
// of your method.

#include <iostream>

struct node
{
    std::string component;
    node *left, *right;
};

class tree
{
    node *root;
    public:
    tree()
    {
        root = NULL;
    }
    node* create();
    // void display();
    void printBT(const std::string& prefix, const node* BSTnode, bool isLeft);
    void printBT(const node* BSTnode);
    void recInorder(node *t);
    void recPreorder(node *t);
    void recPostorder(node *t);
    void menu();
};

node* tree::create()
{
    std::string c;
    node* temp = new node;
    std::cout << "Enter the part of book (NULL to exit): ";
    std::getline(std::cin >> std::ws, c);
    if(c != "NULL")
    {
        temp->component = c;
        std::cout << "Enter left child of " << c << std::endl;
        temp->left = create();
        std::cout << "Enter right child of " << c << std::endl;
        temp->right = create();
    }
    else
    {
        temp = NULL;
    }
    return temp;
}

/* void tree::display()
{
    temp = root;
    std::cout << temp-> 
} */

void tree::printBT(const std::string& prefix, const node* BSTnode, bool isLeft)
{
    if( BSTnode != NULL )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "+--" );

        // print the value of the node
        std::cout << BSTnode->component << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "|   " : "    "), BSTnode->left, true);
        printBT( prefix + (isLeft ? "|   " : "    "), BSTnode->right, false);
    }
}

void tree::printBT(const node* BSTnode)
{
    printBT("", BSTnode, false);   
}

void tree::recInorder(node *t)
{
    if(t != NULL)
    {
        recInorder(t->left);
        std::cout << t->component << "   ";
        recInorder(t->right);
    }
}

void tree::recPreorder(node *t)
{
    if(t != NULL)
    {
        std::cout << t->component << "   ";
        recPreorder(t->left);
        recPreorder(t->right);
    }
}

void tree::recPostorder(node *t)
{
    if(t != NULL)
    {
        recPostorder(t->left);
        recPostorder(t->right);
        std::cout << t->component << "   ";
    }
}

void tree::menu()
{
    root = this->create();
    // pass the root node of your binary tree
    std::cout << std::endl;
    printBT(root);
    std::cout << std::endl;
    std::cout << "\nInorder: " << std::endl;
    recInorder(root);
    std::cout << "\nPreorder: " << std::endl;
    recPreorder(root);
    std::cout << "\nPostorder: " << std::endl;
    recPostorder(root);
}

int main()
{
    tree book;
    book.menu();
    return 0;
}

