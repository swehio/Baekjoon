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
        int a[26] = {0};
        string s;
        cin >> s;

        bool isGroup = true;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==s[i-1]) continue;
            if(a[s[i]-'a'] == 0) a[s[i]-'a']++;
            else isGroup = false;
        }

        if(isGroup) sum++;
    }

    cout << sum;
}