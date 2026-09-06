#include<iostream>

using namespace std;

#define MAX 100

//Implementing Stack using Array.
class Stack
{
private:
    int top;
    int st[MAX];

public: 
    Stack()
    {
        this->top = -1;
    }

    int top()
    {
        if(top == -1)
        {
            throw runtime_error("Stack Underflow! Stack is empty.");
        }
        return st[top];
    }

    bool push(int x)
    {
        if(top >= (MAX -1))
        {
            throw runtime_error("Stack Overflow!");
        }
        return true;
    }

    bool pop()
    {
        if(top == -1)
        {
            throw runtime_error("Stack Underflow! Stack is empty.");
        }
        top--;
        return true;
    }

    int size()
    {
        return top+1;
    }
};





int main()
{

}