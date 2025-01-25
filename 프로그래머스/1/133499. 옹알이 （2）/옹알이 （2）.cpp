#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    unordered_set<string> canBabbling = {"aya", "ye", "woo", "ma"};
    
    for(string word : babbling)
    {
        int wordStart=0;
        string preWord="";
        while(wordStart < word.size())
        {
            string sub3Babbling = word.substr(wordStart, 3);
            if(preWord == sub3Babbling)
            {
                wordStart=0;
                break;
            }
            if(canBabbling.find(sub3Babbling) != canBabbling.end())
            {
                preWord = sub3Babbling;
                wordStart+=3;
            }            
            else
            {
                string sub2Babbling = word.substr(wordStart, 2);
                if(preWord == sub2Babbling)
                {
                    wordStart=0;
                    break;
                }
                if(canBabbling.find(sub2Babbling) != canBabbling.end())
                {
                    preWord = sub2Babbling;
                    wordStart+=2;
                }
                else
                {
                    wordStart=0;
                    break;
                }
            }
        }
        if(wordStart!=0)
            ++answer;
    }
    
    return answer;
}