#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

vector<pair<int, int>> adj[20002]; 
int pre[20002];
int d[20002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, st, en;
    cin >> n >> m;

    fill(d, d+n+1, INF);

    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});  
    }

    cin >> st >> en;

    d[st] = 0; 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({d[st], st});

    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop(); 
        if(d[cur.second] < cur.first) continue; 

        for(auto nxt : adj[cur.second])
        { 
            int nd = d[cur.second]+nxt.first;
            if(nd < d[nxt.second]) 
            {
                d[nxt.second] = nd; 
                pre[nxt.second] = cur.second;
                pq.push({nd, nxt.second});
            }
        } 
    }

    cout << d[en] << '\n';
    int tmp = en;
    stack<int> route;
    while(tmp!=0)
    {
        route.push(tmp);
        tmp = pre[tmp];
    }
    cout << route.size() << '\n';
    while(!route.empty())
    {
        cout << route.top() << ' ';
        route.pop();
    }
}