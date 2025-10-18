#include<bits/stdc++.h>

using namespace std;

int board[1030][1030];

int dp[1030][1030];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> board[i][j];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j == 0) dp[i][j] = board[i][j];
            else dp[i][j] = dp[i][j-1] + board[i][j]; 
        }

    }

    while(m--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        for(int i=x1-1; i<=x2-1;i++)
        {
            sum+=dp[i][y2-1] - dp[i][y1-2];
        }
        cout << sum << '\n';
    }
}