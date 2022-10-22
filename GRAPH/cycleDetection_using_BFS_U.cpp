#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int s, int v, vector<int> adj[], vector<bool> &vis)
{
    queue<pair<int, int>> q;
    vis[s] = true;
    q.push({s, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second; // par->parent
        q.pop();

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = true;
                q.push({it, node});
            }
            else if (par != it)
                return true;
        }
    }
    return false;
}

bool isCycle(vector<int> adj[], int V)
{
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (checkForCycle(i, V, adj, vis))
                return true;
        }
    }
    return false;
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (isCycle(adj, v))
        cout << "Yes cycle exist";
    else
        cout << "cycle not exist";
    return 0;
}