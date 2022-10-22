// shortest path to every verted from a source in weighted graph
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
    cout << "enter source ";
    cin >> source;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(v, INT_MAX);
    distTo[source] = 0;
    pq.push(make_pair(0, source));
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        // vector<pair<int, int>>::iterator it;
        //  for (it = adj[prev].begin(); it != adj[prev].end(); it++)
        for (auto it : adj[prev])
        {
            // int next = it->first;
            // int nextDist = it->second;
            int next = it.first;
            int nextDist = it.second;
            if (distTo[next] > dist + nextDist)
            {
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }

    cout << "The distance from source " << source << ", are : \n";
    for (int i = 0; i < v; i++)
        cout << distTo[i] << " ";

    return 0;
}