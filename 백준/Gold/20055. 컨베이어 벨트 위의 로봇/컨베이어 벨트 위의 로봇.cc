#include <bits/stdc++.h>
using namespace std;

int n, k, t, cnt;
const int MX = 100;
int a[2*MX+2];
bool bot[MX+2];

void rot()
{
    rotate(a, a+2*n-1, a+2*n);
    rotate(bot, bot+n-1, bot+n);
    if(bot[n-1]) bot[n-1] = false;
}

void move()
{
    for(int i=n-2; i>=0; i--)
    {
        int nxt = i+1;
        if(a[nxt]<=0 || !bot[i] || bot[nxt]) continue;
        bot[i] = false;
        bot[nxt] = true;
        if(--a[nxt] == 0) cnt++;
    }
    if(bot[n-1]) bot[n-1] = false;
}

void put_bot()
{
    if(a[0]!=0)
    {
        bot[0]=true;
        if(--a[0] == 0) cnt++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i=0; i<2*n; i++) cin >> a[i];

    while(++t)
    {
        rot();
        move();
        put_bot();
        if(cnt >= k) break;
    }

    cout << t;
}