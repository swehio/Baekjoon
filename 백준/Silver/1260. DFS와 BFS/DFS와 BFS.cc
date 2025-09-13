#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1002];
int vis[1002];
queue<int> q;

void dfs(int cur)
{
    vis[cur] = 1;
    cout << cur << ' ';
    sort(adj[cur].begin(), adj[cur].end());
    for(int nxt : adj[cur])
    {
        if(vis[nxt]) continue;
        dfs(nxt);
    }

}

void bfs(int k)
{
    q.push(k);
    vis[k] = 1;

    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        sort(adj[cur].begin(), adj[cur].end());
        for(int nxt : adj[cur])
        {
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }



    dfs(k);
    cout << '\n';
    fill(vis, vis+n+1, 0);
    bfs(k);
}