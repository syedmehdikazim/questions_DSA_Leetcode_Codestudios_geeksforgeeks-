void solve(vector<int>&arr,BinaryTreeNode<int>* root, int target)
{
    if(root==NULL)
    {
        return;
    }
    solve(arr,root->left,target);
    arr.push_back(root->data);
    solve(arr,root->right,target);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int>arr;
    solve(arr,root,target);

    int i=0;
    int j=arr.size()-1;
    
    while (i < j) { // Use i < j instead of i <= j
        if (arr[i] + arr[j] > target) {
            j--;
        } else if (arr[i] + arr[j] < target) { // Use else if instead of multiple if statements
            i++;
        } else {
            return true;
        }
    }
    return false;
}
