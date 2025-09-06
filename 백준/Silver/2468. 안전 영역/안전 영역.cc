#include <bits/stdc++.h>
using namespace std;

int board[102][102];
int zone[102][102];
int vis[102][102];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
 
int maxCnt;
int cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int max = 0;
    vector<int> heights;
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >> board[i][j];
            heights.push_back(board[i][j]);
        }
    }
    heights.push_back(0);
    sort(heights.begin(), heights.end());
    heights.erase(unique(heights.begin(), heights.end()), heights.end());
    
    for(int k : heights)
    {
        for(int i =0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(board[i][j] <= k)
                {
                    zone[i][j] = 1;
                    vis[i][j] = 1;
                }
            }
        }
        
        for(int i =0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(vis[i][j] == 0)
                {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;
                    cnt++;
                    
                    while(!q.empty())
                    {
                        auto cur = q.front();
                        q.pop();
                        
                        for(int i = 0; i<4; i++)
                        {
                            int nx = cur.first + dx[i];
                            int ny = cur.second + dy[i];
                            
                            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                            if(vis[nx][ny] == 1 || zone[nx][ny] == 1) continue;
                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                    
                }
            }
        }
        
        if(cnt > maxCnt) maxCnt = cnt;
        cnt = 0;
        for(int i = 0; i<n; i++) fill(vis[i], vis[i]+n, 0);
    }
    
    cout << maxCnt;
}