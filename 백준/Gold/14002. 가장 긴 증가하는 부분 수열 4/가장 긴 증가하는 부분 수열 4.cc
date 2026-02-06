#include <bits/stdc++.h>

using namespace std;

int arr[1002];
int dp[1002];
vector<int> v[1002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) 
    {
        cin >> arr[i];
        v[i].push_back(arr[i]);
    }

    fill(dp, dp+n, 1);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[j] < arr[i]) 
            {
                dp[i] = max(dp[i], dp[j] + 1);
                if(dp[i] == dp[j] + 1)
                {
                    v[i] = v[j];
                    v[i].push_back(arr[i]);
                }
            }
        }
    }

    int mxidx = max_element(dp, dp+n) - dp;

    cout << dp[mxidx] << '\n';
    for(int k : v[mxidx]) cout << k << ' ';

    
}