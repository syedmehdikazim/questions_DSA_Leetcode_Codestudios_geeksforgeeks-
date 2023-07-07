#include <unordered_map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

void makeadj(unordered_map<int, set<int>>& adjmat, vector<pair<int, int>>& edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjmat[u].insert(v);
        adjmat[v].insert(u);
    }
}

void bfs(const unordered_map<int, set<int>>& adjmat, unordered_map<int, bool>& visited, vector<int>& ans, int i)
{
    queue<int> q;
    visited[i] = true;
    q.push(i);

    while (!q.empty())
    {
        int frontnode = q.front();
        q.pop();
        ans.push_back(frontnode);
        for (auto j : adjmat.at(frontnode))
        {
            if (!visited[j])
            {
                q.push(j);
                visited[j] = true;
            }
        }
    }
}

void print(const unordered_map<int, set<int>>& adjmat)
{
    for (auto i: adjmat)
    {
        cout<<i.first<<"->";
        
        for(auto j: i.second)
        {
            cout<<j<<", ";
        }
        cout<<endl;
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, bool> visited;
    unordered_map<int, set<int>> adjmat;
    vector<int> ans;
    makeadj(adjmat, edges);

    // Initialize the visited map with false for all vertices
    if(edges.size()==0)
    {
        for(int i=0;i<vertex;i++)
        {
            ans.push_back(i);
        }
        return ans;
    }

    // Traverse all components of the graph
        for(int i=0;i<vertex;i++)
        {
            if(!visited[i])
            {
                bfs(adjmat,visited,ans,i);
            }
        }
        //print(adjmat);
        /*for(int i=0;i<vertex;i++)
        {
            cout<<i<<" ";
        }*/
        
        

    // Adjust vertex indices to start from 0
    

    return ans;
}
