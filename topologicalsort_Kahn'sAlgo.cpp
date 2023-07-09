vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>>adj;
    vector<int>indegree(v);
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int>ans;
    vector<bool>visited(v);
    
   /* for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            bfs(adj, visited, indegree, ans, i);
        }
    }*/

    while(!q.empty())
    {
        int front =q.front();
        q.pop();
        ans.push_back(front);

        //updating neigbours indegree
        if(adj.find(front)!=adj.end())
        {
            for(auto i: adj[front])
            {
                if(!visited[i])
                {
                    indegree[i]--;
                    if(indegree[i]==0)
                    {
                        q.push(i);
                    }
                }
            }
        }
    }
    /*while(!s.empty())
    {
        int num=s.top();
        s.pop();
        ans.push_back(num);
    }*/
    return ans;

}
