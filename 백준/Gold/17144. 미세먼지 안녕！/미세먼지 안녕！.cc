#include <bits/stdc++.h>

using namespace std;
 
int r, c, t;
int board[55][55];
int ans;
int ac;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void spread()
{
    int tmp[55][55] = {0};

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(board[i][j]>0)
            {
                int cnt = 0;
                int amount = ceil(board[i][j]/5);
                for(int k=0; k<4; k++)
                {
                    int nx = i+dx[k];
                    int ny = j+dy[k];

                    if(nx<0||nx>=r||ny<0||ny>=c) continue;
                    if(board[nx][ny]==-1) continue;

                    tmp[nx][ny] += amount;
                    cnt++;
                }
                tmp[i][j] += -(amount*cnt);
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

void rotateDust(int row, bool isclock)
{
    pair<int, int> cur = {row, 0};
    int dir = isclock?2:0;

    int nx = cur.first;
    int ny = cur.second;

    int up=isclock?row-1:0;
    int left=0;
    int right=c;
    int down=isclock?r:row+2;

    while(board[nx][ny]!=-1)
    {
        nx = cur.first+dx[dir];
        ny = cur.second+dy[dir];
 
        if(nx<up||nx>=down||ny<left||ny>=right)
        {
            int add = (isclock?-1:1);
            dir=(dir+add+4)%4; 
            continue;
        }

        board[cur.first][cur.second] = (board[nx][ny] == -1)?0:board[nx][ny];
        cur = {nx, ny};
    }
}

void performac()
{
    rotateDust(ac-1, false);
    rotateDust(ac+2, true);
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
            if(board[i][j]==-1&&ac==0)
                ac = i;
        }
    }

    while(t--)
    {
        spread();
        performac(); 
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(board[i][j]!=-1)ans+=board[i][j];
        }
    }

    cout << ans;
}