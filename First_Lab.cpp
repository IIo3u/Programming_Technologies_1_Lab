
#include <iostream>		// ({[]})
// ([]}{)

using namespace std;

template<typename SomeType>
struct List
{
private:
	template<typename SomeType>
	class Node
	{
	public:
		Node* PreviousAddress;
		Node* NextAddress;
		SomeType data;

		Node(SomeType data = SomeType())
		{
			this->data = data;
			this->NextAddress = this->PreviousAddress = nullptr;
		}
	};

	void add_first(SomeType data);

	Node<SomeType>* Head;
	Node<SomeType>* Tail;
	int Size;

public:
	List();
	void pop_element(int index);
	void pop_element(Node<SomeType>* data);
	void pop_low();
	void pop_top();
	void append(SomeType data);
	void add_front(SomeType data);
	SomeType& get_low();
	SomeType& get_top();
	int get_size() { return Size; };
	SomeType& operator[](int index);
	List<SomeType>& Copy(List<SomeType> List);

};

template<typename SomeType>
List<SomeType>::List()
{
	Size = 0;
	Head = Tail = nullptr;

};

template<typename SomeType>
void List<SomeType>::add_first(SomeType data)
{
	Tail = new Node<SomeType>(data);
	Head = Tail;
}

template<typename SomeType>
void List<SomeType>::append(SomeType data)
{
	if (data != NULL)
	{
		if (this->Tail == nullptr)
		{
			this->add_first(data);
		}
		else
		{
			Node<SomeType>* Previous;
			Node<SomeType>* Current = this->Tail;
			Current->NextAddress = new Node<SomeType>(data);
			Previous = Current;
			Current = Current->NextAddress;
			Current->PreviousAddress = Previous;
			this->Tail = Current;
		}
		Size++;
	}
	else
	{
		cout << "Enter a valid data!" << endl;
	}
}

template<typename SomeType>
void List<SomeType>::add_front(SomeType data)
{
	if (data != NULL)
	{
		if (Head == nullptr)
		{
			this->add_first(data);
		}
		else
		{
			Node<SomeType>* Next;
			Node<SomeType>* Current = this->Head;
			Current->PreviousAddress = new Node<SomeType>(data);
			Next = Current;
			Current = Current->PreviousAddress;
			Current->NextAddress = Next;
			this->Head = Current;
		}
		Size++;
	}
	else
	{
		cout << "Enter a valid data!" << endl;
	}
}

template<typename SomeType>
SomeType& List<SomeType>::get_low()
{
	return this->Tail->data;
};

template<typename SomeType>
SomeType& List<SomeType>::get_top()
{
	return this->Head->data;
};

template<typename SomeType>
void List<SomeType>::pop_element(int index)
{
	if (this->get_size() == 0)
	{
		cout << "This list has no elements!\n";
		return;
	}
	if (this->get_size() == 1)
	{
		delete this->Head;
		this->Size--;
		return;
	}

	int counter = 0;
	Node<SomeType>* Previous = nullptr;
	Node<SomeType>* Current = Head;
	Node<SomeType>* Next = nullptr;
	while (counter != index)
	{
		Current = Current->NextAddress;
		counter++;
	}
	Previous = Current->PreviousAddress;
	Next = Current->NextAddress;
	if (Previous != nullptr)
	{
		Previous->NextAddress = Next;
	}

	if (Next != nullptr)
	{
		Next->PreviousAddress = Previous;
	}
	delete Current;
	Size--;
}

template<typename SomeType>
void List<SomeType>::pop_element(Node<SomeType>* Data)
{
	if (this->get_size() == 0)
	{
		cout << "This list has no elements!\n";
		return;

		if (this->get_size() == 1)
		{
			delete this->Head;
			this->Size--;
			return;
		}
	}
	Node<SomeType>* Previous = nullptr;
	Node<SomeType>* Current = Data;
	Node<SomeType>* Next = nullptr;
	Previous = Current->PreviousAddress;
	Next = Current->NextAddress;
	if (Previous != nullptr)
	{
		Previous->NextAddress = Next;
	}

	if (Next != nullptr)
	{
		Next->PreviousAddress = Previous;
	};
	delete Current;
	Size--;
}

template<typename SomeType>
void List<SomeType>::pop_top()
{
	if (this->get_size() == 0)
	{
		cout << "This list has no elements!\n";
		return;
	}
	if (this->get_size() == 1)
	{
		delete this->Head;
		this->Size--;
		return;
	}
	Node<SomeType>* Current = Head;
	Current = Current->NextAddress;
	this->Head = Current;
	delete Current->PreviousAddress;
	Current->PreviousAddress = nullptr;
	this->Size--;
};

template<typename SomeType>
void List<SomeType>::pop_low()
{
	if (this->get_size() == 0)
	{
		cout << "This list has no elements!\n";
		return;
	}
	if (this->get_size() == 1)
	{
		delete this->Tail;
		this->Size--;
		return;

	}
	Node<SomeType>* Current = Tail;
	Current = Current->PreviousAddress;
	this->Tail = Current;
	delete Current->NextAddress;
	Current->NextAddress = nullptr;
	this->Size--;
};

template<typename SomeType>
List<SomeType>& Copy(List<SomeType>* OldList)
{
	List<SomeType>* NewList = new List<SomeType>;
	for (int i = 0; i < OldList.get_size(); i++)
	{
		NewList->append(OldList.get_low());
	}
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

template<typename SomeType>
bool DefineSequence(List<SomeType> Sequence)
{
	List<SomeType>* Stack = new List<SomeType>;
	char buffer;
	for (int i = 0; i < Sequence.get_size(); i++)
	{
		if ((Sequence[i] == '(') || (Sequence[i] == '{') || (Sequence[i] == '['))
		{
			Stack->append(Sequence[i]);
		}
		else
		{
			if (Stack->get_size() == 0)
			{
				return false;
			}
			buffer = Stack->get_low();
			Stack->pop_low();

			if ((buffer == '(') && (Sequence[i] != ')') || (buffer == '{') && (Sequence[i] != '}') || (buffer == '[') && (Sequence[i] != ']'))
			{
				return false;
			}
		}
	}
	return (Stack->get_size() == 0);

}


int main()
{
	List<char> firstStroke;
	cout << "Enter a bracket sequence: ";

	char buffer;
	while (cin.get(buffer))
	{
		if (buffer != '\n')
		{
			firstStroke.append(buffer);
		}
		else
		{
			break;
		}
	}

	cout << "Your stroke: ";

	for (int i = 0; i < firstStroke.get_size(); i++)
	{

		cout << firstStroke[i];

	}
	cout << endl;

	if (DefineSequence(firstStroke) == true)
	{
		cout << "This stroke is a valid algebraic expression" << endl;
	}
	else
	{
		cout << "This stroke isn't a valid algebraic expression" << endl;
	}




}

