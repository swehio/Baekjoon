#include <bits/stdc++.h>

using namespace std; 

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

string board[602];
bool vis[602][602];

int cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    pair<int, int> start;

    for(int i=0; i<n; i++) 
    {
        cin >> board[i];   
        auto it = find(board[i].begin(), board[i].end(), 'I');
        if(it != board[i].end()) start = {i, it-board[i].begin()};
    }
 
    queue<pair<int, int>> q;
    q.push(start); 
    vis[start.first][start.second] = 1;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(int i=0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(vis[nx][ny] || board[nx][ny] == 'X') continue;
            if(board[nx][ny] == 'P') cnt++;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    if(cnt) cout << cnt;
    else cout << "TT";
}  