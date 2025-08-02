#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    int cnt = 0;
    cin >> n;
    
    int arr[n];
    int numCount[1000001] = {};
    
    for(int i = 0; i<n; ++i)
    {
        cin >> arr[i];
    }
    
    cin >> x;
    
    for(int i = 0; i<n; ++i)
    {
        int pair = x - arr[i];
        if(pair < 0 || pair > 1000000) continue;
        
        if(numCount[pair] == 1)
        {
            ++cnt;
        }
        
        numCount[arr[i]] = 1;
    }
    
    cout << cnt;
}