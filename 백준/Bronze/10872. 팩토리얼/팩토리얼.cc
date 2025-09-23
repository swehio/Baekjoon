#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int multi = 1;

    for(int i=0; i<n; i++)
    {
        multi *= i+1;
    }

    cout << multi;
}