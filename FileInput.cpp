#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


#define SIZE 10

template<typename SomeType>
class Stack
{
private:
    SomeType* Array;
    int TopElement;
    int Size;
    bool isEmpty();
    bool isFull();
public:
    Stack(int size = SIZE);
    ~Stack();

    void push(SomeType);
    SomeType get_top();
    int size();
   
};

template<typename SomeType>
Stack<SomeType>::Stack(int size)
{
    if (size != 0)
    {
        Array = new SomeType[size];
        Size = size;
        TopElement = -1;
        
    }
    else
    {
        cout << "Exeption";
    }
    
}

template<typename SomeType>
Stack<SomeType>::~Stack() {
    delete[] Array;
}

template<typename SomeType>
void Stack<SomeType>::push(SomeType data)
{
    if (isFull())
    {
        "Exeption";
        
    }

    Array[++TopElement] = data;
}



template<typename SomeType> 
SomeType Stack<SomeType>::get_top()
{
    if (!isEmpty()) {
        return Array[TopElement--];
    }
    else {
        cout << "Exeption";
    }
}

template<typename SomeType>
int Stack<SomeType>::size() 
{
    return TopElement + 1;
}

template<typename SomeType>
bool Stack<SomeType>::isEmpty() 
{
    return TopElement == -1;
}

template<typename SomeType>
bool Stack<SomeType>::isFull() 
{
    return TopElement == Size - 1;
}


int main()
{
    int size = 0;
    cin >> size;

    if (size == 0) 
    {
        cout << "Exeption";
        return 0;
    }
    
    string stroke;  
    cin >> stroke;

    if (size == 0)
    {
        cout << "Exeption";
        return 0;
    }
    
    Stack<char>* newStack = new Stack<char>[size];
    
    int res;

    for (int i = 0; i < size; i++)
    {
        if ((stroke[i] == '(') || (stroke[i] == '{') || (stroke[i] == '['))
        {
            newStack->push(stroke[i]);
        }
        else
        {
            if (newStack->size() == 0)
            {
                res = 0;
                break;
            }
            char buffer = newStack->get_top();
            if (((buffer == '(') && (stroke[i] == ')') || (buffer == '{' && stroke[i] != '}') || (buffer == '[' && stroke[i] != ']')))
            {
                res = 0;    
            }
            
            
        }
        
    }
    if (newStack->size() == 0)
    {
        res = 1;
    }
    else
    {
        res = 0;
    }
    cout << "Res = " << res << endl;
}