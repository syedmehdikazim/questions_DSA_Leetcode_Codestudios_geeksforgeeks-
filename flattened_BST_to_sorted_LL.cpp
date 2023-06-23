void solve(vector<int>&arr,TreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    solve(arr,root->left);
    arr.push_back(root->data);
    solve(arr,root->right);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int>arr;
    solve(arr,root);

    TreeNode<int>*newroot= new TreeNode<int>(arr[0]);
    TreeNode<int>*curr=newroot;

    for(int i=1; i<arr.size();i++)
    {
        TreeNode<int>*temp= new TreeNode<int>(arr[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }
    curr->left=NULL;
    curr->right=NULL;

    return newroot;


}
