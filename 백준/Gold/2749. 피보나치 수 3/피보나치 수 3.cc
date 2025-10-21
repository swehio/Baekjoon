#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;  
    n %= 1500000;
    
    if(n == 1)
    {
        cout << '1';
        return 0;
    }

    long long front = 0;
    long long back = 1;

    long long sum = 0;
    
    for(int i=2; i<=n; i++)
    {
        sum = (front + back) % 1000000;
        front = back;
        back = sum;
    }

    cout << sum % 1000000;
}