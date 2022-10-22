#include <bits/stdc++.h>
using namespace std;

void dfsRec(vector<int> adj[], int s, vector<bool> &vis)
{
    vis[s] = true;
    cout << s << " ";
    for (auto u : adj[s])
    {
        if (vis[u] == false)
            dfsRec(adj, u, vis);
    }
}
void dfs(vector<int> adj[], int v)
{
    vector<bool> vis(v, false);
    for (int i = 0; i < v; i++) // for connected component
    {
        if (vis[i] == false)
            dfsRec(adj, i, vis);
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj, V);
    return 0;
}