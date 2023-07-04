#include <bits/stdc++.h>

void solve(int x, int y, vector<vector<int>>& arr, int n, vector<string>& ans, vector<vector<bool>>& visited, string path) {
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }
    visited[x][y] = true;
    // down
    if (x + 1 < n && visited[x + 1][y] != 1 && arr[x + 1][y] != 0) {
        path.push_back('D');
        solve(x + 1, y, arr, n, ans, visited, path);
        path.pop_back();
        
    }
    // left
    if (y - 1 >= 0 && visited[x][y - 1] != 1 && arr[x][y - 1] != 0) {
        path.push_back('L');
        solve(x, y - 1, arr, n, ans, visited, path);
        path.pop_back();
    }
    // right
    if (y + 1 < n && visited[x][y + 1] != 1 && arr[x][y + 1] != 0) {
        path.push_back('R');
        solve(x, y + 1, arr, n, ans, visited, path);
        path.pop_back();
    }
    // up
    if (x - 1 >= 0 && visited[x - 1][y] != 1 && arr[x - 1][y] != 0) {
        path.push_back('U');
        solve(x - 1, y, arr, n, ans, visited, path);
        path.pop_back();
    }
    visited[x][y] = false;
        
}

vector<string> searchMaze(vector<vector<int>>& arr, int n) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    vector<string> ans;
    if(arr[0][0]==0)
    {
        return ans;
    }
    string path = "";
    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}
