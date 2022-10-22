#include <bits/stdc++.h>
using namespace std;

vector<int> ans; // global initialisation of ans vector to push values
                 // dissconnected graph

void bfs(vector<int> adj[], int V, int s, vector<int> &vis)
{
    //  s->source
    queue<int> q;
    vis[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        // cout << u << " ";
        ans.push_back(u);
        for (int v : adj[u])
        {
            if (vis[v] == false)
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    // return ans;
}
void bfsDiss(vector<int> adj[], int v)
{
    int componentCounter = 0;
    vector<int> visited(v + 1, false);
    for (int i = 0; i < v; i++)
    {
        componentCounter++;
        if (visited[i] == false)
            bfs(adj, v, i, visited); // i->source
    }
    cout << "The number of component of graph is " << componentCounter;
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

    bfsDiss(adj, v);

    for (auto it : ans)
        cout << it << " ";
    return 0;
}

// for printing the adjacency list
// for (int i = 0; i < E; i++)
// {
// 	for (int j = 0; j < adj[i].size(); j++)
// 	{
// 		cout << adj[i][j] << " ";
// 	}
// 	cout << endl;
// }