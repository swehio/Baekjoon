#include <bits/stdc++.h>
using namespace std;

int n, m;  
bool num[10];

void solve(int k, vector<int>& st)
{
    if(k==m)
    {
        for(int l : st) cout << l << ' ';
        cout << '\n';
    }

    vector<int> list = st;

    for(int i=0; i<n; i++)
    {
        if(num[i+1]) continue;
        num[i+1] = true;
        list.push_back(i+1);
        solve(k+1, list);
        num[i+1] = false;
        list.pop_back();
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector<int> st;

    solve(0, st);
}