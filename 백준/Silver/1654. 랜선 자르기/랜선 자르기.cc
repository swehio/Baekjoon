#include <bits/stdc++.h>
using namespace std;

int k, n;
int a[100005]; 

bool check(long long length)
{ 
    int cnt=0;
    for(int i=0; i<k; i++)
    {
        cnt+=a[i]/length;
    }

    return cnt >= n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);  

    cin >> k >> n;

    for(int i=0; i<k; i++) cin >> a[i];
    
    long long st = 0;
    long long en = 0xf3f3f3f3;

    while(st<en)
    {
        long long mid = (st+en+1)/2;
        if(check(mid)) st = mid;
        else en = mid-1;
    }

    cout << st;
}