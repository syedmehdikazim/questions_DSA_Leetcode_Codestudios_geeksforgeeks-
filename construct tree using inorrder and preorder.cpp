class Solution{
    public:
    void createmap(int in[], map<int,int>&nodetoindex,int n)
    {
        for(int i=0;i<n;i++)
        {
            nodetoindex[in[i]]=i;
        }
    }
    /*int position(int element,int in[],int n)
    {
        for(int i=0;i<n;i++)
        {
            if(in[i]==element)
            {
                return i;
            }
        }
        return -1;
    }*/
    Node* solve(int in[],int pre[],int preorderindex,int inorderstart,int inorderend, int n,map<int,int>nodetoindex)
    {
        if(preorderindex>=n || inorderstart>inorderend)
        {
            return NULL;
        }
        int element=pre[preorderindex++];
        Node* root= new Node(element);
         
         
        int position=nodetoindex[element];
        //int pos= position(element,in,n);
         
        //Recursive calls
        
        root->left= solve(in,pre,preorderindex,inorderstart, position-1,n,nodetoindex);
        root->right=solve(in,pre,preorderindex,position+1,inorderend,n,nodetoindex);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderindex=0;
        map<int,int>nodetoindex;
        createmap(in,nodetoindex,n);
        Node* ans=solve(in,pre,preorderindex,0,n-1,n,nodetoindex);
        return ans;
    }
};
