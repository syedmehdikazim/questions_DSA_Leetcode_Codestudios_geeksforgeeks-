void solve(vector<int>& arr, TreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    solve(arr, root->left);
    arr.push_back(root->data);
    solve(arr, root->right);
}

TreeNode<int>* make_balance(vector<int>& arr, int s, int e) {
    if (s > e) {
        return NULL;
    }

    int mid = (s + e) / 2;
    TreeNode<int>* temp = new TreeNode<int>(arr[mid]);
    temp->left = make_balance(arr, s, mid - 1);
    temp->right = make_balance(arr, mid + 1, e);
    return temp;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> arr;
    solve(arr, root);
    int s = 0;
    int e = arr.size() - 1;
    int mid = (s + e) / 2;
    TreeNode<int>* newt = make_balance(arr, s, e);
    return newt;
}
