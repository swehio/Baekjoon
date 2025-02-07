#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

void CountScore(const string& type, int choice, vector<int>& targetNum, const vector<char>& targetName, const vector<int>& scoreSpread)
{
    if(choice < 4)
    {
        auto it = find(targetName.begin(), targetName.end(), type[0]);
        if(it != targetName.end())
        {
            targetNum[it-targetName.begin()] += scoreSpread[choice-1];
        }
        else
        {
            cout << "No0";
        }
    }
    else if(choice > 4)
    {
        auto it = find(targetName.begin(), targetName.end(), type[1]);
        if(it != targetName.end())
        {
            targetNum[it-targetName.begin()] += scoreSpread[choice-1];
        }
        else
        {
            cout << "No1";
        }
    }
    else
    {
        cout << "4";
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<int> totalScore = {0, 0, 0, 0, 0, 0, 0, 0};
    vector<char> personality = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
    vector<int> choiceScore = {3, 2, 1, 0, 1, 2, 3};
    int index = 0;
    
    for(int i = 0; i<survey.size();++i)
    {
        CountScore(survey[i], choices[i], totalScore, personality, choiceScore);
    }
    
    for(int i = 0; i<totalScore.size()-1; i+=2)
    {
        if(totalScore[i] >= totalScore[i+1])
        {
            answer.push_back(personality[i]);
        }
        else
        {
            answer.push_back(personality[i+1]);
        }
        
    }
    
    return answer;
}