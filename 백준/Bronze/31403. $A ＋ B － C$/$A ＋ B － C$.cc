#include <bits/stdc++.h>
using namespace std;

int line[3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    cout << a+b-c << '\n';
    string s = to_string(a)+to_string(b);
    cout << stoi(s) - c << '\n'; 
}