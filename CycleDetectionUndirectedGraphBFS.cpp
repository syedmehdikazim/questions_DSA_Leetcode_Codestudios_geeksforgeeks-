#include<unordered_map>
#include<list>
#include<queue>
bool iscycle(unordered_map<int,list<int>>&adj, unordered_map<int,bool>&visited, int node)
{
    unordered_map<int,int>parent;


    parent[node]=-1;
    visited[node]=1;
    queue<int>q;
    

    q.push(node);

    while(!q.empty())
    {
        int front=q.front();
        q.pop();

        if(adj.find(front)!=adj.end())
        {
            for(auto i: adj.at(front))
            {
                if(visited[i]==true && parent[front]!=i)
                {
                    return true;
                }
                else if(!visited[i])
                {
                    q.push(i);
                    visited[i]=true;
                    parent[i]=front;
                }
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>>adj;
    for(int i=0;i<m;i++)
    {
        int u= edges[i][0];
        int v= edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool>visited;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bool ans=iscycle(adj,visited,i);

            if(ans==true)
            {
                return "Yes";
            }
        }
    }
    return "No";
}
