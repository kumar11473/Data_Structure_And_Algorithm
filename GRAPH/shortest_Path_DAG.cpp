// program for finding the shortest path of each vertex from given source vertex
#include <bits/stdc++.h>
using namespace std;

void findTopoShort(int node, vector<int> &vis, stack<int> &st, vector<pair<int, int>> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            findTopoShort(it.first, vis, st, adj);
        }
    }
    st.push(node);
}

void shortestPath(int src, int v, vector<pair<int, int>> adj[])
{
    vector<int> vis(v, 0);
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            findTopoShort(i, vis, st, adj);
    }
    int dist[v];
    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (dist[node] != INT_MAX)
        {
            for (auto it : adj[node])
            {
                if ((dist[node] + it.second) < dist[it.first])
                {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    for (int i = 0; i < v; i++)
        (dist[i] == INT_MAX) ? cout << " INT_MAX " : cout << dist[i] << " ";
}

int main()
{
    int V, e; //
    cin >> V >> e;
    vector<pair<int, int>> adj[V];
    for (int i = 0; i < e; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        adj[x].push_back({y, wt});
    }
    shortestPath(0, V, adj); // 0 -> source

    return 0;
}
