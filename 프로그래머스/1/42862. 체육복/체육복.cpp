#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n, 1);
    
    for(int lostStudent : lost)
    {
        --students[lostStudent-1];
    }
    
    for(int reserveStudent:reserve)
    {
        ++students[reserveStudent-1];
    }
    
    sort(reserve.begin(), reserve.end());
    
    for(int reserveStudent : reserve)
    {
        if(students[reserveStudent-1] > 1)
        {
            if(reserveStudent >1 && students[reserveStudent-2] == 0)
            {
                ++students[reserveStudent-2];
                --students[reserveStudent-1];
                continue;
            }
            else if(reserveStudent < n && students[reserveStudent] == 0)
            {
                ++students[reserveStudent];
                --students[reserveStudent-1];
            }
        }
    }
    
    for(int student : students)
    {
        if(student > 0)
        {
            ++answer;
        }
    }
    return answer;
}