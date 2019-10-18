#include <iostream>
#include <stdlib.h>

using namespace std;
typedef  int TelemType;

typedef struct BinaryTreeNode
{
	TelemType data;
	struct BinaryTreeNode* Left;
	struct BinaryTreeNode* Right;
}Node;

//创建二叉树
Node* createBinaryTree()
{
	Node* p;
	TelemType data;
	cin >> data;
	if (data == 0)
	{
		p = NULL;
	}
	else
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = data;
		p->Left = createBinaryTree();//递归创建左子树
		p->Right = createBinaryTree();//递归创建右子树
	}
	return p;
}

//前序遍历
void  preOrderTraverse(Node* root)
{
	if (root)
	{
		cout << root->data << ' ';
		preOrderTraverse(root->Left);
		preOrderTraverse(root->Right);
	}
}

//中序遍历
void inOrderTraverse(Node* root)
{
	if (root)
	{
		inOrderTraverse(root->Left);
		cout << root->data << ' ';
		inOrderTraverse(root->Right);
	}
}

//后续遍历
void lastOrderTraverse(Node* root)
{
	if (root)
	{
		lastOrderTraverse(root->Left);
		lastOrderTraverse(root->Right);
		cout << root->data << ' ';
	}
}

//二叉树节点中数目
int Nodenum(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + Nodenum(root->Left) + Nodenum(root->Right);
	}
}

//二叉树的深度
int DepthOfTree(Node* root)
{
	if (root)
	{
		return DepthOfTree(root->Left) > DepthOfTree(root->Right) ?
			DepthOfTree(root->Left) + 1 : DepthOfTree(root->Right) + 1;
	}
	if (root==NULL)
	{
		return 0;
	}
}

//二叉树叶子节点数
int Leafnum(Node* root)
{
	if (!root)
	{
		return 0;
	}
	else if ((root->Left == NULL) && (root->Right == NULL))
	{
		return 1;
	}
	else
	{
		return (Leafnum(root->Left) + Leafnum(root->Right));
	}
}


int main()
{
	Node* root = NULL;
	root = createBinaryTree();
	cout << "二叉树建立成功" << endl;
	
	cout << "前序遍历:" << endl;
	preOrderTraverse(root);
	cout << endl;

	cout << "中序遍历:" << endl;
	inOrderTraverse(root);
	cout << endl;

	cout << "后序遍历:" << endl;
	lastOrderTraverse(root);
	cout << endl;

	cout << "二叉树总节点数为：" << Nodenum(root) << endl;

	cout << "二叉树深度为：" << DepthOfTree(root) << endl;

	cout << "二叉树叶子节点数为：" << Leafnum(root) << endl;
	system("pause");
	return 0;
}

///////////C++递归实现前序遍历/////////////
//class Solution {
//public:
//	vector<int> preorderTraversal(TreeNode* root) {
//		if (root)
//		{
//			res.push_back(root->val);
//			preorderTraversal(root->left);
//			preorderTraversal(root->right);
//		}
//		return res;
//	}
//private:
//	vector<int> res;
//};
///////////C++递归实现后序遍历/////////////
//class Solution {
//public:
//	vector<int> postorderTraversal(TreeNode* root) {
//		if (root)
//		{
//			postorderTraversal(root->left);
//			postorderTraversal(root->right);
//			res.push_back(root->val);
//		}
//		return res;
//	}
//private:
//	vector<int> res;
//};