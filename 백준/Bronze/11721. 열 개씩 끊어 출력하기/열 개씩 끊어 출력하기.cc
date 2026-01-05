#include <bits/stdc++.h>
using namespace std; 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c = 0;
    string s;
    cin >> s;

    for(char ch : s)
    {
        cout << ch;
        c++;
        if(c==10)
        {
            cout << '\n';
            c=0;
        }
    }
}