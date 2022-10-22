// a less efficient code for prims algorithm  O(N square)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e, source;
    cin >> v >> e;
    vector<pair<int, int>> adj[v]; //-> 0 indexed
    int a, b, wt;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }

    vector<int> parent(v, -1);     // store the parent vextex of the current vertex
    vector<int> key(v, INT_MAX);   // for storing weight
    vector<bool> mstSet(v, false); // if true means that vertex is included int the mst

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < v - 1; count++) // count <v-1 becoz there are v-1 edges in a mst
    {
        int mini = INT_MAX;
        int u;
        for (int i = 0; i < v; i++)
        {
            if ((mstSet[i] == false) && (key[i] < mini))
            {
                mini = key[i];
                u = i;
            }
        }
        mstSet[u] = true;

        for (auto it : adj[u])
        {
            int node = it.first;
            int weight = it.second;
            if ((mstSet[node] == false) && (weight < key[node]))
            {
                parent[node] = u;
                key[node] = weight;
            }
        }
    }

    for (int i = 0; i < v; i++)
        cout << parent[i] << " - " << i << "\n";
    return 0;
}