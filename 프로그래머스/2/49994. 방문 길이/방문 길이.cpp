#include <string>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

pair<int, int> moveVirtex(char dir, const pair<int, int>& position)
{
    pair<int, int> newP = {0, 0};
    switch(dir)
    {
        case 'U':
            newP.first = position.first;
            newP.second = position.second + 1;
            break;
        case 'D':
            newP.first = position.first;
            newP.second = position.second - 1;
            break;
        case 'L':
            newP.first = position.first - 1;
            newP.second = position.second;
            break;
        case 'R':
            newP.first = position.first + 1;
            newP.second = position.second;
            break;
        default:
            break;
    }
    return newP;
}

int solution(string dirs) {
    //set<pair<int, int>> virtex;
    set<set<pair<int, int>>> lines;
    pair<int, int> currentPosition = {0, 0};
    //virtex.insert(currentPosition);
    
    //bool lineConnect = false;
    
    for(char dir : dirs)
    {
        pair<int, int> newPosition = moveVirtex(dir, currentPosition);
        if(abs(newPosition.first) > 5 || abs(newPosition.second) > 5)
        {
            continue;
        }
        set<pair<int, int>> line;
        line.insert(currentPosition);
        line.insert(newPosition);
        lines.insert(line);
        //auto it = find(virtex.begin(), virtex.end(), newPosition);
        
        // if(it != virtex.end() && !lineConnect)
        // {
        //     lineConnect = true;
        // }
        currentPosition = newPosition;
        //virtex.insert(currentPosition);
    }
    
    int length = lines.size();
    
    return length;
}