
//SOLUTION 1
class Solution 
{
public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int candidate = 0;

        // Find a potential candidate using elimination.
        for (int i = 1; i < n; i++)
        {
            if (M[candidate][i] == 1)
            {
                candidate = i;
            }
        }

        // Verify if the candidate is a celebrity by checking rows.
        for (int i = 0; i < n; i++)
        {
            if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0))
            {
                return -1; // The candidate is not a celebrity.
            }
        }

        return candidate; // Return the celebrity's index.
    }
};

//SOLUTION 2 using stack

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b, int n) {
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        //step1: push all element in stack
        for(int i=0; i<n; i++) {
            s.push(i);
        }   
        
        //step2: get 2 elements and copare them
        
        while(s.size() > 1) {
            
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b,n)){
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        int ans = s.top();
        //step3: single element in stack is potential celeb
        //so verify it
        
        int zeroCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[ans][i] == 0)
                zeroCount++;
        }
        
        //all zeroes
        if(zeroCount != n)
            return -1;
        
        //column check
        int oneCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[i][ans] == 1)
                oneCount++;
        }
        
        if(oneCount != n-1)
            return -1;
        
        return ans;
        
    }
};
