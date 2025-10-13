#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int gcd(int a, int b)
{
    if(a == 0) return b;
    return gcd(b%a, a);
}

int lcm(int a, int b)
{
    return a/gcd(a, b)*b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int lcm_num = lcm(m, n); 

        bool isright = false;
        for(int i = x; i<=lcm_num; i+=m)
        {
            if(((i-1) % n)+1 == y) 
            {
                isright = true;
                cout << i << '\n';
            }
        }
        if(!isright) cout << "-1" << '\n';
    } 
}  