#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool IsPast(const string& today, const string& date, int term)
{
    int todayY = stoi(today.substr(2, 2));
    int todayM = stoi(today.substr(5, 2));
    int todayD = stoi(today.substr(8, 2));
    
    int dateY = stoi(date.substr(2, 2));
    int dateM = stoi(date.substr(5, 2));
    int dateD = stoi(date.substr(8, 2));
    
    int deadlineY = dateY;
    int deadlineM = dateM;
    int deadlineD = dateD;
    
    
    if((dateM+term) % 12 == 0)
    {
        deadlineM = 12;
        deadlineY = (deadlineY+(dateM+term) / 12) - 1;
    }
    else
    {
       deadlineM = (dateM+term) % 12;
       deadlineY = deadlineY+(dateM+term) / 12;
        
    }
   
    --deadlineD;
    if(deadlineD == 0)
    {
        deadlineD = 28;
        --deadlineM;
        if(deadlineM == 0)
        {
            deadlineM = 12;
            --deadlineY;
        }
    }
    
    if(todayY > deadlineY)
    {
        return true;
    }
    else if (todayY < deadlineY)
    {
        return false;
    }
    else
    {
        if(todayM > deadlineM)
        {
            return true;
        }
        else if(todayM < deadlineM)
        {
            return false;
        }
        else
        {
            if(todayD > deadlineD)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, string> mTerms;
    for(string term : terms)
    {
        mTerms[term[0]] = term.substr(2, 3);
    }
    
    for(int i = 0; i<privacies.size(); i++){
        char type = privacies[i][11];
        string date = privacies[i].substr(0, 10);
        if(IsPast(today, date, stoi(mTerms[type])))
        {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}