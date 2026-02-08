#include <bits/stdc++.h>
using namespace std;

int a[305];
int d[305][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;

    for(int i=0; i<n; i++) cin >> a[i];

    d[0][1] = a[0];
    d[0][2] = a[0];
    d[1][1] = a[0]+a[1];
    d[1][2] = a[1];
    d[2][1] = a[1]+a[2];
    d[2][2] = a[0]+a[2];
 
    for(int i=3; i<n; i++)
    {
        d[i][1] = max(d[i-3][1], d[i-3][2]) + a[i-1] + a[i];
        d[i][2] = max(d[i-2][1], d[i-2][2]) + a[i];
    }

    cout << max(d[n-1][1], d[n-1][2]);
}   