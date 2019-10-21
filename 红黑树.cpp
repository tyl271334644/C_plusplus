#include <iostream>
#include <stdlib.h>
//#include <time.h>
using namespace std;

enum Color
{
	BLACK,
	RED
};

template <class K, class V>
struct RBTNode
{
	typedef RBTNode<K, V> Node;
	Node* _pLeft = nullptr;
	Node* _pRight = nullptr;
	Node* _pParent = nullptr;
	pair<K, V> _kv;
	Color _color = RED;
};

template <class K, class V>
class RBTree
{
public:
	typedef RBTNode<K, V> Node;
	typedef Node* pNode;
	typedef Node* PNode;
	RBTree()
	{
		_header = new Node;
		_header->_pParent = nullptr;
		_header->_pLeft = _header;
		_header->_pRight = _header;
	}

	bool Insert(const pair<K, V>& kv)
	{
		if (_header->_pParent == nullptr)
		{
			pNode root = new Node;
			root->_kv = kv;
			root->_color = BLACK;

			root->_pParent = _header;
			_header->_pParent = root;

			_header->_pLeft = root;
			_header->_pRight = root;

			return true;
		}

		pNode cur = _header->_pParent;
		pNode parent = nullptr;

		while (cur)
		{
			if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_pRight;
			}
			else if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_pLeft;
			}
			else
				return false;
		}

		pNode newNode = new Node;
		newNode->_kv = kv;
		if (kv.first > parent->_kv.first)
			parent->_pRight = newNode;
		else
			parent->_pLeft = newNode;

		newNode->_pParent = parent;

		cur = newNode;

		while (cur != _header->_pParent && cur->_pParent->_color == RED)
		{
			// cur, parent, gParent, uncle
			pNode parent = cur->_pParent;
			pNode gParent = parent->_pParent;
			if (gParent->_pLeft == parent)
			{
				pNode uncle = gParent->_pRight;
				// u������Ϊ��
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gParent->_color = RED;
					cur = gParent;
				}
				else
				{
					//u������/  u������Ϊ��
					//��ת����ɫ
					//�ж��Ƿ���Ҫ˫��
					if (cur == parent->_pRight)
					{
						RotateL(parent);
						swap(parent, cur);
					}

					//�ҵ���
					RotateR(gParent);
					parent->_color = BLACK;
					gParent->_color = RED;
					break;
				}
			}
			else
			{
				pNode uncle = gParent->_pLeft;
				//��Ӧ
				if (uncle && uncle->_color == RED)
				{
					uncle->_color = parent->_color = BLACK;
					gParent->_color = RED;
					cur = gParent;
				}
				else
				{
					//�ж��Ƿ�Ҫ˫��
					if (cur == parent->_pLeft)
					{
						RotateR(parent);
						swap(cur, parent);
					}

					RotateL(gParent);
					parent->_color = BLACK;
					gParent->_color = RED;
					break;
				}
			}

		}

		_header->_pParent->_color = BLACK;
		_header->_pLeft = leftMost();
		_header->_pRight = rightMost();
		return true;
	}

	pNode leftMost()
	{
		pNode cur = _header->_pParent;
		while (cur && cur->_pLeft)
			cur = cur->_pLeft;
		return cur;
	}

	pNode rightMost()
	{
		pNode cur = _header->_pParent;
		while (cur && cur->_pRight)
			cur = cur->_pRight;
		return cur;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_pRight;
		Node* subRL = subR->_pLeft;

		subR->_pLeft = parent;
		parent->_pRight = subRL;

		if (subRL)
			subRL->_pParent = parent;

		if (parent != _header->_pParent)
		{
			Node* gParent = parent->_pParent;
			if (gParent->_pLeft == parent)
				gParent->_pLeft = subR;
			else
				gParent->_pRight = subR;
			subR->_pParent = gParent;
		}
		else
		{
			subR->_pParent = nullptr;
			_header->_pParent = subR;
		}

		parent->_pParent = subR;

	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_pLeft;
		Node* subLR = subL->_pRight;

		//�������� subL , parent, subLR
		subL->_pRight = parent;
		parent->_pLeft = subLR;

		//��������subLR
		if (subLR)
			subLR->_pParent = parent;

		//subL��parent->parent ˫������
		if (parent != _header->_pParent)
		{
			Node* gParent = parent->_pParent;
			if (gParent->_pLeft == parent)
				gParent->_pLeft = subL;
			else
				gParent->_pRight = subL;
			subL->_pParent = gParent;
		}
		else
		{
			_header->_pParent = subL;
			subL->_pParent = nullptr;
		}

		//��������parent, subL
		parent->_pParent = subL;

	}

	void _Inorder(pNode root)
	{
		if (root)
		{
			_Inorder(root->_pLeft);
			cout << root->_kv.first << "-->" << root->_kv.second << endl;
			_Inorder(root->_pRight);
		}
	}

	void Inorder()
	{
		_Inorder(_header->_pParent);
	}

	bool IsValidRBTree()
	{
		PNode pRoot = _header->_pParent;
		// ����Ҳ�Ǻ����
		if (nullptr == pRoot)
			return true;

		// �����ڵ��Ƿ��������
		if (BLACK != pRoot->_color)
		{
			cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << endl;
			return false;
		}
		// ��ȡ����һ��·���к�ɫ�ڵ�ĸ���
		size_t blackCount = 0;
		PNode pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_color)
				blackCount++;
			pCur = pCur->_pLeft;
		}
		// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}
	bool _IsValidRBTree(PNode pRoot, size_t k, const size_t blackCount)
	{
		//�ߵ�null֮���ж�k��black�Ƿ����
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
				return false;
			}
			return true;
		}
		// ͳ�ƺ�ɫ�ڵ�ĸ���
		if (BLACK == pRoot->_color)
			k++;
		// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
		PNode pParent = pRoot->_pParent;
		if (pParent && RED == pParent->_color && RED == pRoot->_color)
		{
			cout << "Υ����������û������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}
		return _IsValidRBTree(pRoot->_pLeft, k, blackCount) &&
			_IsValidRBTree(pRoot->_pRight, k, blackCount);
	}


private:
	pNode _header;
};

void testRBTree()
{
	RBTree<int, int> rbtree;
	rbtree.Insert(make_pair(0, 0));
	rbtree.Insert(make_pair(1, 0));
	rbtree.Insert(make_pair(2, 0));
	rbtree.Insert(make_pair(10, 0));
	rbtree.Insert(make_pair(3, 0));
	rbtree.Insert(make_pair(9, 0));



	rbtree.Inorder();
	cout << "IsValidRBTree: " << rbtree.IsValidRBTree() << endl;
}

//void testRBTree2()
//{
//	srand(time(nullptr));
//	int n;
//	cin >> n;
//	RBTree<int, int> rb;
//	while (n--)
//	{
//		int num = rand();
//		//cout << num << " ";
//		rb.Insert(make_pair(num, num));
//	}
//	cout << endl;
//	cout << "IsValidRBTree: " << rb.IsValidRBTree() << endl;
//}

int main()
{
	testRBTree();
	system("pause");
	return 0;
}
