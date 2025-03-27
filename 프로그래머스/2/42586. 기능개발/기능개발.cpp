#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    for(int i = 0; i<progresses.size(); i++)
    {
        int remainDay = 100 - progresses[i];
        int workDay = ceil((float)remainDay / speeds[i]);
        days.push(workDay);
        
    }
    
    int count = 0;
    int frontDay = 0;
    while(!days.empty())
    {
        if(count == 0)
        {
            frontDay = days.front();
            count++;
            days.pop();
        }
        else
        {
            if(frontDay >= days.front())
            {
                count++;
                days.pop();
            }
            else
            {
                answer.push_back(count);
                count = 0;
            }
        }
    }
    
    if(count!=0)
        answer.push_back(count);
    
    return answer;
}