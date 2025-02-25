#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    for(int i = 0; i<N; i++)
    {
        answer.push_back(i+1);
    }
    
    map <int, float> failRate;
    int preCount = 0;
    
    for(int i = 1; i <= N; i++)
    {
        int tryCount = count(stages.begin(), stages.end(), i);
        
        if(tryCount == 0)
        {
            failRate[i] = 0;
            preCount += 0;
            continue;
        }
        failRate[i] = (float)tryCount/(stages.size()-preCount);
        preCount += tryCount;
    }
    
    for(auto it = failRate.begin(); it != failRate.end(); it++)
    {
        cout << it->first << it->second << endl;
    }
    
    for(int i = 0; i<N-1; i++)
    {
        for(int j = i+1; j<N; j++)
        {
            int temp;
            if(failRate[answer[i]] < failRate[answer[j]])
            {
                temp = answer[i];
                answer[i] = answer[j];
                answer[j] = temp;
            }
            else if(failRate[answer[i]] == failRate[answer[j]])
            {
                if(answer[i] > answer[j])
                {
                    temp = answer[i];
                    answer[i] = answer[j];
                    answer[j] = temp;
                }
            }
        }
    }
    
    return answer;
}