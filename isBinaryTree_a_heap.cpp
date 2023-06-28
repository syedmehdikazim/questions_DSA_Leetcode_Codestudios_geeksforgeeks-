class Solution {
  private:
  
    void countnode(struct Node* root, int &count)
    {
        if(root==NULL)
        {
            return;
        }
        countnode(root->left,count);
        count++;
        countnode(root->right,count);
    }
    
    bool isCBT(struct Node* root, int i, int n)
    
    {
        if(root==NULL)
        {
            return true;
        }
        if(i>=n)
        {
            return false;
        }
        else
        {
            bool left=isCBT(root->left, 2*i+1, n);
            bool right= isCBT(root->right, 2*i+2,n);
            return (left&&right);
        }
    }
    
    bool ismaxorder(struct Node* root)
    {
        //leaf node
        if(root->left==NULL && root->right==NULL)
        {
            return true;
        }
        
        // only left node
        
        if(root->right==NULL)
        {
            return (root->data>root->left->data);
        }
        
        //both left ans right node
        
        else
        {
            bool left= ismaxorder(root->left);
            bool right= ismaxorder(root->right);
            
            return (left&&right&&root->data>root->left->data&&root->data>root->right->data);
        }
        
        
    }
  public:
    bool isHeap(struct Node* root) {
        
        int count=0;
        int index=0;
        countnode(root,count);
        
        
        
        if(isCBT(root,index,count) && ismaxorder(root))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
