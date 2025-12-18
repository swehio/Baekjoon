#include <bits/stdc++.h>
using namespace std;

int board[55][55];
int tmp[55][55];
int ans = 2;
int airCleanerUp = -1;
int airCleanerDown;
int r, c, t;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void spread()
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(board[i][j] > 0)
            {
                int cnt = 0;
                int spreadAmount = board[i][j]/5;
                for(int k=0; k<4; k++)
                {
                    int nx = i+dx[k];
                    int ny = j+dy[k];

                    if(nx<0||nx>=r||ny<0||ny>=c) continue;
                    if(board[nx][ny] == -1) continue;
                     
                    tmp[nx][ny] += spreadAmount;
                    cnt++;
                }
                board[i][j] -= spreadAmount*cnt;
            }
        }
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            board[i][j] += tmp[i][j];
        }
    }
}

void rotate(int stX, int dir)
{
    int cx = (dir==1)?stX-1:stX+1;
    int cy = 0; 
    int movedir = dir;
    int t = 30; 

    while(!(cx==stX&&cy==0))
    {
        int nx=cx+dx[movedir];
        int ny=cy+dy[movedir];
        bool xmaxLimit = (dir==1) ? nx<0 : nx>=r;
        bool xminLimit = (dir==1) ? nx>stX : nx<stX;
        if(xminLimit||xmaxLimit||ny<0||ny>=c)
        {
            movedir = (dir==1)?(movedir+1)%4:(movedir-1)%4;
            nx=cx+dx[movedir];
            ny=cy+dy[movedir];
        }
        if(board[nx][ny]!=-1) board[cx][cy] = board[nx][ny]; 
        else board[cx][cy] = 0; 
        cx = nx; cy = ny;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> t;
 
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == -1 && airCleanerUp == -1)
            {
                airCleanerUp = i;
                airCleanerDown = i+1;
            }
        } 
    }

    while(t--)
    {
        for(int i=0; i<r; i++)
        {
            fill(tmp[i], tmp[i]+c, 0);
        }
        spread();  
        rotate(airCleanerUp, 1);
        rotate(airCleanerDown, 3); 
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            ans+=board[i][j];
        }
    }

    cout << ans;
}