#include<bits/stdc++.h>
using namespace std;  

int n, m;
int a[10];
bool used[10];

void solve(int k)
{ 
    if(k==m)
    {
        for(int i=0; i<m; i++) cout << a[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=1; i<=n; i++)
    {
        if(used[i]) continue;
        a[k] = i;
        used[i]=true;
        solve(k+1);
        used[i]=false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin>>n>>m;

    solve(0);
} 