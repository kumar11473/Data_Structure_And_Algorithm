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

    int parent[v];                 // store the parent vextex of the current vertex
    vector<int> key(v, INT_MAX);   // for storing weight
    vector<bool> mstSet(v, false); // if true means that vertex is included int the mst

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int u = pq.top().first; // first-> weight, second-> vertex
        pq.pop();

        mstSet[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
                pq.push({v, key[v]});
            }
        }
    }
    for (int i = 0; i < v; i++)
        cout << parent[i] << " - " << i << "\n";
    return 0;
}
/*
5 6
0 3 6
0 1 2
1 2 3
4 2 7
1 4 5
1 3 8
*/

// Run the loop till all the nodes have been visited
// because in the brute code we checked for mstSet[node] == false while computing the minimum
// but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
// hence its better to keep running till all the nodes have been taken.
// try the following case:
// Credits: Srejan Bera
// 6 7
// 0 1 5
// 0 2 10
// 0 3 100
// 1 3 50
// 1 4 200
// 3 4 250
// 4 5 50