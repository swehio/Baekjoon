#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    
    if(a == b && b == c)
    {
        cout << 10000+a*1000;
    }
    else if(a != b && b != c && a != c)
    {
        
        cout << max({a, b, c})*100;
    }
    else
    {
        int result = a;
        if(b == c) result = b;
        cout << 1000+result*100;
    }
}