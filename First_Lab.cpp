
#include <iostream>

using namespace std;
template<typename SomeType>
class List
{
private:
	template<typename SomeType>
	class Node
	{
	public:						// Если выложить все ячейки по адресам слева на право, то:
		Node* PreviousAddress;  // Это ссылка влево (т.е. ведёт в начало списка)
		Node* NextAddress;		// Это ссылка вправо (т.е. ведёт в конец списка)
		SomeType data;

		Node(SomeType data = SomeType())
		{
			this->data = data;
			this->NextAddress = this->PreviousAddress = nullptr;
		}
	};


	Node<SomeType>* Head;	// Начало
	Node<SomeType>* Tail; // Конец
	int Size;
	void add_first(SomeType data);	// Инициализирует добавление первого элемента

public:

	List();

	void add_on_pos_right(int index, SomeType data); // Добавляет значение справа
	void add_on_pos_left(int index, SomeType data);	 // Добавляет значение слева
	void append(SomeType data);						 // Добавляет значение правее последнего элемента (в конец списка)
	void add_front(SomeType data);					 // Добавляет значение левее первого элемента (в начало списка)
	void pop_element(int index);					 // Удаляет элемент по нужному адресу
	void pop_top();									 // Удаляет Начальный (Head) элемент списка
	void pop_low();									 // Удаляет Конечный (Tail) элемент списка
	SomeType& get_low();							 // Передаёт ссылку на поле data Конечного элемента
	SomeType& get_top();							 // Передаёт ссылку на поле data Начального элемента
	int get_size() { return Size; };				 // Возвращает размер списка
	SomeType& operator[](int index);				 // Оператор индексирования для обращения к полю data нужных элементов


};

template<typename SomeType>
void List<SomeType>::add_first(SomeType data)
{
	Tail = new Node<SomeType>(data);
	Head = Tail;
	this->Size++;
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
List<SomeType>::List()
{
	Size = 0;
	Head = Tail = nullptr;

};

template<typename SomeType>
void List<SomeType>::add_on_pos_right(int index, SomeType data)
{
	if (this->get_size() == 0)
	{
		this->add_first(data);
	}
	else
	{
		if (index == this->Size - 1)
		{
			this->append(data);
		}
		else
		{
			int counter = 0;
			Node<SomeType>* NewNode = new Node<SomeType>(data);
			Node<SomeType>* Current = this->Head;
			while (index != counter)
			{
				Current = Current->NextAddress;
				counter++;
			}
			Node<SomeType>* Previous = Current;
			Node<SomeType>* Next = Current->NextAddress;
			Current = NewNode;
			Previous->NextAddress = Current;
			Current->NextAddress = Next;
			Next->PreviousAddress = Current;
			Current->PreviousAddress = Previous;
			this->Size++;
		}
	}
}

template<typename SomeType>
void List<SomeType>::add_on_pos_left(int index, SomeType data)
{
	if (this->get_size() == 0)
	{
		this->add_first(data);
	}
	else
	{
		if (index == 0)
		{
			this->add_front(data);
		}
		else
		{
			int counter = 0;
			Node<SomeType>* NewNode = new Node<SomeType>(data);
			Node<SomeType>* Current = this->Head;
			while (index != counter)
			{
				Current = Current->NextAddress;
				counter++;
			}
			Node<SomeType>* Next = Current;
			Node<SomeType>* Previous = Current->PreviousAddress;
			Current = NewNode;
			Next->PreviousAddress = Current;
			Current->PreviousAddress = Previous;
			Previous->NextAddress = Current;
			Current->NextAddress = Next;
			this->Size++;
		}
	}
}

template<typename SomeType>
void List<SomeType>::append(SomeType data)
{
	if (this->Tail == nullptr)
	{
		this->add_first(data);
		return;
	}
	else
	{
		this->Tail->NextAddress = new Node<SomeType>(data);
		Node<SomeType>* Buffer = this->Tail;
		this->Tail = this->Tail->NextAddress;
		this->Tail->PreviousAddress = Buffer;
		Size++;
	}

}

template<typename SomeType>
void List<SomeType>::add_front(SomeType data)
{
	if (Head == nullptr)
	{
		this->add_first(data);
		return;
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
		Size++;
	}

}

template<typename SomeType>
void List<SomeType>::pop_element(int index)
{

	if (this->get_size() == 0)
	{
		return;
	}
	if (this->get_size() == 1)
	{
		delete this->Head;
		this->Size--;
		return;
	}
	if (index == this->Size - 1)
	{
		Node<SomeType>* Current = Tail;
		Current = Current->PreviousAddress;
		this->Tail = Current;
		delete Current->NextAddress;
		Current->NextAddress = nullptr;
		this->Size--;
		return;
	}
	if (index == 0)
	{
		Node<SomeType>* Current = Head;
		Current = Current->NextAddress;
		this->Head = Current;
		delete Current->PreviousAddress;
		Current->PreviousAddress = nullptr;
		this->Size--;
		return;
	}
	else
	{
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
		this->Size--;
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
SomeType& List<SomeType>::operator[](int index)
{
	if (index == 0)
	{
		return this->Head->data;

	}
	else
	{
		if (index == this->Size - 1)
		{
			return this->Tail->data;
		}
		else
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
		}

	}
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

	if ((DefineSequence(firstStroke) == true) && firstStroke.get_size() != 0)
	{
		cout << "True expression" << endl;
	}
	else
	{
		cout << "False expression" << endl;
	}




}

