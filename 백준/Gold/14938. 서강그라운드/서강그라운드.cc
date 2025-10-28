#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f; 

int dp[102][102];
int arr[102];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    for(int i=1; i<=n; i++) cin >> arr[i];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j) continue;

            dp[i][j]=INF;
        }
    }

    for(int i=0; i<r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l; 

        dp[a][b] = l;
        dp[b][a] = l;
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int mx = 0;
    for(int i=1; i<=n; i++)
    {
        int sum = 0;
        for(int j=1; j<=n; j++)
        {
            if(dp[i][j] <= m) sum += arr[j]; 
        }
        mx = max(mx, sum);  
    }

    cout << mx;
}