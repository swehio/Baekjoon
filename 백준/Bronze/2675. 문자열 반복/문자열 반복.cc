#include <bits/stdc++.h>
using namespace std;

int arr[8];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while(t--)
    {
        int cnt;
        string s;
        cin >> cnt >> s;

        for(char ch : s)
        {
            for(int i=0; i<cnt; i++) cout << ch;
        }
        cout << '\n';
    }

}