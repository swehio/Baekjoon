#include <bits/stdc++.h>
using namespace std;

int arr[10002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<pair<int, string>> v;
    
    while(n--)
    {
        int old;
        string name;
        cin >> old >> name;
        
        v.push_back({old, name});
    }
    
    stable_sort(v.begin(), v.end(), [](pair<int, string> a, pair<int, string> b) { return a.first < b.first; });
    
    for(auto info : v)
    {
        cout << info.first << ' ' << info.second <<'\n';
    }
}