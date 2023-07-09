#include<unordered_map>
#include<list>
bool dfs(unordered_map<int,bool>&visited, unordered_map<int ,list<int>>&adj, unordered_map<int,bool>&dfsvisited, int node)
{

  visited[node]=true;
  dfsvisited[node]=true;
  if(adj.find(node) != adj.end())
  {
    for(auto i: adj[node])
    {
      if (!visited[i])
      {
        bool cycledetected = dfs(visited, adj, dfsvisited, i);
        if(cycledetected)
        {
          return true;
        }
      }

      else if (dfsvisited[i]==true&& visited[i]==true)
      {
        return true;
      }  
            
    }
  }
  dfsvisited[node]=false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  
  unordered_map<int ,list<int>>adj;
  for(int i=0;i<edges.size();i++)
  {
    int u=edges[i].first;
    int v=edges[i].second;
    adj[u].push_back(v);
  }
  unordered_map<int,bool>visited;
  //
  unordered_map<int,bool>dfsvisited;
  for(int i=1;i<=n;i++)
  {
    if(!visited[i])
    {
      bool ans=dfs(visited,adj, dfsvisited ,i);
      if(ans)
      {
        return true;
      }
    }
  }
  return false;
}
