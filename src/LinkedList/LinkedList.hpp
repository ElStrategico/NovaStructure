#pragma once

#include <map>

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
		void insert(T value, int index);

		void reverse();

		void replace(int index, T value);

		void swap(ListNode<T>* x, ListNode<T>* y);
		void swap(int xIndex, int yIndex);

		void remove(int index);
		int removeDuplicates();
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
			head = new ListNode<T>(value);
			tail = head;
		}
		else
		{
			tail->next = new ListNode<T>(value, tail);
			tail = tail->next;
		}
		size++;
	}

	template<typename T>
	inline void LinkedList<T>::insert(T value, int index)
	{
		if (index < 0 || index >= getSize())
		{
			insert(value);
			return;
		}

		ListNode<T>* node = find(index);
		ListNode<T>* insertable = new ListNode<T>(value, node->prev, node);

		if (node->prev == nullptr) head = insertable;
		else node->prev->next = insertable;

		node->prev = insertable;

		size++;
	}

	template<typename T>
	inline void LinkedList<T>::reverse()
	{
		ListNode<T>* current = tail;

		tail = head;
		head = current;

		while (current != nullptr)
		{
			ListNode<T>* prev = current->prev;

			current->prev = current->next;
			current->next = prev;

			current = prev;
		}
	}

	template<typename T>
	inline void LinkedList<T>::replace(int index, T value)
	{
		ListNode<T>* listNode = find(index);
		if (!listNode) return;

		listNode->value = value;
	}

	template<typename T>
	inline void LinkedList<T>::swap(ListNode<T>* x, ListNode<T>* y)
	{
		T tmp = x->value;
		x->value = y->value;
		y->value = tmp;
	}

	template<typename T>
	inline void LinkedList<T>::swap(int xIndex, int yIndex)
	{
		ListNode<T>* x = find(xIndex);
		ListNode<T>* y = find(yIndex);

		swap(x, y);
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
	inline int LinkedList<T>::removeDuplicates()
	{
		std::map<T, int> table;
		int removed = 0;

		for (int i = 0; i < getSize(); i++)
		{
			ListNode<T>* current = find(i);

			if (table.find(current->value) != table.end())
			{
				remove(i);
				i--;
				removed++;
				continue;
			}

			table[current->value] = 1;
		}

		return removed;
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