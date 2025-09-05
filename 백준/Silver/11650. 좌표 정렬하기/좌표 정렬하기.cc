#include <bits/stdc++.h>
using namespace std;

pair<int, int> pos[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i<n; i++)
    {
        cin >> pos[i].first >> pos[i].second;
    }
    
    sort(pos, pos+n, [&](pair<int, int>& a, pair<int, int>& b){ if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;});
    
    for(int i = 0; i<n; i++)
    {
        cout << pos[i].first << ' ' << pos[i].second << '\n';
    }
}