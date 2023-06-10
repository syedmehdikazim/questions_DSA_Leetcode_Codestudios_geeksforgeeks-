class Solution{
    
    
  public:
  
    void solve(Node *root,int k, int &count, vector<int>arr)
    {
        
        if(root == NULL)
            return ;
        
        arr.push_back(root->data);
        
        //left
        solve(root->left, k, count, arr);
        //right
        solve(root->right, k, count, arr);
        
        //check for K Sum
        
        int size = arr.size();
        int sum = 0;
        for(int i = size-1; i>=0; i--)  {
            sum += arr[i];
            if(sum == k)
                count++;
        }
        
        arr.pop_back();
    }
    int sumK(Node *root,int k)
    {
        vector<int> arr;
        int count = 0;
        solve(root, k, count, arr);
        return count;
    
       
        
    }
};
