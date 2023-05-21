/* A Dictionary stores keywords & its meanings. Provide facility for adding new keywords, deleting keywords, updating values of any entry. Provide facility to display whole data sorted in ascending/descending order. Also find how many maximum comparisons may require for finding any keyword. Use Height balance tree and find the complexity for finding a keyword */
#include <iostream>
#include <string>
int counter = 1;
struct node {
    std::string key, value;
    node *left, *right;
    int height;
};
int max(int a, int b) {
    return a > b ? a : b;
}
std::string convertToLowerCase(std::string str) {
    int j, k, len = str.size();
    std::string str_small = str;
    for (j = 0; j < len; j++) {
        if (((int)str[j] >= 97 && (int)str[j] <= 122) || ((int)str[j] >= 65 && (int)str[j] <= 90))
            str_small[j] = (int)str[j] <= 90 ? (char)((int)str[j] + 32) : str[j];
        else
            str_small[j] = str[j];
    }
    str_small[j] = '\0';
    return str_small;
}
class AVL {
    node *root;
public:
    AVL();
    int heightOfNode(node *t);
    int balance_factor(node *t);
    node *rotateRight(node *t);
    node *rotateLeft(node *t);
    node *createNode(std::string keyword, std::string meaning);
    node *insertNode(node *t, std::string keyword, std::string value);
    node *deleteNode(std::string keyword);
    void preorder(node *t);
    void inorder(node *t);
    void insertNode(std::string keyword, std::string meaning);
    void preorder();
    void inorder();
};
int AVL::heightOfNode(node *t) {
    if (t == NULL)
        return 0;
    return t->height;
}
int AVL::balance_factor(node *t) {
    if (t == NULL)
        return 0;
    return heightOfNode(t->left) - heightOfNode(t->right);
}
node *AVL::rotateRight(node *y) {
    node *x = y->left;
    node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(heightOfNode(y->right), heightOfNode(y->left)) + 1;
    x->height = max(heightOfNode(x->right), heightOfNode(x->left)) + 1;
    return x;
}
node *AVL::rotateLeft(node *x) {
    node *y = x->right;
    node *T2 = y->left;
    y->left = x;
    x->right = T2;
    y->height = max(heightOfNode(y->right), heightOfNode(y->left)) + 1;
    x->height = max(heightOfNode(x->right), heightOfNode(x->left)) + 1;
    return y;
}
node *AVL::createNode(std::string keyword, std::string meaning) {
    node *p = new node;
    p->key = keyword;
    p->value = meaning;
    p->left = NULL;
    p->right = NULL;
    p->height = 1;
    return p;
}
node *AVL::insertNode(node *t, std::string keyword, std::string meaning) {
    std::string key_small = convertToLowerCase(keyword);
    std::string tKey_small = t == NULL ? "" : convertToLowerCase(t->key);
    if (t == NULL)
        return createNode(keyword, meaning);
    else if (tKey_small > key_small)
        t->left = insertNode(t->left, keyword, meaning);
    else 
        t->right = insertNode(t->right, keyword, meaning);
    t->height = 1 + max(heightOfNode(t->left), heightOfNode(t->right));
    int BF = balance_factor(t);
    // Left Left (LL) Case
    if (BF > 1 && key_small < tKey_small)
        return rotateRight(t);
    // Right Right (RR) case
    if (BF < -1 && key_small > tKey_small)
        return rotateLeft(t);
    // Left Right (LR) case
    if (BF > 1 && key_small > tKey_small) {
        t->left = rotateLeft(t->left);
        return rotateRight(t);
    }
    // Right Left (RL) case
    if (BF < -1 && key_small < tKey_small) {
        t->right = rotateRight(t->right);
        return rotateLeft(t);
    }
    return t;
}
void AVL::preorder(node *t) {
    if (t != NULL) {
        std::cout << counter << ")" << t->key << " - " << t->value << std::endl;
        counter++;
        preorder(t->left);
        preorder(t->right);
    }
}
void AVL::inorder(node *t) {
    if (t != NULL) {
        inorder(t->left);
        std::cout << counter << ")" << t->key << " - " << t->value << std::endl;
        counter++;
        inorder(t->right);
    }
}
void AVL::preorder() {
    counter = 1;
    preorder(root);
}
void AVL::inorder() {
    counter = 1;
    inorder(root);
}
AVL::AVL() {
    std::cout << "Enter the no of nodes: ";
    int n;
    std::string keyword, meaning;
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cout << "Entry " << i << std::endl;
        std::cout << "Enter the keyword:" << std::endl;
        std::getline(std::cin >> std::ws, keyword);
        std::cout << "Enter its meaning:" << std::endl;
        std::getline(std::cin >> std::ws, meaning);
        insertNode(keyword, meaning);
    }
}
void AVL::insertNode(std::string keyword, std::string meaning) {
    root = insertNode(root, keyword, meaning);
}
int main() {
    AVL MyTree;
    std::cout << "In Preorder:" << std::endl;
    MyTree.preorder();
    std::cout << "In Inorder:" << std::endl;
    MyTree.inorder();
    std::string keyword, meaning;
    std::cout << "Enter new keyword to be inserted - ";
    std::getline(std::cin >> std::ws, keyword);
    std::cout << "Enter its meaning:" << std::endl;
    std::getline(std::cin >> std::ws, meaning);
    MyTree.insertNode(keyword, meaning);
    std::cout << "In Preorder:" << std::endl;
    MyTree.preorder();
    std::cout << "In Inorder:" << std::endl;
    MyTree.inorder();
    return 0;
}