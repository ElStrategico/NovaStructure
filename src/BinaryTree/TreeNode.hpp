#pragma once

namespace ns
{
	template<typename T>
	class TreeNode
	{
	public:
		TreeNode<T>* right;
		TreeNode<T>* left;
		T value;

		TreeNode(T value = T(), TreeNode<T>* right = nullptr, TreeNode<T>* left = nullptr);
	};

	template<typename T>
	inline TreeNode<T>::TreeNode(T value, TreeNode<T>* right, TreeNode<T>* left) :
	value(value), right(right), left(left)
	{

	}
}