//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find number of strongly connected components in the graph.

    void dfs(int i, vector<int> adj[], vector<bool> &visited, stack<int> &st)
    {
        visited[i] = true;
        for (int x : adj[i])
        {
            if (visited[x] == false)
            {
                dfs(x, adj, visited, st);
            }
        }
        st.push(i);
    }

    void revDfs(int node, vector<int> transpose[], vector<bool> &visited)
    {
        cout << node << " ";
        visited[node] = true;
        for (auto it : transpose[node])
        {
            if (!visited[it])
            {
                revDfs(it, transpose, visited);
            }
        }
    }

    int kosaraju(int V, vector<int> adj[])
    {
        // code her
        int ans = 0;
        stack<int> st;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, st);
            }
        }

        vector<int> reverseAdj[V];

        for (int i = 0; i < V; i++)
        {
            visited[i] = false; // while doing topo sort visited vector is marked (true) so we need to make it false again
            for (int j : adj[i])
            {
                reverseAdj[j].push_back(i);
            }
        }

        // for (int i = 0; i < V; i++)
        //     visited[i] = false;

        while (!st.empty())
        {
            int curr = st.top();
            st.pop();
            if (!visited[curr])
            {
                ans++;
                revDfs(curr, reverseAdj, visited);
                cout << ",";
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution obj;
    cout << obj.kosaraju(V, adj) << "\n";

    return 0;
}

// } Driver Code Ends

// 5 5 5edge 5 vertex
// 1 0
// 0 2
// 2 1
// 0 3
// 3 4