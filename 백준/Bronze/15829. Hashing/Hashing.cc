#include <bits/stdc++.h>
using namespace std;

long long cachePow[55];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l;
    string str;
    cin >> l >> str;

    cachePow[0] = 1;
    for(int i=1; i<l; i++)
    {
        cachePow[i] = cachePow[i-1] * 31 % 1234567891;
    }

    long long sum = 0;
    for(int i = 0; i<l; i++)
    {
        sum += (str[i] - 'a' + 1)*cachePow[i] % 1234567891;
    }

    cout << sum % 1234567891;
}