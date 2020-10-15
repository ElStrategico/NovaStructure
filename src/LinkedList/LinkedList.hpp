#pragma once

#include <stdint.h>

#include <LinkedList/ListNode.hpp>

namespace ns
{
	template<typename T>
	class LinkedList
	{
	private:
		uint32_t size;

		ListNode<T>* head;
		ListNode<T>* tail;
	public:
		LinkedList();
		~LinkedList();

		uint32_t getSize();
		bool isEmpty();

		ListNode<T>* find(int index);
		ListNode<T>* findByValue(T value);
		T operator[](int index);

		void insert(T value);

		void remove(int index);
		void clear();
	};

	template<typename T>
	inline LinkedList<T>::LinkedList()
	{
		size = 0;

		head = nullptr;
		tail = nullptr;
	}

	template<typename T>
	inline LinkedList<T>::~LinkedList()
	{
		clear();
	}

	template<typename T>
	inline uint32_t LinkedList<T>::getSize()
	{
		return size;
	}

	template<typename T>
	inline bool LinkedList<T>::isEmpty()
	{
		return !getSize();
	}

	template<typename T>
	inline ListNode<T>* LinkedList<T>::find(int index)
	{
		ListNode<T>* currentNode = head;

		for (int i = 0; i < getSize(); i++)
		{
			if (i == index) return currentNode;
			currentNode = currentNode->next;
		}

		return nullptr;
	}

	template<typename T>
	inline ListNode<T>* LinkedList<T>::findByValue(T value)
	{
		for (int i = 0; i < getSize(); i++)
		{
			ListNode<T>* listNode = find(i);
			if (listNode->value == value) return listNode;
		}
		return nullptr;
	}

	template<typename T>
	inline T LinkedList<T>::operator[](int index)
	{
		ListNode<T>* node = find(index);

		return node ? node->value : T();
	}

	template<typename T>
	inline void LinkedList<T>::insert(T value)
	{
		if (isEmpty())
		{
			head = new ListNode<T>(value, nullptr, nullptr);
			tail = head;
		}
		else
		{
			tail->next = new ListNode<T>(value, tail, nullptr);
			tail = tail->next;
		}
		size++;
	}

	template<typename T>
	inline void LinkedList<T>::remove(int index)
	{
		ListNode<T>* removable = find(index);
		if (!removable) return;

		if (head == removable) head = removable->next;
		if (tail == removable) tail = removable->prev;

		if (removable->prev) removable->prev->next = removable->next;
		if (removable->next) removable->next->prev = removable->prev;

		size--;
		delete removable;
	}

	template<typename T>
	inline void LinkedList<T>::clear()
	{
		for (int i = 0; i < getSize(); i++)
		{
			remove(i);
		}
	}
}