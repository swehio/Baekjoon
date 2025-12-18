#include <bits/stdc++.h>
using namespace std;

int basket[102];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++)
    {
        int st, en, k;
        cin >> st >> en >> k;

        for(int j=st; j<=en; j++) basket[j] = k;
    }

    for(int i=1; i<=n; i++)
    { cout << basket[i] << ' '; }
}