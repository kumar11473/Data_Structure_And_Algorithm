#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int> adj[], int V)
{
    int s = 0; // s-> source of graph traversing
    vector<int> ans;
    vector<bool> visited(V + 1, false);
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        // cout << u << " ";
        ans.push_back(u);
        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return ans;
}
int main()
{
    int v, e;
    cin >> v >> e;
    int s = 0;

    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> ans = bfs(adj, v);

    for (auto it : ans)
        cout << it << " ";
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