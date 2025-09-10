#include <bits/stdc++.h>

int board[200005];

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    n += 100000;
    k += 100000;
    fill(board, board + 200005, -1);

    queue<int> q;
    q.push(n);
    board[n] = 0;

    if(n == k)
    {
        cout << '0';
        return 0;
    }

    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(int next : {(100000+2*(cur-100000)), cur-1, cur+1})
        {
            if(next < 0 || next>200005) continue;
            if(board[next] != -1) continue;
            if(next != (100000+2*(cur-100000)))
            {
                board[next] = board[cur]+1;
            }
            else board[next] = board[cur];
            q.push(next);
            if(next == k)
            {
                cout << board[k];
                return 0;
            }
        }
    }

}