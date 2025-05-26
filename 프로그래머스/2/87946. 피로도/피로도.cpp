#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b)
{
    if(a[1] == b[1])
    {
        return a[0] > b[0];
    }
    return a[1] < b[1];
}

int solution(int k, vector<vector<int>> dungeons) {
    
    sort(dungeons.begin(), dungeons.end());
    int cntMax = 0;
    do
    {
        int currentK = k;
        int cnt = 0;
        for(auto& dungeon : dungeons)
        {
            if(currentK >= dungeon[0])
            {
                currentK -= dungeon[1];
                ++cnt;
            }
            else break;
        }
        if(cnt > cntMax) cntMax = cnt;
    }
    while(next_permutation(dungeons.begin(), dungeons.end()));
    return cntMax;
}