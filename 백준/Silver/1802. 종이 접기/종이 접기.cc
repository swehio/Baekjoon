#include <bits/stdc++.h>
using namespace std;

bool check(string str)
{
    if(str.size() == 1) return true;
    int size=str.size();
    int half = (size-1)/2;

    for(int i=1; i<=half; i++)
    {
        if(str[half-i] == str[half+i]) return false;
    }

    return check(str.substr(0, size/2));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t; 

    while(t--)
    {
        string str;
        cin >> str;

        bool canFold = check(str); 

        cout << (canFold?"YES":"NO") << '\n';
    }
}