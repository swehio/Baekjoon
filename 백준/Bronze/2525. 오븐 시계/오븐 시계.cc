#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, m, t;
    cin >> h >> m >> t;

    m+=t;
    if(m > 59)
    {
        int addh=m/60; 
        m%=60; 
        h+=addh;
        if(h>23)
        {
            h%=24;
        }
    }
    cout << h << ' ' << m;
}