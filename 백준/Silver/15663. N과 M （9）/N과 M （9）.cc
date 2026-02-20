#include <bits/stdc++.h>
using namespace std;

int a[10];

int n, m;

void solve(int st, int cnt, vector<int> v)
{ 
    if(st!=-1) v.push_back(st);
    if(cnt == m) 
    {
        for(int num : v) cout << a[num] << ' ';
        cout << '\n';
        return;
    }
    for(int i=0; i<n; i++)
    { 
        if(find(v.begin(), v.end(), i)==v.end()) 
        {
            solve(i, cnt+1, v);
            i = upper_bound(a+i, a+n, a[i])-a-1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) cin >> a[i];

    sort(a, a+n);
    vector<int> v;
    solve(-1, 0, v);
}