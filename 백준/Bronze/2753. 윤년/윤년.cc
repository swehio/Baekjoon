#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> num(3);
    int year;
    cin >> year;
    int result = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ? 1 : 0;
    cout << result;
}