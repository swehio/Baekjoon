#include <bits/stdc++.h>
using namespace std;

int cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;

    string pn = "";
    for(int i=0; i<n*2+1; i++)
    {
        if(i%2 != 0) pn+= 'O';
        else pn+= 'I';
    }  
    
    for(int i=0; i<m; i++)
    {
        if(pn == s.substr(i, pn.size())) cnt++;
    }

    cout << cnt;
}