// List342.h
// Contains the definitions and declarations for the List342 class. Due to the
// use of the Node struct in function declarations, the private contents were
// declared before the public contents.
#ifndef LIST342_H
#define LIST342_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int NAUGHT = 0;

template <class T>
class List342 
{
		template <class T>
		friend ostream& operator<<(ostream &sout, const List342<T> &that);

	private:
		template <class T>
		struct Node
		{
			Node<T>() : data(nullptr), next(nullptr) {}
			Node<T>(T *theData, Node<T> *nextNode) : data(theData), next(nextNode) {}
			T *data;
			Node<T> *next;
		};
		Node<T>* head;
		int listCount;

	public:
		List342<T>();
		List342<T>(T *data);
		List342<T>(string filename);
		List342<T>(List342<T> const &list);
		virtual ~List342<T>();

		int getListCount();
		void setListCount(int count);

		bool BuildList(string filename);
		bool Insert(T *obj);
		void Insert(Node<T> *node);
		bool Remove(const T target, T &result); 
		bool Peek(const T target, T &result);
		bool Merge(List342<T> &list1, List342<T> &list2);
		bool isEmpty();
		void ClearList();

		void operator=(const List342<T> &that);
		List342<T> operator+(const List342<T> &that) const;
		List342<T>& operator+=(const List342<T> &that);
		bool operator==(const List342<T> &that) const;
		bool operator!=(const List342<T> &that) const;	
};


template <class T>
List342<T>::List342() : head(nullptr), listCount(NAUGHT) 
{
}


template <class T>
List342<T>::List342(T *data) : head(nullptr), listCount(NAUGHT) 
{
	Insert(data);
}


template <class T>
List342<T>::List342(string filename) : head(nullptr), listCount(NAUGHT) 
{
	BuildList(filename);
}


template <class T>
List342<T>::List342(List342<T> const &list) 
{
	if(list.head != nullptr) 
	{
		listCount = list.listCount;
		head = new Node<T>(list.head->data, nullptr);
		Node<T> *to = head;
		Node<T> *from = list.head->next;
		while(from != nullptr) 
		{
			Node<T> *newNode = new Node<T>(from->data, nullptr);
			to->next = newNode;
			to = to->next;
			from = from->next;
		}
	}
}


template <class T>
List342<T>::~List342() 
{
	ClearList();
}


template <class T>
int List342<T>::getListCount() 
{
	return(listCount);
}


template <class T>
void List342<T>::setListCount(int count) 
{
	listCount = count;
}


template <class T>
bool List342<T>::BuildList(string filename) 
{
	ifstream inFile;
	inFile.open(filename);
	while(inFile.good()) 
	{
		T val;
		T *valPtr;
		inFile >> val;
		valPtr = new T(val);
		Insert(valPtr);
	}
	inFile.close();
	return(true);
}


template <class T>
bool List342<T>::Insert(T *obj) 
{
	Node<T> *newNode = new Node<T>(obj, nullptr);
	if(head == nullptr) 
	{
		head = newNode;
		listCount++;
		return(true);
	} 

	if(*obj <= *head->data) 
	{
		newNode->next = head;
		head = newNode;
		listCount++;
		return(true);
	}

	Node<T>* temp = head;
	while((temp->next != nullptr) && (*temp->next->data < *obj)) 
	{
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	listCount++;
	return(true);
}


template <class T>
void List342<T>::Insert(Node<T>* node) 
{
	if(head == nullptr) 
	{
		head = node;
		listCount++;
		return;
	} 

	if(*node->data <= *head->data) 
	{
		node->next = head;
		head = node;
		listCount++;
		return;
	}

	Node<T>* temp = head;
	while((temp->next != nullptr) && (*temp->next->data < *node->data)) 
	{
		temp = temp->next;
	}
	node->next = temp->next;
	temp->next = node;
	listCount++;
	return;
}


template <class T>
bool List342<T>::Remove(const T target, T &result) 
{
	if(isEmpty()) 
	{
		return(false);
	}

	if(*head->data == target) 
	{
		Node<T> *delNode = head;
		head = head->next;
		result = *delNode->data;
		listCount--;
		delete delNode;
		return(true);
	}

	Node<T>* temp = head;
	while(temp->next != nullptr) 
	{
		if(*temp->next->data == target) 
		{
			Node<T> *delNode = temp->next;
			temp->next = temp->next->next;
			result = *delNode->data;
			listCount--;
			delete delNode;
			return(true);
		}
		temp = temp->next;
	}
	return(false);
}


template <class T>
bool List342<T>::Peek(const T target, T &result) 
{
	if(isEmpty()) 
	{
		return(false);
	}

	if(*head->data == target) 
	{
		result = *head->data;
		return(true);
	}

	Node<T> *temp = head;
	while(temp->next != nullptr) 
	{
		if(*temp->next->data == target) 
		{
			result = *temp->next->data;
			return(true);
		}
		temp = temp->next;
	}
	return(false);
}


template <class T>
bool List342<T>::Merge(List342<T> &list1, List342<T> &list2) 
{
	if(this == &list1 && this == &list2) 
	{
		return(true);
	}

	if(&list1 != &list2 && this != &list1) 
	{
		if(!list1.isEmpty()) 
		{
			while(list1.head != nullptr) 
			{
				Node<T> *temp = list1.head->next;
				list1.head->next = nullptr;
				Insert(list1.head);
				list1.head = temp;
				list1.listCount--;
			}
		}
	}

	if(!list2.isEmpty() && this != &list2) 
	{
		while(list2.head != nullptr) 
		{
			Node<T> *temp = list2.head->next;
			list2.head->next = nullptr;
			Insert(list2.head);
			list2.head = temp;
			list2.listCount--;
		}
	}
	return(true);
}


template <class T>
bool List342<T>::isEmpty() 
{
	if(head == nullptr || listCount == NAUGHT) 
	{
		return(true);
	}
	return(false);
}


template <class T>
void List342<T>::ClearList() 
{
	if(!isEmpty()) 
	{
		while(head != nullptr) 
		{
			Node<T> *temp = head;
			head = temp->next;
			delete temp;
		}
		listCount = NAUGHT;
		head = nullptr;
	}
}


template <class T>
void List342<T>::operator=(const List342<T> &that) 
{
	if(this != &that || that.head != nullptr) 
	{
		ClearList();
		listCount = that.listCount;
		head = new Node<T>(that.head->data, nullptr);
		Node<T> *to = head;
		Node<T> *from = that.head->next;
		while(from != nullptr) 
		{
			Node<T> *newNode = new Node<T>(from->data, nullptr);
			to->next = newNode;
			to = to->next;
			from = from->next;
		}
	}
}


template <class T>
List342<T> List342<T>::operator+(const List342<T> &that) const 
{
	List342<T> temp = *this;
	if(that.head != nullptr) 
	{
		Node<T> *toInsert = that.head;
		while(toInsert != nullptr) 
		{
			T* val = toInsert->data;
			temp.Insert(val);
			toInsert = toInsert->next;
		}
	}
	return(temp);
}


template <class T>
List342<T>& List342<T>::operator+=(const List342<T> &that) 
{
	*this = *this + that;
	return(*this);
}


template <class T>
bool List342<T>::operator==(const List342<T> &that) const 
{
	if(this == &that) 
	{
		return(true);
	}

	if(that.head != nullptr && head != nullptr) 
	{
		Node<T> *thisTracker = head;
		Node<T> *thatTracker = that.head;
		while(thisTracker != nullptr && thatTracker != nullptr) 
		{
			if(*thisTracker->data != *thatTracker->data) 
			{
				return(false);
			}
			thisTracker = thisTracker->next;
			thatTracker = thatTracker->next;
		}
		return(true);
	}
	return(false);
}


template <class T>
bool List342<T>::operator!=(const List342<T> &that) const 
{
	if(!(*this == that)) 
	{
		return(true);
	}
	return(false);
}


template <class T>
ostream& operator<<(ostream &sout, const List342<T> &that) 
{
	if(that.head == nullptr) 
	{
		sout << "empty";
	} 
	else 
	{
		List342<T>::Node<T> *temp = that.head;
		while(temp != nullptr) 
		{ 
			sout << *temp->data;
			temp = temp->next;
		}
	}
	return(sout);
}

#endif