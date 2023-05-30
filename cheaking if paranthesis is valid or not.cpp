#include<stack>
bool isValidParenthesis(string expression)
{
    stack<char>s;
    int i=0;
    while(i<expression.length())
    {
        if(expression[i]=='(' || expression[i]=='{' || expression[i]=='[')
        {
            s.push(expression[i]);
        }
        else
        {
           if(!s.empty())
           {
                if((expression[i]==')'&&s.top()=='(') || (expression[i]=='}'&&s.top()=='{') || (expression[i]==']'&&s.top()=='['))
                {
                    s.pop();
                }

                //This else suggest that we have a parathesis in stack but the next paranthesis is not a match for it eg({))
                else
                {
                    return false;
                }
                
           }
           else
           {
               return false;
           }
        }
        i++;
    }
    if(s.empty())
    {
        //cout<<"Balanced";
        return true;
        
    }
    else
    {
        //cout<<"Not Balanced";
        return false;
    }
}
