#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string temp;
    for(int i=0; i<s.size();++i){
        temp = s.substr(0, i+1);
        reverse(temp.begin(), temp.end());
        auto it = find(temp.begin()+1, temp.end(), temp[0]);
        if(it == temp.end())
            answer.push_back(-1);
        else
            answer.push_back(it-temp.begin());
        
    }
    
    return answer;
}