#ifndef __TLIST_H__
#define __TLIST_H__

#include<iostream>
#include<cstdlib>
#include<iterator>
#include <string>

const int MAXSIZE = 1000;

template <class T>
class TList
{
	template <class T>
	struct link
	{
		T data;
		link *pNext;
		link(T _data = {}, link *_pNext = nullptr)
		{
			data = _data;
			pNext = _pNext;
		}
	};
	link<T> *pFirst;//– указатель на первое звено списка;
	link<T> *pLast; //указатель на последнее звено списка;
	link<T>*pCurrLink; //– указатель на текущее звено списка;
	link<T>*pPrevLink; //– указатель на звено, предшествующее текущему;
	int CurrPos; //– номер текущего звена;
	int ListLen; //-количество звеньев в списке;

public:
	class iterator
	{
	private:
		link<T> *pointer;
	public:
		iterator()
		{
			pointer = new link<T>;
		}
		iterator(const iterator &it)
		{
			pointer = it.pointer;
		}
		iterator& operator=(const iterator &tmp)
		{
			pointer = tmp.pointer;
			return *this;
		}
		link<T>* operator->() const
		{
			return pointer;
		}
		bool operator == (const iterator &it) const
		{
			if (pointer == it.pointer)
				return true;
			else return false;
		}
		bool operator != (const iterator &it) const
		{
			return !(*this == it);
		}
		T operator*()const
		{
			if (pointer == nullptr)
				throw("nullptr");
			return pointer->data;
		}

		iterator& operator ++()
		{
			this->pointer = this->pointer->pNext;
			return *this;
		}
		iterator& operator++(int) { iterator itr = *this; pointer = pointer->pNext; return itr; }
		friend class TList;
	};
	TList()
	{
		pFirst = nullptr;
		pCurrLink = nullptr;
		ListLen = 0;
	}
	TList(const TList<T> &l)
	{
		this->pFirst = nullptr;
		this->ListLen = 0;
		link<T>*count = l.pFirst;
		while (count != nullptr)
		{
			this->Push(count->data);
			count = count->pNext;
		}
	}

	~TList()
	{
		Clear();
	}

	TList<T>& operator = (const TList<T> & l)
	{
		link<T>*count = l.pFirst;
		if (!this->Empty())
			this->Clear();
		while (count != nullptr)
		{
			this->Push(count->data);
			count = count->pNext;
		}
		return *this;
	}

	bool operator==(const TList &lst)const
	{
		if (this->ListLen != lst.ListLen)
			return false;
		else
		{
			link<T>left = this->pFirst;
			link<T>right = lst.pFirst;
			while (right != nullptr)
			{
				if (left->data != right->data)
					return false;
				left = left->pNext;
				right = right->pNext;
			}
			return true;
		}
	}

	bool operator!=(const TList &lst)const
	{
		return !(*this == lst);
	}

	void Clear()
	{
		while (ListLen != 0)
			Pop();
	}

	bool Empty()
	{
		return pFirst == nullptr;
	}

	T Pop()
	{
		T d = pFirst->data;
		link<T> *p = pFirst;
		pFirst = pFirst->pNext;
		delete p;
		ListLen--;
		return d;
	}

	void Push(T d)
	{
		if (Empty())
		{
			pFirst = new link<T>(d);
			pCurrLink = pFirst;
			ListLen++;
		}
		else
		{
			if (ListLen == MAXSIZE)
				throw "Error, Maxsize.";
			link<T> *tmp = new link<T>(d);
			link<T> *tmp2;
			tmp2 = pCurrLink->pNext;
			pCurrLink->pNext = tmp;
			tmp->pNext = tmp2;
			pCurrLink = pCurrLink->pNext;
			ListLen++;
		}
	}

	int GetSize()
	{
		return ListLen;
	}

	iterator Begin()
	{
		iterator it;
		it.pointer = pFirst;
		return it;
	}

	iterator End()
	{
		iterator it;
		if (Empty())
		{
			it.pointer = pFirst;
			return it;
		}
		it.pointer = pCurrLink->pNext;
		return it;
	}

	void Insert(iterator it, T val)
	{
		link<T> *count = pFirst;
		link <T> *prev;
		link<T> *insert = new link<T>(val);
		int pos = 0;
		while (count != it.pointer)
		{
			prev = count;
			count = count->pNext;
			pos++;
		}
		if (pos == 0)
		{
			link<T> *tmp = pFirst;
			insert->pNext = tmp;
			pFirst = insert;
			ListLen++;
		}
		else
		{
			insert->pNext = count;
			prev->pNext = insert;
			ListLen++;
		}
	}
	void Erase(iterator it)
	{
		link<T> *count = pFirst;
		link<T> *prev;
		int pos = 0;
		while (count != it.pointer)
		{
			prev = count;
			count = count->pNext;
			pos++;
		}
		if (pos == 0)
		{
			link<T> *tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
			ListLen--;
		}
		else
		{
			prev->pNext = count->pNext;
			delete count;
			ListLen--;
		}
	}
	friend class iterator;
};
#endif
