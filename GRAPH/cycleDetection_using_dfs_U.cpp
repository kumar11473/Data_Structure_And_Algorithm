// cycle detection using dfs for undirected graph
#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(vector<int> adj[], int parent, vector<bool> &vis, int node)
{
    vis[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (checkForCycle(adj, node, vis, it))
                return true;
        }
        else if (it != parent)
            return true;
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
            if (checkForCycle(adj, -1, vis, i))
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

// for (int i = 0; i < E; i++)
// {
// 	for (int j = 0; j < adj[i].size(); j++)
// 	{
// 		cout << adj[i][j] << " ";
// 	}
// 	cout << endl;
// }