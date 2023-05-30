void insertatbottom(stack<int> &stack,int num)
{
    if(stack.empty())
    {
        stack.push(num);
        return;
    }
    int k=stack.top();
    stack.pop();
    insertatbottom(stack,num);
    stack.push(k);
}
void solve(stack<int> &stack)
{
    

    if(stack.empty())
    {
       return;
    }
    int num=stack.top();
    stack.pop();
    solve(stack);
    insertatbottom(stack,num);
   
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    solve(stack);
}
