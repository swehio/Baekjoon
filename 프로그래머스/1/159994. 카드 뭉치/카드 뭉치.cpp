#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    queue<string> qCards1;
    queue<string> qCards2;
    queue<string> qgoal;
    
    for(string& card : cards1)
    {
        qCards1.push(card);
    }
    
    for(string& card : cards2)
    {
        qCards2.push(card);
    }
        for(string& sgaol : goal)
    {
        qgoal.push(sgaol);
    }
    
    while(!qgoal.empty())
    {
        if(qgoal.front() == qCards1.front())
        {
            qgoal.pop();
            qCards1.pop();
        }
        else if(qgoal.front() == qCards2.front())
        {
            qgoal.pop();
            qCards2.pop();
        }
        else
        {
            return "No";
        }
           
    }
    
    return "Yes";
}