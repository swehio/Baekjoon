#include <bits/stdc++.h>

using namespace std;

bool column[20];
bool downup[50];
bool updown[50];
int cnt;
int n;

void solve(int row)
{
    if(row==n)
    {
        cnt++;
        return;
    }

    for(int i=0; i<n; i++)
    {
        if(column[i]||downup[row+i]||updown[row-i+n]) continue;
        column[i] = 1;
        downup[row+i] = 1;
        updown[row-i+n] = 1;
        solve(row+1);
        column[i] = 0;
        downup[row+i] = 0;
        updown[row-i+n] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    solve(0);
    cout << cnt;
}