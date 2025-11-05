#include <bits/stdc++.h>

using namespace std;

int cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; 
    cin >> n >> m;

    set<string> s;

    for(int i=0; i<n; i++)
    {
        string str;
        cin >> str;

        s.insert(str);
    }

    for(int i=0; i<m; i++)
    {
        string str;
        cin >> str;

        auto it = s.find(str);
        if(it != s.end()) cnt++;
    }

    cout << cnt;
}