#include <bits/stdc++.h>
using namespace std;

int arr[10002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<tuple<int, int, string>> v;
    
    for(int i = 0; i<n; i++)
    {
        int old;
        string name;
        cin >> old >> name;
        
        v.push_back({old, i, name});
    }
    
    sort(v.begin(), v.end(), [](tuple<int, int, string>& a, tuple<int, int, string>& b){
        int aOld, aIdx, bOld, bIdx;
        string aName, bName;
        tie(aOld, aIdx, aName) = a;
        tie(bOld, bIdx, bName) = b;
        if(aOld == bOld) return aIdx < bIdx;
        return aOld < bOld;
    });
    
    for(auto info : v)
    {
        int Old, Idx;
        string Name;
        tie(Old, Idx, Name) = info;
        cout << Old << ' ' <<  Name <<'\n';
    }
}