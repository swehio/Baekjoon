#include <bits/stdc++.h>
using namespace std;

int arr[102];

int pow_custom(int k)
{
    int multi = 1;
    for(int i=0; i<k; i++)
    {
        multi *= 31 % 1234567891;
    }

    return multi;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l;
    string str;
    cin >> l >> str;

    int sum = 0;
    for(int i = 0; i<l; i++)
    {
        sum += (str[i] - 'a' + 1)*pow_custom(i);
    }

    cout << sum % 1234567891;
}