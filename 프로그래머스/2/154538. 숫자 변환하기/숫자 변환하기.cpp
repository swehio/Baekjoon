#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int bfs(int x, int y, int n)
{
    queue<pair<int, int>> q;

    if(x == y) return 0;
    if(y%3 == 0) q.push({y/3, 1});
    if(y%2 == 0) q.push({y/2, 1});
    if(y-n > 0) q.push({y-n, 1});
    
    while(!q.empty())
    {
        pair<int, int> num = q.front();
        q.pop();
        if(num.first == x)
        {
            return num.second;
        }
        if(num.first%3 == 0) q.push({num.first/3, num.second+1});
        if(num.first%2 == 0) q.push({num.first/2, num.second+1});
        if(num.first-n > 0) q.push({num.first-n, num.second+1});
    }
    
    return -1;
}

int solution(int x, int y, int n) {
    return bfs(x, y, n);
}