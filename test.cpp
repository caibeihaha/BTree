#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
template<class K,class V>
struct pair
{
	K _first;
	V _second;
	pair(const K &k, const V &v)
		:_first(k)
		, _second(v)
	{}
};
template <class K,int M>
struct BTreeNode
{
	pair<K, V> _kv;
	K _keys[M];
	BTreeNode<K, M> *_subs[M + 1];
	BTreeNode<K, M>*_parent;
	size_t size;
	BTreeNode()
		:_parent(NULL)
		,_size(0)
		, _kv()
	{
		for (int i = 0; i < M; i++)
		{
			_keys[i] = k();
			_subs[i] = NULL;
		}
		_subs[M] = NULL;
	}
};
template<class K,class V>
class BTree
{
	typedef BTreeNode<K, M> Node;
private:
	Node *_root;
public:
	BTree()
		:_root(NULL)
	{}
	pair<Node *, int> Find(const K&key)
	{
		Node *parent = NULL
			Node *cur = _root;
		while (cur)
		{
			for (int i = 0; i < cur->_size; i++)
			{
				if (cur->_keys[i] == key)
				{
					return pair<Node *, i>(cur, i);
					return true;
				}
				else if (cur->_key[i]>key)
					break;
				else
					i++;
			}
			parent = cur;
			cur = cur->_subs[i];
		}
		return pair<Node *, int>(parent, -1);
	}
	bool Insert(const K&key)
	{
		if (_root == NULL)
		{
			_root = new Node;
			_root->_keys[0] = key;
			_root->_size = 1;
			return true;
		}
		pair<Node *, int> ret = Find(key);
		if (ret._second != -1)
		{
			return false;
		}
		Node *sub = NULL;
		K newkey = key;
		Node *cur = ret._first;
		while (1)
		{
			InsertKey(cur, newkey, sub);
			if (cur->_size < M)
			{
				return true;
			}
			//╥жая

			int div = M / 2;
			Node *tmp = new Node;
			int index = 0;
			for (int i = div + 1; i < cur->_size; i++)
			{
				tmp->_keys[index++] = cur->_keys[i];
				tmp->_size++;
			}
			index = 0;
			for (int i = div + 1; i < cur->_size; i++)
			{
				tmp->_subs[index++] = cur->_subs[i];
				if (cur->_subs[i])
				{
					cur->_subs[i]->_parent = tmp;
				}
			}
			cur->_size = cur->_size - tmp->_size - 1;
			if (cur->_parent == NULL)
			{
				_root = new Node;
				_root->_keys[0] = cur->_keys[div];
				_root->_size = 1;
				_root->_subs[0] = cur;
				cur->_parent = _root;
				_root->_subs[1] = tmp;;
				tmp->_parent = _root;
				return true;
			}
			else
			{

				newkey = cur->_keys[div];
				sub = tmp;
				cur = cur->_parent;
			}
		}
		return false;
	}
	void Inorder()
	{
		_Inorder(root);
	}
	void InsertKey(Node *cur,const k&key,Node *sub)
	{
		int end = cur->_size;
		while (end >= 0)
		{
			if (cur->_keys[end] > key)
			{
				cur->_keys[end + 1] = cur->_keys[end];
				cur->_subs[end + 2] = cur->_subs[end + 1];
				end--;
			}
			else
			{
				break;
			}
		}
		cur->_keys[end + 1] = key;
		cur->_subs[end + 2] = sub;
		if (sub != NULL)
			sub->_parent = cur;
		cur->_size++;
	}
	protected:
		void _Inorder(Node *root)
		{
			if (_root == NULL)
			{
				return;
			}
			for (int i = 0; i < root->_size; i++)
			{
				_Inorder(root->_subs[i]);
				cout << root->_keys[i] << " ";
			}
		}
};
int main()
{
	BTree<int, int> b;
	getchar();
	return 0;
}