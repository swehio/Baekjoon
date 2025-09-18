#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> edge[1000002];
vector<int> p (1002, -1);
int n, e, cnt;
long long ans;

int find(int x)
{
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

int is_diff_group(int u, int v)
{
    u = find(u);
    v = find(v);

    if(u==v) return 0;

    if(p[u] == p[v]) p[u]--;
    if(p[u] > p[v]) swap(u, v);

    p[v] = u;
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int num;
            cin >> num;

            if(i>=j) continue;

            edge[e++] = {num, i, j};
        }
    }

    sort(edge, edge+e);

    for(int i=0; i<e; i++)
    {
        int cost, a, b;
        tie(cost, a, b) = edge[i];

        if(!is_diff_group(a, b)) continue;

        ans+=cost;
        cnt++;
        if(cnt == n-1) break;
    }

    cout << ans;
}