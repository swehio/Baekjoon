#include <bits/stdc++.h>
using namespace std;

int a[100005];
int mn = 0xfffffff;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);  

    int n, s;
    cin >> n >> s;

    for(int i=0; i<n; i++) cin >> a[i];

    int en=0;
    int tot = a[0];

    for(int st=0; st<n; st++)
    {
        while(en<n&&tot<s)
        {
            en++;
            tot+=a[en]; 
        }
        if(en==n) break;

        mn = min(mn, en-st+1);
        tot-=a[st];
    }

    cout << (mn==0xfffffff?0:mn);
}