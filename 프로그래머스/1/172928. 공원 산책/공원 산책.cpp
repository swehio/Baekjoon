#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int h = park.size();           // 세로 길이
    int w = park[0].size();        // 가로 길이
    int x = 0, y = 0;              // 시작 위치

    // 시작 위치 찾기
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (park[i][j] == 'S') {
                x = i;
                y = j;
                break;
            }
        }
    }

    // 방향 정의
    int dx[128] = {0}, dy[128] = {0};
    dx['N'] = -1; dy['N'] = 0;
    dx['S'] = 1;  dy['S'] = 0;
    dx['W'] = 0;  dy['W'] = -1;
    dx['E'] = 0;  dy['E'] = 1;

    // 명령 처리
    for (const string& route : routes) {
        char dir;
        int dist;
        stringstream ss(route);
        ss >> dir >> dist;

        int nx = x;
        int ny = y;
        bool canMove = true;

        for (int i = 0; i < dist; ++i) {
            nx += dx[dir];
            ny += dy[dir];

            // 범위 벗어나거나 장애물 만나면 이동 불가
            if (nx < 0 || ny < 0 || nx >= h || ny >= w || park[nx][ny] == 'X') {
                canMove = false;
                break;
            }
        }

        // 이동 가능하면 좌표 갱신
        if (canMove) {
            x = nx;
            y = ny;
        }
    }

    return {x, y};
}