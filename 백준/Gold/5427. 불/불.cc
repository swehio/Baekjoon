#include <bits/stdc++.h>
using namespace std;

string board[1002];
int fire[1002][1002];
int dist[1002][1002];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        int w, h;
        cin >> w >> h;
        
        bool escape = false;
        
        queue<pair<int, int>> fireQ;
        queue<pair<int, int>> Q;
        
        fill(board, board+h, "");
        for(int i = 0; i<h; i++) fill(fire[i], fire[i]+w, -1);
        for(int i = 0; i<h; i++) fill(dist[i], dist[i]+w, -1);
        
        for(int i = 0; i<h; i++)
        {
            cin >> board[i];
            for(int j = 0; j<w; j++)
            {
                if(board[i][j] == '@') 
                {
                    Q.push({i, j});
                    dist[i][j] = 0;
                }
                if(board[i][j] == '*') 
                {
                    fireQ.push({i, j});
                    fire[i][j] = 0;
                }
            }
        }
        
        while(!fireQ.empty())
        {
            auto cur = fireQ.front(); fireQ.pop();
            for(int i = 0; i<4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                
                if(nx < 0 || nx >= h || ny < 0 || ny>=w) continue;
                if(board[nx][ny] == '#' || fire[nx][ny] != -1) continue;
                fire[nx][ny] = fire[cur.first][cur.second]+1;
                fireQ.push({nx, ny});
            }
        }
        
        
        while(!Q.empty() && !escape)
        {
            auto cur = Q.front(); Q.pop();
            for(int i = 0; i<4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                
                if(nx < 0 || nx >= h || ny < 0 || ny >= w)
                {
                    cout << dist[cur.first][cur.second]+1 << '\n';
                    escape = true;
                    break;
                }
                if(board[nx][ny] == '#' || dist[nx][ny] != -1 || (fire[nx][ny] != -1 && (fire[nx][ny] <= dist[cur.first][cur.second]+1))) continue;
                dist[nx][ny] = dist[cur.first][cur.second]+1;
                Q.push({nx, ny});
            }
        }
        
        if(!escape) cout << "IMPOSSIBLE" << '\n';
    }
}