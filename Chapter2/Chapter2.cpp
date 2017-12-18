// Chapter 2 Solutions
// Linked List Chapter

// Linked List Implementation

#include <iostream>
#include <unordered_set>

struct Node
{
	int data;
	Node* next;
};

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

		Node* getStart()
		{
			return m_head;
		}
		
		// only use this if you know you are deleting at a valid index in the list
		void deleteAt(int index)
		{
			Node* iter = m_head;
			for (int i = 0; i < index - 1; i++)
			{
				iter = iter->next;
			}

			Node* toDelete = iter->next;
			iter->next = iter->next->next;
			delete toDelete;
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
		Node* m_head;
};

/*
	2.1 Remove Dups: Write code to remove duplicates from an unsorted linked list.
*/

void removeDups(LinkedList* someList)
{
	// put all numbers into unordered_set as we go, if it already exists, then remove it from the list

	Node* head = someList->getStart();
	
	std::unordered_set<int> repeats;
	std::unordered_set<int>::iterator iter;

	while (head->next != nullptr)
	{
		iter = repeats.find(head->next->data);
		if (iter == repeats.end())
		{
			repeats.insert(head->data);
		}
		else
		{
			// delete the node


		}
	}

}


int main()
{
	// test basic linked list

	LinkedList* myList = new LinkedList();
	myList->insert(5);
	myList->insert(7);
	myList->insert(3);
	myList->insert(4);
	myList->insert(7);

	myList->deleteAt(2);

	myList->print();

	return 0;
}