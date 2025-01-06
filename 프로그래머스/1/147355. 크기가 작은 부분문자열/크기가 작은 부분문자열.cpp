#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    string subStr = "";
    for(int i = 0; i<=t.size()-p.size(); ++i){
        subStr = "";
        for(int j = i; j < i+p.size(); ++j){
            subStr+=t[j];
        }
        if(stol(p) >= stol(subStr)){
            ++answer;
        }
    }
    
    return answer;
}