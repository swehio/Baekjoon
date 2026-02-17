#include <bits/stdc++.h>
using namespace std;

int t[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int mx = 0; 
    int tot = 0;

    for(int i=0; i<n; i++) cin >> t[i];

    for(int i=0; i<k; i++) tot+=t[i];

    int en = k-1;

    mx = tot;

    for(int st=0; st<n; st++)
    { 
        mx = max(mx, tot);
        tot+=t[++en];
        if(en >= n) break;
        tot-=t[st];
    }

    cout << mx;
}