#include <bits/stdc++.h>
using namespace std;

// Generally vectors are used instead of maps, which makes code faster and efficient. But here I have used map instead of vector
map<int, bool> vis; 
map<int, vector<int>> adj;
unordered_set<int> s;
map<int, int> in, low;
int timer = 0;

void dfs(int node, int par = -1)
{
    vis[node] = true;
    in[node] = low[node] = timer++;
    int children = 0;
    for (int child : adj[node])
    {
        if (child == par)
            continue;

        if (vis[child])
            low[node] = min(low[node], in[child]);
        else
        {
            dfs(child, node);
            low[node] = min(low[node], low[child]);
            if (low[child] >= in[node] && par != -1)
                s.insert(node);
            ++children;
        }
    }
    if (par == -1 && children > 1)
        s.insert(node);
}

void findArticulationPts(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
}

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    while (m--)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        vis[x] = false;
        vis[y] = false;
    }

    findArticulationPts(n);
    cout << "Number of articulation points are " << s.size() << '\n';
    return 0;
}