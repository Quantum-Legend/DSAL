#include <iostream>
#include <string>
using namespace std;

struct AVLnode
{
public:
	string cWord;
	string cMean;
	AVLnode *left, *right;
	int iHt;
};

class AVLtree
{

public:
	AVLnode *Root;
	AVLtree()
	{
		Root = NULL;
	}
	AVLnode *insert(AVLnode *, string, string);
	AVLnode *deletE(AVLnode *, string);
	AVLnode *LL(AVLnode *);
	AVLnode *RR(AVLnode *);
	AVLnode *LR(AVLnode *);
	AVLnode *RL(AVLnode *);
	int height(AVLnode *);
	int bFactor(AVLnode *);
	void inOrder(AVLnode *);
	void search(AVLnode *, string word);
	void update(AVLnode *,string word);
};

AVLnode *AVLtree::insert(AVLnode *root, string nWord, string nMean)
{
	if (root == NULL)
	{
		root = new AVLnode;
		root->left = root->right = NULL;
		root->cWord = nWord;
		root->cMean = nMean;
		root->iHt = 0;
	}
	else if (root->cWord > nWord)
	{
		root->left = insert(root->left, nWord, nMean);
	}
	else
	{
		root->right = insert(root->right, nWord, nMean);
	}

	root->iHt = max(height(root->left), height(root->right)) + 1;

	if (bFactor(root) == 2)
	{
		if (root->left->cWord > nWord)
			root = RR(root);
		else
			root = LR(root);
	}

	if (bFactor(root) == -2)
	{
		if (root->right->cWord > nWord)
			root = RL(root);
		else
			root = LL(root);
	}

	return root;
}

AVLnode *AVLtree::deletE(AVLnode *curr, string x)
{
	AVLnode *temp;
	if (curr == NULL)
	{
		cout << "\nWord not present!\n";
		return curr;
	}

	else if (x > curr->cWord)
		curr->right = deletE(curr->right, x);

	else if (x < curr->cWord)
		curr->left = deletE(curr->left, x);

	else if (curr->right == NULL || curr->left == NULL)
	{
		curr = curr->left ? curr->left : curr->right;
		cout << "\nWord deleted Successfully!\n";
	}

	else
	{
		temp = curr->right;
		while (temp->left)
			temp = temp->left;
		curr->cWord = temp->cWord;
		curr->cMean = temp->cMean;
		curr->right = deletE(curr->right, temp->cWord);
	}

	if (curr == NULL)
		return curr;

	curr->iHt = max(height(curr->left), height(curr->right)) + 1;

	if (bFactor(curr) == 2)
	{
		if (bFactor(curr->left) >= 0)
			curr = RR(curr);
		else
			curr = LR(curr);
	}

	if (bFactor(curr) == -2)
	{
		if (bFactor(curr->right) <= 0)
			curr = LL(curr);
		else
			curr = RL(curr);
	}

	return (curr);
}

int AVLtree::height(AVLnode *curr)
{
	if (curr == NULL)
		return -1;
	else
		return curr->iHt;
}

int AVLtree::bFactor(AVLnode *curr)
{
	int lh = 0, rh = 0;
	if (curr == NULL)
		return 0; 
	else
		return height(curr->left) - height(curr->right);
}

AVLnode *AVLtree::RR(AVLnode *curr)
{
	AVLnode *temp = curr->left;
	curr->left = temp->right;
	temp->right = curr;
	curr->iHt = max(height(curr->left), height(curr->right)) + 1;
	temp->iHt = max(height(temp->left), height(temp->right)) + 1;
	return temp;
}

AVLnode *AVLtree::LL(AVLnode *curr)
{
	AVLnode *temp = curr->right;
	curr->right = temp->left;
	temp->left = curr;
	curr->iHt = max(height(curr->left), height(curr->right)) + 1;
	temp->iHt = max(height(temp->left), height(temp->right)) + 1;
	return temp;
}

AVLnode *AVLtree::RL(AVLnode *curr)
{
	curr->right = RR(curr->right);
	return LL(curr);
}

AVLnode *AVLtree::LR(AVLnode *curr)
{
	curr->left = LL(curr->left);
	return RR(curr);
}

void AVLtree::inOrder(AVLnode *curr)
{
	if (curr != NULL)
	{
		inOrder(curr->left);
		cout << "\n\t" << curr->cWord << "\t" << curr->cMean;
		inOrder(curr->right);
	}
}
void AVLtree::search(AVLnode *curr, string x)
{
	int comparisons = 0;
	if (curr == NULL)
	{
		cout << "\nWord not present!\n";
		return;
	}

	while (curr != NULL)
	{
		comparisons++;
		if (x == curr->cWord)
		{
			cout << "\nWord found!\n";
			cout << "Number of comparisons: " << comparisons << endl;
			return;
		}
		else if (x > curr->cWord)
			curr = curr->right;
		else
			curr = curr->left;
	}
}

void AVLtree::update (AVLnode* root, string word) {
	string newMeaning;
	cout<<"Enter the New Meaning of the Word: ";
	getline(cin,newMeaning);
    AVLnode* curr = root;

    while (curr != NULL) {
        if (word == curr -> cWord) {
            curr -> cMean = newMeaning;
            return;
        }
        else if (word > curr -> cWord)
            curr = curr -> right;
        else if(word<curr->cWord)
            curr = curr -> left;
		else
			cout<<"Word Not Found"<<endl;
    }
}


int main()
{
	int ch, n;
	AVLtree avl;
	AVLnode *temp = NULL;
	string word;
	string mean;

	cout << "\n\tAVL TREE IMPLEMENTATION";
	cout << "\n--------------------------------------";
	do
	{
		cout << "\n--MENU--";
		cout << "\n1.Insert \n2.Inorder \n3.Delete \n4.Search \n5.Update \n6.Exit";
		cout << "\nEnter your choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			cout << "Enter Number of data you want to Enter: ";
			cin >> n;
			cin.ignore();
			for (int i = 0; i < n; i++)
			{
				cout << "\nEnter Word: ";
				getline(cin, word);
				cout << "\nEnter Meaning: ";
				getline(cin, mean);
				avl.Root = avl.insert(avl.Root, word, mean);
			}
			break;
		case 2:
			cout << "\nInorder Traversal:\n\tWORD\tMEANING";
			avl.inOrder(avl.Root);
			cout << '\n';
			break;
		case 3:
			cout << "\nEnter the word to be deleted : ";
			cin >> word;
			avl.Root = avl.deletE(avl.Root, word);
			break;

		case 4:
			cout << "\nEnter Word to be search: ";
			cin.ignore();
			getline(cin, word);
			avl.search(avl.Root, word);
			break;

		case 5:
			cout << "\nEnter Word to be Updated: ";
			cin.ignore();
			getline(cin, word);
			avl.update(avl.Root, word);
			break;
		case 6:
			cout<<"Exiting Program !!!"<<endl;
			exit(0);
		}
	} while (ch != 6);

	return 0;
}

