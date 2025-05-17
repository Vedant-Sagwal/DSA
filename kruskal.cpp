#include <iostream>
#include <vector>
#include <queue>
using namespace std;
static bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
void makeSet(vector<int> &parent, vector<int> &rank, int v)
{
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}
void unionSet(vector<int> &parent, vector<int> &rank, int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (u != v)
    {
        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
}

void displayMst(vector<vector<int>> &mst)
{
    for (auto it : mst)
    {
        cout << it[0] << "-" << it[1] << ":" << it[2] << endl;
    }
}
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> parent(V);
    vector<int> rank(V, 0);
    int minWeight = 0;
    vector<vector<int>> edges;
    vector<vector<int>> mst;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int v = it[0];
            int weight = it[1];
            if (i < v)
            {
                edges.push_back({i, v, weight});
            }
        }
    }
    sort(edges.begin(), edges.end(), cmp);
    makeSet(parent, rank, V);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        if (u != v)
        {
            minWeight += wt;
            unionSet(parent, rank, u, v);
            mst.push_back({edges[i][0], edges[i][1], edges[i][2]});
        }
    }
    displayMst(mst);
    return minWeight;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;
        vector<vector<int>> adj[v];
        for (int i = 0; i < e; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        cout << "mst weight:" << spanningTree(v, adj) << endl;
    }
    return 0;
}
