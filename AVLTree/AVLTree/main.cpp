#include <iostream>
using namespace std;

class TreeNode
{
public:
	int key;
	TreeNode* left;
	TreeNode* right;
	int height;
	TreeNode() {}
};

class AvlTree
{
private:
	TreeNode* root;

	int getNodeHeight(TreeNode* N)
	{
		if (N == NULL)
		{
			return 0;
		}
		return N->height;
	}
	TreeNode* newNode(int key)
	{
		TreeNode* node = new TreeNode();
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		node->height = 1;
		return(node);
	}
	TreeNode* rightRotate(TreeNode* y)
	{
		TreeNode* x = y->left;
		TreeNode* T2 = x->right;

		x->right = y;
		y->left = T2;

		y->height = max(getNodeHeight(y->left), getNodeHeight(y->right)) + 1;
		x->height = max(getNodeHeight(x->left), getNodeHeight(x->right)) + 1;

		return x;
	}

	TreeNode* leftRotate(TreeNode* x)
	{
		TreeNode* y = x->right;
		TreeNode* T2 = y->left;

		y->left = x;
		x->right = T2;

		x->height = max(getNodeHeight(x->left), getNodeHeight(x->right)) + 1;
		y->height = max(getNodeHeight(y->left), getNodeHeight(y->right)) + 1;

		return y;
	}

	int getBalance(TreeNode* N)
	{
		if (N == NULL)
		{
			return 0;
		}
		return getNodeHeight(N->left) - getNodeHeight(N->right);
	}

	TreeNode* insert(TreeNode* node, int key)
	{
		if (node == NULL)
		{
			return(newNode(key));
		}

		if (key < node->key)
		{
			node->left = insert(node->left, key);
		}
		else if (key > node->key)
		{
			node->right = insert(node->right, key);
		}
		else
		{
			return node;
		}

		node->height = 1 + max(getNodeHeight(node->left),
			getNodeHeight(node->right));

		int balance = getBalance(node);

		if (balance > 1 && key < node->left->key)
		{
			return rightRotate(node);
		}

		if (balance < -1 && key > node->right->key)
		{
			return leftRotate(node);
		}

		if (balance > 1 && key > node->left->key)
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		if (balance < -1 && key < node->right->key)
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		return node;
	}

	TreeNode* minValueNode(TreeNode* node)
	{
		TreeNode* current = node;
		while (current->left != NULL)
		{
			current = current->left;
		}
		return current;
	}

	TreeNode* deleteNode(TreeNode* root, int key)
	{
		if (root == NULL)
		{
			return root;
		}

		if (key < root->key)
		{
			root->left = deleteNode(root->left, key);
		}
		else if (key > root->key)
		{
			root->right = deleteNode(root->right, key);
		}
		else
		{
			if ((root->left == NULL) || (root->right == NULL))
			{
				TreeNode* temp = root->left ? root->left : root->right;

				if (temp == NULL)
				{
					temp = root;
					root = NULL;
				}
				else
				{
					*root = *temp;
				}
				delete temp;
			}
			else
			{
				TreeNode* temp = minValueNode(root->right);

				root->key = temp->key;

				root->right = deleteNode(root->right, temp->key);
			}
		}

		if (root == NULL)
		{
			return root;
		}

		root->height = 1 + max(getNodeHeight(root->left), getNodeHeight(root->right));

		int balance = getBalance(root);

		if (balance > 1 && getBalance(root->left) >= 0)
		{
			return rightRotate(root);
		}

		if (balance > 1 && getBalance(root->left) < 0)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		if (balance < -1 && getBalance(root->right) <= 0)
		{
			return leftRotate(root);
		}

		if (balance < -1 && getBalance(root->right) > 0)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}

	void preOrder(TreeNode* root)
	{
		if (root != NULL)
		{
			cout << root->key << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}
public:
	AvlTree() {}
	void addElement(int key)
	{
		root = insert(root, key);
	}

	void deleteElement(int key)
	{
		root = deleteNode(root, key);
	}


	void printTree()
	{
		preOrder(root);
	}

	int getHeight()
	{
		if (root == NULL)
		{
			return 0;
		}
		return root->height;
	}

	int getTreeBalance()
	{
		if (root == NULL)
		{
			return 0;
		}
		return getNodeHeight(root->left) - getNodeHeight(root->right);
	}
};



int main()
{
	AvlTree tree;

	tree.addElement(10);
	tree.addElement(20);
	tree.addElement(30);
	tree.addElement(40);
	tree.addElement(50);
	tree.addElement(25);

	cout << "Preorder traversal of the constructed AVL tree is \n";
	tree.printTree();
	cout << endl;

	cout << "Height of AVL tree is " << tree.getHeight() << endl;
	cout << "Balance of AVL tree is " << tree.getTreeBalance() << endl;

	tree.deleteElement(20);

	cout << "Preorder traversal after deletion of 20: \n";
	tree.printTree();
	cout << endl;

	cout << "Height of AVL tree after deletion is " << tree.getHeight() << endl;
	cout << "Balance of AVL tree after deletion is " << tree.getTreeBalance() << endl;

	return 0;

	return 0;
}