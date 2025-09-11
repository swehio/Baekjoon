#include <bits/stdc++.h>
using namespace std;

int n;

int board1[25][25];
pair<int, int> board2[25][25];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void move(int x, int y, int dir)
{
    int val = board2[x][y].first;
    board2[x][y].first = 0; // 원래 위치 비우기

    int curx = x;
    int cury = y;

    while (true) {
        int nx = curx + dx[dir];
        int ny = cury + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            break;

        if (board2[nx][ny].first == 0) {
            curx = nx;
            cury = ny;
        } 
        else if (board2[nx][ny].first == val && board2[nx][ny].second == 0) {
            board2[nx][ny].first *= 2;
            board2[nx][ny].second = 1;
            return;
        } 
        else {
            break;
        }
    }

    board2[curx][cury].first = val;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> board1[i][j];

    int mx = 0;

    for(int tmp=0; tmp < (1<<(2*5)); tmp++)
    {
        for(int i = 0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                board2[i][j].first = board1[i][j];
                board2[i][j].second = 0;
            }
        }

        int brute = tmp;

        for(int i=0; i<5; i++)
        {
            int dir = brute % 4;
            brute /= 4;

            if(dir > 1) //위, 왼쪽  
            {
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<n; j++)
                    {
                        if(board2[i][j].first != 0)
                            move(i, j, dir);
                    }
                }
            }
            else //아래, 오른쪽  
            {
                for(int i=n-1; i>=0; i--)
                {
                    for(int j=n-1; j>=0; j--)
                    {
                        if(board2[i][j].first != 0)
                            move(i, j, dir);
                    }
                }
            }

            for(int i = 0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    board2[i][j].second = 0;
                }
            }
        }
        
        for(int i = 0; i<n; i++)
            for(int j=0; j<n; j++)
                mx = max(mx, board2[i][j].first);
    }

    cout << mx;
}