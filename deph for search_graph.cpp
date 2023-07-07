void DFS(unordered_map<int, set<int>>& adjlist, unordered_map<int, bool>& visited, int i, vector<int>& component)
{
    component.push_back(i);
    visited[i] = true;

    if (adjlist.find(i) != adjlist.end())
    {
        for (auto j : adjlist[i])
        {
            if (!visited[j])
            {
                DFS(adjlist, visited, j, component);
            }
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>>& edges)
{
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    unordered_map<int, set<int>> adjlist;

    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            DFS(adjlist, visited, i, component);
            ans.push_back(component);
        }
    }

    return ans;
}
