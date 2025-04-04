#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> makeWantList(vector<string>& things, vector<int>& num)
{
    unordered_map<string, int> makeList;
    for(int i = 0; i< things.size(); i++)
    {
        makeList[things[i]] = num[i];
    }
    
    return makeList;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> wantList;
    
    wantList = makeWantList(want, number);
    
    for(int i = 0; i< discount.size()-9; i++)
    {
        for(int j = i; j< i+10; j++)
        {
            if(wantList[discount[j]])
            {
                wantList[discount[j]]--;
                if(wantList[discount[j]] == 0)
                {
                    wantList.erase(discount[j]);
                }
            }
        }
        
        if(wantList.empty())
        {
            answer++;
        }
        wantList = makeWantList(want, number);
    }
    
    return answer;
}