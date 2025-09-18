#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> edge[10002];
vector<int> p(1002, -1);

int find(int x)
{
    if(p[x]<0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int  u, int v)
{
    u = find(u);
    v = find(v);

    if(u == v) return false;

    if(p[u]==p[v]) p[u]--;
    if(p[u]>p[v]) swap(u, v);

    p[v] = u;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        fill(p.begin(), p.end(), -1);

        for(int i=0; i<m; i++)
        {
            int a, b;
            cin >> a >> b;

            edge[i] = {1, a, b};
        }

        sort(edge, edge+m);

        int cnt = 0;
        int ans = 0;

        for(int i=0; i<m; i++)
        {
            int cost, a, b;
            tie(cost, a, b) = edge[i];
            
            if(!is_diff_group(a, b)) continue;
            ans+=cost;
            cnt++;
            if(cnt == n-1) break;
        }

        cout << ans << '\n';
    }



}