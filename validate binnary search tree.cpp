bool validatetree(BinaryTreeNode<int>* root,int min,int max)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data>min && root->data<max)
    {
        bool left=validatetree(root->left,min,root->data);
        bool right=validatetree(root->right,root->data,max);
       return left&&right;
    }
    else
    {
        return false;
    }
}
bool validateBST(BinaryTreeNode<int>* root) 
{
    int mini=INT_MIN;
    int maxi=INT_MAX;
    return validatetree(root,mini,maxi);
}
