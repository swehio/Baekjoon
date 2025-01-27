#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool compare(int a, int b)
{
    return a>b;
}

string solution(string X, string Y) {
    string answer = "";
    map<char, int> Ymap;
    vector<char> result;
    
    for(char num : Y)
    {
         ++Ymap[num]; 
    }
    
    for(char num : X)
    {
        if(Ymap[num] != 0 )
        {
            result.push_back(num);
            --Ymap[num];
        }
    }
    
    sort(result.begin(), result.end(), compare);
    
    for(int num : result)
    {
        answer += num;
    }
    
    if(answer.empty())
        answer = "-1";
    if(answer[0] == '0')
        answer = "0";
    
    return answer;
}