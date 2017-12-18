// Chapter 2 Solutions
// Linked List Chapter

// Linked List Implementation

#include <iostream>

class LinkedList
{
	public:
		LinkedList()
		{
			m_head = nullptr;
		}

		~LinkedList()
		{
			Node* iter = m_head;
			while (iter != nullptr)
			{
				Node* toDelete = iter;
				iter = iter->next;
				delete toDelete;
			}
		}

		void insert(int value)
		{
			Node* toInsert = new Node;
			toInsert->data = value;
			toInsert->next = nullptr;

			// if there are no nodes yet
			if (m_head == nullptr)
			{
				m_head = toInsert;
				return;
			}

			// if we already have some nodes
			Node* iter = m_head;
			while (iter->next != nullptr)
			{
				iter = iter->next;
			}
			iter->next = toInsert;
			return;
		}

		void print()
		{
			Node* iter = m_head;
			while (iter != nullptr)
			{
				std::cout << iter->data << std::endl;
				iter = iter->next;
			}
		}

	private:
		struct Node
		{
			int data;
			Node* next;
		};
		Node* m_head;
};

/*
	2.1 Remove Dups: Write code to remove duplicates from an unsorted linked list.
*/

void removeDups()
{
	
}


int main()
{
	// test basic linked list

	LinkedList* myList = new LinkedList();
	myList->insert(5);
	myList->insert(7);
	myList->print();

	return 0;
}