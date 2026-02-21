#include <bits/stdc++.h>
using namespace std; 

int a[10];
bool vis[10];
int n, m;

void solve(int depth)
{
    if(depth == m)
    {
        for(int i=1; i<=m; i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }

    for(int i=1; i<=n; i++)
    {
        if(vis[i]) continue;
        a[depth+1] = i;
        vis[i] = 1;     
        solve(depth+1);
        vis[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n >> m;

    solve(0);

}