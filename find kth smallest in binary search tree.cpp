void solve(BinaryTreeNode<int>* root, int& count, int k, int& ans) {
    if (root == NULL || count >= k) {
        return;
    }

    solve(root->left, count, k, ans);

    count++;
    if (count == k) {
        ans = root->data;
        return; // Return after finding the kth smallest element
    }

    solve(root->right, count, k, ans);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int count = 0;
    int ans = -1; // Default value if kth smallest element is not found
    solve(root, count, k, ans);
    return ans;
}
