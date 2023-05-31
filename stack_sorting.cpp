void putinplace(stack<int>&s,int num)
{
	if((!s.empty() && s.top() < num)||s.empty())
	{
		s.push(num);
		return;
	}
	int k=s.top();
	s.pop();
	putinplace(s,num);
	s.push(k);
}
void sort(stack<int>& s)
{
	if(s.empty())
	{
		return;
	}
	int num = s.top();
	s.pop();
	sort(s);
	putinplace(s,num);
}
int main()
{
	stack<int>s;
	s.push(5);
	s.push(3);
	s.push(0);
	s.push(10);
	s.push(6);
	s.push(4);
	print(s);
	
	sort(s);
	
	print(s);
	
/*
	stack<string>str_stack;
	str_stack.push("a");
	str_stack.push("b");
	str_stack.push("c");
	str_stack.push("d");
	str_stack.push("e");
//	string st=str_stack.top();




//	cout<<st;
//	cout<<str_stack.top()[0];

/*	if(s.empty()==true)
	{
		cout<<"stack empty"<<endl;
	}
	else
	{
		cout<<"stack is not empty"<<endl;
	}
		printstr(str_stack);
	cout<<str_stack.top();
*/

}
