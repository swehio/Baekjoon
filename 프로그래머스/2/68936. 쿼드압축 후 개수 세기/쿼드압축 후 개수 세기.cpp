#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> num(2, 0);

void dfs(vector<vector<int>>& arr, int startX, int startY, int Size)
{      
    
    int First = arr[startX][startY];
    bool isSame = true;
    for(int i = startX; i<startX+Size; ++i)
    {
        for(int j = startY; j<startY+Size; ++j)
        {
            if(arr[i][j] != First)
            {  

                isSame = false;
                break;
            }
        }
        if(!isSame) break;
    }
    
    if(isSame)
    {
        ++num[First];
    }
    else
    {
        dfs(arr, startX, startY, Size/2);
        dfs(arr, startX+Size/2, startY, Size/2);
        dfs(arr, startX, startY+Size/2, Size/2);
        dfs(arr, startX+Size/2, startY+Size/2, Size/2);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    dfs(arr, 0, 0, arr.size());
    
    return num;
}