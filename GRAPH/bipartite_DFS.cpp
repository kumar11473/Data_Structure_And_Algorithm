#include <bits/stdc++.h>
using namespace std;

bool bipartiteDfs(int node, vector<int> adj[], vector<int> &color) // it should be "&color" and not "&color[]" keep in mind otherwise "array of reference isnot allowed " error occurs
{
    if (color[node] == -1) // node => starting vertex
        color[node] = 1;

    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[node];
            if (!bipartiteDfs(it, adj, color))
                return false;
        }
        else if (color[it] == color[node])
            return false;
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int v)
{
    vector<int> col(v, -1);
    for (int i = 0; i < v; i++)
    {
        if (col[i] == -1)
        {
            if (!bipartiteDfs(i, adj, col))
                return false;
        }
    }
    return true;
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
    if (checkBipartite(adj, v))
        cout << "Yes graph is bipartite";
    else
        cout << "NO graph is not bipartite";

    return 0;
}