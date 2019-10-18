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

//����������
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
		p->Left = createBinaryTree();//�ݹ鴴��������
		p->Right = createBinaryTree();//�ݹ鴴��������
	}
	return p;
}

//ǰ�����
void  preOrderTraverse(Node* root)
{
	if (root)
	{
		cout << root->data << ' ';
		preOrderTraverse(root->Left);
		preOrderTraverse(root->Right);
	}
}

//�������
void inOrderTraverse(Node* root)
{
	if (root)
	{
		inOrderTraverse(root->Left);
		cout << root->data << ' ';
		inOrderTraverse(root->Right);
	}
}

//��������
void lastOrderTraverse(Node* root)
{
	if (root)
	{
		lastOrderTraverse(root->Left);
		lastOrderTraverse(root->Right);
		cout << root->data << ' ';
	}
}

//�������ڵ�����Ŀ
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

//�����������
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

//������Ҷ�ӽڵ���
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
	cout << "�����������ɹ�" << endl;
	
	cout << "ǰ�����:" << endl;
	preOrderTraverse(root);
	cout << endl;

	cout << "�������:" << endl;
	inOrderTraverse(root);
	cout << endl;

	cout << "�������:" << endl;
	lastOrderTraverse(root);
	cout << endl;

	cout << "�������ܽڵ���Ϊ��" << Nodenum(root) << endl;

	cout << "���������Ϊ��" << DepthOfTree(root) << endl;

	cout << "������Ҷ�ӽڵ���Ϊ��" << Leafnum(root) << endl;
	system("pause");
	return 0;
}

///////////C++�ݹ�ʵ��ǰ�����/////////////
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
///////////C++�ݹ�ʵ�ֺ������/////////////
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