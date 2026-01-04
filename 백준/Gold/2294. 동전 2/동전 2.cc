#include <bits/stdc++.h>
using namespace std;

int coin[102];
int d[10002];
const int MX = 0xfffffff;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; 
    cin >> n >> k;

    for(int i=0; i<n; i++) cin >> coin[i];

    fill(d, d+10002, MX);

    d[0] = 0;
    for(int i=1; i<=k; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i-coin[j] >= 0) d[i] = min(d[i], d[i-coin[j]]+1);
        }
    }  

    if(d[k] != MX) cout << d[k];
    else cout << "-1";
}