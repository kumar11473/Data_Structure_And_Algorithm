#include <bits/stdc++.h>
using namespace std;

void miniUnitDistance(vector<int> adj[], int V, int src)
{
    int dis[V];
    for (int i = 0; i < V; i++)
        dis[i] = INT_MAX;

    queue<int> q;
    q.push(src);
    dis[src] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if ((dis[node] + 1) < dis[it])
            {
                dis[it] = dis[node] + 1;
                q.push(it);
            }
        }
    }

    for (int i = 0; i < V; i++)
        cout << dis[i] << " ";
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
        adj[y].push_back(x);
    }
    miniUnitDistance(adj, v, src);

    return 0;
}