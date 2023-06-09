class Solution {
  private:
   pair<int,int> diameterFast(Node* root) {
        //base case
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int,int> ans;
        ans.first = max(op1, max(op2, op3));;
        ans.second = max(left.second , right.second) + 1;

        return ans;
    }
  int height(struct Node* node){
        // code here 
        if(node==NULL)
        {
            return 0;
        }
        int left=height(node->left);
       int  right=height(node->right);
        
        
        
        //int ans=levelordertraversal(node,count);
        int ans=max(left,right);
        ans=ans+1;
        
        return ans;
    }
  public:
  
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
       /* 
        if(root==NULL)
        {
            return 0;
        }
        int op1=diameter(root->left);
       int  op2=diameter(root->right);
       int combine= height(root->left)+height(root->right)+1;
       
        
        int ans = max(op1,max(op2,combine));
        return ans;*/
        
        return diameterFast(root).first;
        
        
    }
    
};
