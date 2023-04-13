/* A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
deleting keywords, updating values of any entry. Provide facility to display whole data
sorted in ascending/ Descending order. Also find how many maximum comparisons may
require for finding any keyword. Use Binary Search Tree for implementation.  */

#include <iostream>

struct node
{
    std::string keyword, meaning;
    node *left, *right;
};

std::string convert(std::string str)
{
    int j, k, len = str.size();
    std::string str_small = str;
    for (j = 0; j < len; j++)
    {
        if (((int)str[j] >= 97 && (int)str[j] <= 122) || ((int)str[j] >= 65 && (int)str[j] <= 90))
        {
            str_small[j] = (int)str[j] <= 90 ? (char)((int)str[j] + 32) : str[j];
            /* if ((int)str[j] <= 90)
            {
                str_small[k] = (char)((int)str[j] + 32);
            }
            else
            {
                str_small[k] = str[j];
            } */
        }
        else
            str_small[j] = str[j];
    }
    str_small[j] = '\0';
    return str_small;
}

class dictionary
{
    node *root;

public:
    dictionary()
    {
        root = NULL;
    }
    void create();
    node *insert(node *t, std::string key, std::string value);
    void display(node *t);
    void display();
    void update(std::string key, std::string value);
};

void dictionary::create()
{
    int noOfElements;
    std::string keyword, meaning;
    std::cout << "How many elements to be inserted for initializing the binary search tree: ";
    std::cin >> noOfElements;
    std::cout << "\nEnter the keyword in the first element (ROOT): ";
    std::getline(std::cin >> std::ws, keyword);
    std::cout << "Enter the meaning: ";
    std::getline(std::cin >> std::ws, meaning);
    root = insert(root, keyword, meaning);
    for (int i = 1; i < noOfElements; i++)
    {
        std::cout << "\nEnter keyword of (" << i + 1 << ")th element: ";
        std::getline(std::cin >> std::ws, keyword);
        std::cout << "Enter the meaning: ";
        std::getline(std::cin >> std::ws, meaning);
        root = insert(root, keyword, meaning);
    }
}

node *dictionary::insert(node *t, std::string key, std::string value)
{
    std::string key_small = convert(key);
    std::string tKey_small = t == NULL ? "" : convert(t->keyword);
    if (t == NULL)
    {
        node *p = new node;
        p->keyword = key;
        p->meaning = value;
        p->left = NULL;
        p->right = NULL;
        t = p;
    }
    else if (tKey_small > key_small)
    {
        t->left = insert(t->left, key, value);
    }
    else
    {
        t->right = insert(t->right, key, value);
    }
    return t;
}

void dictionary::display(node *t)
{
    if (t != NULL)
    {
        display(t->left);
        std::cout << t->keyword << " - " << t->meaning << std::endl;
        display(t->right);
    }
}

void dictionary::display()
{
    display(root);
}

void dictionary::update(std::string key, std::string value)
{
    node *temp = root;
    while (temp != NULL)
    {
        std::string key_small = convert(key);
        std::string tKey_small = temp == NULL ? "" : convert(temp->keyword);
        if (key_small == tKey_small)
        {
            temp->meaning = value;
            std::cout << "Meaning of \"" << temp->keyword << "\" updated!" << std::endl;
            return;
        }
        else if (key_small > tKey_small)
            temp = temp->right;
        else
            temp = temp->left;
    }
    std::cout << "Word not found in the dictionary" << std::endl;
}

int main()
{
    dictionary D;
    /* std::string a = "HAHAHAHAHAH";
    std::string b = convert(a);
    std::cout << a << std::endl << b; */
    D.create();
    D.display();
    std::string k, m;
    std::cout << "Enter keyword to update: ";
    std::cin >> k;
    std::cout << "Enter new meaning: ";
    std::cin >> m;
    D.update(k, m);
    D.display();
    return 0;
}