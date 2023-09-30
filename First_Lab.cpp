
#include <iostream>		// ({[]})
// ([]}{)

using namespace std;

template<typename SomeType>
struct List
{
public:
	
	List();
	SomeType& return_tail();
	void add(SomeType data);
	int get_size() { return Size; };
	SomeType& operator[](int index);

private:

	template<typename SomeType>
	class Node
	{
	public:
		
		Node* NextAddress;
		SomeType data;

		Node(SomeType data = SomeType(), Node* NextAddress = nullptr, Node* PreviousAddress = nullptr)
		{
			this->data = data;
			this->NextAddress = NextAddress;
			
		}

	};
	
	Node<SomeType>* Head;
	int Size;
};

template<typename SomeType>
List<SomeType>::List()
{
	Size = 0;
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
		
		while (Current->NextAddress != nullptr)
		{
			
			Current = Current->NextAddress;
		}
		Current->NextAddress = new Node<SomeType>(data);
		
		
	}
	Size++;
}

template<typename SomeType>
SomeType& List<SomeType>::operator[](int index) 
{
	int counter = 0;
	Node<SomeType>* Current = this->Head;
	while (Current != nullptr) 
	{
		if (counter == index) 
		{
			return Current->data;
		}
		Current = Current->NextAddress;
		counter++;
	}
 };

int main()
{
	List<int> lst;
	lst.add(6);
	lst.add(7);
	lst.add(7);
	lst.add(8);
	lst.add(9);
	lst.add(10);
	lst.add(11);
	/*for (int i = 0; i < lst.get_size(); i++) 
	{
		cout << lst[i] << endl;
	}*/
	lst.return_tail();
}
