#include <bits/stdc++.h>
using namespace std;

bool bipartiteBfs(int s, vector<int> adj[], vector<int> &color) // it should be "&color" and not "&color[]" keep in mind otherwise "array of reference isnot allowed " error occurs
{
    queue<int> q;
    q.push(s);
    color[s] = 1; // you may take it 0 also
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (color[it] == -1) // pehle node ko color karo fir queue me push kro
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
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
            if (!bipartiteBfs(i, adj, col))
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

// int color[v];
// memset(color, -1, sizeof color);

// using memset instead of vector
// #include <bits/stdc++.h>
// using namespace std;

// bool bipertiteBfs(int s, vector<int> adj[], int color[])
// {
//     queue<int> q;
//     q.push(s);
//     color[s] = 1; // you may take it 0 also
//     while (!q.empty())
//     {
//         int node = q.front();
//         q.pop();

//         for (auto it : adj[node])
//         {
//             if (color[it] == -1)  // pehle node ko color karo fir queue me push kro
//             {
//                 color[it] = 1 - color[node];
//                 q.push(it);
//             }
//             else if (color[it] == color[node])
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// bool checkBipertite(vector<int> adj[], int v)
// {
//     int color[v];
//     memset(color, -1, sizeof color);
//     for (int i = 0; i < v; i++)
//     {
//         if (color[i] == -1)
//         {
//             if (!bipertiteBfs(i, adj, color))
//                 return false;
//         }
//     }
//     return true;
// }
// int main()
// {
//     int v, e;
//     cin >> v >> e;
//     vector<int> adj[v];
//     for (int i = 0; i < e; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }
//     if (checkBipertite(adj, v))
//         cout << "Yes graph is bipertite";
//     else
//         cout << "NO graph is not bipertite";

//     return 0;
// }