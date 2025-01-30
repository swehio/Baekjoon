#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int> reKeyMap;
    
    for(string key : keymap)
    {
        int index = 1;
        for(char cha : key)
        {
            ++index;
            if(reKeyMap.find(cha) != reKeyMap.end() && reKeyMap[cha] < index-1)
            {
                continue;
            }

            reKeyMap[cha] = index-1;
            
        }
    }
    
    for(string target : targets)
    {
        int pushCount = 0;
        for(char cha : target)
        {
            if(reKeyMap.find(cha) != reKeyMap.end())
                pushCount += reKeyMap[cha];
            else
            {
                pushCount = -1;
                break;
            }
                
        }
        
        answer.push_back(pushCount);
    }
    
    return answer;
}