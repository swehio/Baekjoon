#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m;
ll arr[1000005];

bool solve(int k)
{
    ll sum = 0;
    for(int i=0; i<n; i++) sum += (arr[i] - k) > 0 ? arr[i] - k : 0;
    return sum >= m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) cin >> arr[i];

    ll st = 0;
    ll en = 1000000000;
    while(st<en)
    {
        ll mid = (st+en+1)/2;
        if(solve(mid)) st = mid;
        else en = mid-1;
    }
    cout << st;
}