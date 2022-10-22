#include <bits/stdc++.h>
using namespace std;

bool checkCycle(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis)
{
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (checkCycle(it, adj, vis, dfsVis))
                return true;
        }
        else if (dfsVis[it])
            return true;
    }
    dfsVis[node] = 0;
    return false;
}
bool CycleDetectionDfs_Dir(vector<int> adj[], int v)
{
    vector<int> vis(v, 0);
    vector<int> dfsVis(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, adj, vis, dfsVis))
                return true;
        }
    }
    return false;
}

int main()
{
    int v, e;
    cin >> v >> e;
    int src = 0;
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    if (CycleDetectionDfs_Dir(adj, v))
        cout << "Yes cycle exist";
    else
        cout << "No cycle doesn't exist";

    return 0;
}