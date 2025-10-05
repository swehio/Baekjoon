#include <bits/stdc++.h>
using namespace std;

int cnt;

int isPrime(int k)
{
    if(k==1) return 0;
    if(k==2) return 1;
    for(int i=2; i*i <= k; i++)
    {
        if(k % i == 0) return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--)
    {
        int num;
        cin >> num;
        cnt += isPrime(num);
    }

    cout << cnt;
}