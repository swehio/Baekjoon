#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100002];
int p[100002];

void dfs(int root)
{
    int cur = root;
    for(int nxt : adj[cur])
    {
        if(p[cur] == nxt) continue;
        p[nxt] = cur;
        dfs(nxt);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    for(int i = 2; i<=n; i++)
    {
        cout << p[i] << '\n';
    }
}