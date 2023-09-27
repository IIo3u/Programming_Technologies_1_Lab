#include <iostream>		// ({[]})
						// ([]}{)

using namespace std;

template<typename SomeType> 
struct List 
{
public:

	List();
	void add(SomeType data);
	int get_size() { return NodeCounter; };

private:

	template<typename SomeType>
	class Node 
	{
	public:
		Node* NextAddress;
		SomeType data;

		Node(SomeType data = SomeType(), Node* NextP = nullptr)
		{
			this->data = data;
			this->NextAddress = NextP;
		}
	
	};

	Node<SomeType>* Head;
	int NodeCounter;
};

template<typename SomeType>
List<SomeType>::List()
{
	NodeCounter = 0;
	Head = nullptr;
};

template<typename SomeType>
void List<SomeType>::add(SomeType data) 
{
	if (Head == nullptr)
	{
		Head = new Node<SomeType>(data);
	}
	else
	{
		Node<SomeType>* Current = this->Head;
		while (Current -> NextAddress != nullptr) 
		{
			Current = Current->NextAddress;
		}
		Current->NextAddress = new Node<SomeType>(data);
	}
	NodeCounter++;
}



void main() 
{
	List<int> lst;
	lst.add(6);
	lst.add(7);
	cout << lst.get_size();
	
}