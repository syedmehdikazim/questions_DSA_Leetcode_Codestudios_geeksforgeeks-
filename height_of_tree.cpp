//RECUSION METHOD
class Solution{
    public:
    //Function to find the height of a binary tree.
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
};

//Using LEVEL ORDER TRAVERSAL

int levelordertraversal(struct Node* node, int count)
{
    queue<Node*>q;
    q.push(node);
    q.push(NULL);
    
    while(!q.empty())
    {
        Node*temp=q.front();
        q.pop();
        
        if(temp==NULL)
        {
            count++;
            if(!q.empty()) { 
                
                q.push(NULL);
            }  
        }
        else
        {
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return count;
}
