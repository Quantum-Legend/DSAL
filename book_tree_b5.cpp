/* A book consists of chapters, chapters consist of sections and sections consist of
subsections. Construct a tree and print the nodes. Find the time and space requirements
of your method. */

#include <iostream>
#define MAX 15

struct node
{
    std::string component;
    node *left, *right;
};

class stack
{
    node *arr[MAX];
    bool flag[MAX];
    int top;

public:
    stack()
    {
        top = -1;
    }
    bool empty();
    void push(node *p);
    void push(node *p, bool f);
    bool flagValue();
    node *pop();
};

bool stack::empty()
{
    if (top == -1)
        return true;
    return false;
}

void stack::push(node *p)
{
    if (top == MAX - 1)
        return;
    top++;
    arr[top] = p;
}

void stack::push(node *p, bool f)
{
    if (top == MAX - 1)
        return;
    top++;
    arr[top] = p;
    flag[top] = f;
}

bool stack::flagValue()
{
    return flag[top];
}

node *stack::pop()
{
    node *temp;
    temp = arr[top];
    top--;
    return temp;
}

class Queue
{
private:
    node *arr[MAX];
    int front, rear;

public:
    Queue()
    {
        front = rear = -1;
    }
    bool empty();
    void insert(node *P);
    node *remove();
};

bool Queue::empty()
{
    if (front == -1 && rear == -1)
        return true;
    return false;
}

void Queue::insert(node *P)
{
    if (this->empty())
    {
        rear = front = 0;
    }
    else
    {
        rear++;
    }
    arr[rear] = P;
}

node *Queue::remove()
{
    node *t = arr[front];
    if (rear == front)
        rear = front = -1;
    else
        front++;
    return t;
}

class tree
{
    node *root;

public:
    tree()
    {
        root = NULL;
    }
    node *create();
    // void display();
    void printBT(const std::string &prefix, const node *BSTnode, bool isLeft);
    void printBT(const node *BSTnode);
    void recInorder(node *t);
    void recPreorder(node *t);
    void recPostorder(node *t);
    void nonRecInorder(node *t);
    void nonRecPreorder(node *t);
    void nonRecPostorder(node *t);
    void BFS(node *t);
    void menu();
};

node *tree::create()
{
    std::string c;
    node *temp = new node;
    std::cout << "Enter the part of book (NULL to exit): ";
    std::getline(std::cin >> std::ws, c);
    if (c != "NULL")
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

void tree::printBT(const std::string &prefix, const node *BSTnode, bool isLeft)
{
    if (BSTnode != NULL)
    {
        std::cout << prefix;


        std::cout << (isLeft ? "|--" : "`--");

        // print the value of the node
        std::cout << BSTnode->component << std::endl;

        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), BSTnode->left, true);
        printBT(prefix + (isLeft ? "|   " : "    "), BSTnode->right, false);
    }
}

void tree::printBT(const node *BSTnode)
{
    printBT("", BSTnode, false);
}

void tree::recInorder(node *t)
{
    if (t != NULL)
    {
        recInorder(t->left);
        std::cout << t->component << "   ";
        recInorder(t->right);
    }
}

void tree::recPreorder(node *t)
{
    if (t != NULL)
    {
        std::cout << t->component << "   ";
        recPreorder(t->left);
        recPreorder(t->right);
    }
}

void tree::recPostorder(node *t)
{
    if (t != NULL)
    {
        recPostorder(t->left);
        recPostorder(t->right);
        std::cout << t->component << "   ";
    }
}

void tree::nonRecInorder(node *t)
{
    stack s;
    node *temp;
    temp = t;
    while (temp != NULL)
    {
        s.push(temp);
        temp = temp->left;
    }
    while (!(s.empty()))
    {
        temp = s.pop();
        std::cout << temp->component << "   ";
        temp = temp->right;
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
    }
}

void tree::nonRecPreorder(node *t)
{
    stack s;
    node *temp;
    temp = t;
    while (temp != NULL)
    {
        std::cout << temp->component << "   ";
        s.push(temp);
        temp = temp->left;
    }
    while (!(s.empty()))
    {
        temp = s.pop();
        temp = temp->right;
        while (temp != NULL)
        {
            std::cout << temp->component << "   ";
            s.push(temp);
            temp = temp->left;
        }
    }
}

void tree::nonRecPostorder(node *t)
{
    stack s;
    node *temp;
    bool flg;
    temp = t;
    while (temp != NULL)
    {
        s.push(temp, false);
        temp = temp->left;
    }
    while (!(s.empty()))
    {
        flg = s.flagValue();
        temp = s.pop();
        if (flg == false)
        {
            s.push(temp, true);
            temp = temp->right;
            while (temp != NULL)
            {
                s.push(temp, false);
                temp = temp->left;
            }
        }
        else
        {
            std::cout << temp->component << "   ";
        }
    }
}

void tree::BFS(node *t)
{
    Queue *q1 = new Queue;
    Queue *q2 = new Queue;
    q1->insert(t);
    std::cout << t->component;
    while (!(q1->empty()))
    {
        q2 = new Queue;
        std::cout << std::endl;
        while (!(q1->empty()))
        {

            node *t = q1->remove();
            if (t->left != NULL)
            {
                std::cout << t->left->component << "    ";
                q2->insert(t->left);
            }
            if (t->right != NULL)
            {
                std::cout << t->right->component << "   ";
                q2->insert(t->right);
            }
        }
        q1 = q2;
    }
}

void tree::menu()
{
    std::cout << "Creating New Binary Tree:\n" << std::endl;
    root = this->create();
    // pass the root node of your binary tree
    std::cout << std::endl;
    printBT(root);
    std::cout << "\n\nRECURSIVE: " << std::endl;
    std::cout << "Inorder: " << std::endl;
    recInorder(root);
    std::cout << "\n\nPreorder: " << std::endl;
    recPreorder(root);
    std::cout << "\n\nPostorder: " << std::endl;
    recPostorder(root);
    std::cout << "\n\nNON RECURSIVE: " << std::endl;
    std::cout << "Inorder: " << std::endl;
    nonRecInorder(root);
    std::cout << "\n\nPreorder: " << std::endl;
    nonRecPreorder(root);
    std::cout << "\n\nPostorder: " << std::endl;
    nonRecPostorder(root);
    std::cout << "\n\nBreadth First Traversal: " << std::endl;
    BFS(root);
}

int main()
{
    tree book;
    book.menu();
    return 0;
}
