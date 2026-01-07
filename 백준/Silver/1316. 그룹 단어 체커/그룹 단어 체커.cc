#include <bits/stdc++.h>
using namespace std;

int sum;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    
    while(n--)
    {
        string s;
        cin >> s;

        bool isGroup = true;

        for(int i=1; i<s.size(); i++)
        {
            if(s[i] == s[i-1]) continue;
            auto it = find(s.begin(), s.begin()+i, s[i]);
            if(it!=s.begin()+i)
            {
                isGroup = false; 
            } 
        }

        if(isGroup) sum++;
    }

    cout << sum;
}