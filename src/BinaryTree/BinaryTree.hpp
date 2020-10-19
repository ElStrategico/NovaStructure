#pragma once

#include <stdint.h>

#include <BinaryTree/TreeNode.hpp>

namespace ns
{
	template<typename T>
	class BinaryTree
	{
	private:
		uint32_t size;
		TreeNode<T>* root;
	public:
		BinaryTree();

		uint32_t getSize();
		bool isEmpty();

		TreeNode<T>* findNode(T key);
		T find(T key);

		void insert(T value);
	};

	template<typename T>
	inline BinaryTree<T>::BinaryTree()
	{
		size = 0;
		root = nullptr;
	}

	template<typename T>
	inline uint32_t BinaryTree<T>::getSize()
	{
		return size;
	}

	template<typename T>
	inline bool BinaryTree<T>::isEmpty()
	{
		return !size;
	}

	template<typename T>
	inline TreeNode<T>* BinaryTree<T>::findNode(T key)
	{
		TreeNode<T>* current = root;

		while (current != nullptr)
		{
			if (key == current->value) return current;

			if (key > current->value) current = current->left;
			else current = current->right;
		}

		return nullptr;
	}

	template<typename T>
	inline T BinaryTree<T>::find(T key)
	{
		TreeNode<T>* treeNode = findNode(key);

		return treeNode ? treeNode->value : T();
	}

	template<typename T>
	inline void BinaryTree<T>::insert(T value)
	{
		if (isEmpty())
		{
			root = new TreeNode<T>(value);
		}
		else
		{
			TreeNode<T>* current = root;

			while (true)
			{
				if (value > current->value)
				{
					if (current->left == nullptr)
					{
						current->left = new TreeNode<T>(value);
						return;
					}
					current = current->left;
				}
				else
				{
					if (current->right == nullptr)
					{
						current->right = new TreeNode<T>(value);
						return;
					}
					current = current->right;
				}
			}
		}
		size++;
	}
}