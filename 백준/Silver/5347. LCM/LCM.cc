#include <bits/stdc++.h>
using namespace std;

int gcd(long long a, long long b)
{
    if(a == 0) return b;
    return gcd(b%a, a);
}

long long lcm(long long a, long long b)
{
    return a * b /gcd(a, b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    while(n--)
    {
        long long a, b;
        cin >> a >> b;

        cout << lcm(a, b) << '\n';
    } 
}