#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = s;
    int j = 0;
    
    for(int i = 0 ; i<s.size(); ++i){
        if(s[i] == ' '){
            j = 0;
        }
        else{
            if(j % 2 == 0){
                answer[i] = toupper(s[i]);
            }
            else {
                answer[i] = tolower(s[i]);
            }
            ++j;            
        }
    }
    
    return answer;
}