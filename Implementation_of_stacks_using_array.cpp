#include<iostream>
#include<stack>
using namespace std;
class Stack
{
	public:
		int *arr;
		int top;
		int size;
		
	Stack(int size)
	{
		this->size=size;
		arr= new int[size];
		top=-1;
	}
	
	void push(int s)
	{
		if(size-top>1)
		{
			top++;
			arr[top]=s;
		}
		else
		{
			cout<<"stackoverflow"<<endl;
		}
		return;
	}
	void pop()
	{
		if(top>=0)
		{
			top--;
		}
		else
		{
			cout<<"stackunderflow"<<endl;
		}
		return;
	}
	int topelement()
	{
		if(top>=0)
		{
			return arr[top];
		}
		else
		{
			cout<<"stack is empty"<<endl;
			return -1;
		}
		
	}
	bool isempty()
	{
		if(top==-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
void print(Stack s)
{
	
	if(s.isempty()==true)
	{
		return;
	}
	int num=s.topelement();
	cout<<num<<" ";
	s.pop();
	print(s);
	s.push(num);
}
int main()
{
	Stack s(6);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	print(s);
	
}
