#include <bits/stdc++.h>
using namespace std;

long long dp[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;

    int absn = abs(n);

    dp[0] = 0; 
    dp[1] = 1;
    
    for(int i=2; i<=absn; i++) dp[i] = (dp[i-1]+dp[i-2]) % 1000000000;

    if(n > 0 || absn % 2 != 0) cout << "1" << '\n';   
    else if(n == 0)  cout << "0" << '\n';  
    else  cout << "-1" << '\n';   

    cout << dp[absn] % 1000000000;
}