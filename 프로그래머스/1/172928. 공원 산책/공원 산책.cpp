#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    vector<int> currentPosition(2);
    unordered_map<char, pair<int, int>> directionMap;
    
    for(int i = 0; i<park.size(); ++i)
    {
        for(int j = 0; j < park[i].size(); ++j)
        {
            if(park[i][j] == 'S')
            {
                currentPosition[0] = i;
                currentPosition[1] = j;
            }
        }
    }
    
    directionMap['E'] = {0, 1};
    directionMap['S'] = {1, 0};
    directionMap['W'] = {0, -1};
    directionMap['N'] = {-1, 0};
    
    for(string route : routes)
    {
        stringstream ss(route);
        char direction;
        int num;
        ss >> direction >> num;
        
        vector<int> tempCurrentPosition(currentPosition.begin(), currentPosition.end());
        
        for(int i = 0; i<num; ++i)
        {
            vector<int> newPosition(2);
            newPosition[0] = currentPosition[0] + directionMap[direction].first;
            newPosition[1] = currentPosition[1] + directionMap[direction].second;
            bool verticalInRange = newPosition[0] >= 0 && newPosition[0] < park.size();
            bool HorizonInRange = newPosition[1] >= 0 && newPosition[1] < park[1].size();
            if(!verticalInRange || !HorizonInRange || park[newPosition[0]][newPosition[1]] == 'X')
            {
                currentPosition[0] = tempCurrentPosition[0];
                currentPosition[1] = tempCurrentPosition[1];
                break;
            }
            currentPosition[0] = newPosition[0];
            currentPosition[1] = newPosition[1];
        }
    }
    answer.push_back(currentPosition[0]);
    answer.push_back(currentPosition[1]);
    return answer;
}