#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int incorrectIndex = 0;
    string preWord = "";
    
    for(int i = 1; i< words.size(); i++)
    {
        preWord = words[i-1];
        auto alreadyUse = find(words.begin(), words.begin()+i, words[i]);
        if(preWord[preWord.size()-1] != words[i][0] || alreadyUse != words.begin()+i)
        {
            incorrectIndex = i;
            break;
        }
    }
    
    answer.push_back(incorrectIndex%n);
    answer.push_back(incorrectIndex/n);
    
    if(incorrectIndex != 0)
    {
        answer[0] += 1;
        answer[1] += 1;
    }

    return answer;
}