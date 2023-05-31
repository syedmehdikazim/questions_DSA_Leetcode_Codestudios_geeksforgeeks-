bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(' || s[i]=='+'|| s[i]=='-'|| s[i]=='*' || s[i]=='/')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            bool hasOperand = false;
            while (!st.empty() && st.top() != '(') {
                hasOperand = true;
                st.pop();
            }
            if (!hasOperand) {
                return true; // Redundant brackets found
            }
            if (!st.empty()) {
                st.pop(); // Pop the opening bracket
            }
        }
    }
    if(st.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
}
