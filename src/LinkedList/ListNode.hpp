#pragma once

namespace ns
{
	template <typename T>
	class ListNode
	{
	public:
		T value;
		ListNode<T>* prev;
		ListNode<T>* next;
	
		ListNode(T value = T(), ListNode<T>* prev = nullptr, ListNode<T>* next = nullptr);
	};

	template<typename T>
	inline ListNode<T>::ListNode(T value, ListNode<T>* prev, ListNode<T>* next) :
	value(value), prev(prev), next(next)
	{

	}
}